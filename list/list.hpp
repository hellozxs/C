#pragma once

#include <iostream>



template <typename T>
struct listNode
{
    T _data;
    listNode<T>* _next;

    listNode(const T& data)
        :_data(data)
         ,_next(NULL)
    {}
};

template <typename T>
class List
{
public:
    typedef listNode<T> Node;
    List()
        :_head(NULL)
    {}

    ~List()
    {
        while(_head)
            popBack();
    }

    void pushBack(const T& data)
    {
        if(_head == NULL)
            _head = new Node(data);
        else
        {
            Node* cur = _head;
            while(cur->_next != NULL)
                cur = cur->_next;
            cur->_next = new Node(data);
        }
    }

    void popBack()
    {
        if(_head == NULL)
            return;
        else if(_head->_next == NULL)
        {
            delete _head;
            _head = NULL;
        }
        else
        {
            Node* cur = _head;
            while(cur->_next->_next != NULL)
                cur = cur->_next;
            delete cur->_next;
            cur->_next = NULL;
        }
    }

    void print()
    {
        Node* cur = _head;
        while(cur != NULL)
        {
            std::cout<<cur->_data<<"  ";
            cur = cur->_next;
        }
        std::cout<<std::endl;
    }


    Node* Find(const T& data)
    {
        Node* cur = _head;
        while(cur)
        {
            if(cur->_data == data)
                return cur;
            cur = cur->_next;
        }
        return NULL;
    }

    void Sort()
    {
        if(_head == NULL || _head->_next == NULL)
            return;

        Node* tail = NULL;
        while(tail != _head->_next)
        {
            bool flag = false;
            Node* cur = _head;
            while(cur->_next != tail)
            {
                if(cur->_data > cur->_next->_data)
                {
                    std::swap(cur->_data, cur->_next->_data);
                    flag = true;
                }
                cur = cur->_next;
            }
            if(flag == false)
                return;
            tail = cur;
        }
    }

    Node* Front()const
    {
        return _head;
    }

    //在O(1)的时间删除结点
    void deleteNode(Node* pToBeDelete);

    //求链表的倒数第K个结点
    Node* findKthToTail(size_t K);

    //反转链表
    Node* reverseList();

    //反转链表：递归实现
    Node* reverseList_R ();

    //合并两个升序的链表
    void Merge(const List<T>& l1,const List<T> &l2);

private:
    void _reverseList_R(Node* &head, Node* p);

private:
    Node* _head;
};
