#pragma once
#include <iostream>
#include "Graph.h"
#include "minHeap.h"

using namespace std;

int main()
{
	int n = 11;
	int prev[12] = { 0,0,0,0,0,0,0,0,0,0,0,0 };

	int dist[12] = { 1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000 };

	cout << "单源图的邻接矩阵如下：" << endl;
	int **c = new int*[n + 1];

	for (int i = 1; i <= n; i++)
	{
		c[i] = new int[n + 1];
		for (int j = 1; j <= n; j++)
		{
			fin >> c[i][j];
			cout << c[i][j] << " ";
		}
		cout << endl;
	}

	int v = 1;
	Graph<int> G;
	G.n = n;

	G.c = c;
	G.dist = dist;
	G.prev = prev;
	G.ShortesPaths(v);

	cout << "从S到T的最短路长是：" << dist[11] << endl;
	for (int i = 2; i <= n; i++)
	{
		cout << "prev(" << i << ")=" << prev[i] << "   " << endl;
	}

	for (int i = 2; i <= n; i++)
	{
		cout << "从1到" << i << "的最短路长是：" << dist[i] << endl;
	}

	for (int i = 1; i <= n; i++)
	{
		delete[]c[i];
	}

	delete[]c;
	c = 0;
	system("pause");
	return 0;
}
