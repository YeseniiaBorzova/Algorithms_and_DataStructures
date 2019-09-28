#include "Graph.h"
int main()
{
	int V, origin, destin, maxEdges;
	cout << "Input number of vertices ";
	cin >> V;
	Graph g1(V);
	maxEdges = V * (V - 1);
	for (int i = 0; i < maxEdges; i++)
	{
		cout << "Enter edge (-1 -1 to exit): ";
		cin >> origin >> destin;
		if ((origin == -1) && (destin == -1))
			break;
		g1.addEdge(origin, destin);
	}
	g1.printGraph(V);
	g1.isTree() ? cout << "Graph is Tree\n" :
		cout << "Graph is not Tree\n";
	system("pause");
	return 0;
}