#include <iostream>

const int hashTableSize = 100;
typedef struct complexListNode
{
    int              _data;
    complexListNode* _next;
    complexListNode* _sibling;

    complexListNode(int data)
        :_data(data)
         ,_next(NULL)
         ,_sibling(NULL)
    {}
}listNode;


typedef struct hashNode
{
    listNode* _key;
    listNode* _value;

    hashNode(listNode* key, listNode* value)
        :_key(key)
         ,_value(value)
    {}
}hashNode;


////////////////////////    利用哈希表实现   ////////////////////////////////////
//listNode* Clone(listNode* pHead)
//{
//    if(pHead == NULL)
//        return NULL;
//    hashTable<int,int> ht(hashTableSize);
//    listNode* pHead1 = new listNode(pHead1->_data);
//    ht.Insert(pHead, pHead1);
//
//    listNode* cur  = pHead->_next;
//    listNode* cur1 = pHead1;
//    while(cur)
//    {
//        listNode* tmp = new listNode(cur->_data);
//        cur = cur->_next;
//        cur1->_next = tmp;
//        cur1 = cur1->_next;
//        ht.Insert(cur, tmp);
//    }
//
//    cur = pHead;
//    cur1 = pHead1;
//    while(cur)
//    {
//        if(cur->_sibling != NULL)
//        {
//            cur1->_sibling = ht.Find(cur1->_sibling)->_value;
//        }
//        cur1 = cur1->_next;
//        cur  = cur->_next;
//    }
//
//    return pHead1;
//}
//

///////////////////  更优的解法  ////////////////////////////

listNode* clone_Pro (listNode* pHead)
{
    if(pHead == NULL)
        return NULL;

    //第一步：插入复制结点
    listNode* pHead1 = NULL;
    listNode* cur = pHead;
    while(cur)
    {
        listNode* cur1 = new listNode(cur->_data);
        cur1->_next = cur->_next;
        cur->_next = cur1;
        cur = cur->_next->_next;
    }

    //第二步：复制sibling
    cur = pHead;
    listNode* next = cur->_next;
    while(cur)
    {
        next = cur->_next;
        if(cur->_sibling)
            next->_sibling = cur->_sibling->_next;
        cur = cur->_next->_next;
    }

    //第三步：分离链表
    pHead1 = pHead->_next;
    next = pHead1;
    cur = pHead;
    while(cur)
    {
        cur->_next = cur->_next->_next;
        if(next->_next)
            next->_next = next->_next;
        cur = cur->_next;
        next = next->_next;
    }
    return pHead1;
}


void complexListPrint(listNode* pHead)
{
    listNode* cur = pHead;
    while(cur)
    {
        std::cout<<"data:"<<cur->_data;
        if(cur->_sibling )
            std::cout<<"  sibling:"<<cur->_sibling->_data<<std::endl;
        else
            std::cout<<"  sibling:NULL"<<std::endl;
        cur = cur->_next;
    }
}



int main()
{
    listNode* pHead = new listNode(1);
    listNode* cur1 = pHead;
    cur1->_next = new listNode(2);
    listNode* cur2 = cur1->_next;
    cur2->_next = new listNode(3);
    listNode* cur3 = cur2->_next;
    cur3->_next = new listNode(4);
    listNode* cur4 = cur3->_next;
    cur4->_next = new listNode(5);
    listNode* cur5 = cur4->_next;

    cur1->_sibling = cur3;
    cur2->_sibling = cur5;
    cur4->_sibling = cur2;

    complexListPrint(pHead);
    complexListPrint(clone_Pro(pHead));
    complexListPrint(pHead);
    complexListPrint(clone_Pro(NULL));



    return 0;
}
