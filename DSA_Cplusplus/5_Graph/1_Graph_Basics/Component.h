#pragma once
#include <iostream>
#include <cassert>
using namespace std;

// ͼ����ȱ���
template <typename Graph>
class Component {
private:
	Graph& G;
	bool* visited;	// ��¼�ýڵ��Ƿ���ʹ�
	int ccount = 0;	// ��¼ͼ����ͨ�����ĸ���
	int* id;		// ���鼯����¼�ڵ��Ƿ�����ͬһ����ͨ����

	// ͼ����ȱ������ݹ��㷨
	void dfs(int v) {
		visited[v] = true;
		id[v] = ccount;
		typename Graph::adjIterator adj(G, v);
		for (int i = adj.begin(); !adj.end(); i = adj.next())
			if (!visited[i])
				dfs(i);
	}

public:
	// ���캯��
	Component(Graph& graph) :G(graph) {
		visited = new bool[G.V()];
		id = new int[G.V()];
		for (int i = 0; i < G.V(); i++)
		{
			visited[i] = false;
			id[i] = -1;
		}
		ccount = 0;

		for(int i = 0; i < G.V(); i++)
			if (!visited[i]) {
				dfs(i);
				ccount++;
			}
				
	}

	// ��������
	~Component() {
		delete[] visited;
		delete[] id;
	}

	// ������ͨ�����ĸ���
	int count() {
		return ccount;
	}

	// �ж������ڵ��Ƿ�����ͬһ����ͨ����
	bool isConnected(int v, int w) {
		assert(v >= 0 && v < G.V());
		assert(w >= 0 && w < G.V());
		assert(id[v] != -1 && id[w] != -1);

		return id[v] == id[w];
	}

};