#include <bits/stdc++.h>
#define pb push_back
#define sc1(n) scanf("%lld",&n)
#define sc2(a,b) scanf("%lld%lld",&a,&b)
#define sc3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define MX 100000
using namespace std;

typedef long long int ll;
typedef unsigned long long ul;
ll n,m;
vector<ll>V[25];
ll dp[205][25];
ll solve(ll pos,ll money)
{
    if(money<0)
        return -10000000000;
    if(pos>n)
    {
        return m-money;
    }
    if(dp[money][pos]!=-1)return dp[money][pos];
    ll ret=-1;
    for(ll i=0;i<V[pos].size();i++)
    {
        ret=max(ret,solve(pos+1,money-V[pos][i]));
    }
    return dp[money][pos]=ret;
}
int main()
{
    ll test;
    sc1(test);
    while(test--)
    {
        memset(dp,-1,sizeof dp);
        sc2(m,n);
        for(ll i=1;i<=n;i++)
        {
            V[i].clear();
            ll nn;
            sc1(nn);
            while(nn--)
            {
                ll val;
                sc1(val);
                V[i].pb(val);
            }
        }
        ll ans=solve(1,m);
        if(ans<0)
            printf("no solution\n");
        else
            printf("%lld\n",ans);
    }
    return 0;
}
