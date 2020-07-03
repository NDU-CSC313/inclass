#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>

struct Test {
	int ex1;
	int ex2;
	int final;
	Test(int x = 0, int y = 0, int z = 0) :ex1(x), ex2(y), final(z) {}

};

int main() {
	std::unordered_map<std::string, Test> grades;
	grades.max_load_factor(10);
	for (int i = 0; i < 20; ++i) {
		auto key = "student" + std::to_string(i);
		grades.insert(std::pair(key, Test(i,i,i)));
	}
	auto bcount = grades.bucket_count();
	auto h = grades.hash_function();
	auto i = grades.find("student4");
	std::cout << (i->second.ex1 + i->second.ex2 + i->second.final) / 3 << std::endl;
}

