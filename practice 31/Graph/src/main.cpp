#include <iostream>
#include "graph.h"

int main()
{
	IGraph* listGraph = new ListGraph(4);
	listGraph->AddEdge(0, 1);
	listGraph->AddEdge(1, 3);
	listGraph->AddEdge(1, 2);
	listGraph->AddEdge(2, 0);
	listGraph->AddEdge(2, 3);
	MatrixGraph matrixGraph;
	matrixGraph = *listGraph;
	matrixGraph.showGraph();
	listGraph->showGraph();
	delete listGraph;
	return 0;
}
