#pragma once
#include<iostream>
using namespace std;
template<class Type>
class Graph
{
	friend void main(void);
public:
	void shortestPath(int);
private:
	int n,  //vertex number of graph G
		*prev; //the array of previous vertex
	Type **c, //the adjancency matrix of graph G
		*dist;//the array of shortest path
};


template<class Type>
class minHeapNode
{
	friend Graph<Type>;
public:
	operator int() const { return length; }
private:
	int i; //No. of vertex
	Type length;//current road length
};


template<class Type>
