#include <iostream>

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

template <class TIter>
void merge_sort(TIter b, TIter e, TIter out) {
	if (e - b > 1) {
		TIter m = b + (e - b) / 2;
		merge_sort(b, m), out;
		merge_sort(m, e, out);
		merge(b, m, m, e, out);
	}
}

int main()
{

	return 0;
} 