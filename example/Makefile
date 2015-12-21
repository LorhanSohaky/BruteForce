all:BruteForce Main.exe testador.exe

BruteForce:../src/BruteForce.c ../src/BruteForce.h
	gcc -c ../src/BruteForce.c -I../src/

main.o:main.c ../src/BruteForce.h
	gcc -c main.c -I../src

Main.exe:main.o BruteForce.o
	gcc -Wall -o Main.exe main.o BruteForce.o

testador.exe:testador.o
	gcc -Wall -o testador.exe testador.o
testador.o:testador.c
	gcc -c testador.c

clean:
	rm -rf *.o
