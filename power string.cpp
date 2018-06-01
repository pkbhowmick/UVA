#include <bits/stdc++.h>
#define pb push_back
#define sc1(n) scanf("%lld",&n)
#define sc2(a,b) scanf("%lld%lld",&a,&b)
#define sc3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define MX 100000
using namespace std;

typedef long long int ll;
typedef unsigned long long ul;

char T[1000006];
ll pi[1000006];
char P[1000006];
void prefix()
{
    ll now;
    pi[0]=now=-1;
    ll len=strlen(T);
    for(ll i=1;i<len;i++)
    {
        while(now!=-1&&T[now+1]!=T[i])
            now=pi[now];
        if(T[now+1]==T[i])pi[i]=++now;
        else pi[i]=now=-1;
    }
}
ll kmp()
{
    ll now;
    now=-1;
    ll n=strlen(T);
    ll m=strlen(P);
    ll cnt=0;
    for(ll i=0;i<n;i++)
    {
        while(now!=-1&&P[now+1]!=T[i])
            now=pi[now];
        if(P[now+1]==T[i])++now;
        else
            return now=-1;

       // cout<<now<<endl;

         if(now==m-1)
                {
                    cnt++;
                    now=-1;
                }
    }
    return cnt;
}
int main()
{
    while(scanf("%s",T)!=EOF)
    {
        if(strcmp(T,".")==0)
            break;
        ll len=strlen(T);
        prefix();
        ll mx=pi[len-1];
        mx++;
        mx=len-mx;

        for(ll i=0;i<mx;i++)
            P[i]=T[i];
        P[mx]='\0';
        ll now=kmp();
        //cout<<"len "<<now<<endl;
        if(now*mx==len)
        {
            printf("%lld\n",now);
        }
        else
            printf("1\n");
    }
    return 0;
}
