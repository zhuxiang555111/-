
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
	int		n,		   //ͼG�Ķ�����
		*prev;     //ǰ����������
	Type	**c,       //ͼG����Ӿ���
		*dist;     //��̾�������
};

template<class Type>
class MinHeapNode
{
	friend Graph<Type>;
public:
	operator int()const { return length; }
private:
	int       i;		  //������
	Type  length;	  //��ǰ·��
};

template<class Type>
void Graph<Type>::ShortesPaths(int v)//��Դ���·����������ȶ���ʽ��֧�޽編
{
	MinHeap<MinHeapNode<Type>> H(1000);
	MinHeapNode<Type> E;

	//����ԴΪ��ʼ��չ�ڵ�
	E.i = v;
	E.length = 0;
	dist[v] = 0;

	while (true)//��������Ľ�ռ�
	{
		for (int j = 1; j <= n; j++)
			if ((c[E.i][j] != 0) && (E.length + c[E.i][j] < dist[j])) {

				// ����i������j�ɴ���������Լ��
				dist[j] = E.length + c[E.i][j];
				prev[j] = E.i;

				// ����������ȶ���
				MinHeapNode<Type> N;
				N.i = j;
				N.length = dist[j];
				H.Insert(N);
			}
				try
			{
				H.DeleteMin(E); // ȡ��һ��չ���
			}
			catch (int)
			{
				break;
			}
			if (H.currentsize == 0)// ���ȶ��п�
			{
				break;
			}
	}
}