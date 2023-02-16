//
// Created by Lucien Van Bussel on 1/18/23.
//

#include "./unity/src/unity.h"
#include "./pipex.h"

void setUp(void) {
	// set stuff up here
}

void tearDown(void) {
	// clean stuff up here
}

void test_input_parsing()
{
	int argc = 4;
	char **argv = NULL;
	TEST_ASSERT_EQUAL(false, p_input_parsing(argc, argv));

	argc = 5;
	TEST_ASSERT_EQUAL(true, p_input_parsing(argc, argv));

	argc = 6;
	TEST_ASSERT_EQUAL(false, p_input_parsing(argc, argv));
}

int main(void) {
	UNITY_BEGIN();
	RUN_TEST(test_input_parsing);
	return UNITY_END();
}