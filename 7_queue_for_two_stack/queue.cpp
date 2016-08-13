#include <iostream>
#include <stack>

using namespace std;


template <typename T>
class _queue
{
public:
    void appendTail(const T& data)
    {
        inStack.push(data);
        cout<<data<<" ";
    }

    void deleteHead()
    {
        if(!outStack.empty())
        {
            cout<<outStack.top()<<" ";
            outStack.pop();
        }
        else if(inStack.empty())
        {
            cout<<"queue is empty";
            return;
        }
        else
        {
            while(!inStack.empty())
            {
                T tmp = inStack.top();
                inStack.pop();
                outStack.push(tmp);
            }
            cout<<outStack.top()<<" ";
            outStack.pop();

        }
    }

private:
    stack<T> inStack;
    stack<T> outStack;
};


int main()
{
    _queue<int> q;
    q.appendTail(1);
    q.appendTail(2);
    q.appendTail(3);
    q.deleteHead();
    q.deleteHead();
    q.deleteHead();
    q.deleteHead();
    return 0;

}
