#pragma once
#include <iostream>
#include <algorithm>
template<typename T>
struct Node {
	T val;
	Node* left;
	Node* right;
	Node(T v = T{}, Node* l = nullptr, Node* r = nullptr)
		:val(v), left(l), right(r) {}
};

template<typename T>
class bst {
private:
	Node<T>* root;
	void insert(Node<T>* &, T);
	void postorder(const Node<T>*);
	bool find(const Node<T>*, T);
	int height(const Node<T>*);
	int numNodes(const Node<T>*);
	Node<T> * findMin(Node<T>*);
	void erase(Node<T>* &, T);
public:
	bst() :root(nullptr) {}
	void insert(T );
	void postorder();
	bool find(T);
	int height();
	int numNodes();
	T findMin();
	void erase(T );

};
template<typename T>
void bst<T>::postorder(const Node<T>* t) {

	if (t == nullptr)return;
	postorder(t->left);
	postorder(t->right);
	std::cout << t->val << ",";

}
template<typename T>

void bst<T>::postorder() {
	postorder(root);

}
template<typename T>

void bst<T>::insert(Node<T>* &t, T val) {
	if (t == nullptr) t = new Node<T>(val);
    else if (val > t->val)insert(t->right, val);
	else insert(t->left, val);
}
template<typename T>

void bst<T>::insert(T v) {
	insert(root, v);
}

template<typename T>
bool bst<T>::find(const Node<T>* t, T val) {
	if (t == nullptr) return false;
	if (t->val == val)return true;
	else if (t->val < val) return find(t->right, val);
	else return find(t->left, val);

}

template<typename T> bool bst<T>::find(T v) {
	return find(root, v);
}
template <typename T>
int bst<T>::height(const Node<T>* t) {
	if (t == nullptr) return -1;
	int hl = height(t->left);
	int hr = height(t->right);
	return std::max(hl, hr) + 1;
}
template <typename T>
int bst<T>::height() {
	return height(root);
}


template <typename T>
int bst<T>::numNodes(const Node<T>* t) {
	if (t == nullptr) return 0;
	int nl = numNodes(t->left);
	int nr = numNodes(t->right);
	return 1 + nl + nr;

}
template<typename T>
int bst<T>::numNodes() {
	return numNodes(root);
}
template<typename T>

Node<T> * bst<T>::findMin(Node<T>* t) {
	if (t->left == nullptr) return t;
	else return findMin(t->left);

}
template <typename T>
void bst<T>::erase(Node<T>* & t, T val) {
	if (t == nullptr) return;
	
	if (t->val < val)erase(t->right, val);
	else if (t->val > val) erase(t->left, val);
	// found the node
	else if (t->left != nullptr && t->right != nullptr) {
			Node<T>* min = findMin(t->right);
			t->val = min->val;
			erase(t->right, min->val);
		}
	else {
		Node<T>* old = t;
		t = (t->left != nullptr) ? t->left : t->right;
		delete old;
	}

}
template <typename T>
void bst<T>::erase(T val) {
	erase(root, val);
}
template<typename T>
T bst<T>::findMin() {
	return findMin(root)->val;
}