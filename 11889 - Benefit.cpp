#include <bits/stdc++.h>
#define pb push_back
#define sc1(n) scanf("%lld",&n)
#define sc2(a,b) scanf("%lld%lld",&a,&b)
#define sc3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define MX 100000
using namespace std;
typedef long long int ll;
ll findlcm(ll a,ll b)
{
    ll n=__gcd(a,b);
    ll res=(a*b)/n;
    return res;
}
int main()
{
    //freopen("out.txt","w",stdout);
    ll test;
    sc1(test);
    while(test--)
    {
        ll a,b;
        sc2(a,b);
        if(b%a!=0)
        {
            printf("NO SOLUTION\n");
            continue;
        }
        ll now=1e18;
        /*
        vector<ll>v;
        ll tem=a;
        for(ll i=2; i*i<=tem; i++)
        {
            while(tem%i==0)
            {
                v.push_back(i);
                tem=tem/i;
            }
        }
        if(tem!=1)
            v.push_back(tem);
        ll id=-1;
        while(findlcm(a,now)!=b)
        {
            now=now*v[++id];
            //cout<<now<<" "<<findlcm(a,now)<<endl;
        }
        //printf("%lld\n",now);
        */
        ll ans=b/a;
        for(ll i=1;;i++)
        {
            if(ans*i<=b)
            {
                if(findlcm(ans*i,a)==b)
                {
                    now=min(now,ans*i);
                    break;
                }
            }
            else
                break;
        }
        printf("%lld\n",now);


    }
    return 0;
}
//8866 1844128
