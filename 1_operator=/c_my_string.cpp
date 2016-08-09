#include <iostream>
#include <string.h>

using namespace std;

class c_my_string
{
public:
    c_my_string(char* pdata = NULL);
    ~c_my_string();
    c_my_string(const c_my_string& str);

    //传统写法
    c_my_string& operator= (const c_my_string& str)
    {
        if(&str != this)
        {
            char* tmp = new char[strlen(str._pdata)+1];
            strcpy(tmp, str._pdata);
        }

        //记得要释放被赋值对象的内存
        delete[] _pdata;
        _pdata = tmp;
        return *this;
    }

    //现代写法
    c_my_string& operator- (c_my_string str)
    {
        if(this != &str)
        {
            swap(*this,str);
        }
        return *this;
    }

private:
    char* _pdata;
}



int main()
{
    return 0;
}
