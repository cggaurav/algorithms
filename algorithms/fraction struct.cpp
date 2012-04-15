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

/* Main code*/
struct fraction
{
    int n,d;
    
    fraction()
    {
        n=d=0;
    }   
    void simplify()
    {
        if(d<0)
        { d=-d; n=-n;}
        for(int i=2;i<=d/2;i++)
        {
            if(n%i==0 && d%i==0)
            {
                n/=i;
                d/=i;
            }
        }   
    }
    void add(fraction f1,fraction f2)
    {
        n=f1.n*f2.d+f2.n*f1.d;
        d=f1.d*f2.d;
        simplify();
    }
    void subtract(fraction f1,fraction f2)
    {
        n=f1.n*f2.d-f2.n*f1.d;
        d=f1.d*f2.d;
        simplify();
    }
    void multiply(fraction f1,fraction f2)
    {
        n=f1.n*f2.n;
        d=f1.d*f2.d;
        simplify();
    }
    void divide(fraction f1,fraction f2)
    {
        n=f1.n*f2.d;
        d=f2.n*f1.d;
        simplify();
    }
};

int main()
{   
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    
    while(1)
    {
        fraction f1,f2,f;int x;
        scanf("%d %d %d %d %d",&f1.n,&f1.d,&f2.n,&f2.d,&x);
        if(x==4)
        {   cout<<"The End\n";
            break;
        }
        else if(f1.d==0 ||f2.d==0)
        cout<<"Division by zero\n";
        else if(x==0)
        {   
            f.add(f1,f2);
            cout<<f.n<<" "<<f.d<<endl;
        }
        else if(x==1)
        {
            f.subtract(f1,f2);
            cout<<f.n<<" "<<f.d<<endl;
        }
        else if(x==2)
        {
            f.multiply(f1,f2);
            cout<<f.n<<" "<<f.d<<endl;
        }
        else if(x==3)
        {
            if(f1.d==0 || f2.n==0)
            cout<<"Division by 0\n";
            else
            {   f.divide(f1,f2);
                cout<<f.n<<" "<<f.d<<endl;
            }
        }
    }
    
system("PAUSE");
return 0;
}
