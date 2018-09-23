#include <bits/stdc++.h>
#define pb push_back
#define sc1(n) scanf("%lld",&n)
#define sc2(a,b) scanf("%lld%lld",&a,&b)
#define sc3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define MX 100000
using namespace std;

typedef long long int ll;
typedef unsigned long long ul;
 //ios_base::sync_with_stdio(false);
   //cin.tie(NULL);
ll x[100005];
int main()
{
    ll test;
    sc1(test);
    ll t=1;
    while(test--)
    {
        vector<ll>V;
        ll n,k;
        sc2(n,k);
        for(ll i=1;i<=n;i++)
        {
            sc1(x[i]);
        }
        for(ll i=1;i<=n;i++)
        {
            ll v;
            sc1(v);
            ll dif=v-x[i];
            V.pb(dif);
        }
        sort(V.begin(),V.end());
        ll ans=0;
        for(ll i=0;i<n;i++)
        {
            if(V[i]<0&&k>0)
            {
                k--;
                continue;
            }
            ans+=V[i];
        }
        printf("Case %lld: ",t++);
        if(ans>0)
            printf("%lld\n",ans);
        else
            printf("No Profit\n");
    }
    return 0;
}
