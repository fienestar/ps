#include <iostream>

using namespace std;

void PutChars(char c,size_t n){
    while(n--)fputc(c,stdout);
}

int main()
{
    size_t N;
    cin>>N;
    for(size_t i=N;i--;){
        PutChars(' ',i);
        PutChars('*',(N-i)*2-1);
        cout << "\n";
    }
}