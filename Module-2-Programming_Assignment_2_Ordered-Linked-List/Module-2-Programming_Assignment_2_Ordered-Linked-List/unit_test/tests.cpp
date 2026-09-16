#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../orderedLinkedList.h"
using namespace std;

TEST(linkedListTest, Test1)
{
	testing::internal::CaptureStdout();
	OrderedLinkedList<int> ol;

	ol.insert(7);
	ol.insert(4);
	ol.insert(9);
	ol.insert(5);
	ol.insert(15);
	ol.insert(8);

	ol.print(std::cout);

	std::string output = testing::internal::GetCapturedStdout();
	cout << output << endl;
	bool match = output.c_str() == "4\n5\n7\n8\n9\n15\n" || output.c_str() == "4 5 7 8 9 15";
	ASSERT_THAT(output.c_str(), testing::MatchesRegex("4\\s*5\\s*7\\s*8\\s*9\\s*15\\s*"));
}

extern "C" int startTest(int x, char **y)
{
	// cout << "begin" << endl;
	// int x = 0;
	// char ** y = NULL;
	testing::InitGoogleTest(&x, y);
	// cout << "Init Complete"<< endl;
	int code = RUN_ALL_TESTS();
	// exit(code);
	return code;
}
// int i = startTest();
extern "C" int __wrap_main(int x, char **y)
{
	return startTest(x, y);
}