// 2.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Graph.h"
#include "ParseCommandLine.h"
#include <fstream>
#include <iostream>

int main(int argc, char* argv[])
{
	if (auto params = ParseComandLine(argc, argv))
	{
		std::ifstream in(params->inputFileName);
		std::ofstream out(params->outputFileName);
		in.exceptions(in.badbit | in.failbit);
		out.exceptions(out.badbit | out.failbit);

		try
		{
			Graph graph(in);
			graph.FindArtPointsAndBridges();
			graph.PrintArtPointsAndBridges(out);
		}
		catch (const std::ios_base::failure& ex)
		{
			std::cout << ex.what() << std::endl;
			std::cout << ex.code() << std::endl;
			std::cout << "File open error!";
		}
		catch (const std::exception &ex)
		{
			std::cout << ex.what() << std::endl;
		}
	}
	else
	{
		std::cout << "Invalid arguments cout \n";
		std::cout << "Usage 2.1.exe <input file name> <output file name>\n";
	}

	return 0;
}
