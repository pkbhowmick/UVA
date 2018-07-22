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
        ll n;
        sc1(n);
        for(ll i=1;i<=n;i++)
        {
            sc1(arr[i]);
        }
        ll ans=0;
        ll now=1;
        for(ll i=1;i<=n;i++)
        {
            if(arr[i]!=now)
            {
                ans++;
            }
            else
            {
                now++;
            }
        }
        printf("Case %lld: %lld\n",t++,ans);
    }
    return 0;
}
