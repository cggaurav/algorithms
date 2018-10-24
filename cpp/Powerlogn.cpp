#include <stdio.h>
/* Gaurav Chandrashekar */

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
int cp(int base,int exp)
{
    if(exp==0)
    return 1;
    int p=cp(base,exp/2);
    if(exp%2==0)
    return p*p;
    else 
    return base*p*p;
}
int main()
{
    int base,exp;
    cin>>base>>exp;
    printf("%d\n",cp(base,exp));  
    system("Pause");
    return 0;
}

