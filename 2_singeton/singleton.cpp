#include <iostream>

using namespace std;

class singleton
{
public:
    static singleton& get_instance()
    {
        if(obj == NULL)
        {
            obj = new singleton();
        }
        return *obj;
    }
private:
    static singleton* obj;

private:
    singleton() {}
    singleton& operator= (const singleton& s);
    singleton (const singleton& s);
};

singleton* singleton::obj = NULL;



void test_singleton ()
{
   singleton& s =  singleton::get_instance ();
   singleton& s1 = singleton::get_instance();
   cout<<&s <<endl;
   cout<<&s1 <<endl;
}

int main()
{
    test_singleton();
    return 0;
}
