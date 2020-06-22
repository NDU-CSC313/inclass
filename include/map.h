#pragma once
#include <iostream>
#include <algorithm>
template<typename Tk,typename Tv>
struct Node {
	Tk key;
	Tv val;
	Node* parent;
	Node* left;
	Node* right;
	char is_nil = 0;
	Node(Tk k,Tv v, Node* p = nullptr,Node* l = nullptr, Node* r = nullptr)
		:key(k),val(v),parent(p), left(l), right(r){}
};

template<typename Tk,typename Tv>
class map {
private:
	Node<Tk, Tv>* head;
//	Node<Tk,Tv>* root;
	void insert(Node<Tk,Tv>* &, std::pair<Tk,Tv>);
	void inorder(const Node<Tk,Tv>*);
	Node<Tk,Tv> * findMin(Node<Tk,Tv>*);
	void erase(Node<Tk,Tv>* &, Tk);
public:
	map() {
		head = new Node<Tk,Tv>(Tk{}, Tv{});
		head->is_nil = 1;
	}
	void insert(std::pair<Tk,Tv> );
	void inorder();
	void erase(Tk );
	Node<Tk, Tv>* next(Node<Tk, Tv>* t);
	Node<Tk, Tv>* begin();
	Node<Tk, Tv>* end();

};
template<typename Tk,typename Tv>
void map<Tk,Tv>::inorder(const Node<Tk,Tv>* t) {

	if (t == nullptr)return;
	inorder(t->left);
	std::cout << t->key << "has parent ";
	if (t->parent)std::cout << t->parent->key << "\n";
	else std::cout<<"null" << std::endl;
	inorder(t->right);

}
template<typename Tk,typename Tv>
Node<Tk, Tv>* map<Tk,Tv>::next(Node<Tk, Tv>* t) {
	if (t->right == nullptr) {
		Node<Tk, Tv>* p;
		while (!(p = t->parent)->is_nil && p->right == t)
			t = p;
		t = p;
	}
	else t=findMin(t->right);
	return t;
}

template<typename Tk,typename Tv>
Node<Tk, Tv>* map<Tk, Tv>::begin() {
	return head->left;
}
template<typename Tk, typename Tv>
Node<Tk, Tv>* map<Tk, Tv>::end() {
	return head;
}
template<typename Tk,typename Tv>
void map<Tk, Tv>::insert(Node<Tk, Tv>*& t, std::pair<Tk, Tv> p) {
	if (t == nullptr) {
		std::cout << "error\n"; return;
	}
	if (p.first > t->key) {
		if (t->right == nullptr) {
			t->right = new Node<Tk, Tv>(p.first, p.second, t);
			if (head->right == t)head->right = t->right;
		}
		else insert(t->right, p);

	}
	else {
		if (t->left == nullptr) {
			t->left = new Node<Tk, Tv>(p.first, p.second, t);
			if (head->left == t)head->left = t->left;
		}
		else insert(t->left, p);

	}
}

template<typename Tk,typename Tv>
void map<Tk, Tv>::insert(std::pair<Tk, Tv> v) {
	if (head->parent== nullptr) {
		head->parent= new Node < Tk, Tv>(v.first, v.second,head);
		head->left = head->parent;
		head->right = head->parent;
	}

	else insert(head->parent, v);
}

template<typename Tk,typename Tv>
Node<Tk,Tv> * map<Tk,Tv>::findMin(Node<Tk,Tv>* t) {
	if (t->left == nullptr) return t;
	else return findMin(t->left);

}
template <typename Tk,typename Tv>
void map<Tk,Tv>::erase(Node<Tk,Tv>* & t, Tk key) {
	if (t == nullptr) return;
	
	if (t->key < key)erase(t->right, key);
	else if (t->key> key) erase(t->left, key);
	// found the node
	else if (t->left != nullptr && t->right != nullptr) {
			Node<Tk,Tv>* min = findMin(t->right);
			t->key = min->key;
			erase(t->right, min->key);
		}
	else {
		Node<Tk,Tv>* old = t;
		t = (t->left != nullptr) ? t->left : t->right;
		delete old;
	}

}

template <typename Tk,typename Tv>
void map<Tk,Tv>::erase(Tk key) {
	erase(root, key);
}
template<typename Tk,typename Tv>
void map<Tk, Tv>::inorder() {
	inorder(head->parent);
}