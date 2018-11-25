//tree.cpp
#include <iostream>
#include "tree.h"

void OutputNodeVisitor::visit(CNode* node) 
{
    std::cout << node->getValue() << std::endl;
}

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

void CNode::insert(CNode *pNode)
{
    // Check that we aren't going to dereference a null pointer. 
    if (pNode == nullptr)
    { 
        return;
    }

    if (pNode->getValue() < _value)
    {
        // on the left!
        if (_left == nullptr)
        {
            _left = pNode;
        }
        else
        {
            _left->insert(pNode);
        }
    }
    else 
    {
        // on the right!
        if (_right == nullptr)
        {
            _right = pNode;
        }
        else
        {
            _right->insert(pNode);
        }

    }

    return;
}


void CNode::accept(CNodeVisitor *pVisitor)
{
    if(_left != nullptr)
    {
        _left->accept(pVisitor);
    }

    pVisitor->visit(this);

    if(_right != nullptr)
    {
        _right->accept(pVisitor);
    }

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

void CTree::insert(CNode *node)
{
    if (_root == nullptr)
    {
        _root = node;
    }
    else{
        _root->insert(node);
    }

    return;
}