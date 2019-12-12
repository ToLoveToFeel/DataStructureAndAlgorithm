#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include "BST.h"
#include "SequenceST.h"
#include "FileOps.h"

using namespace std;

// ʵ������������ľ�����
int main() {

	// ����ʹ���ı�����С�Ĺ����������Խ�������:)
	string filename = "communist.txt";
	vector<string> words;

	if (FileOps::readFile(filename, words)) {

		cout << "There are totally " << words.size() << " words in " << filename << endl;
		cout << endl;


		// ����1, ���ǰ����ı�ԭ��˳����������������
		time_t startTime = clock();
		BST<string, int>* bst = new BST<string, int>();
		for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
			int* res = (*bst).search(*iter);
			if (res == NULL)
				(*bst).insert(*iter, 1);
			else
				(*res)++;
		}

		// ���ǲ鿴uniteһ�ʵĴ�Ƶ
		if (bst->contain("unite"))
			cout << "'unite' : " << *(*bst).search("unite") << endl;
		else
			cout << "No word 'unite' in " + filename << endl;
		time_t endTime = clock();

		cout << "BST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
		cout << endl;

		delete bst;


		// ����2, ���ǰ����ı�ԭ��˳�����˳����ұ�
		startTime = clock();
		SequenceST<string, int>* sst = new SequenceST<string, int>();
		for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
			int* res = (*sst).search(*iter);
			if (res == NULL)
				(*sst).insert(*iter, 1);
			else
				(*res)++;
		}

		// ���ǲ鿴uniteһ�ʵĴ�Ƶ
		if (sst->contain("unite"))
			cout << "'unite' : " << *(*sst).search("unite") << endl;
		else
			cout << "No word 'unite' in " + filename << endl;
		endTime = clock();

		cout << "SST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
		cout << endl;

		delete sst;


		sort(words.begin(), words.end());

		// ����3, ���ǽ�ԭ�ı������������������, �鿴��Ч��
		startTime = clock();
		BST<string, int>* bst2 = new BST<string, int>();

		for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
			int* res = (*bst2).search(*iter);
			if (res == NULL)
				(*bst2).insert(*iter, 1);
			else
				(*res)++;
		}

		// ���ǲ鿴uniteһ�ʵĴ�Ƶ
		cout << "'unite' : " << *(*bst2).search("unite") << endl;
		endTime = clock();

		cout << "BST2 , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
		cout << endl;

		delete bst2;
	}

	return 0;
}