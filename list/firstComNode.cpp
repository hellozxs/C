#include "list.hpp"



//借助辅助栈
#include<stack>
listNode<int>* firstComNode(listNode<int>* pHead1, listNode<int>* pHead2)
{
    std::stack<listNode<int>*> s1, s2;
    listNode<int> *cur1 = pHead1;
    listNode<int> *cur2 = pHead2;
    while(cur1)
    {
        s1.push(cur1);
        cur1 = cur1->_next;
    }

    while(cur2)
    {
        s2.push(cur2);
        cur2 = cur2->_next;
    }

    listNode<int>* pre = NULL;
    while(!s1.empty() && !s2.empty() && s1.top() == s2.top())
    {
        pre = s1.top();
        s1.pop();
        s2.pop();
    }

    return pre;

}



//////////////////////////  更优的解法  ////////////////////////////

int listSize(listNode<int>* pHead)
{
    int count = 0;
    listNode<int>* cur = pHead;
    while(cur)
    {
        count++;
        cur = cur->_next;
    }
    return count;
}
listNode<int>* firstComNode_Pro(listNode<int>* pHead1, listNode<int>* pHead2)
{
   if(pHead1 == NULL || pHead2 == NULL)
       return NULL;

   int size1 = listSize(pHead1);
   int size2 = listSize(pHead2);
   size_t size = size1 -size2;

   listNode<int>* cur1 = pHead1;
   listNode<int>* cur2 = pHead2;
   if(size1 > size2)
   {
       while(size--)
           cur1 = cur1->_next;
   }
   else
   {
       while(size--)
           cur2 = cur2->_next;
   }

   while(cur1 && cur2 && cur1 != cur2)
   {
       cur1 = cur1->_next;
       cur2 = cur2->_next;
   }
   return cur1;
}


int main()
{
    List<int> l1;
    l1.pushBack(1);
    l1.pushBack(3);
    l1.pushBack(4);
    l1.pushBack(5);

    listNode<int>* pHead1 = l1.Front();
    listNode<int>* pHead2 = new listNode<int>(2);
    pHead2->_next = l1.Find(3);


    //listNode<int>* ret = firstComNode_Pro(pHead1, pHead2);
    listNode<int>* ret = firstComNode_Pro(NULL, pHead2);
    if(ret)
        std::cout<<ret->_data<<std::endl;
    else
        std::cout<<ret<<std::endl;

    return 0;
}
