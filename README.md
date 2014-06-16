ShopBot-API
===========

## Introduction
This github repository contains sources and tools about the new FabMo APIs and the new system design.

## Architecture of the new system
  ShopBot wants to bring open-source software and platform to its devices.  
  The process for controlling CNC tools consist of streaming to the tool each steps of the motors from a computer.  
      
  **Time is coming to change it.**  
    
  The new system consists of an embedded Single-Board Microcontroller and a Single-Board Computer on the tool, giving more flexibility from the client side.  
  
  A first draft of the new architecture can be found [here](schema/Global system architecture.pdf).
  
## Hardware
* SBM : Arduino DUE running [G2 software](https://github.com/synthetos/g2)
* SBC : Beaglebone Black running ArchLinux (,Raspberry PI or whatever)
 * support ethernet over usb
 * Processor AM335x 1GHz ARM® Cortex-A8
 * 512MB DDR3 RAM
 * 4GB 8-bit eMMC on-board flash storage
* Wifi-dongle : Gmyle wireless 11n USB Adapter N
  * based on RTL8188CUS chip
  * use 8192CU drivers
  * support wifi-direct and concurrence mode.


## Software
 * G2 [G2 software](https://github.com/synthetos/g2)
 * FabMo SBC API - *still in developement* - provide a restful API to communicate with the G2 system, and do basic file management, streaming, conversion, state & config report and file execution - powered by Node.js
 * FabMo platform - *not develloped yet* - provide a tool configurator, an apps manager & downloader, a supervision tool and more to come - powered by Node.js
 * FabMo Link API - first Windows version released - powered by Node.js
 * [OPTIONAL] [FabMo Javascript Library](fabmo-1.0.3.js) provide a simple way to communicate with the system through your web app.
{TO COMPLETE}


## References

[Documentation of the Link API](http://docs.shopbotlocalapi.apiary.io/)
[Documentation of the SBC API](http://docs.shopbot.apiary.io/)


[ShopBot Tools Devellopement Github](https://github.com/ShopBotTools)  
[G2 Devellopement Github](https://github.com/synthetos/g2)  
[ShopBot Tools Website](http://shopbottoolss.com)  
[beaglebone official website](http://beagleboard.org/)  
[Arduino Due official website](http://arduino.cc/en/Main/arduinoBoardDue)  
