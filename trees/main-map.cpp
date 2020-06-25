#include <iostream>
#include <vector>
#include <map>
#include <string>

#ifdef EXAMPLE1
int main(){
	std::vector<std::pair<int,std::string>> v {{10,"person1"},
	{5,"person2"},{13,"person3"},{9,"person4"},{15,"person5"},{23,"person6"}};
	std::map<int,std::string> m;
	for(auto& x:v)
		m.insert(x);
	std::map<int,std::string>::iterator itr;
	for(itr=m.begin();itr!=m.end();++itr)
		std::cout<<"("<<itr->first<<","<<itr->second<<")\n";
}
#endif

#ifdef EXAMPLE2
int main() {
	std::vector<std::pair<int,std::string>> v{ {10,"person1"},
	{5,"person2"},{13,"person3"},{9,"person4"},{15,"person5"},{23,"person6"} };
	std::map< std::string,int> m;
	for (auto& x : v)
		m.insert(std::pair<std::string,int>(x.second,x.first));
	std::map<std::string,int>::iterator itr;
	for (itr = m.begin(); itr != m.end(); ++itr)
		std::cout << "(" << itr->first << "," << itr->second << ")\n";
}
#endif

#ifdef EXAMPLE3
int main() {
	
	std::map< std::string, int> m;
	m["student1"] = 80;
	m["student2"] = 75;
	m["student3"] = 94;
	for (auto& [name,grade] : m)
		grade = grade+ 10;
	m["student3"] = 100;
	for (auto& x : m)
		std::cout << "(" << x.first << "=>" << x.second << ")\n";

}
#endif

#ifdef EXAMPLE4
#include <iterator>
#include <algorithm>
int main() {

	std::map< std::string, int> m;
	m["student1"] = 92;
	m["student2"] = 75;
	m["student3"] = 94;
	m["student4"] = 89;
	std::vector<std::pair<std::string, int>> v;
	std::copy_if(m.begin(), m.end(), std::back_inserter(v),
		[](auto p) {return p.second >= 90; });
	for (auto& [name, grade] : v)
		std::cout << "name:" << name << " grade:" << grade << std::endl;

}
#endif

