#pragma once

#include <iostream>
#include <cassert>

using namespace std;

// ���ǵĵ��İ�Union-Find
// ��UF4�Ļ����� ������һ��·��ѹ��
namespace UF6 {
	class UnionFind
	{
	private:
		// ���ǵĵڶ���Union-Find, ʹ��һ�����鹹��һ��ָ�򸸽ڵ����
		// parent[i]��ʾ��һ��Ԫ����ָ��ĸ��ڵ�
		int* parent;
		// rank[i]��ʾ��iΪ���ļ�������ʾ�����Ĳ���
		// �ں����Ĵ�����, ���ǲ�����ά��rank������, Ҳ����rank��ֵ��·��ѹ���Ĺ�����, �п��ܲ��������Ĳ���ֵ
		// ��Ҳ�����ǵ�rank����height����depth��ԭ��, ��ֻ����Ϊ�Ƚϵ�һ����׼
		int* rank;
		int count;	// ���ݸ���

	public:
		UnionFind(int n);
		~UnionFind();

		// ���ҹ���, ����Ԫ��p����Ӧ�ļ��ϱ��
		int find(int p);

		// �鿴Ԫ��p��Ԫ��q�Ƿ�����һ������
		// O(1)���Ӷ�
		bool isConnected(int p, int q);

		// �ϲ�Ԫ��p��Ԫ��q�����ļ���
		// O(n) ���Ӷ�
		void unionElements(int p, int q);

	};

	UnionFind::UnionFind(int  n) {
		count = n;

		parent = new int[n];
		rank = new int[n];
		// ��ʼ��, ÿһ��id[i]ָ���Լ�, û�кϲ���Ԫ��
		for (int i = 0; i < n; i++) {
			parent[i] = i;
			rank[i] = 1;
		}

	}

	UnionFind::~UnionFind() {
		delete[] parent;
		delete[] rank;
	}

	// �ݹ��㷨�����ص���p�ĸ��ڵ�
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

		// ��������Ԫ����������Ԫ�ظ�����ͬ�жϺϲ�����
		// ��Ԫ�ظ����ٵļ��Ϻϲ���Ԫ�ظ�����ļ�����
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
