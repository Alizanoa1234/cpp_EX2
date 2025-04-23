Main:
	g++ -std=c++17 -Iinclude src/SquareMat.cpp main/main.cpp -o main_exec

test:
	g++ -std=c++17 -Iinclude src/SquareMat.cpp tests/test_SquareMat.cpp -o test_exec

valgrind:
	valgrind --leak-check=full ./main_exec

clean:
	rm -f *.o main_exec test_exec
