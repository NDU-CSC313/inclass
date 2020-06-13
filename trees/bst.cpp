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
    if(n==NULL)return;
    
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
    if(t==NULL){
        t=new Node(x,NULL,NULL);
    }
    else if ( x< t->data ){
        insert(x,t->left);
    }
    else{
        insert(x,t->right);
    }
    return ;
}


void BST::remove(int x){
    remove(x,root); 
}

int BST::findMin(){
    return findMin(root)->data;
}

BST::Node * BST::findMin(Node *t){
    if(t==NULL)return NULL;
    if(t->left==NULL)return t;
    return findMin(t->left);
}


 BST::Node * BST::findMax(Node *t){
    if(t==NULL)return NULL;
    if(t->right==NULL)return t;
    return findMax(t->right);
}




void BST::printPreorder(Node *t){
    if(t==NULL)return;
    std::cout<<t->data<<",";
    printPreorder(t->left);
    printPreorder(t->right);    
}


void BST::printPostorder(Node *t){
    if(t==NULL)return;
    
    printPostorder(t->left);
    printPostorder(t->right);    
    std::cout<<t->data<<",";
}


void BST::printInorder(Node *t){
    if(t==NULL)return;
    printInorder(t->left);
    std::cout<<t->data<<",";
    printInorder(t->right);    
}


int BST::height(){
    return height(root);
}


int BST::height(BST::Node *t){
    if (t==NULL){std::cout<<"NULL"<<std::endl; return -1;}
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
    if(t==NULL)return 0;
    else
        return 1+numNodes(t->left)+numNodes(t->right);
}


int BST::numLeaves(){
    return numLeaves(root);
}


int BST::numLeaves(BST::Node *t){
    if(t==NULL)return 0;
    else if (t->left==NULL && t->right==NULL)
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
        if(left!=NULL){
            q.push(left);
            ss<<left->data<<' ';
        }
        else{
            ss<<-1<<' ';
        }
        if(right!=NULL){
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

void BST::readLevel(){
    std::fstream input;
    input.open("/Users/apple/tmp/input");
    int x,y;
    std::queue<BST::Node *> q;
    input>>x;
    BST::Node *tmp;
    tmp=new Node(x,NULL,NULL);
    root=tmp;
    q.push(root);

    while(!q.empty()){
        //the scope is already BST
        // so the scoping BST:: is not
        //strictly necessary
        Node *t=q.front();
        BST::Node *left=NULL;
        BST::Node *right=NULL;
        input>>x>>y;
        if(x!=-1){
          left=new Node(x,NULL,NULL);
            q.push(left);
        }
        if(y!=-1){
          right=new Node(y,NULL,NULL);
          q.push(right);
        }
        t->left=left;
        t->right=right;
        q.pop();
    }

}


void BST::remove(int x,Node * &t){
    
    if(t==NULL) return;
    if(x<t->data)remove(x,t->left);
    else if (x> t->data) remove(x,t->right);
    /* found the node */
    else if(t->left!=NULL && t->right!=NULL){
        t->data=BST::findMin(t->right)->data;
        remove(t->data,t->right);
    }
    else {
        Node *oldNode=t;
        t=(t->left!=NULL)?t->left:t->right;
        delete oldNode;
    }
}

void BST::add(Node * t,int h){
    if(h==0)return;
    
    t->left=new Node(h-1,NULL,NULL);
    t->right=new Node(h-1,NULL,NULL);
    add(t->left,h-1);
    add(t->right,h-1);
    
}

void BST::createFull(int h){
    root->data=h;
    add(root,h);
}

