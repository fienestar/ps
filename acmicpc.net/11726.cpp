/*
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	256 MB	44044	16234	12088	34.755%
문제
2×n 크기의 직사각형을 1×2, 2×1 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.

아래 그림은 2×5 크기의 직사각형을 채운 한 가지 방법의 예이다.



입력
첫째 줄에 n이 주어진다. (1 ≤ n ≤ 1,000)

출력
첫째 줄에 2×n 크기의 직사각형을 채우는 방법의 수를 10,007로 나눈 나머지를 출력한다.
*/
// 사용된 알고리즘: dp
// R: X
// T: 0

#include <bits/stdc++.h>

using namespace std;

enum{
    MOD=10007
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Code here!
    size_t dp[1000];
    size_t n;
    cin>>n;
    dp[0]=dp[1]=1;
    for(size_t i=2;i<=n;++i){
        dp[i]=(dp[i-1]+dp[i-2])%MOD;
    }
    cout << dp[n];
}