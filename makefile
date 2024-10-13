all:
	g++ -o encoder main.cpp hash.cpp
	./encoder < inputs/mit_a.txt
	./encoder < inputs/common500.txt
	./encoder < inputs/bertuncased.txt 
