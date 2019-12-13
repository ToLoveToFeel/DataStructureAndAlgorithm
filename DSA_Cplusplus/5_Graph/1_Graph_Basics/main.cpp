#include "ReadGraph.h"
#include "DenseGraph.h"

int main(void) {
	string filename = "testG2.txt";
	DenseGraph g = DenseGraph(7, false);
	ReadGraph<DenseGraph> readGraph(g, filename);
	g.show();

	return 0;
}