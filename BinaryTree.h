#include <stdio.h>

//重建二叉树
struct BinaryTreeNode
{
    int                 m_nValue;
    BinaryTreeNode*     m_pLeft;
    BinaryTreeNode*     m_pRight;
};

BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder)
{
    int rootValue = startPreorder[0];   //前序遍历的第一个值是根节点
    BinaryTreeNode *root = new BinaryTreeNode();
    root->m_nValue = rootValue;
    root->m_pLeft = root->m_pRight = nullptr;
    if(startPreorder == endPreorder)
    {
        if(startInorder == endPreorder && *startPreorder == *startInorder)
            return root;
        else
            throw std::exception("Invalid input");
    }
    int *rootInorder = startInorder;
    while(rootInorder <= endInorder && *rootInorder != rootValue)
        ++rootInorder;
    if(rootInorder == endInorder && *rootInorder != rootValue)
        throw std::exception("Invalid input.")
    int leftLength = rootInorder - startInorder;
    int *leftPreorderEnd = startPreorder + leftLength;
    if(leftLength > 0)
    {
        root->m_pLeft = ConstructCore(startPreorder +1, leftPreorderEnd,startInorder, rootInorder);
    }
    if(leftLength <endPreorder - startPreorder)
    {
        root->m_pRight = ConstructCore(leftPreorderEnd+1,endPreorder, rootInorder+1, endInorder);
    }
    return root;
}

BinaryTreeNode *Construct(int *preorder, int * inorder, int length)
{
    if(preorder == nullptr || inorder == nullptr || length <=0)
        return nullptr;
    return ConstructCore(preorder, preorder+length-1, inorder, inorder+length -1);
}

