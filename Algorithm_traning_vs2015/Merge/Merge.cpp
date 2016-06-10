#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

template <class T, class TFunc, class P1>
void test(T expected, TFunc f, P1 p1)
{
	auto result = f(p1);
	std::cout << "testing: " << expected
		<< "\texpected: " << expected
		<< "== f(" << p1 << ", " << ");";

	if (expected != result)
	{
		std::cout << "\tError: "
			<< "\texpected: " << expected
			<< "!= f(" << p1 << ", " << "), but " << result << endl;
	}
	else
	{
		cout << "\tTest ok " << endl;
	}
}

std::ostream& operator<<(std::ostream& o, const std::vector<int> &v)
{
	o << "{";
	for (const auto& x : v)
		o << x << ",";
	o << "}";
	return o;
}

template <class TFunc>
void test_sorts(TFunc sort_impl) {
	typedef std::vector<int> Vec;
	// lamda
	auto adaptor = [sort_impl](Vec& v) {
		std::vector<int> out;
		out.reserve(_UI32_MAX);
		sort_impl(v.begin(), v.end(), out.begin());
		return std::is_sorted(v.begin(), v.end());
	};

	// degenarated
	test(true, adaptor, Vec());

	// Trivial
	test(true, adaptor, Vec(8));
	test(true, adaptor, Vec(8, 8));
	test(true, adaptor, Vec(8, 9));
	test(true, adaptor, Vec(7, 8));

	// general
	test(true, adaptor, Vec(1, 2, 3, 4, 5, 6, 7, 8, 9));
	test(true, adaptor, Vec(9, 8, 7, 6, 5, 4, 3, 2, 1));
	test(true, adaptor, Vec(8, 8, 8, 8, 8, 8, 8, 8));
	test(true, adaptor, Vec(1, 1, 100, 100));
	test(true, adaptor, Vec(100, 100, 1, 1));
	test(true, adaptor, Vec(8, 6, 0, 7, 5, 9, 3, 9, 2, 5)); // even
	test(true, adaptor, Vec(8, 6, 0, 7, 5, 9, 3, 9, 2)); // odd
}

// complexity O(n)
template <class Titer>
void merge(const Titer b1, const Titer e1, const Titer b2, const Titer e2, Titer out) {
	
	// [b1, i1) [i1, e1)
	// [b2, i2) [i2, e2)
	// [..., out)[out](out, ...)
	Titer i1 = b1;
	Titer i2 = b2;
	Titer b_out = out;
	while (i1 < e1 && i2 < e2) {
		assert(std::is_sorted(b_out, out));
		assert((i1 - b1) + (i2 - b2) == (out - b_out));
		if (*i1 < *i2) { 
			*out = *i1++;
		}
		else {
			*out = *i2++;
		}
		assert(std::is_sorted(b_out, out));
		out++;
	}
	out = std::copy(i1, e1, out);
	out = std::copy(i2, e2, out);
	assert(std::is_sorteed(b_out, out));
	assert((out-b_out) == (e1-b1)+(e2-b2));
}

// complexity O()
template <class TIter>
void merge_sort(TIter b, TIter e, TIter out) {
	if (e - b > 1) {
		TIter m = b + (e - b) / 2;
		// [b, m) U [m, e)
		// [o, 0+m) U [m, e)
		merge_sort(b, m, out);
		merge_sort(m, e, out);
		merge(b, m, m, e, out);
		std::copy(out, out + (e - b), b);
	}
	assert(std::is_sorted(b, e));
}
/*
template <class TIter>
void outer_merge_sort(TIter src_b, TIter src_e, TIter dst_b) {
	if (e - b > 1) {
		TIter m = b + (e - b) / 2;
		outer_merge_sort(src_b, src_b+m, dst_b);
		outer_merge_sort(src_m, src_e, dst_m);
		outer_merge_sort(dst_b, dst_m, d_st_e, dst
	}
	std::copy(src_b, src_e, dst_b);
	assert(std::is_sorted(b, e));
}
*/

int main()
{
	typedef std::vector<int>::iterator iter;
	std::cout << "~~~~~~~~~ Testing: " << "Merge sort" << "~~~~~~~~~~~~~~~~~\n";
	test_sorts(merge_sort<iter>);
	return 0;
} 