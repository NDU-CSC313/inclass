#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
template<typename T>
class heap {
	int _size;
	std::vector<T> _data;
	void percolate_down();
	void percolate_up();
public:
	heap():_size(0),_data(1) {}
	void push(T);
    template<typename ...Ts> void emplace(Ts&& ...args);
	void pop();
	const T top();
	void print();
};
template<typename T> template<typename ...Ts> 

void heap<T> ::  emplace(Ts&& ...args) {
	//_data.emplace_back(std::forward<Ts>(args)...);
	_data.emplace_back(args...);
}
template<typename T>
void heap<T>::pop() {
	std::swap(_data[1], _data[_size]);
	_data.pop_back();
	_size--;
	percolate_down();
}

template<typename T>
const T heap<T>::top() {
	return _data[1];
}
template<typename T>
void heap<T>::push(T v) {
	_data.push_back(v);
	_size++;
	percolate_up();
}
template<typename T>
void heap<T>::percolate_up() {
	int pos = _size;
	while (pos>1 && _data[pos] < _data[pos / 2]) {
		std::swap(_data[pos], _data[pos / 2]);
		pos = pos / 2;
	}
}
template<typename T>
void heap<T>::percolate_down() {
	int pos = 1;
	while (2*pos <= _size ) {
		int idx = 2*pos;
		if (idx + 1 <= _size)idx = _data[idx] < _data[idx+ 1] ? idx : idx + 1;
		if (_data[pos] > _data[idx]) {
			std::swap(_data[pos], _data[idx]);
			pos = idx;
		}
		else break;
	}

}
template<typename T>
void heap<T>::print() {
	for (decltype(auto) x : _data)
		std::cout << x << "  ";
	std::cout << std::endl;
}
