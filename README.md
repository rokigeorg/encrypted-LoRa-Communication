<snippet>
  <content>
# encrypted LoRa Communication

This repository includes code for an Adruino Uno and a Raspberry Pi Model B.
The Arduino (Node) can send AES encrypted data to the Raspberry Pi (Gateway).


## Goal
The goal was to develop a Node to Gateway encrypted communiction with the LoRa technolagy.


## Hardware 
* HopeRF RFM95 - Low Power Long Range Transceiver Module V1.0 (2x)
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

## Dependencies
### for the Node
* AES library for Arduino - [download and instructions found here](http://spaniakos.github.io/AES/)

### for the Gateway
* enable SPI -> check in  ```raspi-config``` on RPi 
* WiringPi: to access GPIO -> install ```sudo apt-get install wiringpi see http://wiringpi.com ```
* start program as root ```sudo ./main``

## Installation
TODO: Describe the installation process
What things you need to install the software and how to install them
```
sudo apt-get install wiringpi
```
Bla
```
Give examples
```
## Usage
TODO: Write usage instructions
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