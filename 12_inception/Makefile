NAME= inception
all:
	sudo mkdir -p /home/acoinus/data/wordpress
	sudo mkdir -p /home/acoinus/data/mariadb
	sudo docker-compose -f srcs/docker-compose.yml build --pull --no-cache
	sudo docker-compose -f srcs/docker-compose.yml up -d
#	sudo echo "127.0.0.1 acoinus.42.fr" >> /etc/hosts

up:
	sudo docker-compose -f srcs/docker-compose.yml up -d

stop:
	sudo docker-compose -f srcs/docker-compose.yml stop

start:
	sudo docker-compose -f srcs/docker-compose.yml start

restart:
	sudo docker-compose -f srcs/docker-compose.yml restart 

clean:
	sudo docker-compose -f srcs/docker-compose.yml stop
	sudo docker-compose -f srcs/docker-compose.yml down

prune:	clean
		sudo rm -rf /home/acoinus/data/*
		docker system prune -f -a

.PHONY: all stop clean prune iclean vclean
