#include <iostream>

#include "list.hpp"

using namespace std;

template <typename T>
void List<T>::_reverseList_R(Node* pre, Node* &head)
{
    if(head == NULL)
    {
       _head = pre;
        return;
    }

    _reverseList_R(head, head->_next);
    head->_next = pre;
}

template <typename T>
listNode<T>* List<T>::reverseList_R()
{
    _reverseList_R(NULL, _head);
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

