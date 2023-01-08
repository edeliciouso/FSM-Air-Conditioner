main:
	gcc -o mylib.o -c mylib/mylib.c
	gcc -o main.exe main.c mylib.o
	./main.exe

run:
	./main.exe
	
clean:
	rm -rf *.out
	rm -rf *.o