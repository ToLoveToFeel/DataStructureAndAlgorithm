#include <iostream>
#include "SparseGraph.h"
#include "DenseGraph.h"
#include "ReadGraph.h"
#include "Dijkstra.h"
#include "BellmanFord.h"

using namespace std;


int main() {

	// 测试我们的Dijkstra最短路径算法
	string filename = "testG1.txt";
	int V = 5;

	SparseGraph<int> g = SparseGraph<int>(V, true);
	// Dijkstra最短路径算法同样适用于有向图
	//SparseGraph<int> g = SparseGraph<int>(V, false);
	ReadGraph<SparseGraph<int>, int> readGraph(g, filename);

	cout << "Test Dijkstra:" << endl << endl;
	Dijkstra<SparseGraph<int>, int> dij(g, 0);
	for (int i = 0; i < V; i++) {
		if (dij.hasPathTo(i)) {
			cout << "Shortest Path to " << i << " : " << dij.shortestPathTo(i) << endl;
			dij.showPath(i);
		}
		else
			cout << "No Path to " << i << endl;

		cout << "----------" << endl;
	}
	cout << endl << endl;



	// 测试Bellman-Ford算法
	string filename2 = "testG2.txt";
	//string filename2 = "testG_negative_circle.txt";
	int V2 = 5;

	SparseGraph<int> g2 = SparseGraph<int>(V2, true);
	ReadGraph<SparseGraph<int>, int> readGraph2(g2, filename2);

	cout << "Test Bellman-Ford:" << endl << endl;

	int s = 0;
	BellmanFord<SparseGraph<int>, int> bellmanFord(g2, s);
	if (bellmanFord.negativeCycle())
		cout << "The graph contain negative cycle!" << endl;
	else
		for (int i = 0; i < V2; i++) {
			if (i == s)
				continue;

			if (bellmanFord.hasPathTo(i)) {
				cout << "Shortest Path to " << i << " : " << bellmanFord.shortestPathTo(i) << endl;
				bellmanFord.showPath(i);
			}
			else
				cout << "No Path to " << i << endl;

			cout << "----------" << endl;
		}

	return 0;
}