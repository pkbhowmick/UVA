#include <bits/stdc++.h>
#define pb push_back
#define sc1(n) scanf("%lld",&n)
#define sc2(a,b) scanf("%lld%lld",&a,&b)
#define sc3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define MX 100000
using namespace std;

typedef long long int ll;
typedef unsigned long long ul;

ll arr[10005];
int main()
{
    ll test;
    sc1(test);
    ll t=1;
    while(test--)
    {
        ll n,m;
        sc2(n,m);
        ll dis=n-m;
        ll ans=0;
        if(dis>0)
        {
            ans=dis/m;
            if(dis%m!=0)
                ans++;
        }
        printf("Case %lld: %lld\n",t++,ans);
    }
    return 0;
}

