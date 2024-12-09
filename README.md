# TIC-DIN-MODBUS

**TIC-DIN-MODBUS** is a device which can demodulate Linky informations TIC (or old french counter meter). It provides informations with RS845 Modbus RTU interface.

You can with Webpage:
* Add specific managed TIC command
* Configure Modbus parameter 
* Configure WiFi SSID/Password
* Add User/Password for HTTP webpage
* See ModBus with mapping table and Network status
* Update the device

**TIC-DIN-MODBUS** is compatible with historic and standard mode. The mode is detected automaticaly.

## Hardware

**TIC-DIN-MODBUS** use a DIN rail module 1U.
It is based on **ESP32-C3** module and a **MAX485** chip for the RS485 interface

### Device v2
<img src="https://github.com/fairecasoimeme/TIC-DIN-MODBUS/blob/master/Doc/images/tic-din-modbus-rtu-rs485_2.jpg" width="600">
<img src="https://github.com/fairecasoimeme/TIC-DIN-MODBUS/blob/master/Doc/images/tic-din-modbus-rtu-rs485.jpg" width="600">

### RS485 pins
- VIN (5 - 12VDC)
- A (+)
- B (-)
- GND

### TIC pins
- I1
- I2
  
### Assembly diagram
<img src="https://github.com/fairecasoimeme/TIC-DIN-MODBUS/blob/master/Doc/images/schema_TIC_MODBUS.jpg" width="600">

## LED Flashing

### 1 flash every second
In this case, **TIC-DIN-MODBUS** can't demodulate the counter meter or there are too errors. It is possible that this case can appear 10-15 seconds after resetting due to the mode detection.

### 1 flash every 3 second
In this case, All it's OK. The device demodulate correctly the counter meter.

## WiFi parameter

### By default  
* SSID : LIXEETIC-XXXX (editable) 
* password : adminXXXX (editable - must be 8 characters) 
PS : XXXX is the end of the @MAC

⚠️**You can desactive WiFi when all it's OK**  

⚠️**To activate WiFi, you have to send ModBus packet with command 0x06 (Write single register) to address 666 with the value 1.**

## Modbus slave parameter

### By default
* id master : 1 (editable)
* speed (bauds) : 9600 (editable)
* Data bits : 8
* Stop bits : 1
* Parity : none

## ModBus mapping table
|Mode|command|@registry|
|------|----------|------|	
|Historique|ADCO		|300-303	|
|Historique|BASE		|1004-1007  |
|Historique|ISOUSC	|1399           |
|Historique|HCHC		|1004-1007  |
|Historique|HCHP		|1008-1011  |
|Historique|EJPHN	|1004-1007      |
|Historique|EJPHPM	|1008-1011      |
|Historique|BBRHCJB	|1004-1007      |
|Historique|BBRHPJB	|1008-1011      |
|Historique|BBRHCJW	|1012-1015      |
|Historique|BBRHPJW	|1016-1019      |
|Historique|BBRHCJR	|1020-1023      |
|Historique|BBRHPJR	|1024-1027      |
|Historique|IINST1	|1320           |
|Historique|IINST2	|1321           |
|Historique|IINST3	|1322           |
|Historique|IINST	|1320           |
|Historique|IMAX1	|1600           |
|Historique|IMAX2	|1601           |
|Historique|IMAX3	|1602           |
|Historique|IMAX		|1600       |
|Historique|PMAX		|1361-1364  |
|Historique|PAPP		|1329-1332  |
|Historique|ADPS		|1700       |
|Historique|ADIR1	|1603           |
|Historique|ADIR2	|1604           |
|Historique|ADIR3	|1605           |
|Historique|PEJP		|1606		|
|Standard|ADSC	|	300-303         |
|Standard|EAST	|	1000-1003       |
|Standard|EASF01	|	1004-1007   |
|Standard|EASF02	|	1008-1011   |
|Standard|EASF03	|	1012-1015   |
|Standard|EASF04	|	1016-1019   |
|Standard|EASF05	|	1020-1023   |
|Standard|EASF06	|	1024-1027   |
|Standard|EASF07	|	1028-1031   |
|Standard|EASF08	|	1032-1035   |
|Standard|EASF09	|	1036-1039   |
|Standard|EASF10	|	1040-1043   |
|Standard|EASD01	|	1100-1103   |
|Standard|EASD02	|	1104-1107   |
|Standard|EASD03	|	1108-1111   |
|Standard|EASD04	|	1112-1115   |
|Standard|EAIT	|	1200-1203       |
|Standard|ERQ1	|	1300-1303       |
|Standard|ERQ2	|	1304-1307       |
|Standard|ERQ3	|	1308-1311       |
|Standard|ERQ4	|	1312-1315       |
|Standard|IRMS1	|	1320            |
|Standard|IRMS2	|	1321            |
|Standard|IRMS3	|	1322            |
|Standard|URMS1	|	1323            |
|Standard|URMS2	|	1324            |
|Standard|URMS3	|	1325            |
|Standard|PREF	|	1399            |
|Standard|STGE	|	                |
|Standard|PCOUP	|	1398            |
|Standard|SINSTI	|	1400-1403   |
|Standard|SMAXIN-1	|1404-1407      |
|Standard|SMAXIN		|1408-1411  |
|Standard|CCASN-1	|1500-1503      |
|Standard|CCASN		|1504-1507      |
|Standard|CCAIN-1	|1412-1415      |
|Standard|CCAIN		|1416-149       |
|Standard|UMOY1		|1326           |
|Standard|UMOY2		|1327           |
|Standard|UMOY3		|1328           |
|Standard|SINSTS1	|1329-1332      |
|Standard|SINSTS2	|1333-1336      |
|Standard|SINSTS3	|1337-1340      |
|Standard|SINSTS		|1329-1332  |
|Standard|SMAXSN-1	|1345-1348      |
|Standard|SMAXSN1-1	|1345-1348      |
|Standard|SMAXSN2-1	|1353-1356      |
|Standard|SMAXSN3-1	|1357-1360      |
|Standard|SMAXSN1	|1361-1364      |
|Standard|SMAXSN2	|1365-1368      |
|Standard|SMAXSN3	|1369-1372      |
|Standard|SMAXSN		|1361-1364  |

## Screenshots

### Network Status
<img src="https://github.com/fairecasoimeme/TIC-DIN-MODBUS/blob/master/Doc/images/network_status.png" width="600">

### WiFi Config
<img src="https://github.com/fairecasoimeme/TIC-DIN-MODBUS/blob/master/Doc/images/WiFi_config.png" width="600">

### ModBus Status
<img src="https://github.com/fairecasoimeme/TIC-DIN-MODBUS/blob/master/Doc/images/modbus_status.png" width="600">

### ModBus Config
<img src="https://github.com/fairecasoimeme/TIC-DIN-MODBUS/blob/master/Doc/images/modbus_config.png" width="600">

### Modbus Specific mapping
<img src="https://github.com/fairecasoimeme/TIC-DIN-MODBUS/blob/master/Doc/images/specific_mapping.png" width="600">

## Changelog

### Version v1.0
* Initial version
