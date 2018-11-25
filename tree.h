//tree.h

// implmentation of a binary search tree. Perhaps an AVL or Red Black tree or LLRT?  
// At some point I'll get stuck and look up the answers and learn.  I've got a copy
// of Sedgewick around here someplace.  I should go find it. 


//forware Declaration
class CNode;


class CNodeVisitor
{
public:
    virtual void visit(CNode* node) = 0;
};

class OutputNodeVisitor : public CNodeVisitor
{
public:
    virtual void visit(CNode* node) override;
};

class CNode
{
public: 
    CNode();
    ~CNode();


    int getValue();
    void setValue(int value);

    CNode* getLeft();
    CNode* getRight();
    void setLeft(CNode *pNode);
    void setRight(CNode *pNode);

    void insert(CNode *pNode);

    void accept(CNodeVisitor *pVisitor);

private:
    int _value;
    CNode* _left;
    CNode* _right;
};


class CTree
{
public:
    CTree();
    ~CTree();
    CNode* getRoot();
    void setRoot(CNode *node);
    void insert(CNode *node);
private:
    CNode *_root;
};

