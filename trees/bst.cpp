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
#include "bst.h"


void BST::print(){
    print(root,0);
}

void BST::print(Node *n,int level){
    if(n==nullptr)return;
    
    for(int i=0;i!=level;i++)
        std::cout<<" ";
    std::cout<<n->data<<std::endl;
    print(n->left,level+1);
    print(n->right,level+1);
}


void BST::insert(int x) {
    insert(x,root);
    
}

void BST::insert(int x,Node * &t) {
    if(t==nullptr){
        t=new Node(x,nullptr,nullptr);
    }
    else if ( x< t->data ){
        insert(x,t->left);
    }
    else{
        insert(x,t->right);
    }
    return ;
}


void BST::erase(int x){
    erase(x,root); 
}

int BST::findMin(){
    return findMin(root)->data;
}

BST::Node * BST::findMin(Node *t){
    if(t==nullptr)return nullptr;
    if(t->left==nullptr)return t;
    return findMin(t->left);
}


 BST::Node * BST::findMax(Node *t){
    if(t==nullptr)return nullptr;
    if(t->right==nullptr)return t;
    return findMax(t->right);
}




void BST::printPreorder(Node *t){
    if(t==nullptr)return;
    std::cout<<t->data<<",";
    printPreorder(t->left);
    printPreorder(t->right);    
}


void BST::printPostorder(Node *t){
    if(t==nullptr)return;
    
    printPostorder(t->left);
    printPostorder(t->right);    
    std::cout<<t->data<<",";
}


void BST::printInorder(Node *t){
    if(t==nullptr)return;
    printInorder(t->left);
    std::cout<<t->data<<",";
    printInorder(t->right);    
}


int BST::height(){
    return height(root);
}


int BST::height(BST::Node *t){
    if (t==nullptr){std::cout<<"nullptr"<<std::endl; return -1;}
    else{
        int hl=height(t->left);
        int hr=height(t->right);
        int mh=1+std::max(hl,hr);
         std::cout<<"Height="<<mh<<std::endl;
        return mh;
    }
}

int BST::numNodes(){
    return numNodes(root);
}


int BST::numNodes(Node *t){
    if(t==nullptr)return 0;
    else
        return 1+numNodes(t->left)+numNodes(t->right);
}


int BST::numLeaves(){
    return numLeaves(root);
}


int BST::numLeaves(BST::Node *t){
    if(t==nullptr)return 0;
    else if (t->left==nullptr && t->right==nullptr)
        return 1;
    else
        return numLeaves(t->left)+numLeaves(t->right);
}


std::string BST::printLevel(){
    std::stringstream ss;
    std::queue<Node *> q;

    std::cout<<"print level\n";
    q.push(root);
    ss<<root->data<<' ';

    while(!q.empty()){
        Node *t=q.front();
        Node *left=t->left;
        Node *right=t->right;
        if(left!=nullptr){
            q.push(left);
            ss<<left->data<<' ';
        }
        else{
            ss<<-1<<' ';
        }
        if(right!=nullptr){
            q.push(right);
            ss<<right->data<<' ';
        }
        else{
            ss<<-1<<' ';
        }

        q.pop();
    }
    return ss.str();
}


void BST::erase(int x,Node * &t){
    
    if(t==nullptr) return;
    if(x<t->data)erase(x,t->left);
    else if (x> t->data) erase(x,t->right);
    /* found the node */
    else if(t->left!=nullptr && t->right!=nullptr){
        t->data=BST::findMin(t->right)->data;
        erase(t->data,t->right);
    }
    else {
        Node *oldNode=t;
        t=(t->left!=nullptr)?t->left:t->right;
        delete oldNode;
    }
}
