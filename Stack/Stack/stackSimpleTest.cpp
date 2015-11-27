#include <iostream>
#include "stack.hpp"
int main() {
	std::cout << std::endl;
	std::cout << "Creating first stack" << std::endl;
	Stack s1;         // Ctor: I am allocating space for 10 integers
	std::cout << "Creating a second stack" << std::endl;
	Stack s2(15);     // Ctor: I am allocating space for 15 integers
	std::cout << "\nChecking if the second stack is full or empty" << std::endl;
	if (s2.isFull()) {
		std::cout << "Is full\n" << std::endl;
	}
	if (s2.isEmpty()) {
		std::cout << "Is empty\n" << std::endl;
	}   // Is empty
	std::cout << "Filling the second stack" << std::endl;
	for (int i = 0; i<15; i++) {
		s2.push(2 * i);
	}
	s2.show();  // 0 2 4 6 8 10 12 14 16 18 20 22 24 26 28
	if (s2.isFull()) {
		std::cout << "Is full\n" << std::endl;
	}
	if (s2.isEmpty()) {
		std::cout << "Is empty\n" << std::endl;
	} // Is full
	std::cout << "Releasing values: ";
	while (!s2.isEmpty()) {
		std::cout << s2.pop() << " ";
	} // Releasing values: 28 26 24 22 20 18 16 14 12 10 8 6 4 2 0
	std::cout << std::endl;
	std::cout << "Creating a third stack" << std::endl;
	Stack s3(s1);   //Cctor called
	std::cout << "Checking the contents" << std::endl;
	std::cout << "s1: ";
	s1.show(); // 0 2 4 6 8 10 12 14 16 18
	std::cout << "s3: ";
	s3.show(); // 0 2 4 6 8 10 12 14 16 18
	std::cout << "They should be identical!\n" << std::endl;
	s1.pop();
	s1.push(42);
	s3 = s1;    //Cop= called
	std::cout << "Checking the contents" << std::endl;
	std::cout << "s1: ";
	s1.show(); // 0 2 4 6 8 10 12 14 42
	std::cout << "s3: ";
	s3.show(); // 0 2 4 6 8 10 12 14 42
	std::cout << "They should be identical!\n" << std::endl;
	std::cout << "Trying to move memory. (this is hard!)" << std::endl;
	// If you are not able to compile, maybe your cmake is missing a "-std=c++11"
	std::cout << "Before swaping the memory" << std::endl;
	std::cout << "s2: ";
	s2.show();  //s2:
	std::cout << "s3: ";
	s3.show();  //s3: 0 2 4 6 8 10 12 14 42
	std::swap(s3, s2);
	std::cout << "After swaping the memory" << std::endl;
	std::cout << "s2: ";
	s2.show();  //s2: 0 2 4 6 8 10 12 14 42
	std::cout << "s3: ";
	s3.show();  //s3:
	std::cout << std::endl;
	s3 = std::move(s2);
	std::cout << "s2: ";
	s2.show();  //s2: 0 2 4 6 8 10 12 14 42
	std::cout << "s3: ";
	s3.show();  //s3:
	std::cout << std::endl;
	std::cout << "Leaving the program" << std::endl;
}