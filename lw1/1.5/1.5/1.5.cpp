#include <algorithm>
#include <boost\timer.hpp>
#include <iostream>
#include <iterator>
#include <vector>

void initMultitude(std::vector<int>& multitude)
{
	for (size_t i = 0; i < multitude.size(); i++)
	{
		multitude[i] = static_cast<int>(i);
	}
}

void distributionGenerationPrint(const int n, const int k, std::ostream& out)
{
	int sizeVector = k + 1;
	std::vector<int> multitude(sizeVector);
	initMultitude(multitude);
	int m = 1;
	while (m != 0)
	{
		do
		{
			//copy(multitude.begin() + 1, multitude.end(), std::ostream_iterator<size_t>(out, " "));
			//std::cout << std::endl;
		} while (std::next_permutation(multitude.begin() + 1, multitude.end()));
		m = k;
		while (multitude.at(m) == n - k + m)
		{
			--m;
		}
		++multitude.at(m);
		for (auto i = m + 1; i <= k; i++)
		{
			multitude[i] = multitude[i - 1] + 1;
		}
	}
}

int main()
{
	boost::timer time;
	time.restart();
	distributionGenerationPrint(50, 5, std::cout);
	auto duration = time.elapsed();
	std::cout << duration << std::endl;

	return 0;
}
