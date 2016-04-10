# In The Name Of God
# ========================================
# [] File Name : Makefile
#
# [] Creation Date : 10-04-2016
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================

all: init users build
# Database initiation
init:
	sudo -u postgres psql -f init.sql
# User table creation
users: init
	psql -U chapnat -W -d chapnat -h 127.0.0.1 -f init-users.sql
# Database populating
buid: init users
	sudo -u postgres psql -d chapnat -h 127.0.0.1 -f build.sql
# Database reseting :)
clean:
	sudo -u postgres psql -f reset.sql
