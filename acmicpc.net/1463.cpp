// 사용된 알고리즘: 
// R: O

#include <bits/stdc++.h>

using namespace std;

#ifndef LOCAL
#define LOCAL(x) ((void)0)
#endif

int main()
{
    LOCAL(OUTPUT_TO_FILE);
    LOCAL(INPUT_FROM_FILE);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Code here!
    size_t X;
    queue<pair<size_t,size_t>> q;
    vector<size_t> v;
    cin >> X;
    v.resize(X,0);
    q.push({1,0});
    for(;;){
        auto o = q.front();
        q.pop();

        if(o.first == X){
            cout << o.second;
            return 0;
        }

        if(o.first > X || v[o.first])
            continue;
        
        v[o.first] = true;

        q.emplace(o.first*3,o.second+1);
        q.emplace(o.first*2,o.second+1);
        q.emplace(o.first+1,o.second+1);
    }
}