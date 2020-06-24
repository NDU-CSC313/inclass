#include <iostream>
class Test {
	int _x, _y;
public:
	Test(int x = 0, int y = 0) :_x(x), _y(y) {
		std::cout << "ctor with x=" << _x << " and y=" << _y << std::endl;
	}
	int x() const {
		return _x;
	}
	int y() const {
		return _y;
	}
#if defined(EXAMPLE3) || defined(EXAMPLE5) || defined(EXAMPLE6) || defined(EXAMPLE7)
	bool operator<(const Test& rhs) const {
		return _x < rhs.x();
	}
	bool operator>(const Test& rhs) const {
		return _x > rhs.x();
	}
#endif

};

#if defined (EXAMPLE5) || defined (EXAMPLE6)
std::ostream& operator<<(std::ostream& os, const Test& t) {
	os <<"(" <<t.x() << "," << t.y()<<")" << std::endl;
	return os;
}
#endif