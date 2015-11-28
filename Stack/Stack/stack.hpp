#pragma once
class Stack {
private:
	int size=0;
	int count=0;
	// In diesem Fall ist int* identisch mit int[].
	int *data=nullptr;
public:
	//Konstrkutoren
	explicit Stack(int);
	Stack(void);
	Stack(const Stack& other);
	Stack(Stack&&);
	//Destruktor
	virtual ~Stack();
	//Methoden
	bool isFull();
	bool isEmpty();
	void push(int);
	int pop(void);
	void show(void);
	//Operatoren
	Stack& operator=(const Stack&);
	Stack& operator=(Stack&&);
};