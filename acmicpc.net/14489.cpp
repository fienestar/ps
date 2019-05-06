#include <iostream>

int main()
{
    size_t A,B,C;
    std::cin >> A >> B >> C;
    C<<=1;
    A+=B;
    if(C <= A)
        std::cout << A-C;
    else
        std::cout << A;
}