//treegraph.cpp
#include <iostream>

#include "tree.h"

#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"

TEST_GROUP(Unit)
{

};

TEST(Unit, Test1)
{
    CHECK_TRUE(true);
}

int main (int argc, char *argv[])
{
    return RUN_ALL_TESTS(argc, argv);
}
