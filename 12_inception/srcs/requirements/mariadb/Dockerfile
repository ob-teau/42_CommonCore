FROM	debian:buster

RUN	apt-get -y update
RUN	apt-get -y install mariadb-server

EXPOSE	3306

COPY	./conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf
COPY	./tools /var/www

RUN	mkdir -p /run/mysqld
RUN	chown -R mysql:root /run/mysqld
RUN	chown -R mysql:mysql /var/lib/mysql

ENTRYPOINT	["bash", "var/www/mariadb_start.sh"]
CMD	["mysqld"]
