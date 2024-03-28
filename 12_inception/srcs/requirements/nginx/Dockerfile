FROM	debian:buster
RUN	apt-get -y update

RUN	apt-get install -y nginx openssl

COPY	./conf/nginx.conf /etc/nginx/sites-enabled/nginx.conf

RUN	mkdir -p /var/www/html/wordpress

RUN	openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
	-out /etc/ssl/certs/nginx.crt \
	-keyout /etc/ssl/certs/nginx.key \
	-subj '/C=FR/ST=75/L=Paris/O=42/OU=acoinus/CN=acoinus.42.fr'

EXPOSE	443

CMD	["/usr/sbin/nginx", "-g", "daemon off;"]
