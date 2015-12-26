#include <iostream>
using namespace std;
template<typename T,int size=4>class Stack {
public:
	Stack() {
		count = 0;
	}
	bool isfull();
	bool isempty();
	void push(T v);
	T pop();
private:
	T stack[size];
	int count;
};
class StackException : public exception {
private:
	const char* message;
public:
	StackException(const char*message):message(message) {}
	const char* what() const noexcept {
		return message;
	}
};
int main(void) {
	Stack<int,3> mystack;
	cout << "Empty: " << mystack.isempty() << ", Full " << mystack.isfull() << endl;
	try {
		for (int i = 1; i <= 4; ++i) {
			mystack.push(i);
			cout << "Empty: " << mystack.isempty() << ", Full " << mystack.isfull() << endl;
		}
	} catch (StackException&se) {
		cerr << se.what() << endl;
	}
	try {
		while (true) {
			cout << "Pop " << mystack.pop() << endl;
			cout << "Empty: " << mystack.isempty() << ", Full " << mystack.isfull() << endl;
		}
	} catch (StackException&se) {
		cerr << se.what() << endl;
	}
}
template<typename T, int size>
bool Stack<T, size>::isfull() {
	return count == size;
}
template<typename T, int size>
bool Stack<T, size>::isempty() {
	return count == 0;
}
template<typename T, int size>
void Stack<T, size>::push(T v) {
	if (!isfull())
		stack[count++] = v;
	else
		throw StackException("Stack is full");
}
template<typename T, int size>
T Stack<T, size>::pop() {
	if (!isempty())
		return stack[--count];
	else
		throw StackException("Stack is empty");
}