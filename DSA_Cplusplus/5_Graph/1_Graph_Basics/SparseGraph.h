#pragma once


#include <iostream>
#include <vector>
#include <cassert>


using namespace std;

// ϡ��ͼ - �ڽӱ�
class SparseGraph {

private:
	int n, m;		// �ڵ����ͱ���
	bool directed;	// �Ƿ�Ϊ����ͼ
	vector<vector<int>> g;	// ͼ�ľ�������

public:
	// ���캯��
	SparseGraph(int n, bool directed) {
		this->n = n;
		this->m = 0;
		this->directed = directed;
		// g��ʼ��Ϊn���յ�vector, ��ʾÿһ��g[i]��Ϊ��, ��û���κͱ�
		g = vector<vector<int>>(n, vector<int>());
	}

	// ��������
	~SparseGraph() { }

	// ���ؽڵ����
	int V() {
		return n;
	}

	// ���رߵĸ���
	int E() {
		return m;
	}

	// ��ͼ�����һ����
	void addEdge(int v, int w) {
		assert(v >= 0 && v < n);
		assert(w >= 0 && w < n);

		g[v].push_back(w);
		if (v != w && !directed)
			g[w].push_back(v);

		m++;
	}

	// ��֤ͼ���Ƿ��д�v��w�ı�
	bool hasEdge(int v, int w) {
		assert(v >= 0 && v < n);
		assert(w >= 0 && w < n);

		for (int i = 0; i < g[v].size(); i++)
			if (g[v][i] == w)
				return true;
		return false;
	}

	// ��ʾͼ����Ϣ
	void show() {
		for (int i = 0; i < n; i++) {
			cout << "vertex " << i << ":\t";
			for (int j = 0; j < g[i].size(); j++)
				cout << g[i][j] << "\t";
			cout << "\n";
		}
	}

	// �ڱߵ�����, ����һ��ͼ��һ������,
	// ���������ͼ�к�����������������ж���
	class adjIterator {
	private:
		SparseGraph& G;
		int v;
		int index;

	public:
		// ���캯��
		adjIterator(SparseGraph& graph, int v) : G(graph) {
			this->v = v;
			index = 0;
		}

		~adjIterator() {}

		// ����ͼG���붥��v�����ӵĵ�һ������
		int begin() {
			index = 0;
			if (G.g[v].size())
				return G.g[v][index];
			// ��û�ж����v������, �򷵻�-1
			return -1;
		}

		// ����ͼG���붥��v�����ӵ���һ������
		int next() {
			index++;
			if (index < G.g[v].size())
				return G.g[v][index];
			// ��û�ж����v������, �򷵻�-1
			return -1;
		}

		// �鿴�Ƿ��Ѿ���������ͼG���붥��v�����ӵ����ж���
		bool end() {
			return index >= G.g[v].size();
		}
	};
};



