#include "list.hpp"


template <typename T>
void List<T>::Merge(const List<T> &l1, const List<T> &l2)
{
    const Node* cur1 = l1.Front();
    const Node* cur2 = l2.Front();

    while(cur1 && cur2)
    {
        if(cur1->_data < cur2->_data)
        {
            pushBack(cur1->_data);
            cur1 = cur1->_next;
        }
        else
        {
            pushBack(cur2->_data);
            cur2 = cur2->_next;
        }
    }

    if(cur1 == NULL)
    {
        while(cur2)
        {
            pushBack(cur2->_data);
            cur2 = cur2->_next;
        }
    }
    else
    {
        while(cur1)
        {
            pushBack(cur1->_data);
            cur1 = cur1->_next;
        }
    }
}


int main()
{
    List<int> l1;
    List<int> l2;

    l1.pushBack(1);
    l1.pushBack(9);
    l1.pushBack(7);
    l1.pushBack(5);
    l1.pushBack(3);
    //l1.print();
    l1.Sort();
    l1.print();

    l2.pushBack(0);
    l2.pushBack(4);
    l2.pushBack(8);
    l2.pushBack(2);
    l2.pushBack(6);
    //l2.print();
    l2.Sort();
    l2.print();

    List<int> l;
    l.print();
    l.Merge(l1, l2);
    l.print();


    return 0;
}
