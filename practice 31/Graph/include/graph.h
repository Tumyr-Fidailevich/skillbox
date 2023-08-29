#pragma once

#include <vector>
#include <unordered_set>

class IGraph;

class MatrixGraph;

class ListGraph;

class IGraph
{
public:
	virtual ~IGraph()
	{}

	explicit IGraph() = default;

	explicit IGraph(IGraph* oth)
	{};

	virtual void AddEdge(int from, int to) = 0;

	virtual int VerticesCount() const = 0;

	virtual std::vector<int> GetNextVertices(int vertex) const = 0;

	virtual std::vector<int> GetPrevVertices(int vertex) const = 0;

	virtual void showGraph() const = 0;
};

class ListGraph : public IGraph
{
private:
	std::vector<std::unordered_set<int>> _adjacencyList;
public:
	explicit ListGraph() : ListGraph(0) {}

	explicit ListGraph(const int &size);

	explicit ListGraph(const IGraph* oth);

	ListGraph &operator=(const IGraph &other);

	void AddEdge(int from, int to) override;

	int VerticesCount() const override;

	std::vector<int> GetNextVertices(int vertex) const override;

	std::vector<int> GetPrevVertices(int vertex) const override;

	void showGraph() const override;
};

class MatrixGraph : public IGraph
{
private:
	std::vector<std::vector<bool>> _adjacencyMatrix;
public:
	explicit MatrixGraph() : MatrixGraph(0) {}

	explicit MatrixGraph(const int &size);

	explicit MatrixGraph(const IGraph* oth);

	MatrixGraph &operator=(const IGraph &other);

	void AddEdge(int from, int to) override;

	int VerticesCount() const override;

	std::vector<int> GetNextVertices(int vertex) const override;

	std::vector<int> GetPrevVertices(int vertex) const override;

	void showGraph() const override;
};