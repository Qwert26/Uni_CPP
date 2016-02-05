#include "memcheck.h"
#include "hashtable.h"
#include <iostream>
struct info {
	const char*file;
	int line;
	bool is_array;
};
std::ostream& operator<<(std::ostream &output,const info &info) {
	output << info.file << ":" << info.line<<" allocated an ";
	if (info.is_array) {
		output << "array";
	} else {
		output << "object";
	}
	return output;
}
HashTable<void*,info>memTable;
/*

*/
void memchecker_checknew(void * ptr,char const * file,int line,bool is_array) {
	info in;
	in.file = file;
	in.line = line;
	in.is_array = is_array;
	if (!memTable.insert(ptr, in)) {
		//Wir konnten das Info-Struct nicht einfügen!
		std::cerr << "MemTable is full!" << std::endl;
	} else {
		#ifdef _DEBUG
		std::cout << ptr << "=" << in << std::endl;
		#endif
	}
}
/*

*/
void memchecker_checkdelete(void * ptr,bool is_array) {
	info*infoPtr = memTable.find(ptr);
	if (infoPtr == nullptr) {
		std::cerr << "Block is already free or it was never allocated in the first place!" << std::endl;
	} else {
		if (is_array == infoPtr->is_array) {
			memTable.remove(ptr);
		} else {
			std::cerr << "An ";
			if (is_array) {
				std::cerr << "array";
			} else {
				std::cerr << "object";
			}
			std::cerr << " has to be deleted but an ";
			if (infoPtr->is_array) {
				std::cerr << "array";
			} else {
				std::cerr << "object";
			}
			std::cerr << " was allocated before!" << std::endl;
		}
	}
}
/*

*/
void memchecker_print_allocated(void) {
	memTable.print();
}