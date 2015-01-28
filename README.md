Chapat
======
#Introduction
Chapat(Chapal Application of Telecommunication),is a GapApp application server  
This project written completely by pure C and BSD sockets under linux mint and gcc  
In this project we using kernel-coding style from Linus Torvalds and using some
script from kernel to validate our code against that.  
This project also worked on Darwin 14.0.0

Finally our sever, client model created as follow:  
First GapApp must connect to DB connected server and get it's user UUID and then
connect to connection server for telecominucation with other users.  
For more information see doc/protocol.txt

#Contribution
If you have bug or idea about this project send me an [email](mailto:parham.alvani@gmail.com)  
Our coding style based on kernel standard.

#Dependencies
1. [GLib 2.42.1](https://developer.gnome.org/glib/2.42/)

#Installation
Going to src folder and execute following command

	$ make

