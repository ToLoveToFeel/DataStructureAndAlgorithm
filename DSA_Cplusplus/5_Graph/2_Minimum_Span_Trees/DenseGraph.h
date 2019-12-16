#pragma once

#include <iostream>
#include <vector>
#include <cassert>
#include "Edge.h"

using namespace std;

// ����ͼ - �ڽӾ���
template <typename Weight>
class DenseGraph {
	
private:
	int n, m;		// �ڵ����ͱ���
	bool directed;	// �Ƿ�Ϊ����ͼ
	vector<vector<Edge<Weight>* >> g;	// ͼ�ľ�������

public:

	// ���캯��
	DenseGraph(int n, bool directed) {
		this->n = n;
		this->m = 0;
		this->directed = directed;
		g = vector<vector<Edge<Weight>* >>(n, vector<Edge<Weight>* >(n, NULL));
	}

	// ��������
	~DenseGraph() {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (NULL != g[i][j])
					delete g[i][j];
	}

	int V() { return n; } // ���ؽڵ����
	int E() { return m; } // ���رߵĸ���

	// ��ͼ�����һ����, ȨֵΪweight
	void addEdge(int v, int w, Weight weight) {
		if (hasEdge(v, w))
		{
			delete g[v][w];
			if (v != w && !directed)
				delete g[w][v];
			m--;
		}

		g[v][w] = new Edge<Weight>(v, w, weight);
		if (v != w && !directed)
			g[w][v] = new Edge<Weight>(w, v, weight);
		m++;
	}

	// ��֤ͼ���Ƿ��д�v��w�ı�
	bool hasEdge(int v, int w) {
		assert(v >= 0 && v < n);
		assert(w >= 0 && w < n);
		return NULL == g[v][w];
	}

	// ��ʾͼ����Ϣ
	void show() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				if (g[i][j])
					cout << g[i][j]->wt() << "\t";
				else
					cout << "NULL\t";
			cout << endl;
		}
	}

	// �ڱߵ�����, ����һ��ͼ��һ������,
	// ���������ͼ�к�����������������б�
	class adjIterator {
	private:
		DenseGraph& G;  // ͼG������
		int v;
		int index;

	public:
		// ���캯��
		adjIterator(DenseGraph& graph, int v) : G(graph) {
			this->v = v;
			this->index = -1;   // ������-1��ʼ, ��Ϊÿ�α�������Ҫ����һ��next()
		}

		~adjIterator() {}

		// ����ͼG���붥��v�����ӵĵ�һ����
		Edge<Weight>* begin() {
			// ������-1��ʼ, ��Ϊÿ�α�������Ҫ����һ��next()
			index = -1;
			return next();
		}

		// ����ͼG���붥��v�����ӵ���һ����
		Edge<Weight>* next() {
			// �ӵ�ǰindex��ʼ�������, ֱ���ҵ�һ��g[v][index]Ϊtrue
			for (index += 1; index < G.V(); index++)
				if (G.g[v][index])
					return G.g[v][index];
			// ��û�ж����v������, �򷵻�NULL
			return NULL;
		}

		// �鿴�Ƿ��Ѿ���������ͼG���붥��v�����ӵ����б�
		bool end() {
			return index >= G.V();
		}
	};

};
