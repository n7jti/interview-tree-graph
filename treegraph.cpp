//treegraph.cpp
#include <iostream>
#include <queue>

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

TEST(UnitTree, Insert)
{
    CTree myTree;
    for(int i = 0; i < 10; ++i)
    {

    }
}

class CQueueVisitor : public CNodeVisitor
{
public:
    virtual void visit(CNode* node) override
    {
        _queue.push(node->getValue());
    }

    std::queue<int> &getQueue()
    {
        return _queue;
    }
private:
    std::queue<int> _queue;

};

TEST(UnitTree, Traverse)
{

    int array[10] = {0,1,4,3,2,5,9,8,6,7};
    
    CTree myTree;

    for (int i = 0; i < 10; ++i)
    {
        CNode* pNode = nullptr; 
        pNode = new CNode();
        pNode->setValue(array[i]);

        myTree.insert(pNode);
    }

    CQueueVisitor vis;

    // check that an inorder traversal gives an ordered output. 
    myTree.getRoot()->accept(&vis); 
    int old = INT_MIN;
    int cur = INT_MIN;
    while(!(vis.getQueue().empty()))
    {
        int cur = vis.getQueue().front();
        vis.getQueue().pop();
        CHECK_COMPARE(cur, >=, old);

        old = cur; 
    }

    return;
}

int main (int argc, char *argv[])
{
    return RUN_ALL_TESTS(argc, argv);
}
