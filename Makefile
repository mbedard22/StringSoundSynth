all: KSGuitarSim

KSGuitarSim: CircularBuffer.o StringSound.o KSGuitarSim.o
	g++ CircularBuffer.o StringSound.o KSGuitarSim.o -o KSGuitarSim -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
CircularBuffer.o: CircularBuffer.cpp CircularBuffer.h
	g++ -c CircularBuffer.cpp -Wall -Werror -pedantic

StringSound.o: StringSound.cpp StringSound.h
	g++ -c StringSound.cpp -Wall -Werror -pedantic

KSGuitarSim.o: KSGuitarSim.cpp 
	g++ -c KSGuitarSim.cpp -Wall -Werror -pedantic
clean:
	rm *.o KSGuitarSim
