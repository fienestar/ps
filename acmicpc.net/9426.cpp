// 사용된 알고리즘: 
// R: X
// T: 0

// 아뉘 오름차순 내림차순 반대로한것같은데
// ㄴㄷ 시간 복잡도 흑우

#include <bits/stdc++.h>

using ull=unsigned long long;

size_t N, K, S, B;

using vs=std::vector<ull>;
vs merged[2500'000];

vs merge(const vs& l,const vs& r)
{
    vs v(l.size()+r.size());
    size_t vi=0;
    size_t i=0;
    size_t j=0;

    while(i!=l.size()&&j!=r.size())
        if(l[i] > r[j])
            v[vi++]=l[i++];
        else
            v[vi++]=r[j++];

    while(i!=l.size())
        v[vi++]=l[i++];
    while(j!=r.size())
        v[vi++]=r[j++];
    
    return std::move(v);
}

void merge_all()
{
    size_t P=B>>1;
    for(;P!=0;P>>=1)
        for(size_t i=0;i!=P;++i)
            merged[P+i]=merge(merged[((P+i)<<1)+1],merged[(P+i)<<1]);
}

vs merge(size_t n,size_t s,size_t e,size_t l,size_t r)
{
    // std::cout << "need " << l << " ~ " << r << " from " << n << "(" << s << " ~ " << e << ")" << std::endl;
    if(l>e||r<s)
        return {};

    if(l<=s&&e<=r){
        // std::cout << "use " << n << std::endl;
        return merged[n];
    }

    return merge(
        merge(n<<1,s,(s+e)>>1,l,r),
        merge((n<<1)+1,((s+e)>>1)+1,e,l,r)
        );
}

int main()
{
    using namespace std;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Code here!
    
    cin >> N >> K;

    B=N;
    if(B!=(B&-B)){
        do
            B-=(B&-B);
        while(B!=(B&-B));
        B<<=1;
    }
    
    for(size_t i=0;i!=N;++i){
        merged[B+i].resize(1);
        cin >> merged[B+i][0];
    }

    for(size_t i=N;i!=B;++i)
        merged[B+i].resize(0);
    
    merge_all();

    // for(size_t i=1;i!=B*2;++i){
    //     cout << i << endl;
    //     for(auto& j:merged[i])
    //         cout << j << " ";
    //     cout << endl << endl;
    // }

    for(size_t i=0;i+K<=N;++i){
        // cout << "merge " << N-1 << ", " << i+K-1 << endl;
        // auto m(::merge(1,0,B-1,i,i+K-1));
        // for(auto& i:m)
        //     cout << i << " ";
        // cout << endl;
        // S+=m[K>>1];
        // cout << m[K>>1] << endl;

        S+=::merge(1,0,B-1,i,i+K-1)[K>>1];

        cout << ::merge(1,0,B-1,i,i+K-1)[K>>1] << endl;
    }
    
    cout << S;
}