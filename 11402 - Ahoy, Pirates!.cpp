#include <bits/stdc++.h>
#define pb push_back
#define sc1(n) scanf("%lld",&n)
#define sc2(a,b) scanf("%lld%lld",&a,&b)
#define sc3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define MX 1024005
using namespace std;

typedef long long int ll;
typedef unsigned long long ul;

ll arr[MX];
ll tree[MX*4];
char lazy[MX*4];
char crr[MX];
void build(ll n,ll l,ll r)
{
    if(l==r)
    {
        tree[n]=arr[l];
        return;
    }
    ll mid=(l+r)/2;
    build(2*n,l,mid);
    build(2*n+1,mid+1,r);

    tree[n]=tree[2*n]+tree[2*n+1];
}
void propagate(ll node,char ch)
{
    if(ch!='F')
        lazy[node*2]=ch;
    else
    {
        if(lazy[node*2]=='C')
            lazy[2*node]='S';
        else if(lazy[node*2]=='S')
            lazy[2*node]='C';
        else if(lazy[node*2]=='F')
            lazy[node*2]='N';
        else
            lazy[node*2]='F';
    }
    if(ch!='F')
        lazy[node*2+1]=ch;
    else
    {
        if(lazy[node*2+1]=='C')
            lazy[2*node+1]='S';
        else if(lazy[node*2+1]=='S')
            lazy[2*node+1]='C';
        else if(lazy[node*2+1]=='F')
            lazy[node*2+1]='N';
        else
            lazy[node*2+1]='F';
    }

}
void update(ll node,ll L,ll R,ll l,ll r,char ch)
{
    if(lazy[node]!='N')
    {
        if(lazy[node]=='S')
        {
            tree[node]=(R-L+1);
        }
        else if(lazy[node]=='C')
        {
            tree[node]=0;
        }
        else
        {
            tree[node]=(R-L+1)-tree[node];
        }
        if(L!=R)
        {
            propagate(node,lazy[node]);
        }
        lazy[node]='N';

    }
    if(L>r||R<l)
        return;
    if(L>=l&&R<=r)
    {
        if(ch=='S')
            tree[node]=(R-L+1);
        else if(ch=='C')
            tree[node]=0;
        else{
            //cout<<tree[node]<<" sum"<<endl;
            tree[node]=(R-L+1)-tree[node];
            //cout<<tree[node]<<" sum"<<endl;
        }

        if(L!=R)
            propagate(node,ch);

        return;
    }
    ll mid=(L+R)/2;
    update(2*node,L,mid,l,r,ch);
    update(2*node+1,mid+1,R,l,r,ch);

    tree[node]=tree[2*node]+tree[2*node+1];
}
ll query(ll node,ll L,ll R,ll l,ll r)
{
    if(L>R||L>r||R<l)
        return 0;

    if(lazy[node]!='N')
    {
        if(lazy[node]=='S')
        {
            tree[node]=(R-L+1);
        }
        else if(lazy[node]=='C')
        {
            tree[node]=0;
        }
        else
        {
            tree[node]=(R-L+1)-tree[node];

        }
        if(L!=R)
        {
            propagate(node,lazy[node]);
        }
        lazy[node]='N';
    }
    if(L>=l&&R<=r)
    {
        return tree[node];
    }
    ll mid=(L+R)/2;
    ll p=query(2*node,L,mid,l,r);
    ll q=query(2*node+1,mid+1,R,l,r);

    return p+q;
}
int main()
{
    ll test;
    sc1(test);
    ll t=1;
    while(test--)
    {
        memset(lazy,'N',sizeof lazy);
        memset(tree,0,sizeof tree);
        ll now=0;
        ll n;
        sc1(n);
        for(ll i=1; i<=n; i++)
        {
            ll m;
            sc1(m);
            getchar();
            scanf("%s",crr);
            ll l=strlen(crr);
            while(m--)
            {
                for(ll j=0; j<l; j++)
                {
                    arr[++now]=crr[j]-'0';
                    //cout<<arr[now]<<endl;
                }
            }
        }
        //cout<<now<<endl;
        printf("Case %lld:\n",t++);
        build(1,1,now);
        ll q;
        sc1(q);
        ll qn=1;
        for(ll i=1;i<=q;i++)
        {
            getchar();
            char ch;
            ll l,r;
            scanf("%c",&ch);
            sc2(l,r);

            l++;
            r++;
            if(ch=='F')
                update(1,1,now,l,r,'S');
            else if(ch=='E')
                update(1,1,now,l,r,'C');
            else if(ch=='I')
                update(1,1,now,l,r,'F');
            else
            {
                ll ans=query(1,1,now,l,r);
                printf("Q%lld: %lld\n",qn++,ans);
            }
        }
    }
    return 0;
}
