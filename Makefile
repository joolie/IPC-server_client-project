#! /bin/bash

server : main.o init.o creatinfra.o prores.o invoprocl.o
	gcc -o server main.o init.o creatinfra.o prores.o invoprocl.o
main.o : main.c header.h declaration.h mydatatype.h 
	gcc -c main.c	
init.o : init.c header.h declaration.h mydatatype.h
	gcc -c init.c	
creatinfra.o : creatinfra.c header.h declaration.h mydatatype.h
	gcc -c creatinfra.c	
prores.o : prores.c header.h declaration.h mydatatype.h
	gcc -c prores.c	
invoprocl.o : invoprocl.c header.h declaration.h mydatatype.h
	gcc -c invoprocl.c	
