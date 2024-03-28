#!/bin/bash

mkdir -p /var/run/php/;
touch /var/run/php/php7.3-fpm.pid;

wp core download --allow-root

wp config create --dbname=wordpress --dbuser=$LOGIN --dbpass=$PASSWORD --dbhost=mariadb --dbcharset="utf8mb4" --dbcollate="utf8mb4_unicode_ci" --force --allow-root

wp core install --url=$DOMAIN_NAME --title=inception --admin_user=$LOGIN --admin_password=$PASSWORD --admin_email=$EMAIL --skip-email --allow-root

wp user create $GUEST_LOGIN $GUEST_EMAIL --user_pass=$GUEST_PWD --allow-root

sed -i "s/;cgi.fix_pathinfo=1/cgi.fix_pathinfo=0/" /etc/php/7.3/fpm/php.ini;

exec "$@"
