#include <iostream>
using namespace std;

#include <string>

void strComb(string s)
{
    int i = 1;
    for(; i <= s.size(); i++)
    {
        int start = 0;
        for( ;start <= s.size()-i;start++)
        {
            for(int j = 0; j < i; j++)
            {
                cout<<s[start+j];
            }
            cout<<"  ";
        }
    }
    cout<<endl;
}

int main()
{
    string s;
    cin>>s;
    strComb(s);
    return 0;
}
