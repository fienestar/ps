#include <iostream>

int main()
{
    size_t N;
    std::cin >> N;
    while(N!=1)
	if(N&1)break;
        else N>>=1;
    std::cout << (N==1);
}