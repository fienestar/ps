#include <iostream>

using namespace std;

void PutChars(char c,size_t n){
    while(n--)fputc(c,stdout);
}

int main()
{
    size_t N;
    cin>>N;
    for(size_t i=0;i!=N;++i){
        PutChars(' ',N-i-1);
        PutChars('*',i+1);
        cout << "\n";
    }
}