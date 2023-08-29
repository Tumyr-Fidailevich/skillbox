#include <iostream>
#include <vector>
#include <unordered_set>
#include "graph.h"

int ListGraph::VerticesCount() const
{
	return (int) _adjacencyList.size();
}

void ListGraph::AddEdge(int from, int to)
{
	if (from < 0 || from >= _adjacencyList.size() || to < 0 || to >= _adjacencyList.size())
	{
		std::cout << "Invalid vertex index" << std::endl;
	} else
	{
		_adjacencyList[from].insert(to);
	}
}

void ListGraph::showGraph() const
{
	if (_adjacencyList.empty())
	{
		std::cout << "Graph is empty" << std::endl;
	} else
	{
		for (int i = 0; i < _adjacencyList.size(); i++)
		{
			std::cout << i;
			for (int it: _adjacencyList[i])
			{
				std::cout << "->" << it;
			}
			std::cout << std::endl;
		}
	}
}

std::vector<int> ListGraph::GetNextVertices(int vertex) const
{
	if (vertex >= 0 || vertex < _adjacencyList.size())
	{
		return {_adjacencyList[vertex].begin(), _adjacencyList[vertex].end()};
	} else
	{
		std::cout << "Invalid vertex index" << std::endl;
		return {};
	}

}

std::vector<int> ListGraph::GetPrevVertices(int vertex) const
{
	std::vector<int> result;
	if (vertex >= 0 || vertex < _adjacencyList.size())
	{
		for (int i = 0; i < _adjacencyList.size(); i++)
		{
			if (_adjacencyList[i].contains(vertex))
			{
				result.push_back(i);
			}
		}
	} else
	{
		std::cerr << "Index error" << std::endl;
	}
	return result;
}

ListGraph::ListGraph(const int &size)
{
	_adjacencyList.resize(size);
}

ListGraph::ListGraph(const IGraph* oth)
{
	int vertices = oth->VerticesCount();
	_adjacencyList.resize(vertices);

	for (int vertex = 0; vertex < vertices; ++vertex) {
		std::vector<int> nextVertices = oth->GetNextVertices(vertex);
		for (int nextVertex : nextVertices) {
			ListGraph::AddEdge(vertex, nextVertex);
		}
	}
}

ListGraph &ListGraph::operator=(const IGraph &oth)
{
	if(this != &oth)
	{
		int vertices = oth.VerticesCount();
		_adjacencyList.resize(vertices);

		for (int vertex = 0; vertex < vertices; ++vertex) {
			std::vector<int> nextVertices = oth.GetNextVertices(vertex);
			for (int nextVertex : nextVertices) {
				ListGraph::AddEdge(vertex, nextVertex);
			}
		}
	}
	return *this;
}

void MatrixGraph::AddEdge(int from, int to)
{
	if (from < 0 || from >= _adjacencyMatrix.size() || to < 0 || to >= _adjacencyMatrix.size())
	{
		std::cout << "Invalid vertex index" << std::endl;
	} else
	{
		_adjacencyMatrix[from][to] = true;
	}
}

int MatrixGraph::VerticesCount() const
{
	return (int) _adjacencyMatrix.size();
}

void MatrixGraph::showGraph() const
{
	if (_adjacencyMatrix.empty())
	{
		std::cout << "Graph is empty" << std::endl;
	} else
	{
		for (int i = 0; i < _adjacencyMatrix.size(); i++)
		{
			for (int j = 0; j < _adjacencyMatrix.size(); j++)
			{
				std::cout << (int) _adjacencyMatrix[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const
{
	std::vector<int> result;
	if (vertex >= 0 || vertex < _adjacencyMatrix.size())
	{
		for (int i = 0; i < _adjacencyMatrix[vertex].size(); i++)
		{
			if (_adjacencyMatrix[vertex][i])
			{
				result.push_back(i);
			}
		}
	}
	return result;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const
{
	std::vector<int> result;
	if (vertex >= 0 || vertex < _adjacencyMatrix.size())
	{
		for (int i = 0; i < _adjacencyMatrix.size(); i++)
		{
			if (_adjacencyMatrix[i][vertex])
			{
				result.push_back(i);
			}
		}
	}
	return result;
}

MatrixGraph::MatrixGraph(const int &size)
{
	_adjacencyMatrix = std::vector<std::vector<bool>>(size, std::vector<bool>(size, false));
}

MatrixGraph::MatrixGraph(const IGraph* oth)
{
	int vertices = oth->VerticesCount();
	_adjacencyMatrix.resize(vertices, std::vector<bool>(vertices, false));

	for (int vertex = 0; vertex < vertices; vertex++) {
		std::vector<int> nextVertices = oth->GetNextVertices(vertex);
		for (int nextVertex : nextVertices) {
			MatrixGraph::AddEdge(vertex, nextVertex);
		}
	}
}

MatrixGraph &MatrixGraph::operator=(const IGraph &oth)
{
	if(this != &oth)
	{
		int vertices = oth.VerticesCount();
		_adjacencyMatrix.resize(vertices, std::vector<bool>(vertices, false));

		for (int vertex = 0; vertex < vertices; ++vertex) {
			std::vector<int> nextVertices = oth.GetNextVertices(vertex);
			for (int nextVertex : nextVertices) {
				MatrixGraph::AddEdge(vertex, nextVertex);
			}
		}
	}
	return *this;
}