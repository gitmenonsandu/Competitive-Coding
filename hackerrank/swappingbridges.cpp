#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define l long

#define MAX 100003
#define MOD 1000000007

#define fin(i,a,n) for(i=a;i<=n;i++)
#define fde(i,a,n) for(i=n;i>=a;i--)

#define sd(a) scanf("%d",&a)
#define sld(a) scanf("%ld",&a)
#define slld(a) scanf("%lld",&a)
#define slf(a) scanf("%lf",&a)
#define sllf(a) scanf("%llf",&a)

#define pd(a) printf("%d",a)
#define pld(a) printf("%ld",a)
#define plld(a) printf("%lld",a)
#define plf(a) printf("%lf",a)
#define pllf(a) printf("%llf",a)
#define pn printf("\n")
#define ps printf(" ")

#define mp make_pair
#define pb push_back

int a[MAX];
bool visited[MAX];

int main()
{
    int t,n,i;
    sd(t);
    while(t--)
    {
        sd(n);
        fin(i,1,n)
        {
            sd(a[i]);
            visited[i] = false;
        }
        int res = 0;
        fin(i,1,n)
        {
            if(!visited[i])
            {
                visited[i] = true;
                int j = a[i];
                while(!visited[j])
                {
                    visited[j] = true;
                    j = a[j];
                }
                res++;
            }
        }
        pd(res-1);
        pn;
    }
    return 0;
}
