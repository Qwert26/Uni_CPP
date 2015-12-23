#include <iostream>
#include <string>
#include <cctype>
using namespace std;
//Das ist eine abstrakte Klasse, es gibt von ihr keine Objekte!
class StringPrinter {
public:
	virtual ~StringPrinter() {}
	virtual void doPrint(string&s) = 0;
	//Macht die Konvertierung vom C-string zum C++-string und ruft dann doPrint auf.
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
//Abstrakte Superklasse für konkrete Dekoratoren.
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
	virtual void doPrint(string&s) = 0;
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
		//Mache weitere Sachen
		stringComponent->doPrint(s);
	}
};
//Konvertiert alle Buchstaben und Zahlen zu Leerzeichen.
class StringAlphaNum :public StringDecorator {
public:
	StringAlphaNum(StringPrinter*component):StringDecorator(component) {}
	virtual void doPrint(string&s) {
		size_t length = s.length();
		for (size_t index = 0; index < length;++index) {
			//Wenn Zahl oder Buchstabe ersetze mit Leerzeichen.
			if (isalnum(s[index])) {
				s[index] = ' ';
			}
		}
		//Mache weitere Sachen.
		stringComponent->doPrint(s);
	}
};
//Komprimiert den String.
class StringCompress :public StringDecorator {
public:
	StringCompress(StringPrinter*component):StringDecorator(component) {}
	virtual void doPrint(string&s) {
		//Während des Durchlaufs wird sich die Länge ändern!
		for (size_t index = 0; index < s.length()-1; ++index) {
			//Wenn das aktuelle und das nächste Zeichen ein Leerzeichen ist, dann lösche das aktuelle und reduziere den index um 1.
			if (isspace(s[index])&&isspace(s[index+1])) {
				s.erase(index, 1);
				--index;
			}
		}
		//Mache weitere Sachen
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