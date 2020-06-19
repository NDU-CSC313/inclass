//
//  bst.cpp
//  bst
//
//  Created by Hikmat Farhat on 15/3/12.
//  Copyright (c) 2012 NDU. All rights reserved.
//

#include <iostream>
#include <queue>
#include <fstream>
#include <string>
#include <sstream>

class BST {

private:
    struct Node {
        Node *left;
        Node *right;
        int data;
        Node(const int x,Node *l,Node *r)
        :data(x),left(l),right(r){}
    };
    Node *root;
    void print(Node *n,int level);
    void insert(int ,Node * &);
    void remove(int, Node * & t);
    void printPreorder(Node *);
    void printPostorder(Node *);
    void printInorder(Node *);
    Node * findMin(Node *);
    Node * findMax(Node *);
    int height(Node *);
    int numNodes(Node *);
    int numLeaves(Node *);
public:
    BST(int x){
        root=new Node(x,NULL,NULL);
    }
    std::string printLevel();
    int numNodes();
    int numLeaves();
    void insert(int );
    void remove(int);
    int findMin();
    int findMax();
    int height();
    void print();
    void printPreorder(){printPreorder(root);}
    void printPostorder(){printPostorder(root);}
    void printInorder(){printInorder(root);}
};

