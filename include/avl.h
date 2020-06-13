//
//  avl.h
//  AVL
//
//  Created by apple on 31/10/14.
//  Copyright (c) 2014 apple. All rights reserved.
//

#ifndef AVL_avl_h

#include <string>
#include <fstream>
#include <sstream>


class AVL{
    
private:
    struct Node {
        Node *left;
        Node *right;
        Node *parent;
        int height;
        int balance;
        int data;
        Node(const int x,Node *l,Node *r,Node *p)
        :data(x),left(l),right(r),parent(p){height=0;balance=0;}
    };
    Node *root;
    
    void leftR(Node *);
    void rightR(Node *);
    void check(Node *);
    void updateHeight(Node *);
  public:
    AVL(int x){
        root=new Node(x,NULL,NULL,NULL);
    }
    void insert(int );
    std::string print();
    
};


#define AVL_avl_h


#endif
