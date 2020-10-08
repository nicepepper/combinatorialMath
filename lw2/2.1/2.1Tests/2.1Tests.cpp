#define BOOST_TEST_MODULE 2.1Tests
#include "../2.1/Graph.h"
#include "boost/test/unit_test.hpp"
#include <iostream>
#include <string>
#include <sstream>

void Clear(std::string & str, std::stringstream & stream)
{
	str.clear();
	stream.str("");
	stream.clear();
}

void GetStringsFromStream(std::string & str, std::stringstream & stream)
{
	std::string temp;
	while (!stream.eof())
	{
		std::getline(stream, temp);
		str += temp;
	}
}

BOOST_AUTO_TEST_SUITE(Graph_Tests)

	BOOST_AUTO_TEST_CASE(Example_with_correct_parameters)
	{
		std::stringstream stream;
		std::string str = "9 11  1 2  2 3  3 1  2 4  4 5  5 6  6 4  4 7  7 8  8 9  9 7";
		stream.str(str);	

		Graph graph(stream);
		graph.FindArtPointsAndBridges();

		Clear(str, stream);
		graph.PrintArtPoints(stream);
		GetStringsFromStream(str, stream);
		BOOST_CHECK(strcmp(str.c_str(), "2 4 7 ") == 0);

		Clear(str, stream);
		graph.PrintBridges(stream);
		GetStringsFromStream(str, stream);		
		BOOST_CHECK(strcmp(str.c_str(), "2 4 4 7 ") == 0);

		Clear(str, stream);
		graph.PrintArtPointsAndBridges(stream);
		GetStringsFromStream(str, stream);
		BOOST_CHECK(strcmp(str.c_str(), "2 4 7 2 4 4 7 ") == 0);
	}

BOOST_AUTO_TEST_SUITE_END()