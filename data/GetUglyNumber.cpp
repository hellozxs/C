#include <iostream>
using namespace std;
#include <vector>

int min(int num1, int num2, int num3)
{
    if(num1 < num2)
    {
        if(num1 < num3)
            return num1;
        else
            return num3;
    }
    else //num2 < num1
    {
        if(num2 < num3)
            return num2;
        else
            return num3;
    }
}


void UpdateFlag(const vector<int>& a, int& flag, int num)
{
    while(flag * num <= a[a.size()-1])
        flag++;
}

void GetUglyNumber(size_t N)
{
    if(N == 0)
        return;
    vector<int> a;
    a.push_back(1);
    int max = a[1];
    int t2 = 1, t3 =1, t5= 1;
    int index =0;
    cout<<a[index++]<<" ";
    while(a.size() < N)
    {
        int tmp = min(2*t2, 3*t3, 5*t5);
        a.push_back(tmp);
        max = tmp;
        UpdateFlag(a, t2, 2);
        UpdateFlag(a, t3, 3);
        UpdateFlag(a, t5, 5);
        cout<<a[index++]<<" ";
    }
    cout<<endl;
}


int main()
{

    size_t num = 0;
    cout<<"请输入要输出的丑数的个数：";
    fflush(stdout);
    cin>>num;
    GetUglyNumber(num);
    return 0;
}
