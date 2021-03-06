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

pair<ll,ll> a[5*MAX];
vector<int> adjList[5*MAX];
bool visited[5*MAX];
int parent[5*MAX];
vector<ll> v,v1;

ll dfs(int k)
{
    visited[k] = true;
    int j;
    for(j=0;j<adjList[k].size();j++)
        {
            if(!visited[adjList[k][j]])
            {
                parent[adjList[k][j]] = k;
                a[k].second += dfs(adjList[k][j]);
            }
        }
    return a[k].second + a[k].first ;
}

int main()
{
    int n,i;
    int p,q;
    sd(n);
    ll sum = 0;
    fin(i,1,n)
    {
        slld(a[i].first);
        a[i].second = 0;
        sum += a[i].first;
        visited[i] = false;
    }
    fin(i,1,n-1)
    {
        sd(p);
        sd(q);
        adjList[p].push_back(q);
        adjList[q].push_back(p);
    }
    parent[1]=-1;
    dfs(1);
    ll m = -1,temp;
    int j;
    for(j=0;j<adjList[1].size();j++)
    {
        temp = sum - a[adjList[1][j]].first - a[adjList[1][j]].second;
        v.pb(temp);
    }
    sort(v.begin(),v.end());
    v1.pb(v[0]);
    fin(i,2,n)
    {
        v.clear();
        for(j=0;j<adjList[i].size();j++)
        {
            if(adjList[i][j]==parent[i])
            {
                temp = a[i].first + a[i].second ;
                v.pb(temp);
            }
            else
            {
                temp = sum - a[adjList[i][j]].first - a[adjList[i][j]].second;
                v.pb(temp);
            }
        }
        sort(v.begin(),v.end());
        v1.pb(v[0]);
    }
    m = *max_element(v1.begin(),v1.end());
    plld(m);
    return 0;
}
