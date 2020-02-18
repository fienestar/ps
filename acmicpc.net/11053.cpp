// 사용된 알고리즘: BS
// R: X
// T: 0

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Code here!
    size_t N,A;
    vector<int> LIS;
    // LIS[idx] = idx길이의 증가 수열중 마지막값의 최솟값
    cin >> N;
    LIS.reserve(N);
    while(N--){
        cin >> A;
        if(auto it=lower_bound(LIS.begin(),LIS.end(),A);it==LIS.end())
            LIS.push_back(A);
        else
            *it=A;
    }
    cout << LIS.size();
}