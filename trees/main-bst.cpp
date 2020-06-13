//
//  main.cpp
//  bst
//
//  Created by Hikmat Farhat on 15/3/12.
//  Copyright (c) 2012 NDU. All rights reserved.
//

#include <iostream>

#include "bst.h"
using namespace std;

int main (int argc, const char * argv[])
{

 
     BST bst(0);
    bst.createFull(2);
    //bst.readLevel();
//    bst.insert(13);
//    bst.insert(35);
//    bst.insert(6);
//    bst.insert(14);
//    bst.insert(29);
//    bst.insert(45);
//    bst.insert(5);
//    bst.insert(8);
//    bst.insert(18);

//   cout<<"Preorder\n";
//   bst.printPreorder();
//    cout<<"Postorder\n";
//    bst.printPostorder();
//    cout<<"Inorder\n";
//    bst.printInorder();
//    cout<<"starting"<<endl;
//    cout<<"----------------------"<<endl;
   cout<<"the height of the tree is"<<bst.height()<<endl;
    //cout<<"for a total of "<<bst.numNodes()<<" number of nodes\n";
    //cout<<"of which "<<bst.numLeaves()<<" are leaves\n";
    std::cout<<bst.printLevel();
    cout<<"Done"<<endl;
    cout<<"-----------"<<endl;
    return 0;
}

