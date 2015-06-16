### Introduction: ###
The goal of this project is to add IPv6 support to u-boot using uip stack and get it working on Embest SBC9261-I (clone of Ronetix PM9261 Starter Kit). In this project, u-boot serves as a dual stack (IPv4/IPv6) bootloader using uip for IPv6 functionality and the in built stack for IPv4 functionality.

The code is pretty modular and hence it should be easily portable to any other target platform.

Quickstart guide: http://code.google.com/p/sbc9261-uboot-uip-ipv6/wiki/Quickstart

![http://srinij.files.wordpress.com/2011/01/contact2.jpg](http://srinij.files.wordpress.com/2011/01/contact2.jpg)

<a href='Hidden comment: 
Email: _srinivasan d0t jayarajan at gmail d0t com_
http://srinij.files.wordpress.com/2011/01/contact.jpg
'></a>
### Following works as of now: ###
  1. ping an IPv6 host from u-boot
  1. tftp image download from an IPv6 enabled TFTP server
### Plan to support: ###
  1. IPv6 auto configuration
### Credits: ###
This project uses code from the following projects.
  1. ethersex  @http://ethersex.de/index.php/Ethersex/en
  1. uIP stack @http://www.sics.se/~adam/uip/index.php/Main_Page
### Quickstart video and demo: ###
<a href='http://www.youtube.com/watch?feature=player_embedded&v=bk7lcbredWg' target='_blank'><img src='http://img.youtube.com/vi/bk7lcbredWg/0.jpg' width='800' height=600 /></a>
