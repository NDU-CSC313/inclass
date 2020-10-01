#include <iostream>
#include <list>
#include <vector>
#include <iterator>
#include <algorithm>
#include <random>
#include <chrono>
#define EXAMPLE6
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

#ifdef EXAMPLE1
int main() {

    std::list<int> mylist{ 1,2,3,4,5 };

    mylist.push_back(6);
    std::list<int>::iterator itr;
    for (itr = mylist.begin(); itr != mylist.end(); ++itr)
        std::cout << *itr << ",";
    std::cout << std::endl;
}
#endif 

#ifdef EXAMPLE2
int main() {

    std::list<int> mylist{ 1,2,3,4,5 };

    mylist.push_front(6);
    for (auto x:mylist)
        std::cout << x<< ",";
    std::cout << std::endl;
}

#endif

#ifdef EXAMPLE3
using namespace std::chrono;
int main() {
std::random_device e;
std::uniform_int_distribution<> dist(1, 10);

std::vector<int> myvec;

auto startv = system_clock::now();
for(int i=0;i<1000000;i++)
   myvec.insert(myvec.begin(), dist(e));

auto elapsed = duration_cast<seconds>(system_clock::now() - startv);
std::cout << elapsed.count() << std::endl;

std::list<int> mylist;
auto startl = system_clock::now();
for (int i = 0; i < 100000; i++)
    mylist.push_front(dist(e));
elapsed = duration_cast<seconds>(system_clock::now() - startl);
std::cout << elapsed.count() << std::endl;

}
#endif 

#ifdef EXAMPLE4
using namespace std::chrono;
int main() {
    std::random_device e;
    std::uniform_int_distribution<> dist(1, 10);

    const int n = 1000000;
    const int ops = 1000;
    std::vector<int> myvec(n);
    std::list<int> mylist(n);

    std::generate(myvec.begin(), myvec.end(), [&]() { return dist(e); });
    std::generate(mylist.begin(), mylist.end(), [&]() { return dist(e); });

    auto startv = system_clock::now();
    for (int i = 0; i < ops; i++)
        std::advance(myvec.begin(), n/2);
    auto elapsed = duration_cast<seconds>(system_clock::now() - startv);
    std::cout << elapsed.count() << std::endl;
    auto startl = system_clock::now();
    for (int i = 0; i < ops; i++)
        std::advance(mylist.begin(), n/2);
    elapsed = duration_cast<seconds>(system_clock::now() - startl);
    std::cout << elapsed.count() << std::endl;
}
#endif
       
#ifdef EXAMPLE5
using namespace std::chrono;

int main() {
    const int n = 1000000;
    const int ops = 100;
    std::random_device e;
    std::uniform_int_distribution<> dist(1, 10);
    std::vector<int> v;
    std::list<int> l;
    v.resize(n);
    l.resize(n);
    std::generate(v.begin(), v.end(), [&]() {return  dist(e); });
    std::generate(l.begin(), l.end(), [&]() {return  dist(e); });

    auto startv = system_clock::now();
    for (int i = 0; i < ops; i++) {
        std::vector<int> ov;
        std::copy_if(v.begin(), v.end(), std::back_inserter(ov),
            [](int i) { return i % 2 == 0; });
    }

    auto elapsed = duration_cast<seconds>(system_clock::now() - startv);
    std::cout << elapsed.count() << std::endl;
    std::list<int> ol;

    auto startl = system_clock::now();
    for (int i = 0; i < ops; i++) {
        std::copy_if(l.begin(), l.end(),std::back_inserter(ol),
            [](int i) { return i % 2 == 0; });
    }
    elapsed = duration_cast<seconds>(system_clock::now() - startl);
    std::cout << elapsed.count() << std::endl;

}
#endif 

#ifdef EXAMPLE6
using namespace std::chrono;

int main() {
    const int n = 1000000;
    const int ops = 1000;
    std::random_device e;
    std::uniform_int_distribution<> dist(1, 10);
    std::vector<int> srcv(n);
    std::list<int> srcl(n);
    std::generate(srcv.begin(), srcv.end(), [&]() {return  dist(e); });
    std::generate(srcl.begin(), srcl.end(), [&]() {return  dist(e); });

    std::vector<int> dstv(n);
    auto startv = system_clock::now();
    for (int i = 0; i < ops; i++) {
        std::copy_if(srcv.begin(), srcv.end(), dstv.begin(),
            [](int i) { return i % 2 == 0; });
    }

    auto elapsed = duration_cast<seconds>(system_clock::now() - startv);
    std::cout << elapsed.count() << std::endl;
    std::list<int> dstl(n);

    auto startl = system_clock::now();
    for (int i = 0; i < ops; i++) {
        std::copy_if(srcl.begin(), srcl.end(), dstl.begin(),
            [](int i) { return i % 2 == 0; });
    }
    elapsed = duration_cast<seconds>(system_clock::now() - startl);
    std::cout << elapsed.count() << std::endl;

}
#endif 