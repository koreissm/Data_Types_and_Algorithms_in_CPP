all : linkedlist stack queue deque

linkedlist : SimpleLinkedList.cpp ./tests/tLinkedList.cpp
	g++ ./tests/tLinkedList.cpp SimpleLinkedList.cpp -o ./bin/linkedlist

stack : stack.cpp ./tests/tStack.cpp util.cpp
	g++ ./tests/tStack.cpp stack.cpp util.cpp -o ./bin/stack

queue : queue.cpp ./tests/tQueue.cpp
	g++ ./tests/tQueue.cpp queue.cpp -o ./bin/queue

deque : deque.cpp ./tests/tDeque.cpp
	g++ ./tests/tDeque.cpp deque.cpp -o ./bin/deque

clean:
	rm -fr *.o ./bin/*
