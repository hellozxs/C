#include <iostream>

#include "list.hpp"

using namespace std;

template <typename T>
listNode<T>* List<T>::reverseList()
{
    if(_head == NULL || _head->_next == NULL)
        return _head;

    Node* pre = _head;
    Node* cur = _head->_next;
    Node* next = cur->_next;
    pre->_next = NULL;
    while(cur->_next)
    {
        cur->_next = pre;
        pre = cur;
        cur = next;
        next = next->_next;
    }
    cur->_next = pre;
    _head = cur;
    return _head;

}



int main()
{
    List<int> l;
    l.reverseList ();

    l.pushBack(1);
    l.print();
    l.reverseList ();
    l.print();

    l.pushBack(2);
    l.print();
    l.reverseList();
    l.print();

    l.pushBack(3);
    l.print();
    l.reverseList();
    l.print();

    return 0;
}

