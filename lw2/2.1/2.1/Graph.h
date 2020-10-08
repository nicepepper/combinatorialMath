#pragma once
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <exception>

constexpr int MINIMUM_NUMBER_OF_VERTICES = 1;
constexpr int MAXIMUM_NUMBER_OF_VERTICES = 400;

class Graph
{
public:
	Graph(std::istream& in);
	void FindArtPointsAndBridges();
	void PrintArtPoints(std::ostream& out);
	void PrintBridges(std::ostream& out);
	void PrintArtPointsAndBridges(std::ostream& out);

private:
	void Initialization(std::istream& in);
	void DFS(int v, int p = -1);
	std::pair<int, int> Edge(int firstPoint, int secondPoint);

	std::vector<std::vector<int>> m_graph;
	std::vector<bool> m_used;
	std::vector<int> m_d, m_up;
	std::set<int> m_articulationPoints;
	std::map<int, int> m_bridges;

	int m_timer;
	int m_numberOfVertices;
	int m_numberOfEdges;
};
