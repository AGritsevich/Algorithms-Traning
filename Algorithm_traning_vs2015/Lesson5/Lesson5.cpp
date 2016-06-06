
template <class Titer>
Titer min_element(Titer b, Titer e)
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

template <class T>
void swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template <class Titer>
void sort_naive(Titer b, Titer e)
{
	for (Titer i = b; i < e; ++i)
	{
		for (Iter j = i + 1; j < e; ++j)
		{
			if (*j < *i)
			{
				swap(*i, *j);
			}
		}
	}
}

template <class Titer>
void sort_selection(Titer b, Titer e)
{
	for (Titer pivot = b; pivot < e; ++pivot)
	{
		assert(is_sorted(b, pivot));
		auto m = min_element(pivot, e);
		if (pivot != m)
		{
			swap(*pivot, *m);
		}
	}
}

template <class Titer>
void sort_selection_fun(Titer b, Titer e)
{
	for (Titer pivot = b; pivot < e; ++pivot)
		swap(*pivot, *min_element(pivot, e));
}

template <class Titer>
void buble_sort_my(Titer b, Titer e) {
	for (Titer pivot = 0; pivot != e; ++pivot) {
		for (int sw = pivot + 1; sw != e; ++sw) {
			if (*sw < *pivot) {
				swap(*pivot, *sw);
			}
		}
	}
}

template <class Titer>
void buble_sort_r(Titer b, Titer e) {
	for (Titer pivot = e; pivot != b; pivot--) {
		assert(std::is_sorted(pivot, e));
		for (Titer next_i = b + 1; next_i < pivot; ++next_i) {
			assert(i == min_element(b, i+1));
			auto i = next_i - 1;
			assert(i == min_element(b, next_i));

			if (*next_i < *i) {
				swap(*i, *next_i);
			}
		}
	}
}

template <class Titer>
void insertion_sor0t_r(Titer b, Titer e) {
	// [b, e) = [sorted) U [unsorted)
	// [b, e) = [b, pivot) U [pivot, e)

	for (Titer pivot = ? ; pivot != ? ; ??pivot) {
		assert(is_sorted(b, pivot));
		
		// [b, pivot) U [pivot, e) = [sorted) U [unsorted)
		// [b, e) = [b, pivot) U [pivot, e)

		// insert *pivot to [b, pivot)
		for (Titer i = pivot; i != b; --i) {
			assert(std::is_sorted(b, i) && std::is_sorted(i+1, pivot+1));
			
			auto next_i = i + 1;
			if (*next_i < *i) {
				std::swap_iter(i, next_i);
			}
			else
			{
				break;
			}
		}
	}

	assert(is_sorted(b, pivot));
}

int main()
{
    return 0;
}

