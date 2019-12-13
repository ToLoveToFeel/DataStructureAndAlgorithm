#pragma once
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <cassert>

using namespace std;

// ������ȱ���
// Ѱ����Ȩͼ�����·��
template <typename Graph>
class ShortestPath {
private:
	Graph& G;       // ͼ������
	int s;          // ��ʼ��
	bool* visited;  // ��¼bfs�Ĺ����нڵ��Ƿ񱻷���
	int* from;      // ��¼·��, from[i]��ʾ���ҵ�·����i����һ���ڵ�
	int* ord;       // ��¼·���нڵ�Ĵ���ord[i]��ʾi�ڵ���·���еĴ���

public:
	// ���캯��, Ѱ����Ȩͼgraph��s�㵽����������·��
	ShortestPath(Graph& graph, int s) :G(graph) {
		// �㷨��ʼ��
		assert(s >= 0 && s < graph.V());
		
		this->s = s;
		visited = new bool[graph.V()];
		from = new int[graph.V()];
		ord = new int[graph.V()];
		for (int i = 0; i < graph.V(); i++)
		{
			visited[i] = false;
			from[i] = -1;
			ord[i] = -1;
		}

		// ��Ȩͼ���·���㷨, ��s��ʼ������ȱ�������ͼ
		queue<int> q;
		q.push(s);
		visited[s] = true;
		ord[s] = 0;
		while (!q.empty())
		{
			int v = q.front();
			q.pop();

			typename Graph::adjIterator adj(G, v);
			for(int i = adj.begin(); !adj.end(); i = adj.next())
				if (!visited[i]) {
					visited[i] = true;
					q.push(i);
					from[i] = v;
					ord[i] = ord[v] + 1;
				}
		}

	}

	// ��������
	~ShortestPath() {

		delete[] visited;
		delete[] from;
		delete[] ord;
	}

	// ��ѯ��s�㵽w���Ƿ���·��
	bool hasPath(int w) {
		assert(w >= 0 && w < G.V());
		return visited[w];
	}

	// ��ѯ��s�㵽w���·��, �����vec��
	void path(int w, vector<int>& vec) {

		assert(w >= 0 && w < G.V());

		stack<int> s;
		// ͨ��from����������ҵ���s��w��·��, ��ŵ�ջ��
		int p = w;
		while (p != -1) {
			s.push(p);
			p = from[p];
		}

		// ��ջ������ȡ��Ԫ��, ���˳��Ĵ�s��w��·��
		vec.clear();
		while (!s.empty()) {
			vec.push_back(s.top());
			s.pop();
		}
	}

	// ��ӡ����s�㵽w���·��
	void showPath(int w) {

		assert(w >= 0 && w < G.V());

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

	// �鿴��s�㵽w������·������
	int length(int w) {
		assert(w >= 0 && w < G.V());
		return ord[w];
	}
};