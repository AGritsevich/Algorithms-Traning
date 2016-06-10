#include <ostream>
#include <iostream>
#include <vector>
#include <algorithm>

template <class Titer>
void min_element(Titer b, Titer e)
{
	Titer result = b;
	while (b < e)
	{
		if (*b < *result)
		{
			result = b;
		}
		++b;
	}
	return result;
}

template<class Iter>
void EasySort(Iter b, Iter e) {
	for (Iter i = b; i != e; ++i) {
		for (Iter j = b+1; j != e; ++j) {
			if (*i > *j) {
				std::iter_swap(i, j);
			}
		}
	}
}

template<class Iter>
void BubleSort(Iter b, Iter e) {
	for (Iter i; i != e; ++i) {
		for (Iter j = i + 1; i != e; ++j) {
			if (*i > *j) {
				std::iter_swap(i, j);
			}
		}
	}
}

template<class Iter>
void SelectionSort(Iter b, Iter e) {
	for (Iter pivot = b; pivot != e; ++pivot) {
		Iter min = min_element(b, pivot);
		std::iter_swap(pivot, min); //
	}
}

template<class Iter>
void InsertionSort(Iter b, Iter e) {
	for (Titer pivot = b ; pivot != i ; ++pivot) {

		for (Iter i = pivot; i != b; --i) {
			auto next_i = i + 1;
			if (*next_i < *i) {
				std::iter_swap(i, next_i);
			}
			else
			{
				break;
			}
		}
	}
}

template <class T, class TFunc, class P1, class P2>
void test(T expected, TFunc f, P1 p1)
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
		sort_impl(v.begin(), v.end());
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
	test(true, adaptor, Vec(1,2,3,4,5,6,7,8,9));
	test(true, adaptor, Vec(9,8,7,6,5,4,3,2,1));
	test(true, adaptor, Vec(8,8,8,8,8,8,8,8));
	test(true, adaptor, Vec(1, 1, 100, 100));
	test(true, adaptor, Vec(100, 100, 1, 1));
	test(true, adaptor, Vec(8,6,0,7,5,9,3,9,2,5)); // even
	test(true, adaptor, Vec(8, 6, 0, 7, 5, 9, 3, 9, 2)); // odd
}

int main()
{
	typedef std::vector<int>::iterator iter;
	std::cout << "~~~~~~~~~ Testing: " << "Easy sort" << "~~~~~~~~~~~~~~~~~\n";
	test_sorts(EasySort<iter>);

	std::cout << "~~~~~~~~~ Testing: " << "Buble sort" << "~~~~~~~~~~~~~~~~~\n";
	test_sorts(BubleSort<iter>);
	
	std::cout << "~~~~~~~~~ Testing: " << "Selection sort" << "~~~~~~~~~~~~~~~~~\n";
	test_sorts(SelectionSort<iter>);
	
	std::cout << "~~~~~~~~~ Testing: " << "Insertion sort" << "~~~~~~~~~~~~~~~~~\n";
	test_sorts(InsertionSort<iter>);
    
	return 0;
}

