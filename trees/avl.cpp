//
//  avl.cpp
//  AVL
//
//  Created by apple on 31/10/14.
//  Copyright (c) 2014 apple. All rights reserved.
//

#include <stdio.h>
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
#include "avl.h"

extern std::ofstream data,inorder,level;


void AVL::insert(int x) {

    Node *p =root,*tmp=root;
    //std::cout<<"inserting value "<<x<<std::endl;
   
    while(tmp!=NULL){
        if(x>tmp->data){
            p=tmp;
            tmp=tmp->right;
        }
        else{
            p=tmp;
            tmp=tmp->left;
        }
    }
    //at this point p is the deepest non-null node
    // and will be the parent of tmp
    tmp=new Node(x,NULL,NULL,p);
    if(x>p->data){p->right=tmp;}
    else {p->left=tmp;}
   
    updateHeight(p);
    check(p);
}

std::string AVL::print(){
    
    std::stringstream ss;
    std::queue<Node *> q;
    
    q.push(root);
   // ss<<root->data<<"("<<root->height<<")("<<root->balance<<")"<<' ';
    ss<<root->data<<' ';
    while(!q.empty()){
        Node *t=q.front();
        Node *left=t->left;
        Node *right=t->right;
        if(left!=NULL){
            q.push(left);
           // ss<<left->data<<"("<<left->height<<")("<<left->balance<<")"<<' ';
           ss<<left->data<<' ';
        }
        else{
            ss<<-1<<' ';
        }
        if(right!=NULL){
            q.push(right);
           //ss<<right->data<<"("<<right->height<<")("<<right->balance<<")"<<' ';
            ss<<right->data<<' ';
        }
        else{
            ss<<-1<<' ';
        }
        
        q.pop();
    }
    return ss.str();
}
void AVL::leftR(Node *t){
   // std::cout<<"Left rotation at node "<<t->data<<std::endl;
   
    if(t==root){
        root=t->right;
    }
   
    else{
        if(t->data<t->parent->data)
            t->parent->left=t->right;
        else t->parent->right=t->right;
    }
    
    t->right->parent=t->parent;
    Node *tmp=t->right->left;
    t->right->left=t;
    t->parent=t->right;
    t->right=tmp;
    if(tmp!=NULL) tmp->parent=t;
    updateHeight(t);
   // update(t);
   // std::cout<<print()<<std::endl;
}


void AVL::rightR(Node *t){

  //  std::cout<<"Right rotation at node "<<t->data<<std::endl;
    if(t==root){
        root=t->left;
    }
    else{
        if(t->data<t->parent->data)
            t->parent->left=t->left;
        else t->parent->right=t->left;
    }
    
    t->left->parent=t->parent;
    Node *tmp=t->left->right;
    
    t->left->right=t;
    t->parent=t->left;
    t->left=tmp;
    if(tmp!=NULL)tmp->parent=t;
      updateHeight(t);
}

void AVL::check(AVL::Node *t){
    if(t->balance<-1){// right branch is higher than left one
        if(t->right->balance>0){// check to see if a double rotation is needed
            rightR(t->right);
        }
        leftR(t);
    }
    else if(t->balance>1){// left branch is higher than right one
        if(t->left->balance<0){leftR(t->left);}//check to see if a double rotation is needed
         rightR(t);
    }
    else {
        if(t->parent!=NULL)check(t->parent);
    }
}

//recursively update the height of t
// and all its ancestors

void AVL::updateHeight(AVL::Node *t){
    int l,r;
    if(t->left!=NULL){
        l=t->left->height;
    }
    else l=-1;
    
    if(t->right!=NULL)
        r=t->right->height;
    else r=-1;
    t->balance=l-r;
    t->height=1+std::max(l,r);
    
        if(t->parent!=NULL)updateHeight(t->parent);
    
}

