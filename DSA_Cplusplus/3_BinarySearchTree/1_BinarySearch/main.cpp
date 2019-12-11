#include "binarySearch.h"

// �ȽϷǵݹ�͵ݹ�д���Ķ��ֲ��ҵ�Ч��
// �ǵݹ��㷨����������΢������
int main(void) {

	int n = 1000000;
	int* a = new int[n];
	for (int i = 0; i < n; i++)
		a[i] = i;

	// ���Էǵݹ���ֲ��ҷ�
	clock_t startTime = clock();

	// �������ǵĴ���������[0...N)
	// ��[0...N)�������ֵʹ�ö��ֲ��ң����ս��Ӧ�þ������ֱ���
	// ��[N...2*N)�������ֵʹ�ö��ֲ��ң���Ϊ��Щ���ֲ���arr�У����Ϊ-1
	for (int i = 0; i < 2 * n; i++) {
		int v = binarySearch(a, n, i);
		if (i < n)
			assert(v == i);
		else
			assert(v == -1);
	}
	clock_t endTime = clock();
	cout << "Binary Search (Without Recursion): " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;


	// ���Եݹ�Ķ��ֲ��ҷ�
	startTime = clock();

	// �������ǵĴ���������[0...N)
	// ��[0...N)�������ֵʹ�ö��ֲ��ң����ս��Ӧ�þ������ֱ���
	// ��[N...2*N)�������ֵʹ�ö��ֲ��ң���Ϊ��Щ���ֲ���arr�У����Ϊ-1
	for (int i = 0; i < 2 * n; i++) {
		int v = binarySearch2(a, n, i);
		if (i < n)
			assert(v == i);
		else
			assert(v == -1);
	}
	endTime = clock();
	cout << "Binary Search (Recursion): " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;

	delete[] a;

	return 0;
}