#include <iostream>
class MyClass {
public:
	MyClass() {
		std::cout << "---start---\n";
	}
	~MyClass() {
		std::cout << "---end---\n";
	}
};
static MyClass mc;
int main(void) {
	std::cout<<"Hello world!"<<std::endl;
	return 0;
}