// 사용된 알고리즘: 
// R: X
// T: 0

#include <bits/stdc++.h>

using namespace std;

#ifndef LOCAL
#define LOCAL(x) ((void)0)
#endif
#define endl "\n"
#define elif else if
#define ifn(v) if(v);else
#define elifn(v) else ifn(v)

template <class T>
class seg_tree{
    vector<T> v;
    public:
    enum{
        least_value=0
    };

    static size_t cal_size(size_t N)
    {
        while(N!=(N&-N))N+=N&-N;
        return N<<1;
    }

    size_t begin_idx()
    {
        return v.size()>>1;
    }

    T upper_value(const T& left_value,const T& right_value)
    {
        return left_value+right_value;
    }

    public:

    seg_tree(vector<T> _v)
    :v(cal_size(_v.size())){
        size_t i=begin_idx();
        for(auto& e:_v)
            v[i++]=e;
        while(i!=v.size())
            v[i++]=least_value;
        for(i=begin_idx();--i;)
            v[i]=upper_value(v[i<<1],v[(i<<1)^1]);
    }
    
    void set(size_t idx,T value)
    {
        idx+=begin_idx();
        v[idx]=value;
        while(idx>>=1)
            v[idx]=upper_value(v[idx<<1],v[(idx<<1)^1]);
    }

    T get(size_t end)
    {
        T most=least_value;
        end+=begin_idx();
        while(end){
            if(end&1){
                if(end==1){
                    most=upper_value(most,v[end]);
                }
                end>>=1;
            }else{
                most=upper_value(most,v[end]);
                if(end==(end&-end))
                    return most;
                end=(end>>1)-1;
            }
        }

        return most;
    }

    T get(size_t begin,size_t end)
    {
        return get(end)-get(begin);
    }
};

using ull=unsigned long long;

int main()
{
    //LOCAL(OUTPUT_TO_FILE);
    LOCAL(INPUT_FROM_FILE);
    ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    // Code here!
    size_t N,M,K;
    ull a,b,c;

    cin >> N >> M >> K;
    M+=K;
    vector<ull> v(N);
    for(auto& i:v)
        cin>>i;
    seg_tree<ull> seg(v);
    while(M--){
        cin>>a>>b>>c;
        if(a==1)
            seg.set(b-1,c);
        else
            cout << seg.get(b-1,c-1) << endl;
    }
}
