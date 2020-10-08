#include "Graph.h"

Graph::Graph(std::istream& in)
{
	Initialization(in);
}

void Graph::Initialization(std::istream& in)
{
	in >> m_numberOfVertices >> m_numberOfEdges;
	if ((m_numberOfVertices < MINIMUM_NUMBER_OF_VERTICES) || (m_numberOfVertices > MAXIMUM_NUMBER_OF_VERTICES))
	{
		throw std::exception("Vertex count error!");
	}
	if ((m_numberOfEdges < 0) || m_numberOfEdges > ((m_numberOfVertices * (m_numberOfVertices - 1)) / 2) )
	{
		throw std::exception("Edge count error!");
	}

	m_graph.resize(m_numberOfVertices + 1);
	m_used.resize(m_numberOfVertices + 1, false);

	m_d.resize(m_numberOfVertices + 1);
	m_up.resize(m_numberOfVertices + 1);

	int firstVertex, secondVertex;
	for (auto i = 0; i < m_numberOfEdges; i++)
	{
		in >> firstVertex >> secondVertex;
		if ((firstVertex < MINIMUM_NUMBER_OF_VERTICES) && 
			(secondVertex < MINIMUM_NUMBER_OF_VERTICES) && 
			(firstVertex > MAXIMUM_NUMBER_OF_VERTICES) && 
			(secondVertex > MAXIMUM_NUMBER_OF_VERTICES))
		{
			throw std::exception("Edge parameter error!");
		}
		m_graph[firstVertex].push_back(secondVertex);
		m_graph[secondVertex].push_back(firstVertex);
	}
}

void Graph::FindArtPointsAndBridges()
{
	m_timer = 1;
	for (auto i = 1; i <= m_numberOfVertices; i++)
	{
		if (!m_used[i])
		{
			DFS(i);
		}
	}
}

void Graph::PrintArtPoints(std::ostream& out)
{
	std::copy(m_articulationPoints.begin(), m_articulationPoints.end(), std::ostream_iterator<size_t>(out, " "));
	out << std::endl;
}

void Graph::PrintBridges(std::ostream& out)
{
	for (const auto& it : m_bridges)
	{
		out << it.first << " " << it.second << " " << std::endl;
	}
}

void Graph::PrintArtPointsAndBridges(std::ostream& out)
{
	this->PrintArtPoints(out);
	this->PrintBridges(out);
}

void Graph::DFS(int v, int p)
{
	int i, to, children;
	m_used[v] = true;
	m_d[v] = m_up[v] = m_timer++;
	children = 0;

	for (i = 0; i < m_graph[v].size(); i++)
	{
		to = m_graph[v][i];

		if (to == p)
		{
			continue;
		}

		if (m_used[to])
		{
			m_up[v] = std::min(m_up[v], m_d[to]);
		}
		else
		{
			DFS(to, v);
			m_up[v] = std::min(m_up[v], m_up[to]);

			if (m_up[to] > m_d[v])
			{
				m_bridges.insert(Edge(v, to));
			}

			if ((m_up[to] >= m_d[v]) && (p != -1))
			{
				m_articulationPoints.insert(v);
			}
			children++;
		}
	}
	if ((p == -1) && (children > 1))
	{
		m_articulationPoints.insert(v);
	}
}

std::pair<int, int> Graph::Edge(int firstPoint, int secondPoint)
{
	if (firstPoint > secondPoint)
	{
		std::swap(firstPoint, secondPoint);
	}
	return std::make_pair(firstPoint, secondPoint);
}
