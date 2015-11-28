#pragma once
class Stack {
private:
	//Maximale Anzahl der ints im Stack.
	int size=0;
	//Aktuelle Anzahl der ints im Stack.
	int count=0;
	// In diesem Fall ist int* identisch mit int[].
	int *data=nullptr;
public:
	//Konstruktoren
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