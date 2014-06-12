ShopBot-API
===========

## Introduction
This github repository contains sources and tools about the new Shopbot's API and the new system design.

## Architecture of the new system
  ShopBot wants to bring open-source software and platform to its devices.  
  The process for controlling CNC tools consist of streaming to the tool each steps of the motors from a computer.  
      
  **Time is coming to change it.**  
    
  The new system consists of an embedded Single-Board Microcontroller and a Single-Board Computer on the tool, giving more flexibility from the client side.  
  
  A first draft of the new architecture can be found [here](schema/Global system architecture.pdf).
  
## Hardware
* SBM : Arduino DUE running [G2 software](https://github.com/synthetos/g2)
* SBC : Beaglebone Black running ArchLinux
 * support ethernet over usb
 * Processor AM335x 1GHz ARM® Cortex-A8
 * 512MB DDR3 RAM
 * 4GB 8-bit eMMC on-board flash storage
* Wifi-dongle : Gmyle wireless 11n USB Adapter N
  * based on RTL8188CUS chip
  * use 8192CU drivers
  * support wifi-direct and concurrence mode.


## Software
{TO COMPLETE}


## References
[ShopBot Tools Devellopement Github](https://github.com/ShopBotTools)  
[G2 Devellopement Github](https://github.com/synthetos/g2)  
[ShopBot Tools Website](http://shopbottoolss.com)  
[beaglebone official website](http://beagleboard.org/)  
[Arduino Due official website](http://arduino.cc/en/Main/arduinoBoardDue)  
