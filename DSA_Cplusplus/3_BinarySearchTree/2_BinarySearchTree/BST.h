#pragma once
#include <iostream>
#include <queue>
#include <cassert>

using namespace std;

// 二分搜索树
template <typename Key, typename Value>
class BST {

private:
	// 树中的节点为私有的结构体, 外界不需要了解二分搜索树节点的具体实现
	struct Node
	{
		Key key;
		Value value;
		Node* left;
		Node* right;

		Node(Key key, Value value) {
			this->key = key;
			this->value = value;
			this->left = NULL;
			this->right = NULL;
		}

		Node(Node* node) {
			this->key = node->key;
			this->value = node->value;
			this->left = node->left;
			this->right = node->right;
		}
	};

	Node* root;		// 根节点
	int count;		// 树中的节点个数

public:
	// 构造函数, 默认构造一棵空二分搜索树
	BST() {

	}

	// 析构函数, 释放二分搜索树的所有空间
	~BST() {

	}

	// 返回二分搜索树是否为空
	bool isEmpty() {

	}

	// 向二分搜索树中插入一个新的(key, value)数据对
	void insert(Key key, Value value) {

	}

	// 查看二分搜索树中是否存在键key
	bool contain(Key key) {

	}

	// 在二分搜索树中搜索键key所对应的值。如果这个值不存在, 则返回NULL
	Value* search(Key key) {

	}

	// 二分搜索树的前序遍历
	void preOrder() {

	}

	// 二分搜索树的中序遍历
	void inOrder() {

	}

	// 二分搜索树的后序遍历
	void postOrder() {

	}

	// 二分搜索树的层序遍历
	void levelOrder() {

	}

	// 寻找二分搜索树的最小的键值
	Key minimum() {

	}

	// 寻找二分搜索树的最大的键值
	Key maximum() {

	}

	// 从二分搜索树中删除最小值所在节点
	void removeMin() {

	}

	// 从二分搜索树中删除最大值所在节点
	void removeMax() {

	}

	// 从二分搜索树中删除键值为key的节点
	void remove(Key key) {

	}

private:
	// 向以node为根的二分搜索树中, 插入节点(key, value), 使用递归算法
	// 返回插入新节点后的二分搜索树的根
	Node* insert(Node* node, Key key, Value value) {

	}

	// 查看以node为根的二分搜索树中是否包含键值为key的节点, 使用递归算法
	bool contain(Node* node, Key key) {

	}

	// 在以node为根的二分搜索树中查找key所对应的value, 递归算法
	// 若value不存在, 则返回NULL
	Value* search(Node* node, Key key) {

	}

	// 对以node为根的二分搜索树进行前序遍历, 递归算法
	void preOrder(Node* node) {

	}

	// 对以node为根的二分搜索树进行中序遍历, 递归算法
	void inOrder(Node* node) {

	}

	// 对以node为根的二分搜索树进行后序遍历, 递归算法
	void postOrder(Node* node) {

	}

	// 释放以node为根的二分搜索树的所有节点
	// 采用后续遍历的递归算法
	void destory(Node* node) {

	}

	// 返回以node为根的二分搜索树的最小键值所在的节点, 递归算法
	Node* minimum(Node* node) {

	}

	// 返回以node为根的二分搜索树的最大键值所在的节点, 递归算法
	Node* maximum(Node* node) {

	}

	// 删除掉以node为根的二分搜索树中的最小节点, 递归算法
	// 返回删除节点后新的二分搜索树的根
	Node* removeMin(Node* node) {

	}

	// 删除掉以node为根的二分搜索树中的最大节点, 递归算法
	// 返回删除节点后新的二分搜索树的根
	Node* removeMax(Node* node) {

	}

	// 删除掉以node为根的二分搜索树中键值为key的节点, 递归算法
	// 返回删除节点后新的二分搜索树的根
	Node* remove(Node* node) {

	}
};

