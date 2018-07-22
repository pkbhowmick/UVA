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
        ll dis=m-n+1;
        if(dis>3)
        {
            printf("0\n");
            continue;
        }
        if(n%4==1||m%4==1)
        {
            printf("0\n");
            continue;
        }
        ll st;
        if(n%4==2)
        {
            st=n;
        }
        if(n%4==3)
        {
            st=1;
        }
        if(n%4==0)
        {
            st=n+1;
        }
        ll cnt=1;
        while(cnt<dis)
        {
            n++;
            cnt++;
            if(n%4==2)
            {
                st=st&n;
            }
            if(n%4==3)
            {
                st=st&1;
            }
            if(n%4==0)
            {
                st=st&(n+1);
            }
            if(n%4==1)
                st=st&0;
        }
        printf("%lld\n",st);


    }
    return 0;
}
