#pragma once
class Stack {
private:
	int size=0;
	int count=0;
	int *data=nullptr;
public:
	explicit Stack(int);
	Stack(void);
	Stack(const Stack& other);
	virtual ~Stack();
	bool isFull();
	bool isEmpty();
	void push(int);
	int pop(void);
	void show(void);
	Stack& operator=(const Stack& other);
};