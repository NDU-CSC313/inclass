
class Test {
	int _x, _y;
public:
	Test(int x = 0, int y = 0) :_x(x), _y(y) {}
	int x() const {
		return _x;
	}
	int y() const {
		return _y;
	}
#ifdef EXAMPLE3
	bool operator<(const Test& rhs) const  {
		return _x < rhs.x();
    }
#endif

};
