#pragma once

#include <iostream>
#include <cassert>

using namespace std;

// 我们的第二版Union-Find
// 思路和UF1完全不同
namespace UF2 {
	class UnionFind
	{
	private:
		// 我们的第二版Union-Find, 使用一个数组构建一棵指向父节点的树
		// parent[i]表示第一个元素所指向的父节点
		int* parent;
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
		// 初始化, 每一个id[i]指向自己, 没有合并的元素
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}

	UnionFind::~UnionFind() {
		delete[] parent;
	}

	int UnionFind::find(int p) {
		assert(p >= 0 && p < count);
		
		// 不断去查询自己的父亲节点, 直到到达根节点
		// 根节点的特点: parent[p] == p
		while (p != parent[p])
			p = parent[p];
		return p;
	}

	bool UnionFind::isConnected(int p, int q) {
		return find(p) == find(q);
	}

	void UnionFind::unionElements(int p, int q) {
		int pRoot = find(p);
		int qRoot = find(q);

		if (pRoot == qRoot)
			return;

		parent[pRoot] = qRoot;
	}
}
