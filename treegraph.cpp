//treegraph.cpp
#include <iostream>

#include "tree.h"

#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"

TEST_GROUP(UnitNode)
{

};

TEST(UnitNode, valueGetSet)
{
    CNode myNode;

    for(int i = -100; i < 100; ++i)
    {
        myNode.setValue(i);
        CHECK_EQUAL(i,myNode.getValue());
    }
}

TEST(UnitNode, leftGetSet)
{
    CNode array[100];
    CNode myNode; 
    for(int i= 0; i < 100; ++i)
    {
        myNode.setLeft(&(array[i]));
        CHECK_EQUAL(&(array[i]), myNode.getLeft());
    }
    myNode.setLeft(nullptr);
}

TEST(UnitNode, rightGetSet)
{
    CNode array[100];
    CNode myNode; 
    for(int i= 0; i < 100; ++i)
    {
        myNode.setRight(&(array[i]));
        CHECK_EQUAL(&(array[i]), myNode.getRight());
    }
    myNode.setRight(nullptr);
}

TEST_GROUP(UnitTree)
{

};

TEST(UnitTree, rootGetSet)
{
    CNode myNode; 
    CTree myTree;
    myTree.setRoot(&myNode);
    CHECK_EQUAL(&myNode, myTree.getRoot());
    myTree.setRoot(nullptr);
}



int main (int argc, char *argv[])
{
    return RUN_ALL_TESTS(argc, argv);
}
