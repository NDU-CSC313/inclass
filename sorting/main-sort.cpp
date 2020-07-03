#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>
#include <random>
#include <list>
#include "sort.hpp"

int main() {
	
	std::vector<int> v{ 18,18,23,7,19,34,34,8,12,15,18,15 };
	

	quicksort3(v.begin(), v.end());
	std::cout << "end\n";
	/*auto itr = std::adjacent_find(v.begin(), v.end(), [](auto a, auto b) { return b < a; });
	if (itr != v.end()) {
		std::cout << "not sorted\n";
	}
	else std::cout << "sorted\n";*/

	/*std::vector<int> v;
	std::random_device e;
	std::uniform_int_distribution<> dist(1, 100);
	
	std::generate_n(std::back_inserter(v),20, [&]() {return dist(e); });
	quicksort(v.begin(),v.end());
	auto itr = std::adjacent_find(v.begin(), v.end(), [](auto a, auto b) { return b < a; });
	if (itr != v.end()) {
		std::cout << "not sorted\n";
	}
	else std::cout << "sorted\n";

	std::cout << std::boolalpha;
	std::cout << std::is_sorted(v.begin(), v.end());*/
}
