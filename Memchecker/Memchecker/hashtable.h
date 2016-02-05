#pragma once
// this is the code from the exercise sheet. use it where needed...
#define TABLESIZE_POW 5
#define TABLESIZE (1 << TABLESIZE_POW)

#include <utility> //std::pair
#include <iostream> //std::cout
template<typename keyT, typename T>class HashTable {
private:
	//Den Inhalt der HashTable
	std::pair<keyT,T> content[TABLESIZE];
	//Marker für benutzte Zellen
	bool used[TABLESIZE];
	/* hash function. Note that it combines hash_M() and hash() from the lecture,
	i.e. it already returns a value in the range 0..TABLESIZE-1 */
	unsigned int hash(const keyT &key) const {
		unsigned int shift = (32 - TABLESIZE_POW) / 2;
		return (hash_M(key) >> shift) & ((1 << TABLESIZE_POW) - 1);
	}
	/* Hash-Funktion. Diese hier wird für das vergleichen von Schlüsseln verwendet.*/
	unsigned int hash_M(const keyT &key) const {
		const unsigned int C = 2654435769u;  // std::round( phi*2^32 )
		return (C*(unsigned long)key);
	}
public:
	/*
	Fügt ein neues Schlüssel-Wert-Paar ein.
	Gibt true zurück, wenn es aufgenommen werden konnte, false, wenn nicht oder wenn die HashTable voll ist.
	*/
	bool insert(const keyT &key,const T &value) noexcept {
		//erwarteter Index
		unsigned int i = hash(key);
		const unsigned int lastTry = i;
		const unsigned int fullHash = hash_M(key);
		do {
			//Zelle bereits benutzt?
			if (used[i]) {
				//Hashcode gleich?
				if (fullHash == hash_M(content[i].first)) {
					return false;
				}
			} else {
				//Markiere Zelle
				used[i] = true;
				//Schreibe Inhalt
				content[i].first = key;
				content[i].second = value;
				return true;
			}
			i=(i+1)%TABLESIZE;
		} while (i != lastTry);
		//Wir sind jetzt einmal im Array rumgegangen...
		return false;
	}
	/*
	Gibt einen Pointer zu einem Wert zurück, wenn der entsprechende Schlüssel gefunden worden ist, ansonsten den null-Pointer.
	*/
	T* find(const keyT &key) noexcept {
		//erwarteter Index
		unsigned int i = hash(key);
		const unsigned int lastTry = i;
		const unsigned int fullHash = hash_M(key);
		do {
			//Ist die Zelle belegt?
			if (used[i]) {
				//Hashcodes gleich?
				if (fullHash == hash_M(content[i].first)) {
					return &(content[i].second);
				}
			}
			i = (i + 1) % TABLESIZE;
		} while (lastTry != i);
		//Wir sind jetzt einmal im Array rumgegangen...
		return nullptr;
	}
	/*
	Druckt den Inhalt der Hashtable aus.
	*/
	void print() {
		for (unsigned int i = 0; i < TABLESIZE; i++) {
			if (used[i]) {
				std::cout << content[i].first << "=" << content[i].second << std::endl;
			}
		}
	}
	/*
	Entfernt ein Schlüssel-Wert-Paar aus der HashTable
	*/
	bool remove(const keyT &key) noexcept {
		//erwarteter Index
		unsigned int i = hash(key);
		const unsigned int lastTry = i;
		const unsigned int fullHash = hash_M(key);
		do {
			//Ist die Zelle belegt?
			if (used[i]) {
				//Hashcodes gleich?
				if (fullHash == hash_M(content[i].first)) {
					//Markiere als frei. (Fake-delete)
					used[i] = false;
					return true;
				}
			}
			i = (i + 1) % TABLESIZE;
		} while (lastTry != i);
		//Wir sind jetzt einmal im Array rumgegangen...
		return false;
	}
};