all:derle bagla calistir
derle:
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -c -I "./include" ./src/Liste.cpp -o ./lib/Liste.o
	g++ -c -I "./include" ./src/Gen.cpp -o ./lib/Gen.o
	g++ -c -I "./include" ./src/Genom.cpp -o ./lib/Genom.o
	g++ -c -I "./include" ./src/Kromozom.cpp -o ./lib/Kromozom.o
bagla:
	g++ ./lib/main.o ./lib/Liste.o ./lib/Gen.o ./lib/Genom.o ./lib/Kromozom.o -o ./bin/program
calistir:
	./bin/program