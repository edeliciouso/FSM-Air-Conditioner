<<<<<<< HEAD
main:
	gcc -o mylib.o -c mylib/mylib.c
	gcc -o main.exe main.c mylib.o
	./main.exe

run:
	./main.exe
	
clean:
	rm -rf *.out
=======
main:
	gcc -o mylib.o -c mylib/mylib.c
	gcc -o main.exe main.c mylib.o
	./main.exe

run:
	./main.exe
	
clean:
	rm -rf *.out
>>>>>>> 7881863747079c689b3f675ae5958986e4e8f591
	rm -rf *.o