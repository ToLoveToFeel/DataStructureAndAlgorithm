#pragma once
#include <iostream>
#include <queue>
#include <cassert>

using namespace std;

// ����������
template <typename Key, typename Value>
class BST {

private:
	// ���еĽڵ�Ϊ˽�еĽṹ��, ��粻��Ҫ�˽�����������ڵ�ľ���ʵ��
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

	Node* root;		// ���ڵ�
	int count;		// ���еĽڵ����

public:
	// ���캯��, Ĭ�Ϲ���һ�ÿն���������
	BST() {
		root = NULL;
		count = 0;
	}

	// ��������, �ͷŶ��������������пռ�
	~BST() {
		destory(root);
	}

	// ���ض����������Ľڵ����
	int size() {
		return count;
	}

	// ���ض����������Ƿ�Ϊ��
	bool isEmpty() {
		return 0 == count;
	}

	// ������������в���һ���µ�(key, value)���ݶ�
	void insert(Key key, Value value) {
		root = insert(root, key, value);
	}

	// �鿴�������������Ƿ���ڼ�key
	bool contain(Key key) {
		return contain(root, key);
	}

	// �ڶ�����������������key����Ӧ��ֵ��������ֵ������, �򷵻�NULL
	Value* search(Key key) {
		return search(root, key);
	}

	// ������������ǰ�����
	void preOrder() {
		preOrder(root);
	}

	// �������������������
	void inOrder() {
		inOrder(root);
	}

	// �����������ĺ������
	void postOrder() {
		postOrder(root);
	}

	// �����������Ĳ������
	void levelOrder() {
		if (NULL == root)
			return;
		
		queue<Node*> q;
		q.push(root);
		while (!q.empty())
		{
			Node* node = q.front();
			q.pop();

			cout << node->key << endl;

			if (node->left)
				q.push(node->left);
			if (node->right)
				q.push(node->right);
		}
	}

	// Ѱ�Ҷ�������������С�ļ�ֵ
	Key minimum() {
		assert(count > 0);
		Node* node = minimum(root);
		return node->key;
	}

	// Ѱ�Ҷ��������������ļ�ֵ
	Key maximum() {
		assert(count > 0);
		Node* node = maximum(root);
		return node->key;
	}

	// �Ӷ�����������ɾ����Сֵ���ڽڵ�
	void removeMin() {
		if (root)
			root = removeMin(root);
	}

	// �Ӷ�����������ɾ�����ֵ���ڽڵ�
	void removeMax() {
		if (root)
			root = removeMax(root);
	}

	// �Ӷ�����������ɾ����ֵΪkey�Ľڵ�
	void remove(Key key) {
		root = remove(root, key);
	}

private:
	// ����nodeΪ���Ķ�����������, ����ڵ�(key, value), ʹ�õݹ��㷨
	// ���ز����½ڵ��Ķ����������ĸ�
	Node* insert(Node* node, Key key, Value value) {
		if (NULL == node) {
			count++;
			return new Node(key, value);
		}

		if (key == node->key)
			node->value = value;
		else if (key > node->key)
			node->right = insert(node->right, key, value);
		else
			node-> left = insert(node->left, key, value);

		return node;
	}

	// �鿴��nodeΪ���Ķ������������Ƿ������ֵΪkey�Ľڵ�, ʹ�õݹ��㷨
	bool contain(Node* node, Key key) {
		if (NULL == node)
			return false;

		if (key == node->key)
			return true;
		else if (key > node->key)
			return contain(node->right, key);
		else
			return contain(node->left, key);
	}

	// ����nodeΪ���Ķ����������в���key����Ӧ��value, �ݹ��㷨
	// ��value������, �򷵻�NULL
	Value* search(Node* node, Key key) {
		if (NULL == node)
			return NULL;

		if (key == node->key)
			return &(node->value);
		else if (key > node->key)
			return search(node->right, key);
		else
			return search(node->left, key);
	}

	// ����nodeΪ���Ķ�������������ǰ�����, �ݹ��㷨
	void preOrder(Node* node) {
		if (NULL != node)
		{
			cout << node->key << endl;
			preOrder(node->left);
			preOrder(node->right);
		}
	}

	// ����nodeΪ���Ķ��������������������, �ݹ��㷨
	void inOrder(Node* node) {
		if (NULL != node)
		{
			inOrder(node->left);
			cout << node->key << endl;
			inOrder(node->right);
		}
	}

	// ����nodeΪ���Ķ������������к������, �ݹ��㷨
	void postOrder(Node* node) {
		if (NULL != node)
		{
			postOrder(node->left);
			postOrder(node->right);
			cout << node->key << endl;
		}
	}

	// �ͷ���nodeΪ���Ķ��������������нڵ�
	// ���ú��������ĵݹ��㷨
	void destory(Node* node) {
		if (NULL != node)
		{
			destory(node->left);
			destory(node->right);
			delete node;
			count--;
		}
	}

	// ������nodeΪ���Ķ�������������С��ֵ���ڵĽڵ�, �ݹ��㷨
	Node* minimum(Node* node) {
		if (NULL == node->left)
			return node;

		return minimum(node->left);
	}

	// ������nodeΪ���Ķ���������������ֵ���ڵĽڵ�, �ݹ��㷨
	Node* maximum(Node* node) {
		if (NULL == node->right)
			return node;

		return maximum(node->right);
	}

	// ɾ������nodeΪ���Ķ����������е���С�ڵ�, �ݹ��㷨
	// ����ɾ���ڵ���µĶ����������ĸ�
	Node* removeMin(Node* node) {
		if (NULL == node->left) {
			Node* rightNode = node->right;
			delete node;
			count--;
			return rightNode;
		}

		node->left = removeMin(node->left);
		return node;
	}

	// ɾ������nodeΪ���Ķ����������е����ڵ�, �ݹ��㷨
	// ����ɾ���ڵ���µĶ����������ĸ�
	Node* removeMax(Node* node) {
		if (NULL == node->right)
		{
			Node* leftNode = node->left;
			delete node;
			count--;
			return leftNode;
		}

		node->right = removeMax(node->right);
		return node;
	}

	// ɾ������nodeΪ���Ķ����������м�ֵΪkey�Ľڵ�, �ݹ��㷨
	// ����ɾ���ڵ���µĶ����������ĸ�
	Node* remove(Node* node, Key key) {
		if (NULL == node)
			return NULL;

		if (key < node->key)
			node->left = remove(node->left, key);
		else if (key > node->key)
			node->right = remove(node->right, key);
		else  // key == node->key
		{
			if (NULL == node->left) {
				Node* rightNode = node->right;
				delete node;
				count--;
				return rightNode;
			}
			else if (NULL == node->right) {
				Node* leftNode = node->left;
				delete node;
				count--;
				return leftNode;
			}
			else {
				// ��ɾ���ڵ�������������Ϊ�յ����
				// �ҵ��ȴ�ɾ���ڵ�����С�ڵ�, ����ɾ���ڵ�����������С�ڵ�
				// ������ڵ㶥���ɾ���ڵ��λ��

				Node* successor = new Node(minimum(node->right));
				count++;
				
				successor->right = removeMin(node->right);
				successor->left = node->left;

				delete node;
				count--;

				return successor;
			}
		}
	}
};

