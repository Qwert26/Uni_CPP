#include <iostream>
#define MAKEVAR(name,type)	type name;\
							/*Nutzt den ## Operator um den Funktionsnamen nach der Expansion zusammenzubauen.*/\
							void set_ ## name(type val) {name = val;}\
							type get_ ## name(void) {return name;}

MAKEVAR(weight,int)
MAKEVAR(price,float)
int main(void) {
	set_weight(100);
	set_price(1.25);
	std::cout << "Weight: " << get_weight() << ", Price: " << get_price() << std::endl;
}