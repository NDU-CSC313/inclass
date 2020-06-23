

#include <iostream>
#include <exception>
//#include <map>
#include <vector>
#include <string>
#include "map.h"
//using namespace std;

int main(int argc, const char* argv[])
{
    

    ::map<int, double > m;
    m.insert({ 10, 90 });
    m.insert({ 20,92.4 });
    m.insert({ 30,44 });
    m.insert({ 25,54 });
    m.insert({ 5,44 });
    m.insert({ 8,44 });
   m.inorder();
   //std::cout << "\n-----------------\n";
   // //m["person4"] = 15;
    auto itr=m.begin();
    while (itr != m.end()) {
        std::cout << itr->key << "," << itr->val << std::endl;
        itr = m.next(itr);
    }
    ///m.erase("person2");
    std::cout << "\n after delete\n";
    itr = m.end();
    
    while (itr!=m.begin()) {
        itr = m.prev(itr);
        std::cout << itr->key << "," << itr->val << std::endl;
    }
    
   /*while(itr!=m.end()) {
        auto [x, y] = *itr;
        std::cout << x << "==>" << y << std::endl;
        ++itr;
    }*/

    return 0;
}

