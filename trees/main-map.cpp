//
//  main.cpp
//  bst
//
//  Created by Hikmat Farhat on 15/3/12.
//  Copyright (c) 2012 NDU. All rights reserved.
//

#include <iostream>
#include <map>
#include <string>
#include "map.h"
using namespace std;

int main(int argc, const char* argv[])
{
    std::map<std::string, double > m;
    m.insert({ "person1", 90 });
    m.insert({ "person2",92.4 });
    m.insert({ "person3",44 });
    m["person4"] = 15;
    std::map<std::string, double>::iterator itr=m.begin();
    itr++;
    std::cout << itr->first << std::endl;
   /* while(itr!=m.end()) {
        auto [x, y] = *itr;
        std::cout << x << "==>" << y << std::endl;
        ++itr;
    }*/

    return 0;
}

