#include <cstdlib>
#include <iostream>
#include <algorithm>
#define pf printf
#define sf scanf
#define FOR(i, a, b) for(int i=int(a); i<=int(b); i++)

using namespace std;

const int MAXN = 100000;
const int INF = 2000000000;

struct point { int x, y; };
bool operator < (const point& p1, const point& p2)
{
    return ( (p1.x==p2.x) ? (p1.y<p2.y) : (p1.x<p2.x ) );
}
point p[MAXN+1];

int n;
int l[MAXN+1], m[MAXN+1];

int main(int argc, char *argv[])
{
    int ntt;
    scanf("%d", &ntt);
    while(ntt--) {
    sf("%d", &n);

    FOR(i, 1, n) {
        m[i] = INF;
        sf("%d%d", &p[i].x, &p[i].y);
    }
    sort(p+1, p+n+1);

    m[1] = p[1].y;
    l[1]=1;
    
    FOR(i, 2, n) {  // calc l[i] and upd m[l[i]]
        l[i] = upper_bound(m+1, m+n+1, p[i].y) - m;
        m[l[i]] = min( m[l[i]], p[i].y );
        //pf("%d\n", l[i]);
    }

    int ans = 0;
    FOR(i, 1, n)
        ans = max(ans, l[i]);

    pf("%d\n", ans);
    }
    //system("PAUSE");
    return EXIT_SUCCESS;
}

