#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    long long a,b;
    scanf("%d%lld",&n,&a); 
    n--;
    while(n--)
    {
        scanf("%lld",&b);
        long long d=__gcd(a,b);
        a=a/d*b;
    }
    printf("%lld",a);
}
