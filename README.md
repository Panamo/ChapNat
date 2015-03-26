Chapat
======
#Introduction
Chapnat(Chapal Application of Telecommunication, The New One),
is a GapApp & GapNap application server  
This project written completely by pure C and BSD sockets
under ubuntu and gcc (please note that we use some other library)  
In this project we using kernel-coding style from Linus Torvalds and using some
script from kernel to validate our code against that.  
This project also worked on Darwin 14.1.0  

For more information of implementation see doc/protocol files.  

Chapnat  
  |  
  |  
  \ connection -> create communication links  
  |  
  |  
  \ db -> control users and group authentication  
  |  
  |  
  \ resolver -> find best route between chapnats  

#KamyLib
This is simple library for event dispatching using gnome C OO design.
we use this library in chapat db and connection. you can use it for
other projcets.  
This library named after our friend *Seyed Kamyar Seyed Ghasemi Pour*.  
library source code avaiable at /common.

##How KamyLib work
first we making chevents for our events with `chevent_new()` then add some unique data
to them with `chevent_register_data()` after that add all our events into chsession.
atfer all we can call `chsession_dispatch()` for event dispatching with following syntax :
* session : chsession
* data : void * -> used for event distinguishing.
* message : chmessage
* user data : void * -> this data pass into event handler.

##Future of KamyLib
in the future following features is added into KamyLib
* mutlithreading support.
* asynchronous event dispatching with thread queue named chqueue.

#Contribution
If you have bug or idea about this project send me an [email](mailto:parham.alvani@gmail.com)  
Our coding style based on kernel standard.

#Dependencies
1. [GLib 2.42.1](https://developer.gnome.org/glib/2.42/)
2. [LibPQ 1.9.4](http://www.postgresql.org/docs/9.4/static/index.html)

#Installation
Going to src folder and execute following command

	$ make

