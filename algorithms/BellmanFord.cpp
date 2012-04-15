/* Gaurav Chandrashekar */


/* Bellman Ford - Find the single source shortest path for negative weight edges- check for negative weight cycles
    V*E solution*/

#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <cmath>
#include <queue>
#include <map>
#include <iostream>
#include <list>
#include <deque>

using namespace std;

/* traversing macros */
#define FOR(i, a, b)        for(int i=int(a); i<=int(b); i++)
#define FORN(i, n)          FOR(i, 1, int(n))
#define RFOR(i, a, b)       for(int i=int(a); i>=int(b); i--)
#define TR(c, it)           for(typeof((c).begin()) it = (c).begin(); it!=(c).end(); it++)

/* shortform macros */
#define PB                  push_back
#define MP                  make_pair
#define SIZE(c)             (int((c).size()))

/* debug and printing macros */
#define _DEBUG(x) cerr<<#x<<" = "<<x<<endl;

/* typedefs */
typedef         long long           LL;
typedef         long double         LD;
typedef         vector<int>         VI;
typedef         vector<bool>        VB;
typedef         pair<int, int>      PII;
typedef         vector< PII >       VPII;
typedef         set<int>            SI;

/* infinity */

#define OO 200000000

int ntt;
int n,m;
vector< pair<int,int> > A[10001];
int d[10001];

int main()
{   
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    //scanf("%d",&ntt);   
    //while(ntt--)
    scanf("%d %d",&n,&m);
    FORN(i,n)
    {
        int l;
        scanf("%d",&l);
        FORN(j,l)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            A[i].PB(MP(a,b));
        }
    }   
    fill(d+1,d+10001,OO);
    d[1]=0;
    FORN(i,n)
    FORN(u,n)
    {
        FOR(j,0,A[u].size()-1)
        {
            int v=A[u][j].first;
            int w=A[u][j].second;
            
            d[v]=min(d[v],d[u]+w);
        }
    }
    FORN(i,n)
    cout<<i<<" "<<d[i]<<endl;
    
    bool nwc=false;
    FORN(u,n)
    {
        FOR(j,0,A[u].size()-1)
        {
            int v=A[u][j].first;
            int w=A[u][j].second;
            
            if(d[v]>d[u]+w)
            nwc=true;
        }
    }
    
    cout<<"nwc "<<nwc<<endl;
    
    system("PAUSE");
    return 0;
}
