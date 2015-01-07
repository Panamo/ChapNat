Chapat
======
#Introduction
Chapat(Chapal Application of Telecommunication),is a GapApp application server  
This projcet written completely by pure C and BSD sockets under linux mint and gcc  
In this project we using kernel-coding style from Linus Torvalds and using some script from kernel to validate our code against that.

Finally our sever, client model created as follow:  

Chapat:  
       Java  
|-------------------|  
|DB connected server|  
|-------------------|  
Port: 13731  
  
      Pure C  
|-------------------|  
|connection server  |  
|-------------------|  
Port: 13732  
  
First GapApp must connect to DB connected server and get it's user UUID and then connect to connection server for telecominucation with other
users.

#Contribution
If you have bug or idea about this project send me an [email](mailto:parham.alvani@gmail.com)

#Installation
Going to src folder and execute following command

	$ make

