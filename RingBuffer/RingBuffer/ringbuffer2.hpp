#pragma once
template<typename T,int size> class RingBuffer {
private:
	T storage[size];
	T *start=storage,*end=storage;
public:
	virtual bool empty() {
		return start == end;
	}
	virtual bool full() {
		T* expectedEnd = start - 1;
		if (expectedEnd < storage) {
			expectedEnd += size;
		}
		return expectedEnd == end;
	}
	virtual void push_front(T value) {
		if (!full()) {
			*start = value;
			if (start == storage) {
				start += size;
			}
			--start;
		}
	}
	virtual void push_back(T value) {
		if (!full()) {
			*end = value;
			if (end == storage + size - 1) {
				end = storage-1;
			}
			++end;
		}
	}
	virtual T pop_front() {
		if (!empty()) {
			T ret = *start;
			++start;
			if (start == storage + size) {
				start = storage;
			}
			return ret;
		} else {
			throw std::range_error("pop_front on empty buffer");
		}
	}
	virtual T pop_back() {
		if (!empty()) {
			T ret = *end;
			--end;
			if (end < storage) {
				end += size;
			}
			return ret;
		} else {
			throw std::range_error("pop_back on empty buffer");
		}
	}
	virtual void print() {
		if (empty()) {
			std::cout << "Buffer is empty" << std::endl;
		} else {
			std::cout << "Content of Buffer: ";
			T *current = start;
			while (current != end) {
				std::cout << (*current) << '\t';
				current++;
				if (current == storage + size) {
					current = storage;
				}
			}
			std::cout << std::endl;
		}
	}
};