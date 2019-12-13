#include "ReadGraph.h"
#include "DenseGraph.h"
#include "SparseGraph.h"
#include "Component.h"
#include "Path.h"
#include "ShortestPath.h"

int main(void) {

	// TestG1.txt
	// DenseGraph
	// ����ͼ - �ڽӾ���
	string filename1 = "testG1.txt";
	DenseGraph g1 = DenseGraph(13, false);
	ReadGraph<DenseGraph> readGraph1(g1, filename1);
	Component<DenseGraph> component1(g1);
	cout << "TestG1.txt, Component Count: " << component1.count() << endl;
	//g1.show();


	// TestG2.txt
	// SparseGraph
	// ϡ��ͼ - �ڽӱ�
	string filename2 = "testG2.txt";
	SparseGraph g2 = SparseGraph(7, false);
	ReadGraph<SparseGraph> readGraph2(g2, filename2);
	Component<SparseGraph> component2(g2);
	cout << "TestG2.txt, Component Count: " << component2.count() << endl;
	//g2.show();

	cout << endl;

	
	// ������ȱ���
	Component<DenseGraph> component(g1);
	cout << "Test Random Graph, Component Count: " << component.count() << endl;

	// ����Ѱ·�㷨
	Path<SparseGraph> dfs(g2, 0);
	cout << "DFS : ";
	dfs.showPath(6);

	// ���Թ�ȱ�������Ȩͼ���·��
	ShortestPath< SparseGraph> bfs(g2, 0);
	cout << "BFS : ";
	bfs.showPath(6);

	return 0;
}