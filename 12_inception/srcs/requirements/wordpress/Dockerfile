FROM	debian:buster

WORKDIR	/var/www/html/wordpress

RUN	apt-get -y update

RUN	apt-get -y install wget php7.3-fpm php7.3-common php-mysql mariadb-client

RUN	wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN	chmod +x wp-cli.phar
RUN	cp wp-cli.phar /usr/local/bin/wp

EXPOSE	9000

COPY	./conf/www.conf /etc/php/7.3/fpm/pool.d/www.conf
COPY	./tools /var/www/html
RUN	chmod +x /var/www/html/wordpress_start.sh

ENTRYPOINT	["bash", "/var/www/html/wordpress_start.sh"]
CMD		["/usr/sbin/php-fpm7.3", "--nodaemonize"]
