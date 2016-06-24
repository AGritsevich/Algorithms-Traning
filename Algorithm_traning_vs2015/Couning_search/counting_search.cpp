#include <vector>

template <typename T>
void counting_sort(std::vector<T>& v)
{
	size_t counters_size = sizeof(T)*CHAR_BIT;
	size_t = counters[sizeof(T)*CHAR_BIT] = {0};

	for (const auto& x : v)
	{
		++counter[x];
	}

	size_t pos = 0;
	for (size_t i = 0; i < counters_size; i++)
	{
		for (size_t j = 0;  j < counters[i]; ++j)
		{
			v[pos]=i;
			pos++;
		}
	}
}

template <class T>
uint8_t radix_value(T x, size_t radix)
{
	return static_cast<uint_8>(x >> (radix*CHAR_BIT));
}

template <class T>
std::vector<size_t> cumulitive_sums(const std::vector<size_t>& freq)
{
	std::vector<size_t> sums(freq.size() + 1);
	copy(freq.begin, freq.end, std::back_inserter(sums))

	for(size_t i = 1; i < sums.size(); i++)
	{
		sums[i] += sums[i-1] + freq[i]
	}
	return sums;
}

template <class T>
std::vector<size_t>& compute_frequencies(std::vector<T>& v, size_t radix )
{
	size_t counters_size = sizeof(T)*CHAR_BIT;
	std::vecor<size_t> freq(counters_size, 0);
	for (const auto& x : v)
	{
		auto digit = radix_value(x, radix);
		++freq[x];
	}
	return freq;
}

template <class T>
void radix_sort(std::vector<T>& v)
{
	std::vector<T> buff(v.size());

	auto radix_count = sizeof(T);
	for(size_t radix = 0; radix < radix_count; ++radix)
	{
		auto freq = compute_frequencies(v, radix);
		auto sums = cumulitive_sums(freq);

		for (auto x: v)
		{
			auto digit = radix_value(x, radix);
			auto index = sums[digit];
			buff[inex] = x;
			++sums[digit];
		}

		v.swap(buff);
	}
}

int main(int argc, char** argv) 
{
}