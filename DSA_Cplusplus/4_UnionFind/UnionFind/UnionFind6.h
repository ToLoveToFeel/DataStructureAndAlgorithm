#pragma once

#include <iostream>
#include <cassert>

using namespace std;

// 我们的第四版Union-Find
// 在UF4的基础上 增加另一种路径压缩
namespace UF6 {
	class UnionFind
	{
	private:
		// 我们的第二版Union-Find, 使用一个数组构建一棵指向父节点的树
		// parent[i]表示第一个元素所指向的父节点
		int* parent;
		// rank[i]表示以i为根的集合所表示的树的层数
		// 在后续的代码中, 我们并不会维护rank的语意, 也就是rank的值在路径压缩的过程中, 有可能不在是树的层数值
		// 这也是我们的rank不叫height或者depth的原因, 他只是作为比较的一个标准
		int* rank;
		int count;	// 数据个数

	public:
		UnionFind(int n);
		~UnionFind();

		// 查找过程, 查找元素p所对应的集合编号
		int find(int p);

		// 查看元素p和元素q是否所属一个集合
		// O(1)复杂度
		bool isConnected(int p, int q);

		// 合并元素p和元素q所属的集合
		// O(n) 复杂度
		void unionElements(int p, int q);

	};

	UnionFind::UnionFind(int  n) {
		count = n;

		parent = new int[n];
		rank = new int[n];
		// 初始化, 每一个id[i]指向自己, 没有合并的元素
		for (int i = 0; i < n; i++) {
			parent[i] = i;
			rank[i] = 1;
		}

	}

	UnionFind::~UnionFind() {
		delete[] parent;
		delete[] rank;
	}

	// 递归算法，返回的是p的根节点
	int UnionFind::find(int p) {
		assert(p >= 0 && p < count);

		if (p != parent[p])
			parent[p] = find(parent[p]);

		return parent[p];
	}

	bool UnionFind::isConnected(int p, int q) {
		return find(p) == find(q);
	}

	void UnionFind::unionElements(int p, int q) {
		int pRoot = find(p);
		int qRoot = find(q);

		if (pRoot == qRoot)
			return;

		// 根据两个元素所在树的元素个数不同判断合并方向
		// 将元素个数少的集合合并到元素个数多的集合上
		if (rank[pRoot] < rank[qRoot]) {
			parent[pRoot] = qRoot;
		}
		else if (rank[pRoot] > rank[qRoot]) {
			parent[qRoot] = pRoot;
		}
		else { // rank[pRoot] == rank[qRoot]
			parent[pRoot] = qRoot;
			rank[qRoot] += 1;
		}

	}
}
