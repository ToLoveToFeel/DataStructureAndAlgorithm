#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cassert>

using namespace std;

// ��ȡ��Ȩͼ��
template <typename Graph, typename Weight>
class ReadGraph {

public:
	// ���ļ�filename�ж�ȡ��Ȩͼ����Ϣ, �洢��ͼgraph��
	ReadGraph(Graph& graph, const string& filename) {

		ifstream file(filename);
		string line;
		int V, E;

		assert(file.is_open());

		// ��һ�ж�ȡͼ�еĽڵ�����ͱߵĸ���
		assert(getline(file, line));
		stringstream ss(line);
		ss >> V >> E;
		assert(graph.V() == V);

		// ��ȡÿһ���ߵ���Ϣ
		for (int i = 0; i < E; i++) {
			assert(getline(file, line));
			stringstream ss(line);

			int a, b;
			Weight w;
			ss >> a >> b >> w;
			assert(a >= 0 && a < V);
			assert(b >= 0 && b < V);
			graph.addEdge(a, b, w);
		}

	}
};