#include "UnionFindTestHelper.h"

int main(void) {

	int n = 1000000;

	//UnionFindTestHelper::testUF1(n);	//100k数据，7s左右
	//UnionFindTestHelper::testUF2(n);  //100k数据，7s左右
	UnionFindTestHelper::testUF3(n);  //1000k数据，0.569s左右
	UnionFindTestHelper::testUF4(n);  //1000k数据，0.565s左右
	UnionFindTestHelper::testUF5(n);  //1000k数据，0.514s左右
	UnionFindTestHelper::testUF6(n);  //1000k数据，0.539s左右

	return 0;
}