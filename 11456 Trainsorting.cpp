#include <bits/stdc++.h>
#define pb push_back
#define sc1(n) scanf("%lld",&n)
#define sc2(a,b) scanf("%lld%lld",&a,&b)
#define sc3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define MX 100000
using namespace std;

typedef long long int ll;
typedef unsigned long long ul;

ll in[2005];
ll de[2005];
ll arr[2005];
int main()
{
    ll test;
    sc1(test);
    while(test--)
    {
        ll n;
        sc1(n);
        for(ll i=0;i<n;i++)
        {
            sc1(arr[i]);
        }
        for(ll i=0;i<n;i++)
        {
            in[i]=1;
            de[i]=1;
        }
        for(ll i=n-1;i>=0;i--)
        {
            for(ll j=i-1;j>=0;j--)
            {
                if(arr[i]>arr[j]&&in[j]<in[i]+1)
                    in[j]=in[i]+1;
                if(arr[i]<arr[j]&&de[j]<de[i]+1)
                    de[j]=de[i]+1;
            }
        }
        ll mx=0;
        for(ll i=0;i<n;i++)
        {
            mx=max(mx,in[i]+de[i]-1);
        }
        printf("%lld\n",mx);
    }
    return 0;
}
