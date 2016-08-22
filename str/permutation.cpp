#include <iostream>
#include <string>

void _permutation(std::string s, size_t start, size_t end)
{
    if(start == end)
    {
        std::cout<<s<<std::endl;
        return;
    }
    int i = start;
    for( ; i <= end; i++ )
    {
        std::swap(s[start], s[i]);
        _permutation(s, start+1, end);
    }
}

void permutation( std::string s)
{
    _permutation(s, 0, s.size()-1);
}


int main()
{
    std::string s;
    std::cin>>s;
    permutation(s);
    return 0;
}
