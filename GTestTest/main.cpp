
#include <iostream>
#include <string>
#include "gtest/gtest.h"

//#ifdef _DEBUG  
//#pragma comment(lib, "gtestd.lib")  
//#pragma comment(lib, "gtest_maind.lib")  
//#else  
//#pragma comment(lib, "gtest.lib")  
//#pragma comment(lib, "gtest_main.lib")   
//#endif

int Power(int value)
{
	return value * value;
}

const char *GetBuffer(std::string &str)
{
	return str.c_str();
}

std::string g_str("global string");
std::string g_upstr("GLOBAL sTring");

TEST(ExpectTest, Expect)
{
	// expect equal
	EXPECT_EQ(4, Power(2)); 
	// expect not equal
	EXPECT_NE(5, Power(-3));
	// expect boolean true
	EXPECT_TRUE(Power(-5) > 0);
	// expect boolean false
	EXPECT_FALSE(3 == Power(3));

	// expect string equal
	EXPECT_STREQ(g_str.c_str(), GetBuffer(g_str));
	// expect string not equal
	EXPECT_STRNE(NULL, GetBuffer(g_str));
	// expect string case equal
	EXPECT_STRCASEEQ(g_str.c_str(), GetBuffer(g_str));
	// expect string case not equal
	EXPECT_STRCASEEQ(g_str.c_str(), GetBuffer(g_upstr));
}



int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();

	getchar();
	return 0;
}