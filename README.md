# ChapNat [Chapal behind NAT Message Passing System]
=======
## Introduction
This project written completely by pure C and BSD sockets
under Ubuntu and gcc (please note that we use some other library).
In this project we using kernel-coding style from Linus Torvalds and using some
script from kernel to validate our code against that.
This project also worked on Darwin 14.1.0.

For more information of implementation see doc/protocol files.

```
Chapat
  |
  |
  |-> connection : create and store TCP communication links
  |
  |
  |-> db : control users and group authentication
  |
  |
  |-> resolver : find best route between chapat servers
```

## KamyLib
This is simple library for event dispatching using gnome C OO design.
we use this library in chapat db and connection. you can use it for
other projects.
This library named after our friend *Seyed Kamyar Seyed Ghasemi Pour*.
library source code available at /common.

### How KamyLib works
First we make chevents for our events with `chevent_new()` then add some unique data
to them with `chevent_register_data()` after that add all our events into chsession.
after all we can call `chsession_dispatch()` for event dispatching with
following syntax :
* session : chsession
* data : void * -> used for event distinguishing.
* message : chmessage
* user data : void * -> this data pass into event handler.

### Future of KamyLib
In the future following features will be added into KamyLib
* multi threading support.
* asynchronous event dispatching with thread safe queue named chqueue.


## Resolver
For resolving userID of a person and find server that containing his socket we use
chptr protocol. we design this protocol in transport layer on top of IP ! :-).
we do this just for **having fun** ! this protocol basically is a DHT and we use
controlled flooding with sequence number for implementing it.


## Contribution
If you have bug or idea about this project send me an [email](mailto:parham.alvani@gmail.com)  
Our coding style based on kernel standard.

## Dependencies
1. [GLib 2.42.1](https://developer.gnome.org/glib/2.42/)
2. [LibPQ 1.9.4](http://www.postgresql.org/docs/9.4/static/index.html)

## Installation
```bash
mkdir build; cd build
cmake ..
make
```
