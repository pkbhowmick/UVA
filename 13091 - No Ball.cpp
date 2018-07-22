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
    char A[6][6];
    ll test;
    sc1(test);
    ll t=1;
    while(test--)
    {
        ll no=0;
        ll line;
        for(ll i=1;i<=5;i++)
        {
            for(ll j=1;j<=5;j++)
            {
                cin>>A[i][j];
                if(A[i][j]=='|')
                {
                    line=j;
                }
            }
        }
        for(ll i=1;i<=5;i++)
        {
            for(ll j=1;j<=5;j++)
            {
                if(A[i][j]=='>'&&j>line)
                {
                    no=1;
                }
                else if(A[i][j]=='<'&&j<line)
                {
                    no=1;
                }
            }
        }
        printf("Case %lld: ",t++);
        if(no)
        {
            printf("No Ball\n");
        }
        else
            printf("Thik Ball\n");
    }
    return 0;
}
