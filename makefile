build : main.o
	g++ -o out/main.out main.o
main.o : main.cpp
clean :
	rm out/main.o out/main.out