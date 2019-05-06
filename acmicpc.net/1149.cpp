#include <iostream>
#include <algorithm>

int main()
{
    using namespace std;
    size_t N;
    size_t DP[2][3]={{}};
    size_t RGB[3]={};
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    while(N--){
        for(size_t i=0;i!=3;++i){
            DP[0][i] = DP[1][i];
            DP[1][i] += 1000;
            cin >> RGB[i];
        }
        for(size_t i=0;i!=3;++i)
            for(size_t j=0;j!=3;++j)
                if(j!=i && DP[0][j]+RGB[i] < DP[1][i])
                    DP[1][i] = DP[0][j]+RGB[i];         
    }
    sort(DP[1],DP[1]+3);
    cout << DP[1][0];
}