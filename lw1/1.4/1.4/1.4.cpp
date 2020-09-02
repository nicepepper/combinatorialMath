// 1.4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <boost\timer.hpp>

void initMultitude(std::vector<int>& multitude)
{
	for (auto i = 0; i <= multitude.size(); i++)
	{
		multitude[i] = static_cast<int>(i);
	}
}

void printGeneratingCombinationsLexicographicOrder(const int n,const int k, std::ostream & out)
{
	int sizeVector = k + 1;
	std::vector<int> multitude(sizeVector);
	initMultitude(multitude);
	int m = 1;
	while (m != 0)
	{
		copy(multitude.begin() + 1, multitude.end(), std::ostream_iterator<size_t>(out, " "));
		std::cout << std::endl;
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
	printGeneratingCombinationsLexicographicOrder(10, 5, std::cout);
	auto duration = time.elapsed();
	std::cout << duration << std::endl;
	
	return 0;
}
