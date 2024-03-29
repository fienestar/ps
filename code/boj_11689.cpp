/*
    GCD(n, k) = 1
    https://www.acmicpc.net/problem/11689
*/
#include <bits/stdc++.h>

using namespace std;
using ull = long long;

ull euler_phi(ull n) {
    ull result = n;
    for (ull i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

int main()
{
    ull n;
    cin >> n;

    ull rslt = n;

    if(n%2 == 0){
        while(n%2 == 0)n/=2;
        rslt -= rslt/2;
    }

    if(n%3 == 0){
        while(n%3 == 0)n/=3;
        rslt -= rslt/3;
    }

    for(ull i=5; i*i <= n; i+=6){
        if(n%i == 0){
            while(n%i == 0)n/=i;
            rslt -= rslt/i;
        }

        ull k = i+2;
        if(n%k == 0){
            while(n%k == 0)n/=k;
            rslt -= rslt/k;
        }
    }

    if(n>1) rslt-=rslt/n;

    cout << rslt;
}