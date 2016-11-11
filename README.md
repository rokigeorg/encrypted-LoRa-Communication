<snippet>
  <content>
# Encrypted LoRa Communication - Node to Gateway

This repository includes code for an Adruino Uno and a Raspberry Pi Model B.
The Arduino (Node) can send AES encrypted data to the Raspberry Pi (Gateway). The LoRa commincation parameters are adjustable. Default settings are LoRa Frequency 868,1 MHz, Spreading Factor SF7 and Coding Rate 4/5. LoRa Communication is possible encrypted and without encryption. Right now the encrypted LoRa payload is limited to 16 Bytes.


## Goal
The goal was to develop a Node to Gateway encrypted communiction with the LoRa Radio technolagy. (Not LoRaWan)


## Hardware 
The code functions with the following hardware components.
* 2 x HopeRF RFM95 - Low Power Long Range Transceiver Module V1.0 
* Raspberry Pi - Model B
* Arduino Uno

### Hardware Wiring - Node and Gateway

#### RFM95 LoRa Modul - Arduino Uno
* 3.3V - 3.3V
* GND - GND 
* MISO - Digital 12  
* MOSI - Digital 11  
* SCK - Digital 13  
* NSS - Digital 10  
* DIO0 - Digital 3 
* RST - Digital 9 

#### RFM95 LoRa Modul - Raspbery Pi Model B
* 3.3V - 3.3V (header pin #1) 
* GND - GND (pin #6) 
* MISO - MOSI (pin #21) 
* MOSI - MISO (pin #19) 
* SCK - CLK (pin #23) 
* NSS - GPIO6 (pin #22) 
* DIO0 - GPIO7 (pin #7) 
* RST - GPIO0 (pin #11)

## Software Dependencies 
The code requires the following software libraries.
### for the Node
* AES library for Arduino - [download and instructions found here](http://spaniakos.github.io/AES/)

### for the Gateway
* enable SPI -> check in  ```raspi-config``` on RPi 
* WiringPi: to access GPIO -> install ```sudo apt-get install wiringpi```
* start program as root ``sudo ./main``

## Setup and Installation
### for the Node
1. Clone this repository to your machine you will program the Arduino ```git clone https://github.com/rokigeorg/encrypted-LoRa-Communication.git ``` 
2. Wire up the Arduino with the first RFM95 LoRa Modul (see section Hardware Wiring)
3. install AES library in arduino sketch Folder ``/Arduino/ libraries``  [instructions here](http://spaniakos.github.io/AES/)
4. Download [Download RadioHead v1.59](https://cdn-learn.adafruit.com/assets/assets/000/031/670/original/RadioHead-1.59.zip?1460574831) and install the library in arduino sketch Folder ``/Arduino/ libraries`` . Reboot IDE.
5. Back in our repository folder open ``$ cd arduino_Node && ls``. There are two example sketches. ```ex1_send_NOT_encryp_LoRaPackage``` -> send NOT encrypted LoRa Packages , ```ex2_send_encryp_LoRaPackage``` -> send encrypted LoRa Packages (16 Bytes Payload size only)
6. open sketch ``cd ex2_send_encryp_LoRaPackage`` in the adruino IDE and upload it to the Uno  
7. Node send LoRa packages now

### for the Gateway
1. Clone this repository to your Raspberry Pi ```git clone https://github.com/rokigeorg/encrypted-LoRa-Communication.git ``` 
2. Wire up the Raspberry Pi with the second RFM95 LoRa Modul (see section Hardware Wiring)
3. On the command line in our repository folder  ``$ cd RaspberryPi_Gateway``
4. Compile the code via the Makefile ``$ make``
5. Run the LoRa Radio Receiver ``$ sudo ./main -f 868100000 -sf 7 -cr 5`` 

Please note the adjustable arguments 
```
-f 868100000
 ``` 
 specifizes the frequency
 ```
 -sf 7
 ``` 
 specifizes the spreadig factor SF7
  ```
 -cr 5
 ``` 
 specifizes the coding rate 4/5



## Usage
The code should demostrate the usage of the LoRa Radio  
## Contributing
1. Fork it!
2. Create your feature branch: `git checkout -b my-new-feature`
3. Commit your changes: `git commit -am 'Add some feature'`
4. Push to the branch: `git push origin my-new-feature`
5. Submit a pull request :D




## History
TODO: Write history sure
## Credits
TODO: Write credits
## License
TODO: Write license
]]></content>
  <tabTrigger>readme</tabTrigger>
</snippet>