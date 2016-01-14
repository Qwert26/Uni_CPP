#pragma once
template<typename T,int size> class RingBuffer {
private:
	T storage[size];
	int count=0,indexOfFirst=0;
public:
	virtual bool empty() {
		return count == 0;
	}
	virtual bool full() {
		return count == size;
	}
	virtual void print() {
		if (empty()) {
			std::cout << "Buffer is empty" << std::endl;
		} else {
			std::cout << "Content of Buffer: ";
			for (int offset=0;offset<count;++offset) {
				std::cout << storage[(indexOfFirst+offset)%size]<<'\t';
			}
			std::cout << std::endl;
		}
	}
	virtual void push_front(T value) {
		if (!full()) {
			if (--indexOfFirst < 0) {
				indexOfFirst += size;
			}
			storage[indexOfFirst] = value;
			++count;
		}
	}
	virtual void push_back(T value) {
		if (!full()) {
			storage[(indexOfFirst + count) % size] = value;
			++count;
		}
	}
	virtual T pop_front() {
		if (empty()) {
			throw std::range_error("pop_front on empty buffer");
		} else {
			T ret = storage[indexOfFirst];
			indexOfFirst = (indexOfFirst + 1) % size;
			--count;
			return ret;
		}
	}
	virtual T pop_back() {
		if (empty()) {
			throw std::range_error("pop_back on empty buffer");
		} else {
			T ret = storage[(indexOfFirst + count-1) % size];
			--count;
			return ret;
		}
	}
};