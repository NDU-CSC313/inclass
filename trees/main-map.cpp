//
//  main.cpp
//  bst
//
//  Created by Hikmat Farhat on 15/3/12.
//  Copyright (c) 2012 NDU. All rights reserved.
//

#include <iostream>
//#include <map>
#include <vector>
#include <string>
#include "map.h"
//using namespace std;

int main(int argc, const char* argv[])
{
    

    ::map<std::string, double > m;
    m.insert({ "person1", 90 });
    m.insert({ "person2",92.4 });
    m.insert({ "person3",44 });
    m.insert({ "person14",54 });
    m.insert({ "person40",44 });
    m.insert({ "person35",44 });
   m.inorder();
   //std::cout << "\n-----------------\n";
   // //m["person4"] = 15;
    auto itr=m.begin();
    while (itr != m.end()) {
        std::cout << itr->key << "," << itr->val << std::endl;
        itr = m.next(itr);
    }
    m.erase("person2");
    std::cout << "\n after delete\n";
    itr = m.begin();
    while (itr != m.end()) {
        std::cout << itr->key << "," << itr->val << std::endl;
        itr = m.next(itr);
    }
   /*while(itr!=m.end()) {
        auto [x, y] = *itr;
        std::cout << x << "==>" << y << std::endl;
        ++itr;
    }*/

    return 0;
}

