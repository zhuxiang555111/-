
#include "MinHeap.h"
#include <iostream>
#include <fstream> 
using namespace std;

ifstream fin("6d2.txt");

template<class Type>
class Graph
{
	friend int main();
public:
	void ShortesPaths(int);
private:
	int		n,		   //图G的顶点数
		*prev;     //前驱顶点数组
	Type	**c,       //图G的领接矩阵
		*dist;     //最短距离数组
};

template<class Type>
class MinHeapNode
{
	friend Graph<Type>;
public:
	operator int()const { return length; }
private:
	int       i;		  //顶点编号
	Type  length;	  //当前路长
};

template<class Type>
void Graph<Type>::ShortesPaths(int v)//单源最短路径问题的优先队列式分支限界法
{
	MinHeap<MinHeapNode<Type>> H(1000);
	MinHeapNode<Type> E;

	//定义源为初始扩展节点
	E.i = v;
	E.length = 0;
	dist[v] = 0;

	while (true)//搜索问题的解空间
	{
		for (int j = 1; j <= n; j++)
			if ((c[E.i][j] != 0) && (E.length + c[E.i][j] < dist[j])) {

				// 顶点i到顶点j可达，且满足控制约束
				dist[j] = E.length + c[E.i][j];
				prev[j] = E.i;

				// 加入活结点优先队列
				MinHeapNode<Type> N;
				N.i = j;
				N.length = dist[j];
				H.Insert(N);
			}
				try
			{
				H.DeleteMin(E); // 取下一扩展结点
			}
			catch (int)
			{
				break;
			}
			if (H.currentsize == 0)// 优先队列空
			{
				break;
			}
	}
}