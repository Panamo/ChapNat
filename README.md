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

#Contribution
If you have bug or idea about this project send me an [email](mailto:parham.alvani@gmail.com)  
Our coding style based on kernel standard.

#Dependencies
1. [GLib 2.42.1](https://developer.gnome.org/glib/2.42/)
2. [LibPQ 1.9.4](http://www.postgresql.org/docs/9.4/static/index.html)
3. [LibSSH 2.1]()

#Installation
Going to src folder and execute following command

	$ make

