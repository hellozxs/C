#include <iostream>
#include "List.hpp"

template <typename T>
void List<T>::deleteNode(listNode<T>* pToBeDelete)
{
    if(_head == NULL || pToBeDelete == NULL)
        return;

    //删除的是尾结点
    if(pToBeDelete->_next == NULL)
    {
        popBack();
    }
    else  //非尾结点
    {
        Node* cur = pToBeDelete;
        Node* next = cur->_next;
        cur->_data = next->_data;
        cur->_next = next->_next;
        delete next;

    }

}


int main()
{
    List<int> l;
    l.pushBack (1);
    l.pushBack (2);
    l.pushBack (3);
    l.pushBack (4);
    l.print();
    List<int>:: Node* ret = l.Find(3);
    l.deleteNode(ret);
    l.print();

    ret = l.Find(4);
    l.deleteNode(ret);
    l.print();

    ret = l.Find(1);
    l.deleteNode(ret);
    l.print();

    return 0;
}
