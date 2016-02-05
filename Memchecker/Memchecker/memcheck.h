#pragma once
#ifndef _MEMCHECK_HPP_
#define _MEMCHECK_HPP_

#define DEBUG

#ifdef DEBUG
#include <iostream>
#endif
#include <cstdlib>

// Prototypes for memcheck.cpp
void memchecker_checknew(void *ptr, char const *file, int line, bool is_array);
void memchecker_checkdelete(void *ptr, bool is_array);
void memchecker_print_allocated(void);



// overloaded new/delete operators - Do not change these

inline void* operator new(size_t size, char const *file, int line){
	void *ptr = malloc(size);
	#ifdef DEBUG
	std::cout << "alloc " << ptr << std::endl;
	#endif
	memchecker_checknew(ptr, file, line, false);
	return ptr;
}

inline void* operator new[](size_t size, char const *file, int line) {
	void *ptr = malloc(size);
	#ifdef DEBUG
	std::cout << "alloc[] " << ptr << std::endl;
	#endif
	memchecker_checknew(ptr, file, line, true);
	return ptr;
}

inline void operator delete(void *ptr) {
	#ifdef DEBUG
	std::cout << "free " << ptr << std::endl;
	#endif
	memchecker_checkdelete(ptr, false);
	free(ptr);
}

inline void operator delete[](void *ptr) {
	#ifdef DEBUG
	std::cout << "free[] " << ptr << std::endl;
	#endif
	memchecker_checkdelete(ptr, true);
	free(ptr);
}

// redefinition of new to add the file name and line

#define MEMCHECK_NEW new(__FILE__, __LINE__)
#define new MEMCHECK_NEW

#endif
