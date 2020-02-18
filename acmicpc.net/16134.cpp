// 사용된 알고리즘: 
// R: X
// T: 0

#include <bits/stdc++.h>

using namespace std;

using i=unsigned long long;
enum:i{
    MOD=1'000'000'007ULL
};

int main()
{
    using ::i;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Code here!
    i N,R;
    cin >> N >> R;
    i s=1;
    for(i I=0;I<R;++I){
        s=s*(N-I)/(I+1) % ::MOD;
        s%=::MOD;
    }
    cout << s;
}