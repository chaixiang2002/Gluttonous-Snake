all:
	g++ -c Position.cc -o Position.o
	g++ -c window.cc -o window.o
	g++ -c tc_snake.cc -o tc_snake.o
	# g++ -c user_scanf.cc -o user_scanf.o
	g++ -c main.cc -o main.o
	g++ main.o  tc_snake.o window.o Position.o -o main.exe