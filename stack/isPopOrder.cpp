#include <iostream>
#include <stack>


bool isPopOrder(const int* arrPush, const int* arrPop, size_t size)
{
    if(arrPush == NULL || arrPop == NULL || size == 0)
        return false;

    std::stack<int> s;
    int popIndex = 0, pushIndex = 0;
    for( ; popIndex < size; popIndex++ )
    {
        if(!s.empty() && s.top() == arrPop[popIndex])
        {
            s.pop();
            continue;
        }
        while(pushIndex < size && arrPush[pushIndex] != arrPop[popIndex])
            s.push(arrPush[pushIndex++]);
        if(pushIndex >= size)
            return false;
        pushIndex++;
    }
    return true;
}



int main()
{
    int arrPush[] = {1, 2, 3, 4, 5};
    //int arrPop[] = {3, 5, 4, 2, 1};
    //int arrPop[] = {3, 5, 2, 4, 1};
    int arrPop[] = {1, 2, 3, 4, 5};


    std::cout<<isPopOrder(arrPush, arrPop, sizeof(arrPush)/sizeof(arrPush[0]))<<std::endl;

    return 0;
}
