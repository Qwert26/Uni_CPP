#include "stack.hpp"
#include <stdlib.h>
#include <iostream>
Stack::Stack(int size=10):size(size) {
	std::cout << "Ctor: I am allocating space for " << size << " integers\n";
	data = (int*)malloc(sizeof(int)*size);
}
Stack::Stack(void) {
	size = 10;
	std::cout << "Ctor: I am allocating space for 10 integers\n";
	data = (int*)malloc(sizeof(int)*10);
}
Stack::Stack(const Stack & other) {
	size = other.size;
	data = (int*)malloc(sizeof(int)*size);
	for (int c = 0; c < other.count;c++) {
		push(other.data[c]);
	}
	std::cout << "Cctor called\n";
}
Stack::~Stack() {
	std::cout<<"Dtor: I am deallocating a stack of "<<size<<" integers filled with "<<count<<" values\n";
	free(data);
	data = NULL;
	size = count = 0;
}
bool Stack::isFull() {
	return size==count;
}
bool Stack::isEmpty() {
	return count==0;
}
void Stack::push(int i) {
	if (!isFull()) {
		data[count++] = i;
	} else {
		std::cout << "The stack is full\n";
	}
}
int Stack::pop(void) {
	if (!isEmpty()) {
		return data[--count];
	} else {
		std::cout << "The stack is empty\n";
		return 0;
	}
}
void Stack::show(void) {
	for (int i = 0; i < size;i++) {
		std::cout << data[i] << " ";
	}
	std::cout << std::endl;
}
Stack& Stack::operator=(const Stack& other) {
	std::cout << "Cop= called\n";
	if (this != &other) {
		free(data);
		size = other.size;
		data = (int*)malloc(sizeof(int)*size);
		for (int c = 0; c < other.count;c++) {
			push(other.data[c]);
		}
	}
	return *this;
}