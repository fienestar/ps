// 사용된 알고리즘: BFS
// R: X
// T: 0

#include <bits/stdc++.h>

using namespace std;

static size_t hm[500][500];
static size_t cm[500][500];
int M, N;

using pii=pair<int, int>;
#define x first
#define y second

bool in_range(pii p)
{
    return p.x>=0 && p.x<M && p.y>=0 && p.y<N;
}

size_t count()
{
    queue<pii> q;
    q.emplace(0,0);
    cm[0][0]=1;
    size_t fg;
    while(!q.empty()){
        auto p=q.front();
        q.pop();
        int mx[]={1,-1,0,0};
        int my[]={0,0,1,-1};
        
        for(size_t i=0;i!=4;++i)
            if(in_range({p.x+mx[i],p.y+my[i]})&&hm[p.x][p.y]>=hm[p.x+mx[i]][p.y+my[i]]){
                q.emplace(p.x+mx[i],p.y+my[i]);
            }
    }
    return cm[M-1][N-1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Code here!
    cin >> M >> N;
    for(size_t i=0;i!=M;++i)
        for(size_t j=0;j!=N;++j)
            cin >> hm[i][j];
    count();
    for(size_t i=0;i!=M;++i){
        for(size_t j=0;j!=N;++j)
            cout << cm[i][j] << " ";
        cout << endl;
    }
    cout << count();
}