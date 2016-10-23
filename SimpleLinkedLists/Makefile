test : SimpleLinkedList.o
	g++ SimpleLinkedList.o Main.cpp -o test

debug : SimpleLinkedList.o
	g++ -g SimpleLinkedList.o Main.cpp -o test

SimpleLinkedList.o:
	g++ -c SimpleLinkedList.cpp

clean:
	rm -f *.o test
