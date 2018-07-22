#include <bits/stdc++.h>
#define pb push_back
#define sc1(n) scanf("%lld",&n)
#define sc2(a,b) scanf("%lld%lld",&a,&b)
#define sc3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define MX 100000
using namespace std;

typedef long long int ll;
typedef unsigned long long ul;
vector<ll>V[30];
vector<string>ss;
ll vis[30];
void dfs(ll u)
{
    vis[u]=1;
    for(ll i=0;i<V[u].size();i++)
    {
        ll v=V[u][i];
        if(vis[v]==0)
            dfs(v);
    }
}
int main()
{
    ll test;
    cin>>test;
    getchar();
    string line;
    getline(cin,line);
    while(test--)
    {
        string str;
        getline(cin,str);
        ll n=str[0]-'A';
        for(ll i=0;i<=n;i++)
        {
            V[i].clear();
        }
        while(getline(cin,str))
        {
            if(str.size()==0)
                break;
            ll u=str[0]-'A';
            ll v=str[1]-'A';
            V[u].pb(v);
            V[v].pb(u);
        }
        memset(vis,0,sizeof vis);
        ll ans=0;
        for(ll i=0;i<=n;i++)
        {
            if(vis[i]==0){
                dfs(i);
                ans++;
            }
        }
        printf("%lld\n",ans);
        if(test>0)
            printf("\n");
    }
    return 0;
}

