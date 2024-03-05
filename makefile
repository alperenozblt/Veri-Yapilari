all: build debug run


build:
	
	g++ -I ./include/ -o ./lib/Console.o -c ./src/Console.cpp
	g++ -I ./include/ -o ./lib/ReadAndWrite.o -c ./src/ReadAndWrite.cpp
	g++ -I ./include/ -o ./lib/SatirListesi.o -c ./src/SatirListesi.cpp
	g++ -I ./include/ -o ./lib/SatirListesiNode.o -c ./src/SatirListesiNode.cpp
	g++ -I ./include/ -o ./lib/YoneticiListesi.o -c ./src/YoneticiListesi.cpp
	g++ -I ./include/ -o ./lib/YoneticiNode.o -c ./src/YoneticiNode.cpp

debug:
	g++ -I ./include/ -o ./bin/main ./lib/Console.o  ./lib/ReadAndWrite.o ./lib/SatirListesi.o ./lib/SatirListesiNode.o ./lib/YoneticiListesi.o  ./lib/YoneticiNode.o   ./src/main.cpp

run:
	./bin/main