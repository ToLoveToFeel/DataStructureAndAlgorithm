#include "UnionFindTestHelper.h"

int main(void) {

	int n = 1000000;

	//UnionFindTestHelper::testUF1(n);	//100k���ݣ�7s����
	//UnionFindTestHelper::testUF2(n);  //100k���ݣ�7s����
	UnionFindTestHelper::testUF3(n);  //1000k���ݣ�0.569s����
	UnionFindTestHelper::testUF4(n);  //1000k���ݣ�0.565s����
	UnionFindTestHelper::testUF5(n);  //1000k���ݣ�0.514s����
	UnionFindTestHelper::testUF6(n);  //1000k���ݣ�0.539s����

	return 0;
}