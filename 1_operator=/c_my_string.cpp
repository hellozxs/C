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
        if(&str != str)
        {
            _pdata = new char[strlen(str._pdata)+1];
            strcpy(_pdata, str._pdata);
        }
    }

    //现代写法
    c_my_string& operator- (c_my_string str)
    {
        if(this != &str)
        {
            swap(*this,str);
        }
    }

private:
    char* _pdata;
}



int main()
{
    return 0;
}
