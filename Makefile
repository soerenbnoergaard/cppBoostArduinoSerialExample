all : main

main : main.cpp
	g++ -lboost_system -lpthread main.cpp -o main
