#include <iostream>

//size_t numberOf1( unsigned int num)
//{
//    //std::cout<<num<<std::endl;
//    size_t count = 0;
//    while(num)
//    {
//        if(num & 1 == 1)
//            count++;
//        num >>= 1;
//    }
//    return count;
//}

size_t numberOf1(int num)
{
    int i = 0;
    size_t count = 0;
    for(; i < 32; i++)
    {
        if(num & (1<<i))
            count++;
    }
    return count;
}


//
size_t numberOf1_Pro(int num)
{
    int count = 0;
    while(num)
    {
        count++;
        num = num & (num-1);
    }
    return count;
}



int main()
{
    //int num = -1;
    //int num = 0x80000000;
    int num = 0xFFFFFFFF;
    size_t ret = numberOf1_Pro(num);
    std::cout<<ret<<std::endl;
    return 0;
}
