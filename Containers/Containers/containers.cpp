#include <vector>
#include <deque>
#include <list>
#include <utility> //std::pair
#include <iostream>
#include <algorithm> //std::remove_if
using namespace std;
/*
F�llt einen Container mit den Zahlen 2 bis 64 auf.
*/
template<typename Container>void fill(Container&con) {
	for (long in = 2; in <= 64; in += 2) {
		con.push_back(in);
	}
}
/*
Druckt einen kompletten Container aus.
*/
template<typename Container>void print(Container&con) {
	typename Container:: iterator start = con.begin();
	typename Container:: iterator end = con.end();
	for (;start!=end;++start) {
		cout << *start<<" ";
	}
	cout << endl;
}
/*
Findet die zwei Postionen, die vor und nach dem �bergebenen Wert sind. Im falle von 31 sollte das eine Zahl kleiner als diese sein und eine die gr��er oder gleich gro� ist.
*/
template<typename Container> pair<typename Container:: iterator,typename Container:: iterator> findPosition(Container&con,const long value) {
	typename Container:: iterator iter = con.begin();
	for (;*iter<value;++iter) {}
	if (iter == con.begin()) {
		return make_pair(iter, iter);
	} else {
		typename Container:: iterator next(iter);
		++next;
		return std::make_pair(iter, next);
	}
}
/*
Druckt die n�chsten drei Elemente eines Containers aus, inklusive dem Element, auf das der �bergebene Iterator zeigt.
*/
template<typename Container>void printNext3(Container&con,typename Container:: iterator iter) {
	for (char count = 0; count < 3 & iter != con.end(); count++,++iter) {
		cout << *iter << " ";
	}
	cout << endl;
}
bool isOdd(long l) {
	return (l & 1) == 1;
}
/*
Nutzt die Funktion isOdd(long) um s�mtliche ungerade Zahlen zu entfernen. Anschlie�end muss der Container noch auf sein neues Ende zugeschnitten werden.
*/
template<typename Container>void deleteOddFunctor(Container&con) {
	typename Container:: iterator newEnd=remove_if(con.begin(),con.end(),isOdd);
	con.erase(newEnd,con.end());
}
/*
Nutzt einen Lambda-Ausdruck um s�mtliche ungerade Zahlen zu entfernen.
Anschlie�end muss der Container noch auf sein neues Ende zugeschnitten werden.
Ansonsten w�rde der letzte Eintrag mehrfach erscheinen.
*/
template<typename Container>void deleteOddLambda(Container&con) {
	typename Container:: iterator newEnd = remove_if(con.begin(), con.end(),[](long l){return (l & 1) == 1;});
	con.erase(newEnd, con.end());
}
int main() {
	//Deklarationen
	vector<long> v;
	deque<long> d;
	list<long> l;

	//Auff�llen
	fill(v);
	fill(d);
	fill(l);

	//Ausdrucken
	print(v);
	print(d);
	print(l);

	//Iteratoren
	vector<long>::iterator vIter = v.begin();
	vIter += 2;
	//vIter ist ein Random-Access-Iterator
	deque<long>::iterator dIter = d.begin();
	dIter += 2;
	//dIter ist auch ein Random-Access-Iterator
	list<long>::iterator lIter = l.begin();
	lIter++;
	lIter++;
	//lIter ist nur ein Bidirektionaler Iterator

	//drittes Element ausdrucken
	cout << *vIter << endl;
	cout << *dIter << endl;
	cout << *lIter << endl;

	#if defined(FIX_A)

	//31 in vector einf�gen:
	pair<vector<long>::iterator, vector<long>::iterator> positionV = findPosition(v, 31);
	positionV.first--;
	positionV.second--;
	v.insert(positionV.second, 31);
	printNext3(v, positionV.first);

	//31 in deque einf�gen:
	pair<deque<long>::iterator, deque<long>::iterator> positionD = findPosition(d, 31);
	positionD.first--;
	positionD.first--;
	positionD.second--;
	d.insert(positionD.second, 31);
	printNext3(d, positionD.first);

	//31 in list einf�gen:
	pair<list<long>::iterator, list<long>::iterator> positionL = findPosition(l, 31);
	positionL.first--;
	positionL.second--;
	l.insert(positionL.second, 31);
	printNext3(l,positionL.first);

	#elif defined(FIX_B)

	//31 in vector einf�gen:
	pair<vector<long>::iterator, vector<long>::iterator> positionV = findPosition(v, 31);
	vector<long>::iterator posV=v.insert(positionV.second, 31);
	long value = *(--posV);
	v.erase(posV);
	v.insert(++posV, value);
	//Revalidierung des Iterators.
	printNext3(v,--positionV.first);

	//31 in deque einf�gen:
	pair<deque<long>::iterator, deque<long>::iterator> positionD = findPosition(d, 31);
	deque<long>::iterator posD=d.insert(positionD.second, 31);
	value = *(--posD);
	d.erase(posD);
	d.insert(++(++posD), value);
	//Revalidierung des Iterators.
	printNext3(d,--(--positionD.first));

	//31 in list einf�gen:
	pair<list<long>::iterator, list<long>::iterator> positionL = findPosition(l, 31);
	list<long>::iterator posL=l.insert(positionL.second, 31);
	value = *(--posL);
	l.erase(posL);
	l.insert(++(++posL), value);
	//Revalidierung des Iterators.
	printNext3(l,--positionL.first);

	#else

	//31 in vector einf�gen:
	pair<vector<long>::iterator,vector<long>::iterator> positionV = findPosition<vector<long>>(v, 31);
	v.insert(positionV.second,31);
	printNext3(v,positionV.first);

	//31 in deque einf�gen:
	pair<deque<long>::iterator,deque<long>::iterator> positionD = findPosition<deque<long>>(d, 31);
	d.insert(positionD.second, 31);
	printNext3(d,positionD.first);

	//31 in list einf�gen:
	pair<list<long>::iterator,list<long>::iterator> positionL = findPosition<list<long>>(l, 31);
	l.insert(positionL.second, 31);
	printNext3(l,positionL.first);

	#endif

	//Ausdrucken
	print(v);
	print(d);
	print(l);

	//Ungerade Zahlen entfernen
	deleteOddFunctor(v);
	deleteOddLambda(d);
	deleteOddFunctor(l);

	//Ausdrucken
	print(v);
	print(d);
	print(l);
}