#!/bin/bash
#
# In The Name Of God
# ========================================
# [] File Name : capture.bash
#
# [] Creation Date : 03-04-2015
#
# [] Last Modified : Thu 09 Apr 2015 08:45:03 PM IRDT
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================

tcpdump -i wlan0 -s 65535 -w $(date +"%F_%H:%m:%S").pcap
