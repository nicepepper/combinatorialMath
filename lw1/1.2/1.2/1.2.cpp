#include <algorithm>
#include <boost/timer.hpp>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>

using namespace std;

constexpr auto N = 10;

int main()
{
	map<int, int> elems, reverse, direction;
	int counter;
	int temp;
	boost::timer t;
	t.restart();
	for (int i = 1; i <= N; i++)
	{
		elems[i] = reverse[i] = i;
		direction[i] = -1;
	}

	direction[0] = 0;
	elems[0] = elems[N + 1] = N + 1;
	counter = N;
	while (counter != 1)
	{
		//copy(elems.cbegin(), elems.cend(), ostream_iterator<int>(cout, " "));
		counter = N;
		while (elems[reverse[counter] + direction[counter]] > counter && counter > 1)
		{
			direction[counter] = -direction[counter];
			counter--;
		}
		temp = elems[reverse[counter] + direction[counter]];
		elems[reverse[counter] + direction[counter]] = elems[reverse[counter]];
		elems[reverse[counter]] = temp;
		temp = reverse[elems[reverse[counter]]];
		reverse[elems[reverse[counter]]] = reverse[counter];
		reverse[counter] = temp;
	}
	double duration = t.elapsed();
	cout << duration << endl;
	return 0;
}