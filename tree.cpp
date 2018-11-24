//tree.cpp

#include "tree.h"

CNode::CNode()
    : _value(0)
    , _left(nullptr)
    , _right(nullptr)
{

}

CNode::~CNode()
{
    if (nullptr != _left)
    {
        delete _left;
        _left = nullptr; 
    }

    if (nullptr != _right)
    {
        delete _right;
        _right = nullptr; 
    }
}


int CNode::getValue()
{
    return _value; 
}

void CNode::setValue(int value)
{
    _value = value; 
}

CNode* CNode::getLeft()
{
    return _left; 
}

CNode* CNode::getRight()
{
    return _right; 
}

void CNode::setLeft(CNode* pNode)
{
    _left = pNode; 
}

void CNode::setRight(CNode* pNode)
{
    _right = pNode; 
}


CTree::CTree()
    : _root(nullptr)
{

}

CTree::~CTree()
{
    if(_root != nullptr)
    {
        delete _root;
        _root = nullptr; 
    }
}

CNode* CTree::getRoot()
{
    return _root;
}

void CTree::setRoot(CNode* node)
{
    _root = node; 
}