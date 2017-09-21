CPP=g++
FLAGS= -std=c++11 -g

all: main ejercicio1 ejercicio2



main: main.cpp graph.o
	$(CPP) $(FLAGS) -o $@ $< graph.o

ejercicio1: ejercicio1.cpp solver.o graph.o
	$(CPP) $(FLAGS) -o $@ $< solver.o graph.o

ejercicio2: ejercicio2.cpp graph.o
	$(CPP) $(FLAGS) -o $@ $< graph.o

%.o: %.cpp
	$(CPP) $(FLAGS) -c -o $@ $<

clean:
	rm -f *.o
	rm main
	rm ejercicio1
	rm ejercicio2