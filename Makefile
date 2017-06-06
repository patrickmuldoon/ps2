all: PhotoMagic

PhotoMagic: PhotoMagic.o LFSR.o
	g++ PhotoMagic.o LFSR.o -o PhotoMagic -lsfml-window -lsfml-graphics -lsfml-system

PhotoMagic.o: PhotoMagic.cpp
	g++ -c PhotoMagic.cpp -lsfml-window -lsfml-graphics -lsfml-system

LFSR.o: LFSR.cpp
	g++ -c LFSR.cpp -Wall -Werror -ansi -pedantic

clean:
	$(RM) LFSR.o PhotoMagic.o PhotoMagic