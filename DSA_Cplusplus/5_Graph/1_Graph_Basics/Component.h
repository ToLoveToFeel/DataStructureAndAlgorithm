#pragma once
#include <iostream>
#include <cassert>
using namespace std;

// 图的深度遍历
template <typename Graph>
class Component {
private:
	Graph& G;
	bool* visited;	// 记录该节点是否访问过
	int ccount = 0;	// 记录图中连通分量的个数
	int* id;		// 并查集，记录节点是否属于同一个连通分量

	// 图的深度遍历，递归算法
	void dfs(int v) {
		visited[v] = true;
		id[v] = ccount;
		typename Graph::adjIterator adj(G, v);
		for (int i = adj.begin(); !adj.end(); i = adj.next())
			if (!visited[i])
				dfs(i);
	}

public:
	// 构造函数
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

	// 析构函数
	~Component() {
		delete[] visited;
		delete[] id;
	}

	// 返回连通分量的个数
	int count() {
		return ccount;
	}

	// 判断两个节点是否属于同一个连通分量
	bool isConnected(int v, int w) {
		assert(v >= 0 && v < G.V());
		assert(w >= 0 && w < G.V());
		assert(id[v] != -1 && id[w] != -1);

		return id[v] == id[w];
	}

};