// ConsoleApplication3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "bst.h"

int main()
{
    bst<double> t;
    t.insert(10);
    t.insert(6);
    t.insert(20);
    t.insert(8);
    t.insert(3);
    t.postorder();
    std::cout << "-----------\n";
    std:: cout << std::boolalpha;
    std::cout << t.find(3) << std::endl;
    std::cout << t.find(7) << std::endl;
    std::  cout << "\n------heights --------\n";
    std::cout << t.height() << std::endl;
    t.insert(4);
    std::cout << t.height() << std::endl;
    std::cout << "\n----erase---\n";
    t.erase(6);
    t.postorder();
    /*
    std::cout << '\n';
    auto min = t.findMin();
    std::cout << min->_val << std::endl;*/
}
