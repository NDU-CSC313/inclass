#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>
#include <list>
#include <random>
#include <type_traits>

void bubble(std::vector<int>& a) {
	for (int j = 1; j < a.size(); ++j)
		for (int i = 0; i < a.size() - 1; ++i)
			if (a[i] > a[i + 1])
				std::swap(a[i], a[i + 1]);

}
void insertion(std::vector<int>& a) {

	for (int k = 1; k < a.size(); ++k) {
		int tmp = a[k];
		while (k > 0 && tmp < a[k - 1]) {
			a[k] = a[k - 1];
			k--;
		}
		a[k] = tmp;
	}
}
template<typename T>
int partition(std::vector<T>& v, int start, int end) {

	int j = start, i = start;
	int pivot = v[end];
	while (j != end) {
		if (v[j] <= pivot) {
			std::swap(v[j], v[i]);
			i++;
		}
		j++;
	}
	std::swap(v[j], v[i]);
	return i;

}
template<typename T>
void quicksort(std::vector<T>& v, int start, int end) {
	if (start >= end)return;
	T mid = partition(v, start, end);
	if (mid > start) quicksort(v, start, mid - 1);
	if (mid < end) quicksort(v, mid + 1, end);

}
template<typename RanIt>
void median3(RanIt first,RanIt mid, RanIt last) {
	//auto mid = first + ((last - first) >> 1);
	if (*mid < *first)std::iter_swap(mid, first);
	if (*mid > * last) {
		std::iter_swap(mid, last);
		if (*first > * mid)
			std::iter_swap(mid, first);
	}
}
template<typename RanIt>
auto Prev_iter(RanIt itr) {
	return --itr;
}
template<typename RanIt>
auto Next_iter(RanIt itr) {
	return ++itr;
}
template <typename T,typename RanIt>
auto partition2(T& cont,RanIt start, RanIt end) {
	if (start == end) return std::pair<RanIt,RanIt>(start,end);
	RanIt mid = start + ((end - start) >> 1);

	median3(start,mid, Prev_iter(end));

	RanIt pfirst = mid;
	RanIt plast = Next_iter(pfirst);
	RanIt left = pfirst;
	RanIt right = plast;
	for (;;) {
		//find the first value to the right
		// smaller than the pivot
		for (; right < end; ++right) {
			if (*right > * pfirst) {}//bigger than pivot move

			else if (*right < *pfirst) {// found it
				break;
			}
			else if (right== plast) {//equal to pivot but also next to the last one
				++plast;
			}
			else {//equal to pivot but not next to the last one
				std::iter_swap(right, plast);
				++plast;
			}
		}
		for (; left > start; ++left) {
			if (*Prev_iter(left) < *pfirst) {}//smaller than pivot move
			else if (*Prev_iter(left) > * pfirst) {//found it
				break;
			}
			else if (--pfirst != Prev_iter(left)) {//equal to pivot swap only if it is not next to it
				std::iter_swap(pfirst, Prev_iter(left));
			}
		}
		//at this point , glast points to the first element to the right smaller 
		//than pivot and Prev_iter(gfirst) points to the first element to the left bigger
		if (left == start && right == end) {
			return std::pair<RanIt, RanIt>(pfirst, plast);
		}
		if (right == end) {
			std::cout << "at the end\n";
		}
		else if (left == start) {
			std::cout << "at beg\n";
		}
		else {
			std::iter_swap(--left, right);
			++right;
		}
	}
}

template<typename RanIt>
auto partition(RanIt start, RanIt end) {
	if (start == end)return start;
	//there is at least one value in the range
	typename RanIt::value_type pivot = *(end-1);
    RanIt i=start, j=start;
	while (j != end) {
		if (*j <= pivot) {
			std::iter_swap(i, j);
			i++;
		}
		j++;
	}
	return i;
}
template<typename T,typename RanIt>
auto partition3(T& cont,RanIt start, RanIt end) {
	auto mid = start + ((end - start) >> 1);
	median3(start, mid, Prev_iter(end));
	auto pfirst = Prev_iter(end);
	std::iter_swap(pfirst, mid);
	auto i = start, j = start;
	while (*i < *pfirst){
		i++; j++;
	}
	while (j != pfirst) {
		if (*j < *pfirst) {
			std::iter_swap(i, j);
			i++; j++;
		}
		else if (*j == *pfirst) {
			std::iter_swap(j, --pfirst);
		}
		else j++;

	}
	RanIt first=i, last=i;
	for (auto itr = pfirst; itr < end; ++itr, ++i,++last) {
		std::iter_swap(itr, i);
	}
	return std::pair<RanIt, RanIt>(first, last);
}
template<typename RdIt>
void quicksort(RdIt start,RdIt end) {
	if (start >= end) return;
	RdIt mid = partition(start, end);
	if (mid >start) quicksort(start, mid-1);
	if (end>mid)quicksort(mid , end);
}

