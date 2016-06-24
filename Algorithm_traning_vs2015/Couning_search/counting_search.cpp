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

int main(int argc, char** argv) 
{
}