#include <map>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
int main() {
	//Typendefinition f�r den Inhalt.
	typedef vector<int> lines;
	//Die Map mit den Werten.
	map<string, lines> data;
	int line = 1;
	string input;
	while (cin >> input) {
		//Wenn ein einzelner Punkt, gehe aus der Schleife raus.
		if (input.compare(".") == 0) {
			break;
		} else {
			//Finde den Eintrag, falls vorhanden
			map<string,lines>::iterator keyPos = data.find(input);
			//Wenn da, tu die n�chste Zeile rein:
			if (keyPos != data.end()) {
				(*keyPos).second.push_back(line);
			}
			//Wenn nicht, erzeuge einen neuen vector<int>, tue die Zeile rein und dann den vector<int> mit dem kopierten string als Schl�ssel in die map<string,vector<int>>:
			else {
				lines first;
				string copy = input;
				first.push_back(line);
				data.emplace(copy,first);
			}
			//Und erh�he am Ende den Zeilenz�hler.
			++line;
		}
	}
	while (cin >> input) {
		//Wenn ein einzelner Punkt, gehe aus der Schleife raus.
		if (input.compare(".") == 0) {
			break;
		} else {
			//Finde den Eintrag, falls vorhanden
			map<string, lines>::iterator keyPos = data.find(input);
			//Wenn da, gebe den vector<int> aus:
			if (keyPos != data.end()) {
				lines &content = (*keyPos).second;
				//Wer braucht schon std::for_each?
				for each (int l in content) {
					cout << l << " ";
				}
				cout << endl;
			}
			//Wenn nicht gebe die Fehlermeldung raus:
			else {
				cout << "Not found" << endl;
			}
		}
	}
	return 0;
}