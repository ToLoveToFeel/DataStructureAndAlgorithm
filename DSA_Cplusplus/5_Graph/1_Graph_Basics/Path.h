#pragma once
#include <vector>
#include <stack>
#include <iostream>
#include <cassert>

using namespace std;

// ·����ѯ
template <typename Graph>
class Path {
private:
	Graph& G;
	int s;      // ��ʼ��
	bool* visited;	// ��¼�ýڵ��Ƿ���ʹ�
	int* from;		// ��¼·��, from[i]��ʾ���ҵ�·����i����һ���ڵ�

	// ͼ����ȱ������ݹ��㷨
	void dfs(int v) {
		visited[v] = true;
		typename Graph::adjIterator adj(G, v);
		for (int i = adj.begin(); !adj.end(); i = adj.next())
			if (!visited[i]) {
				from[i] = v;
				dfs(i);
			}
	}

public:
	// ���캯��
	Path(Graph& graph, int s) :G(graph) {
		visited = new bool[G.V()];
		from = new int[G.V()];
		for (int i = 0; i < G.V(); i++)
		{
			visited[i] = false;
			from[i] = -1;
		}
		this->s = s;

		// Ѱ·�㷨
		dfs(s);

	}

	// ��������
	~Path() {
		delete[] visited;
		delete[] from;
	}

	// ��ѯ��s�㵽w���Ƿ���·��
	int hasPath(int w) {
		assert(w >= 0 && w < G.V());
		return visited[w];
	}

	// ��ѯ��s�㵽w���·��, �����vec��
	void path(int w, vector<int>& vec) {
		assert(hasPath(w));

		stack<int> s;

		// ͨ��from����������ҵ���s��w��·��, ��ŵ�ջ��
		int p = w;
		while (-1 != p)
		{
			s.push(p);
			p = from[p];
		}
		
		// ��ջ������ȡ��Ԫ��, ���˳��Ĵ�s��w��·��
		vec.clear();
		while (!s.empty())
		{
			vec.push_back(s.top());
			s.pop();
		}
	}

	// ��ӡ����s�㵽w���·��
	void showPath(int w) {
		vector<int> vec;
		path(w, vec);
		for (int i = 0; i < vec.size(); i++) {
			cout << vec[i];
			if (i == vec.size() - 1)
				cout << endl;
			else
				cout << " -> ";
		}
	}

};