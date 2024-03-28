#!/bin/bash

if [ ! -d /var/lib/mysql/wordpress ]; then

	mysqld&

	until mysqladmin ping; do
		sleep 1
	done

	echo "create database if not exists wordpress;" | mysql -u root
	echo "create user if not exists '$LOGIN' identified by '$PASSWORD';" | mysql -u root
	echo "grant usage on wordpress.* TO '$LOGIN'@'%' identified by '$PASSWORD';" | mysql -u root
	echo "grant all privileges on wordpress.* TO '$LOGIN'@'%' with grant option;" | mysql -u root
	echo "flush privileges;" | mysql -u root
	echo "alter user 'root'@'localhost' identified by '$PASSWORD';" | mysql -u root

	killall mysqld

fi

exec "$@"
