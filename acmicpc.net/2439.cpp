#include <iostream>

using namespace std;

#ifndef LOCAL
#define LOCAL(x) ((void)0)
#endif

void PutChars(char c,size_t n){
    while(n--)fputc(c,stdout);
}

int main()
{
    LOCAL(OUTPUT_TO_FILE);
    LOCAL(INPUT_FROM_FILE);
    size_t N;
    cin>>N;
    for(size_t i=0;i!=N;++i){
        PutChars(' ',N-i-1);
        PutChars('*',i+1);
        cout << "\n";
    }
}