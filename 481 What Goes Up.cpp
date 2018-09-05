#include <bits/stdc++.h>
#define pb push_back
#define sc1(n) scanf("%lld",&n)
#define sc2(a,b) scanf("%lld%lld",&a,&b)
#define sc3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define MX 100000
using namespace std;

typedef long long int ll;
typedef unsigned long long ul;
vector<ll>in;
ll num[300005];
ll I[300005];
int main()
{
    ll v;
    while(sc1(v)==1)
    {
        in.pb(v);
    }
    ll n=in.size();
    for(ll i=0;i<=n;i++)
    {
        I[i]=1e18;
    }
    I[0]=-1e18;
    ll mx=0;
    for(ll i=0;i<n;i++)
    {
        ll lo,hi,mid;
        lo=0;
        hi=mx;
        while(lo<=hi)
        {
            mid=(lo+hi)/2;
            if(I[mid]<in[i]){
                lo=mid+1;
            }
            else
                hi=mid-1;
        }
        I[lo]=in[i];
        num[i]=lo;
        if(mx<lo)
            mx=lo;
    }
    printf("%lld\n-\n",mx);
    vector<ll>ans;
    ll now=1e18;
    ll need=mx;
    for(ll i=n-1;i>=0;i--)
    {
        if(num[i]==need&&in[i]<now)
        {
            ans.pb(in[i]);
            now=in[i];
            need--;
        }
    }
    ll sz=ans.size();
    for(ll i=sz-1;i>=0;i--)
    {
        printf("%lld\n",ans[i]);
    }
    return 0;
}
