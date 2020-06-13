#pragma once
#include <iostream>
#include <algorithm>

template<typename T>
class vector {
    int _size, _capacity;
    T* _data;
   
public:

    using  value_type= T;

    class iterator {
        T* p;
    public:
        iterator() :p(nullptr) {}
        iterator(T* q) :p(q) {}
        bool operator!=(iterator rhs) {
            return p != rhs.p;
        }
        iterator operator++() {
            p++;
            return *this;
        }
        iterator operator++(int d) {
            p++;
            return *this;
        }
        iterator operator--() {
            p--;
            return *this;
        }
        iterator operator--(int d) {
            p--;
            return *this;
        }
        iterator operator+(size_t off) {
            return iterator(p + off);
        }
        iterator operator-(size_t off) {
            return iterator(p - off);
        }
        int& operator*() {
            return *p;
        }
        T* operator->() {
            return p;
        }
        friend vector<T>;
    };
    vector() :_size(0), _capacity(0),_data(nullptr) {}
    vector(int c) :_size(c), _capacity(c),_data(nullptr) {
        //create space for and initialize c elements
        _data = new T[_capacity]{};
    }
    /// @brief Copy constructor
    /// @param rhs right hand size
    /// @return constructed object
    vector(const vector& rhs) {
        _size = rhs._size;
        _capacity = rhs._capacity;
        _data = new T[_capacity];
        for (int i = 0; i < _size; i++)
            _data[i] = rhs._data[i];

    }
    
    ~vector() {
        if (_data != nullptr)
            delete[] _data;
    }
    void push_back(T val) {
        if (_capacity == 0) {
            _data = new T[1];
            _capacity = 1;
        }
        else if (_size == _capacity) {
            resize();
        }
        _data[_size++] = val;

    }
    void resize(){
        T* old = _data;
        _capacity *= 2;
        _data = new T[_capacity];
        for (int i = 0; i < _size; ++i) {
            _data[i] = old[i];
        }
        delete[] old;
    }
    int size() {
        return _size;
    }
     iterator begin() noexcept  {
        return iterator(_data);
    }
    iterator end() noexcept  {
      
        return iterator(_data + _size);
    }
    /// @brief insert at arbitrary position
    /// we should be careful when we resize
    /// because it invalidates the input iterator p
    /// this is why we save the offset from the beginning
    /// of the data
    /// @param p (iterator) position to insert
    /// @param val value to insert
    /// @return an iterator to the inserted element
    iterator insert(iterator p,T val) {
        auto offset = p.p - _data;
        if (_size == _capacity) {
            resize();
        }
        iterator q(_data + offset);
        for (iterator itr =begin()+_size; itr != q; --itr) {
            *itr = *(itr - 1);
        }
        *q = val;
        _size++;
        return q;
    }

     T& operator[](int idx) const noexcept  {
        return _data[idx];
    }
    
};



template<int nodebug=0>
class TestClass {
    int _x, _y;
public:
    TestClass(int x = 0, int y = 0) :_x(x), _y(y) {
       if(!nodebug) std::cout << "ctor ("<<_x<<","<<_y<<")\n";

    }
    TestClass(const TestClass& rhs) {
        if (!nodebug) {
            std::cout << "copy ctor\n";
            /*std::cout << _x << "->" << rhs._x << std::endl;
            std::cout << _y << "->" << rhs._y << std::endl;*/
        }
        _x = rhs._x;
        _y = rhs._y;
    };
 
    TestClass& operator=(const TestClass& rhs) {
        if (!nodebug) {
            std::cout << "assignment\n";
            //std::cout << _x << "->" << rhs._x << std::endl;
            //std::cout << _y << "->" << rhs._y << std::endl;
        }
        _x = rhs._x;
        _y = rhs._y;
        return *this;
    }
   
    ~TestClass() {
        if(!nodebug)std::cout << "dtor\n";
    }
    std::pair<int, int> val() {
        return std::pair<int, int>(_x, _y);
    }
    int& x() {
        return _x;
    }
    int& y() {
        return _y;
    }
};



class Container {
    int* p, * _begin;
    int _size;
    int* _end;
public:
    class Iterator {
        int* current;
        int _size;
    public:
        Iterator(int* p, int size) :current(p), _size(size) {}
        Iterator operator++() {

            if (*current == _size - 1)current = current + 1;
            else if (*current % 2 == 0)
                current = current + _size / 2;
            else
                current = current - _size / 2 + 1;
            return *this;
        }
        int operator *() {
            return *current;
        }
        bool operator!=(const Iterator& rhs) {
            return current != rhs.current;
        }

    };
    Container(int size) :_size(size) {
        p = new int[_size];
        _begin = p;
        _end = p + size;
        for (int i = 0; i < _size; ++i) {
            if (i % 2 == 0)
                p[i / 2] = i;
            else
                p[_size / 2 + i / 2] = i;
        }
    }
    Iterator begin() {
        return Iterator(_begin, _size);
    }
    Iterator end() {
        return Iterator(_end, _size);
    }
};
