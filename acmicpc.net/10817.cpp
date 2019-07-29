// 사용된 알고리즘: sort
// R: O
// T: 1

#include <bits/stdc++.h>

using namespace std;

#ifndef LOCAL
#define LOCAL(x) ((void)0)
#endif

int main()
{
    LOCAL(OUTPUT_TO_FILE);
    //LOCAL(INPUT_FROM_FILE);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Code here!
    vector<int> v(3);
    for(auto&i:v)cin>>i;
    sort(v.begin(),v.end());
    cout<<v[1];
}