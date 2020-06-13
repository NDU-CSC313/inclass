//
//  main.cpp
//  AVL
//
//  Created by apple on 31/10/14.
//  Copyright (c) 2014 apple. All rights reserved.
//

#include <iostream>
#include "avl.h"

int main(int argc, const char * argv[]) {
    
    
    AVL t(atoi(argv[1]));
for(int i=2;i<argc;i++){
t.insert(atoi(argv[i]));
}
/*
    t.insert(2);
    t.insert(1);
    t.insert(4);
  t.insert(5);
    t.insert(6);
   t.insert(7);
    t.insert(16);
   t.insert(15);
    t.insert(14);
    t.insert(13);
    t.insert(12);
    t.insert(11);
    t.insert(10);
    t.insert(8);
    t.insert(9);
*/
    std::cout<<t.print()<<std::endl;
    return 0;
}
