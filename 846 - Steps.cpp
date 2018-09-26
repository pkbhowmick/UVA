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
int main()
{
    ll test;
    sc1(test);
    while(test--)
    {
        ll a,b;
        sc2(a,b);
        ll dif=b-a;
        ll lo=0;
        ll hi=1e5;
        ll ans=hi;
        while(lo<=hi)
        {
            ll mid=(lo+hi)/2;
            ll now;
            if(mid%2==0)
            {
                ll x=mid/2;
                now=(x*x)+x;
            }
            else
            {
                ll x=mid/2;
                now=(x*x)+x+(x+1);
            }
            if(now>=dif)
            {
                ans=min(ans,mid);
                hi=mid-1;
            }
            else
                lo=mid+1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
