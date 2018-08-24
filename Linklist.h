#include <stdio.h>
#include <stack>
using namespace std;

struct ListNode{
    int         m_nValue;
    ListNode    *m_pNext;
    ListNode(int val):m_nValue(val),m_pNext(nullptr){}
};

void AddToTail(ListNode **pHead, int value)
{
    ListNode *pNew = new ListNode(value);
    if(*pHead == nullptr)
    {
        *pHead = pNew;
    }
    else
    {
        ListNode *Node = *pHead;
        while(Node->m_pNext != nullptr)
        {
            Node = Node->m_pNext;
        }
        Node->m_pNext = pNew;
    }

}

// 找到含有第一个某值的节点并删除
void RemoveNode(ListNode **pHead, int value)
{
    if(pHead ==nullptr || *pHead == nullptr)
        return;
    ListNode *pToDelete = nullptr;
    if((*pHead)->m_nValue == value)
    {
        pToDelete = *pHead;
        *pHead = (*pHead)->m_pNext;
    }
    else
    {
        ListNode *pNode = *pHead;
        while(pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue != value)   //当前节点的下一个节点是否符合
            pNode = pNode->m_pNext;
        
        if(pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue == value)
        {
            pToDelete = pNode->m_pNext;                 // drop,D: A->B->"C"->(D)->E, current node:C
            pNode->m_pNext = pNode->m_pNext->m_pNext;   //A->B->"C"->E->E, A->B->"C"->E, done
        }
        if(pToDelete != nullptr)        //free this node
        {
            delete pToDelete;
            pToDelete = nullptr;
        }
    }
}

void PrintListReverse(ListNode *head)
{
    std::stack<ListNode *> Nodes;
    ListNode * node = head;
    while(node != nullptr)
    {
        Nodes.push(node);
        node = node->m_pNext;
    }
    while(!Nodes.empty())
    {
        node = Nodes.top();
        printf("%d\n", node->m_nValue);
        Nodes.pop();
    }
}