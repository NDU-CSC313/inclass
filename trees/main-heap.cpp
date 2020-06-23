#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include "heap.h"

#define EXAMPLE2

#ifdef EXAMPLE1
int main(){
	//max heap by default

	/*std::priority_queue<int> q;
	q.push(10); q.push(20); q.push(4); q.push(7);
	while (!q.empty()) {
		std::cout << q.top() << ",";
		q.pop();
	}
	std::cout << std::endl;*/
	//min heap
	
	std::priority_queue<int,std::vector<int>, std::greater<int> > p;
	p.push(4); p.push(19); p.push(25); p.push(5); p.push(8); p.push(1);
	while (!p.empty()) {
		std::cout << p.top() << ",";
		p.pop();
	}
	std::cout << std::endl;
}
#endif

#ifdef EXAMPLE2
#include "Test.h"
struct comp {
	bool operator() (Test &a,Test& b) {
		return a.y() > b.y();
	}
};
int main(){
	
	std::priority_queue<Test, std::vector<Test>, comp> q;
	q.push(Test(10, 20)); q.push(Test(4, 5)); q.emplace(1, 7);
	while (!q.empty()) {
		auto t = q.top();
		std::cout << "(" << t.x() << "," << t.y() << ")\n";
		q.pop();
	}

}
#endif

#ifdef EXAMPLE3
#include "Test.h"

int main() {
	std::priority_queue<Test> q;
	q.push(Test(10, 20)); q.push(Test(4, 5)); q.emplace(1, 7);
	while (!q.empty()) {
		auto t = q.top();
		std::cout << "(" << t.x() << "," << t.y() << ")\n";
		q.pop();
	}

}
#endif