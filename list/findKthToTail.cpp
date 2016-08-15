#include <iostream>
#include "list.hpp"
using namespace std;

#define DEBUG

template <typename T>
listNode<T>* List<T>::findKthToTail(size_t K)
{
    if (K == 0 || _head == NULL)
        return NULL;
    listNode<T>* slow = _head;
    listNode<T>* fast = _head;

    while(K--)
    {
        fast = fast->_next;
        if(fast == NULL)
        {
            if(K == 0)
                break;
            else
                return NULL;
        }
    }

    while(fast)
    {
        fast = fast->_next;
        slow = slow->_next;
    }

#ifdef DEBUG
    cout<<slow->_data<<endl;
#endif
    return slow;

}




int main()
{
    List<int> l;
    l.pushBack(1);
    l.pushBack(2);
    l.pushBack(3);
    l.pushBack(4);
    l.pushBack(5);
    l.pushBack(6);
    l.print();

    l.findKthToTail(0);
    l.findKthToTail(1);
    l.findKthToTail(2);
    l.findKthToTail(3);
    l.findKthToTail(4);
    l.findKthToTail(5);
    l.findKthToTail(6);
    l.findKthToTail(7);
    return 0;
}
