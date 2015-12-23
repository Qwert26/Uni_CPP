#include <iostream>
#include <string>
#include <cctype>
using namespace std;
//Das ist eine abstrakte Klasse, es gibt von ihr keine Objekte!
class StringPrinter {
public:
	virtual ~StringPrinter() {}
	virtual void doPrint(string&s) = 0;
	void print(const char*s) {
		string news(s);
		doPrint(news);
	}
};
//Druckt einen String in einen Outputstream.
class StreamPrinter:public StringPrinter {
private:
	ostream&output;
public:
	StreamPrinter(ostream&os):output(os) {}
	virtual ~StreamPrinter() {}
	virtual void doPrint(string&s) {
		output<<'|'<<s<<'|';
	}
};
//Superklasse für konkrete Dekoratoren.
class StringDecorator:public StringPrinter {
protected:
	StringPrinter*stringComponent;
public:
	StringDecorator(StringPrinter*component) {
		stringComponent = component;
	}
	virtual ~StringDecorator() {
		//Ob das Sinn macht?
		//delete stringComponent;
	}
};
//Entfernt alle Leerzeichen vom Anfang und Ende eines strings.
class StringTrim:public StringDecorator {
public:
	StringTrim(StringPrinter*component):StringDecorator(component) {}
	virtual void doPrint(string&s) {
		//So lange der letzte Buchstabe ein Leerzeichen ist, lösche ihn.
		while (isspace(s.back())) {
			s.pop_back();
		}
		//So lange der erste Buchstabe ein Leerzeichen ist, lösche ihn.
		while (isspace(s.front())) {
			s.erase(0,1);
		}
		stringComponent->doPrint(s);
	}
};
//Konvertiert alle Buchstaben und Zahlen zu Leerzeichen.
class StringAlphaNum :public StringDecorator {
public:
	StringAlphaNum(StringPrinter*component):StringDecorator(component) {}
	virtual void doPrint(string&s) {
		size_t length = s.length();
		for (size_t index = 0; index < length; index++) {
			//Wenn Zahl oder Buchstabe ersetze mit Leerzeichen.
			if (isalnum(s[index])) {
				s[index] = ' ';
			}
		}
		stringComponent->doPrint(s);
	}
};
//Komprimiert den String.
class StringCompress :public StringDecorator {
public:
	StringCompress(StringPrinter*component):StringDecorator(component) {}
	virtual void doPrint(string&s) {

		stringComponent->doPrint(s);
	}
};
int main(void) {
	StringPrinter *normal = new StreamPrinter(cout);
	StringPrinter *trimmer = new StringTrim(new StreamPrinter(cout));
	StringPrinter *alphanum = new StringAlphaNum(new StringCompress(new StreamPrinter(cout)));
	StringPrinter *all = new StringAlphaNum(new StringTrim(new StringCompress(new StreamPrinter(cout))));
	normal->print("  Hello, world!  ");
	cout << endl;
	trimmer->print("  Hello, world!  ");
	cout << endl;
	alphanum->print("  Hello, world!  ");
	cout << endl;
	all->print("  Hello, world!  ");
	cout << endl;
	alphanum->print("C++ is great!");
	cout << endl;
	all->print("C++ is great!");
	cout << endl;
}