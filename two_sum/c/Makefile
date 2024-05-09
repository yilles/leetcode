build:
	gcc -c submit1.c submit2.c

test: build
	gcc submit1.o test.c -o test1
	gcc submit2.o test.c -o test2
	echo "Test 1"
	./test1
	echo "Test 2"
	./test2

clean:
	rm *o test1 test2
