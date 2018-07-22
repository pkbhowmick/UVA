#include <bits/stdc++.h>
#define pb push_back
#define sc1(n) scanf("%lld",&n)
#define sc2(a,b) scanf("%lld%lld",&a,&b)
#define sc3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define MX 100000
using namespace std;

typedef long long int ll;
typedef unsigned long long ul;

int main()
{
    ll arr[30];
    ll cnt[30];
    ll test;
    sc1(test);
    ll t=1;
    while(test--)
    {
        memset(arr,0,sizeof arr);
        memset(cnt,0,sizeof cnt);
        string str;
        cin>>str;
        ll len=str.size();
        for(ll i=0; i<len; i++)
        {
            ll now=str[i]-'a';
            arr[now]++;
        }
        ll low;
        for(ll i=0;i<26;i++)
        {
            if(arr[i]>0)
            {
                low=i;
                break;
            }
        }
        for(ll i=0; i<26; i++)
        {
            if(arr[i]>0)
            {
                cnt[i]++;
                arr[i]--;
                while(arr[i]>0)
                {
                    cnt[low]++;
                    arr[i]--;
                }
            }
        }
        for(ll i=0; i<26; i++)
        {
            char ch=i+'a';
            while(cnt[i]>0)
            {
                printf("%c",ch);
                cnt[i]--;
            }
        }
        printf("\n");
    }
    return 0;
}
