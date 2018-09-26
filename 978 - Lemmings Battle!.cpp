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

priority_queue<ll>blue;
priority_queue<ll>green;
int main()
{
    //freopen("out.txt","w",stdout);
    ll test;
    sc1(test);
    while(test--)
    {
        ll n,g,b;
        sc3(n,g,b);
        for(ll i=1;i<=g;i++)
        {
            ll v;
            sc1(v);
            green.push(v);
        }
        for(ll i=1;i<=b;i++)
        {
            ll v;
            sc1(v);
            blue.push(v);
        }
        while(!blue.empty()&&!green.empty())
        {
            queue<ll>bb;
            queue<ll>gg;
            for(ll i=1;i<=n;i++)
            {
                if(!blue.empty()&&!green.empty())
                {
                    ll tb=blue.top();
                    blue.pop();
                    ll tg=green.top();
                    green.pop();
                    //cout<<tg<<" "<<tb<<endl;
                    if(tb>tg)
                    {
                        bb.push(tb-tg);
                    }
                    else if(tg>tb)
                    {
                        gg.push(tg-tb);
                    }
                }
                else
                    break;
            }
            while(!bb.empty())
            {
                ll tp=bb.front();
                bb.pop();
                blue.push(tp);
            }
            while(!gg.empty())
            {
                ll tp=gg.front();
                gg.pop();
                green.push(tp);
            }
        }
        if(blue.empty()&&green.empty())
            printf("green and blue died\n");
        else if(!green.empty())
        {
            printf("green wins\n");
            while(!green.empty())
            {
                ll now=green.top();
                green.pop();
                printf("%lld\n",now);
            }
        }
        else if(!blue.empty())
        {
            printf("blue wins\n");
            while(!blue.empty())
            {
                ll now=blue.top();
                blue.pop();
                printf("%lld\n",now);
            }
        }
        if(test>0)
            printf("\n");

    }
    return 0;
}
