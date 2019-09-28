#pragma once
#include<iostream> 
#include <list> 
#include<vector>
#include <limits.h> 
using namespace std;
class Graph
{
	int V;
	list<int> *adj;
	bool isCyclicUtil(int v, bool visited[], int parent);
public:
	Graph(int V);
	void addEdge(int v, int w);
	void printGraph(int V);
	bool isTree();
};