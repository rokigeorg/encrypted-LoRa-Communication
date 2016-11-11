//Transfer Libraries for Communication between Arduino -> HopeRF
#include <SPI.h>
#include <RH_RF95.h>

//Encryption Library
#include <AES.h>

#define RFM95_CS 10   //LoRa Modul Chip select pin
#define RFM95_RST 9   //LoRa Modul Reset pin
#define RFM95_INT 3   //LoRa Modul Interrupt pin

// Change to 434.0 or other frequency, must match RX's freq!
#define RF868_FREQ 868.1

#define LORA_PHY_PAYLOAD_SIZE 16

// Singleton instance of the radio driver
RH_RF95 rf95(RFM95_CS, RFM95_INT);

// create AES instance
AES aes;

//cipher Arr will alloc memory once on the Stack where the encrypted data will be written to
static byte cipher[(LORA_PHY_PAYLOAD_SIZE+7)] ;
    
//==========================================================================
//======================= FUNCTIONS=========================================
//==========================================================================

uint8_t * encrypData(uint8_t plain[])
{
  uint8_t key[] = "0123456789987654";
  static uint8_t cipher [N_BLOCK] ;
  uint8_t check [N_BLOCK] ;
  const uint8_t bits = 128;

  byte succ ;

  /// Set key 
  succ = aes.set_key (key, bits) ;
  if (succ != SUCCESS)
    Serial.println ("Failure set_key") ;
  
  succ = aes.encrypt (plain, cipher) ;
    if (succ != SUCCESS)
        Serial.println ("Failure encrypt") ;
  return cipher;
 }



void setup() {

  Serial.begin(9600);

//======================setup HopeRF 95M======================================
    pinMode(RFM95_RST, OUTPUT);
    digitalWrite(RFM95_RST, HIGH);

    delay(100);
    // manual reset
    digitalWrite(RFM95_RST, LOW);
    delay(10);
    digitalWrite(RFM95_RST, HIGH);
    delay(10);

    while (!rf95.init()) {
        while (1);
    }

    // Defaults after init are 434.0MHz, modulation GFSK_Rb250Fd250, +13dbM
    if (!rf95.setFrequency(RF868_FREQ)) {
        while (1);
    }

    // Defaults after init are 434.0MHz, 13dBm, Bw = 125 kHz, Cr = 4/5, Sf = 128chips/symbol, CRC on

    // The default transmitter power is 13dBm, using PA_BOOST.
    // If you are using RFM95/96/97/98 modules which uses the PA_BOOST transmitter pin, then 
    // you can set transmitter powers from 5 to 23 dBm:
    rf95.setTxPower(23, false);

}

void loop() {
 
    //=======================formating the LoRa Package =====================================

    String str ="{\"Tmp\":\"";
    String tempStr = "21.02";
    str += tempStr;
    str += "\"}";

    static char radiopacket[LORA_PHY_PAYLOAD_SIZE];
    str.toCharArray(radiopacket, LORA_PHY_PAYLOAD_SIZE);

    //=======================encrype LoRa Package =====================================
 
    uint8_t * encryDataArrPtr;  //pointer holds return add of the encrypted Data Array
    encryDataArrPtr = encrypData((byte *) radiopacket);

    //=======================send LoRa Package =====================================

    // Send a message to rf95_server
    rf95.send(encryDataArrPtr, LORA_PHY_PAYLOAD_SIZE);
    Serial.println ("Send Package") ;

    delay(10);
    rf95.waitPacketSent();
    // Now wait for a reply
    uint8_t buf[RH_RF95_MAX_MESSAGE_LEN];
    uint8_t len = sizeof(buf);

    delay(4000);
}
