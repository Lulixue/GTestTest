
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

////////////////////////////////////////////////////
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

void Foo()
{
	int *pInt = NULL;
	fprintf(stderr, "Foo death at: %d", __LINE__);
	*pInt = 42;
	_exit(1);
}


TEST(ExpectTest, Expect)
{
	// expect equal
	EXPECT_EQ(4, Power(2)); 
	// expect not equal
	EXPECT_NE(5, Power(-3));
	// expect greater than
	EXPECT_GT(17, Power(4));
	// expect greater or equal
	EXPECT_GE(16, Power(4));
	// expect less or equal
	EXPECT_LE(15, Power(4));
	// expect less
	EXPECT_LT(14, Power(4));


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
// 系统优化运行test_case_name中包含DeathTest的测试实例
TEST(FooDeathTest, Demo)
{
	EXPECT_EXIT(_exit(1), testing::ExitedWithCode(1), "");
	/* 
	 "    Result: died but not with expected exit code:\n"
	 "            " << ExitSummary(status()) << "\n"
	 "Actual msg:\n" << FormatDeathTestOutput(error_message);
	*/
	//EXPECT_DEATH(Foo(), "Foo death at: .*");
}

////////////////////////////////////////////////////
class FixtureTest : public testing::Test 
{
protected:
	FixtureTest() : m_a(0), m_b(1) {}

	void SetUp() {
		m_a++;  
		m_b--;
		m_strStatus = "setup";
	}

	int m_a;
	int m_b;
	std::string m_strStatus;
};

TEST_F(FixtureTest, TestSetup)
{
	EXPECT_EQ(m_a, 1);
	EXPECT_FALSE(m_a == m_b);
	EXPECT_STREQ("setup", m_strStatus.c_str());
}
///////////////////////////////////////////////

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();

	getchar();
	return 0;
}