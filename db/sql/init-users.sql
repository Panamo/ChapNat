/*
 * In The Name Of God
 * ========================================
 * [] File Name : init-2.sql
 *
 * [] Creation Date : 10-01-2016
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2016 Parham Alvani.
*/
CREATE TABLE if NOT EXISTS users (
	s_id integer primary key CHECK (s_id > 0),
	username varchar(255) unique not null,
	password varchar(255) not null,
	name varchar(255) not null,
	family varchar(255) not null,
	hometown varchar(255),
	career varchar(255),
	birthday date
);
