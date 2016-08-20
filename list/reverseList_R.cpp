#include <iostream>

#include "list.hpp"

using namespace std;


template <typename T>
void List<T>::_reverseList_R(listNode<T>* &head,listNode<T>* p)
{
    if(p == NULL)
        return;
    if(p->_next == NULL)
    {
       head = p;
        return;//找到最后一个结点
    }

    _reverseList_R(head,p->_next);
    p->_next->_next = p;  //反转结点
    p->_next = NULL;//第一个结点反转后其后继为空

}

template <typename T>
listNode<T>* List<T>::reverseList_R()
{
    _reverseList_R(_head,_head);
}


int main()
{
    List<int> l;
    l.reverseList_R ();

    l.pushBack(1);
    l.print();
    l.reverseList_R ();
    l.print();

    l.pushBack(2);
    l.print();
    l.reverseList_R();
    l.print();

    l.pushBack(3);
    l.print();
    l.reverseList_R();
    l.print();

    return 0;
}

