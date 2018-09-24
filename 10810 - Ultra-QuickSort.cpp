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
struct A
{
    ll val;
    ll id;
}in[500005];
ll tree[4*500005];
ll arr[500005];
bool comp(A a,A b)
{
    return a.val<b.val;
}
void update(ll node,ll l,ll r,ll pos)
{
    if(l==r)
    {
        tree[node]++;
        return;
    }
    ll mid=(l+r)/2;
    if(pos<mid)
    {
        update(node*2,l,mid,pos);
    }
    else
        update(node*2+1,mid+1,r,pos);

    tree[node]=tree[node*2]+tree[node*2+1];
}
ll query(ll node,ll b,ll e,ll l,ll r)
{
    if(b>e||b>r||e<l)
        return 0;
    if(b>=l&&e<=r)
        return tree[node];
    ll mid=(b+e)/2;
    return query(node*2,b,mid,l,r)+query(node*2+1,mid+1,e,l,r);
}
int main()
{
    ll n;
    while(sc1(n)==1&&n)
    {
        memset(tree,0,sizeof tree);
        unordered_map<ll,ll>mp;
        for(ll i=1;i<=n;i++)
        {
            sc1(in[i].val);
            in[i].id=i;
            arr[i]=in[i].val;
        }
        sort(in+1,in+n+1,comp);
        for(ll i=1;i<=n;i++)
        {
            mp[in[i].val]=i;
        }
        ll ans=0;
        for(ll i=1;i<=n;i++)
        {
            ll now=mp[arr[i]];
            ans+=query(1,1,n,now+1,n);
            update(1,1,n,now);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
