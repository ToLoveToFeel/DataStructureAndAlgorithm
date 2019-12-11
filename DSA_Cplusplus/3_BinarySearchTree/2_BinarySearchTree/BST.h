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

	}

	// ��������, �ͷŶ��������������пռ�
	~BST() {

	}

	// ���ض����������Ƿ�Ϊ��
	bool isEmpty() {

	}

	// ������������в���һ���µ�(key, value)���ݶ�
	void insert(Key key, Value value) {

	}

	// �鿴�������������Ƿ���ڼ�key
	bool contain(Key key) {

	}

	// �ڶ�����������������key����Ӧ��ֵ��������ֵ������, �򷵻�NULL
	Value* search(Key key) {

	}

	// ������������ǰ�����
	void preOrder() {

	}

	// �������������������
	void inOrder() {

	}

	// �����������ĺ������
	void postOrder() {

	}

	// �����������Ĳ������
	void levelOrder() {

	}

	// Ѱ�Ҷ�������������С�ļ�ֵ
	Key minimum() {

	}

	// Ѱ�Ҷ��������������ļ�ֵ
	Key maximum() {

	}

	// �Ӷ�����������ɾ����Сֵ���ڽڵ�
	void removeMin() {

	}

	// �Ӷ�����������ɾ�����ֵ���ڽڵ�
	void removeMax() {

	}

	// �Ӷ�����������ɾ����ֵΪkey�Ľڵ�
	void remove(Key key) {

	}

private:
	// ����nodeΪ���Ķ�����������, ����ڵ�(key, value), ʹ�õݹ��㷨
	// ���ز����½ڵ��Ķ����������ĸ�
	Node* insert(Node* node, Key key, Value value) {

	}

	// �鿴��nodeΪ���Ķ������������Ƿ������ֵΪkey�Ľڵ�, ʹ�õݹ��㷨
	bool contain(Node* node, Key key) {

	}

	// ����nodeΪ���Ķ����������в���key����Ӧ��value, �ݹ��㷨
	// ��value������, �򷵻�NULL
	Value* search(Node* node, Key key) {

	}

	// ����nodeΪ���Ķ�������������ǰ�����, �ݹ��㷨
	void preOrder(Node* node) {

	}

	// ����nodeΪ���Ķ��������������������, �ݹ��㷨
	void inOrder(Node* node) {

	}

	// ����nodeΪ���Ķ������������к������, �ݹ��㷨
	void postOrder(Node* node) {

	}

	// �ͷ���nodeΪ���Ķ��������������нڵ�
	// ���ú��������ĵݹ��㷨
	void destory(Node* node) {

	}

	// ������nodeΪ���Ķ�������������С��ֵ���ڵĽڵ�, �ݹ��㷨
	Node* minimum(Node* node) {

	}

	// ������nodeΪ���Ķ���������������ֵ���ڵĽڵ�, �ݹ��㷨
	Node* maximum(Node* node) {

	}

	// ɾ������nodeΪ���Ķ����������е���С�ڵ�, �ݹ��㷨
	// ����ɾ���ڵ���µĶ����������ĸ�
	Node* removeMin(Node* node) {

	}

	// ɾ������nodeΪ���Ķ����������е����ڵ�, �ݹ��㷨
	// ����ɾ���ڵ���µĶ����������ĸ�
	Node* removeMax(Node* node) {

	}

	// ɾ������nodeΪ���Ķ����������м�ֵΪkey�Ľڵ�, �ݹ��㷨
	// ����ɾ���ڵ���µĶ����������ĸ�
	Node* remove(Node* node) {

	}
};

