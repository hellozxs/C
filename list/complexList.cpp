#include <iostream>

const hashTableSize = 100;
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



listNode* Clone(listNode* pHead)
{
    if(pHead == NULL)
        return;
    hashTable<int,int> ht(hashTableSize);
    listNode* pHead1 = new listNode(pHead1->_data);
    ht.Insert(pHead, pHead1);

    listNode* cur  = pHead->_next;
    listNode* cur1 = pHead1;
    while(cur)
    {
        listNode* tmp = new listNode(cur->_data);
        cur = cur->_next;
        cur1->_next = tmp;
        cur1 = cur1->_next;
        ht.Insert(cur, tmp);
    }

    cur = pHead;
    cur1 = pHead1;
    while(cur)
    {
        if(cur->_sibling != NULL)
        {
            cur1->_sibling = ht.Find(cur1->_sibling)->_value;
        }
        cur1 = cur1->_next;
        cur  = cur->_next;
    }

    return pHead1;
}


int main()
{
    return 0;
}
