#include "ReadGraph.h"
#include "DenseGraph.h"
#include "SparseGraph.h"

int main(void) {
	string filename = "testG2.txt";
	DenseGraph g = DenseGraph(7, false);
	ReadGraph<DenseGraph> readGraph(g, filename);
	g.show();

	cout << endl;

	SparseGraph g2 = SparseGraph(7, false);
	ReadGraph<SparseGraph> readGraph2(g2, filename);
	g2.show();
	

	return 0;
}