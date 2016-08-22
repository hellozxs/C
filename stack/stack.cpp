
#include <iostream>
#include <vector>

template <typename T>
class Stack
{
public:
    void Push(const T& data)
    {
        if(a.size() > 0)
        {
            const T &tmp = a[a.size()-1];
            a.push_back(data);
            if(tmp > data)
                a.push_back(data);
            else
                a.push_back(tmp);
        }
        else
        {
            a.push_back(data);
            a.push_back(data);
        }
    }


    void Pop()
    {
        if(a.size() == 0)
            return;
        a.pop_back();
        a.pop_back();
    }

    T Top()
    {
        if(a.size() > 0)
            throw;
        T tmp = a[a.size()-1];
        a.pop_back();
        T ret = a[a.size()-1];
        a.push_back(tmp);
        return ret;
    }

    bool Empty()
    {
        if(a.size() > 0)
            return false;
        else
            return true;
    }

    T Min()
    {
        if(a.size() == 0)
            throw;
        else
            return a[a.size()-1];
    }

private:
    std::vector<T> a;
};




int main()
{

    Stack<int> s;
    s.Push(3);
    std::cout<<s.Min()<<std::endl;
    s.Push(5);
    std::cout<<s.Min()<<std::endl;
    s.Push(2);
    std::cout<<s.Min()<<std::endl;
    s.Push(1);
    std::cout<<s.Min()<<std::endl;

    s.Pop();
    std::cout<<s.Min()<<std::endl;
    s.Pop();
    std::cout<<s.Min()<<std::endl;
    s.Pop();
    std::cout<<s.Min()<<std::endl;


    return 0;
}
