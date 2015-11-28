#include "stack.hpp"
#include <stdlib.h>
#include <iostream>
/*
* Konstruktor mit Angabe der Anzahl an ints.
*/Stack::Stack(int size=10):size(size) {
	//std::cout << "Ctor: I am allocating space for " << size << " integers\n";
	data = (int*)malloc(sizeof(int)*size);
}
/*
* Standardkonstruktor
*/Stack::Stack(void) {
	//std::cout << "Ctor: I am allocating space for 10 integers\n";
	size = 10;
	data = (int*)malloc(sizeof(int)*10);
}
/*
* Kopierkonstruktor
*/Stack::Stack(const Stack& other) {
	//std::cout << "Cctor called\n";
	size = other.size;
	data = (int*)malloc(sizeof(int)*size);
	for (int c = 0; c < other.count;c++) {
		push(other.data[c]);
	}
}
/*
* Bewegungskonstruktor
*/Stack::Stack(Stack&& other) {
	//std::cout << "Mctor called\n";
	size = other.size;
	count = other.count;
	data = other.data;
	other.size = 0;
	other.count = 0;
	other.data = nullptr;
}
/*
* Destruktor
*/Stack::~Stack() {
	//std::cout<<"Dtor: I am deallocating a stack of "<<size<<" integers filled with "<<count<<" values\n";
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
/*
* Setzt den übergebenen Wert auf den Stack, wenn noch Platz da ist.
*/void Stack::push(int i) {
	if (!isFull()) {
		data[count++] = i;
	} else {
		std::cout << "The stack is full\n";
	}
}
/*
* Gibt den zuletzt hinzugefügten Wert zurück, wenn es keinen gibt, wird 0 zurückgegeben.
*/int Stack::pop(void) {
	if (!isEmpty()) {
		return data[--count];
	} else {
		std::cout << "The stack is empty\n";
		return 0;
	}
}
/*
* Zeigt den aktuellen Inhalt des Stacks.
*/void Stack::show(void) {
	for (int i = 0; i < count;i++) {
		std::cout << data[i] << " ";
	}
	std::cout << std::endl;
}
/*
* Kopiert den anderen Stack in diesen.
*/Stack& Stack::operator=(const Stack& other) {
	//std::cout << "Cop= called\n";
	if (this != &other) {
		free(data);
		size = other.size;
		count = 0;
		data = (int*)malloc(sizeof(int)*size);
		for (int c = 0; c < other.count;c++) {
			push(other.data[c]);
		}
	}
	return *this;
}
/*
* Bewegt den Inhalt des anderen Stack in diesen.
*/Stack& Stack::operator=(Stack&& other) {
	//std::cout<<"Mop= called\n";
	if(this!=&other) {
		free(data);
		size = other.size;
		count = other.count;
		data = other.data;
		other.size = 0;
		other.count = 0;
		other.data = nullptr;
	}
	return *this;
}