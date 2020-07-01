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
    std::cout<<t.print()<<std::endl;
    return 0;
}
