
#include <iostream>
#include "gtest/gtest.h"

//#ifdef _DEBUG  
//#pragma comment(lib, "gtestd.lib")  
//#pragma comment(lib, "gtest_maind.lib")  
//#else  
//#pragma comment(lib, "gtest.lib")  
//#pragma comment(lib, "gtest_main.lib")   
//#endif


int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();

	getchar();
	return 0;
}