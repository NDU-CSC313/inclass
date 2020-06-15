#include <iostream>
#include "list.h"
#include <list>
#include <vector>
#include <iterator>
#include <algorithm>
#include <random>
#include <chrono>

template<int nodebug = 0>
class TestClass {
    int _x, _y;
public:
    TestClass(int x = 0, int y = 0) :_x(x), _y(y) {
        if (!nodebug) std::cout << "ctor (" << _x << "," << _y << ")\n";

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
        if (!nodebug)std::cout << "dtor\n";
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


int main() {
    {
        std::list<int> mylist{ 1,2,3,4,5 };
        auto itr = mylist.begin();
        std::advance(itr, 2);
        std::cout << *itr;
        for (auto& x : mylist)
            std::cout << x << ",";
        std::cout << std::endl;
        for (auto itr = mylist.begin(); itr != mylist.end(); ++itr)
            std::cout << *itr << ",";
        std::cout << std::endl;
    }
     /*{
        std::list<TestClass<0>> a;
        std::vector<TestClass<0>> b;
        a.push_back(TestClass<0>(1, 2));
        a.push_back(TestClass<0>(3, 4));
        a.push_back(TestClass<0>(5, 6));

        b.push_back(TestClass<0>(1, 2));
        b.push_back(TestClass<0>(3, 4));
        b.push_back(TestClass<0>(5, 6));
        std::cout << "------------------------\n";
        std::cout << " adding to the front of list\n";
        a.push_front(TestClass<0>(7, 8));
        std::cout << "------------------------\n";
        std::cout << " adding to the front of vector\n";
        b.insert(b.begin(), TestClass<0>(7, 8));
        std::cout << "------------------\n";
        std::cout << " done \n";
        std::cout << "------------------\n";
    }*/

    /*{
        using namespace std::chrono;

        std::vector<int> myvec(1000000);
        std::random_device e;
        std::uniform_int_distribution<> dist(1, 10);
        std::generate(myvec.begin(), myvec.end(), [&]() { return dist(e); });
        std::cout << "done generating\n";
       
        auto start = system_clock::now();
        for (int i = 0; i < 100; i++)
            std::advance(myvec.begin(), 999999);
        auto elapsed = duration_cast<seconds>(system_clock::now() - start);
        std::cout << elapsed.count() << std::endl;
        myvec[10] = 17;
    }*/

   /* {
        using namespace std::chrono;
        std::list<int> mylist(1000000);
        std::random_device e;
        std::uniform_int_distribution<> dist(1, 10);
        std::generate(mylist.begin(), mylist.end(), [&]() { return dist(e); });
        std::cout << "done generating\n";
        auto start = system_clock::now();
        for (int i = 0; i < 100; i++)
            std::advance(mylist.begin(), 999999);
        auto elapsed = duration_cast<seconds>(system_clock::now() - start);
        std::cout << elapsed.count()<<std::endl;
    }*/

   
	/*{
		list<int> l;
		l.push_back(1); l.push_back(2);
		l.push_front(3);
		for (auto itr = l.begin(); itr != l.end(); ++itr)
			std::cout << *itr << std::endl;
	}*/
}
