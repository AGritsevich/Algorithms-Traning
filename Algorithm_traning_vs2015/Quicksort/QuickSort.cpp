#include <iostream>
#include <iomanip>
#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;

template <class T, class TFunc, class P1, class P2>
void test(T expected, TFunc f, P1 p1, P2 p2)
{
	auto result = f(p1, p2);
	std::cout << "testing: " << expected
		<< "\texpected: " << expected
		<< "== f(" << p1 << ", " << p2 << ");";

	if (expected != result)
	{
		std::cout << "\tError: "
			<< "\texpected: " << expected
			<< "!= f(" << p1 << ", " << p2 << "), but " << result << endl;

	}
	else
	{
		cout << "\tTest ok " << endl;
	}

}

ostream& operator<<(ostream& o, const vector<int> &v)
{
	o << "{";
	for (const auto& x : v)
		o << x << ",";
	o << "}";
	return o;
}

template <class TFunc>
void test_binary_search(TFunc binary_search_impl)
{
	typedef vector<int> Vec;
	int key = 42;
	// lamda
	auto adaptor = [binary_search_impl](Vec& v, int key) {
		auto result = binary_search_impl(v.begin(), v.end(), key);
		return result == v.end() ? -1 : result - v.end();
	};

	// degenarated
	test(-1, adaptor, Vec(), key);

	// trivial and second trivial
	test(-1, adaptor, Vec({ 1 }), key);
	test(0, adaptor, Vec({ key }), key);

	// second trivial
	test(-1, adaptor, Vec({ 1, 2 }), key);
	test(1, adaptor, Vec({ 1, key }), key);
	test(0, adaptor, Vec({ key, 100 }), key);

	// key not in array
	test(-1, adaptor, Vec({ 1, 2, 3, 5, 41 }), key);
	test(-1, adaptor, Vec({ 43, 45, 67, 100 }), key);
	test(-1, adaptor, Vec({ 3, 5, 41, 43, 45,67 }), key);

	// key in array 
	test(4, adaptor, Vec({ 1, 2, 3, 5, key }), key);
	test(0, adaptor, Vec({ key, 45, 67, 100 }), key);
	test(3, adaptor, Vec({ 3, 5, 41, key, 45,67 }), key);

	// binary search specific
	test(3, adaptor, Vec({ 3, 5, 41, key, 45,67 }), key);
	test(2, adaptor, Vec({ 2, 5, key, 45,67 }), key);

	// more than one key
	test(1, adaptor, Vec({ key, key }), key);
	test(3, adaptor, Vec({ 1, 2, key, key }), key);
	test(4, adaptor, Vec({ 1, 2, 3, key, key }), key);
	test(1, adaptor, Vec({ key, key, key + 1, key + 10 }), key);


}
//////////////////////////////////////////////////////////////////////////////

template <class TIter>
void partition(TIter b, TIter pivot, TIter e) {
	assert(b <= pivot && pivot <= e);

	// ...
	auto i = b;
	while (i != e) {
		assert(std::max_element(b, i) <= i);
		if (i > pivot) {
			std::iter_swap(i, e);
		}
		++i;
	}

	assert(*max(b, pivot) < *pivot);
	assert(*min(pivot + 1, e) >= *pivot);

}

template <class TIter>
void partition(TIter b, TIter pivot, TIter e) {
	assert(b <= pivot && pivot <= e);
	assert(e-b > 0);
	// [b, pivot) U [p] U [pivot + 1, e)
	auto x = *pivot;

	while () {
		// [partitioned)				[unpartitioned)
		/// [b, p) [p, bu)				[bu, e)

		// [b, p) [p] [p+1, bu)
		if (bu >= *p) {
			// [b, p)[p, bu][bu+1, e)
			bu++;
		} else {
			//
		}
	}

	assert(*max(b, pivot) < *pivot);
	assert(*min(pivot + 1, e) >= *pivot);

}

int main(int argv, char  **argc) {
	return 0;
}