#include <iostream>
#include <ctime>
#include "DenseGraph.h"
#include "SparseGraph.h"
#include "ReadGraph.h"
#include "LazyPrimMST.h"
#include "PrimMST.h"

int main(void) {

	string filename = "testG1.txt";
	int V = 8;

	SparseGraph<double> g = SparseGraph<double>(V, false);
	ReadGraph<SparseGraph<double>, double> readGraph(g, filename);

	// Test Lazy Prim MST
	cout << "Test Lazy Prim MST:" << endl;
	LazyPrimMST<SparseGraph<double>, double> lazyPrimMST(g);
	vector<Edge<double>> mst = lazyPrimMST.mstEdges();
	for (int i = 0; i < mst.size(); i++)
		cout << mst[i] << endl;
	cout << "The MST weight is: " << lazyPrimMST.result() << endl;

	cout << endl;

	// Test Prim MST
	cout << "Test Prim MST:" << endl;
	PrimMST<SparseGraph<double>, double> primMST(g);
	mst = primMST.mstEdges();
	for (int i = 0; i < mst.size(); i++)
		cout << mst[i] << endl;
	cout << "The MST weight is: " << primMST.result() << endl;

	cout << endl;



	// 测试我们实现的两种Prim算法的性能差距
	// 可以看出这一节使用索引堆实现的Prim算法优于上一小节的Lazy Prim算法

	string filename1 = "testG1.txt";
	int V1 = 8;

	string filename2 = "testG2.txt";
	int V2 = 250;

	string filename3 = "testG3.txt";
	int V3 = 1000;

	string filename4 = "testG4.txt";
	int V4 = 10000;

	//    string filename5 = "testG5.txt";
	//    int V5 = 1000000;


		// 文件读取
	SparseGraph<double> g1 = SparseGraph<double>(V1, false);
	ReadGraph<SparseGraph<double>, double> readGraph1(g1, filename1);
	cout << filename1 << " load successfully." << endl;

	SparseGraph<double> g2 = SparseGraph<double>(V2, false);
	ReadGraph<SparseGraph<double>, double> readGraph2(g2, filename2);
	cout << filename2 << " load successfully." << endl;

	SparseGraph<double> g3 = SparseGraph<double>(V3, false);
	ReadGraph<SparseGraph<double>, double> readGraph3(g3, filename3);
	cout << filename3 << " load successfully." << endl;

	SparseGraph<double> g4 = SparseGraph<double>(V4, false);
	ReadGraph<SparseGraph<double>, double> readGraph4(g4, filename4);
	cout << filename4 << " load successfully." << endl;

	//    SparseGraph<double> g5 = SparseGraph<double>(V5, false);
	//    ReadGraph<SparseGraph<double>,double> readGraph5(g5, filename5);
	//    cout<<filename5<<" load successfully."<<endl;

	cout << endl;


	clock_t startTime, endTime;

	// Test Lazy Prim MST
	cout << "Test Lazy Prim MST:" << endl;

	startTime = clock();
	LazyPrimMST<SparseGraph<double>, double> lazyPrimMST1(g1);
	endTime = clock();
	cout << "Test for G1: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;

	startTime = clock();
	LazyPrimMST<SparseGraph<double>, double> lazyPrimMST2(g2);
	endTime = clock();
	cout << "Test for G2: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;

	startTime = clock();
	LazyPrimMST<SparseGraph<double>, double> lazyPrimMST3(g3);
	endTime = clock();
	cout << "Test for G3: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;

	startTime = clock();
	LazyPrimMST<SparseGraph<double>, double> lazyPrimMST4(g4);
	endTime = clock();
	cout << "Test for G4: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;

	//    startTime = clock();
	//    LazyPrimMST<SparseGraph<double>, double> lazyPrimMST5(g5);
	//    endTime = clock();
	//    cout<<"Test for G5: "<<(double)(endTime-startTime)/CLOCKS_PER_SEC<<" s."<<endl;

	cout << endl;


	// Test Prim MST
	cout << "Test Prim MST:" << endl;

	startTime = clock();
	PrimMST<SparseGraph<double>, double> PrimMST1(g1);
	endTime = clock();
	cout << "Test for G1: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;

	startTime = clock();
	PrimMST<SparseGraph<double>, double> PrimMST2(g2);
	endTime = clock();
	cout << "Test for G2: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;

	startTime = clock();
	PrimMST<SparseGraph<double>, double> PrimMST3(g3);
	endTime = clock();
	cout << "Test for G3: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;

	startTime = clock();
	PrimMST<SparseGraph<double>, double> PrimMST4(g4);
	endTime = clock();
	cout << "Test for G4: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;

	//    startTime = clock();
	//    PrimMST<SparseGraph<double>, double> PrimMST5(g5);
	//    endTime = clock();
	//    cout<<"Test for G5: "<<(double)(endTime-startTime)/CLOCKS_PER_SEC<<" s."<<endl;

	cout << endl;

	return 0;
}