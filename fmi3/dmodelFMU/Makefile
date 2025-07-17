CC=gcc
CFLAGS=-I.

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)
all:
	gcc -fPIC -Wall -c fmu.c -lpthread
	gcc -fPIC -Wall -c skeleton.c -lpthread
	gcc -fPIC -Wall -c adapted_C/DiscreteGrippingArm.c -lpthread -w
	gcc -shared -o DiscreteGrippingArm.so DiscreteGrippingArm.o skeleton.o fmu.o -lpthread
	rm -rf sources
	rm -rf binaries
	mkdir sources
	mkdir  binaries
	mkdir binaries/x86_64-linux
	cp fmu.h sources
	cp fmu.c sources
	cp skeleton.c sources
	cp -r adapted_C sources
	cp -r fmi3 sources
	mv DiscreteGrippingArm.so binaries/x86_64-linux/
	
	zip -r dmodelFMU.fmu modelDescription.xml binaries/ resources/ sources/
	rm -rf sources
	rm -rf binaries
	
clean:
	rm -rf  DiscreteGrippingArm.o fmu.o skeleton.o
