build: ./src/main.cpp ./src/tokenizer.hpp ./src/tokenizer.cpp
	g++ -std=c++17 -g src/main.cpp src/tokenizer.cpp -o dist/main

execute: dist/main
	./dist/main

run: src/main.cpp build execute

debug: 
	gdb dist/main
	
	