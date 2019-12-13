#pragma once


#include <iostream>
#include <vector>
#include <cassert>


using namespace std;

// ����ͼ - �ڽӾ���
class DenseGraph {

private:
	int n, m;		// �ڵ����ͱ���
	bool directed;	// �Ƿ�Ϊ����ͼ
	vector<vector<bool>> g;	// ͼ�ľ�������

public:
	// ���캯��
	DenseGraph(int n, bool directed) {
		this->n = n;
		this->m = 0;
		this->directed = directed;
		// g��ʼ��Ϊn*n�Ĳ�������, ÿһ��g[i][j]��Ϊfalse, ��ʾû���κͱ�
		g = vector<vector<bool>>(n, vector<bool>(n, false));
	}

	// ��������
	~DenseGraph() { }

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
		if (hasEdge(v, w))
			return;

		g[v][w] = true;
		if (!directed)
			g[w][v] = true;

		m++;
	}

	// ��֤ͼ���Ƿ��д�v��w�ı�
	bool hasEdge(int v, int w) {
		assert(v >= 0 && v < n);
		assert(w >= 0 && w < n);

		return g[v][w];
	}

	// ��ʾͼ����Ϣ
	void show() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cout << g[i][j] << "\t";
			cout << "\n";
		}
	}

	// �ڱߵ�����, ����һ��ͼ��һ������,
	// ���������ͼ�к�����������������ж���
	class adjIterator {
	private:
		DenseGraph& G;
		int v;
		int index;

	public:
		// ���캯��
		adjIterator(DenseGraph& graph, int v): G(graph) {
			this->v = v;
			index = -1;
		}

		~adjIterator() {}

		// ����ͼG���붥��v�����ӵĵ�һ������
		int begin() {
			// ������-1��ʼ, ��Ϊÿ�α�������Ҫ����һ��next()
			index = -1;
			return next();
		}
		
		// ����ͼG���붥��v�����ӵ���һ������
		int next() {
			for (index += 1; index < G.V(); index++)
				if (G.g[v][index])
					return index;
			// �ӵ�ǰindex��ʼ�������, ֱ���ҵ�һ��g[v][index]Ϊtrue
			return -1;
		}

		// �鿴�Ƿ��Ѿ���������ͼG���붥��v�����ӵ����ж���
		bool end() {
			return index >= G.V();
		}
	};
};



