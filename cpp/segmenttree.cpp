#include <cstdlib>
#include <iostream>
#define FOR(i, a, b) for(int i=int(a); i<=int(b); i++)

using namespace std;
const int INF = 200000000;

struct node { int st, end, val; };

node tree[262144]; // the nearest power of two * 2
int logn;

int n, m;

void printTree()  // jus for debugging
{
    printf("\n");
    FOR(i, 1, ((1<<(logn+1))-1) )
        printf("%d %d %d\n", tree[i].st, tree[i].end, tree[i].val);
    printf("\n");
}

int query(int i, int j, int v=1) // query segment i...j in node v
{
    if(i>j) return 0;  // actually speaking this shudnt happen

    /* Very important base case 
       If this line of code is not written then the algo wont be logn */
    if(i==tree[v].st && j==tree[v].end) return (tree[v].val);

    int lchi=(2*v), rchi=(2*v + 1);

    if(j<=tree[lchi].end) return (query(i, j, lchi));
    if(i>=tree[rchi].st) return (query(i, j, rchi));
    return (query(i, tree[lchi].end, lchi) + query(tree[rchi].st, j, rchi));
}

int main(int argc, char *argv[])
{
    scanf("%d%d", &n, &m);

    /* find ceil(log_2(n)) */
    FOR(i, 0, 31) {
        if((1<<i) >= n) { logn=i; break; }
    }

    /* initialise the leaves */
    FOR( i, (1<<logn), ((1<<(logn+1))-1) ) {
        tree[i].st = tree[i].end = i-(1<<logn)+1;
        tree[i].val = 0;
    }

    int value;
    FOR(i, 1, n) {
        scanf("%d", &value);
        tree[ i + (1<<logn) - 1 ].val  =  value;
    }

    for(int i=((1<<logn)-1); i>=1; i--) {
        int lchi=(2*i), rchi=(2*i + 1);
        tree[i].st = tree[lchi].st;
        tree[i].end = tree[rchi].end;
        tree[i].val = tree[lchi].val + tree[rchi].val;
    }
//    printTree();

    /* process queries */
    int lb, ub;
    FOR(i, 1, m) {
        scanf("%d%d", &lb, &ub);
        printf("%d\n", query(lb, ub));
    }
 
//    system("PAUSE");
    return EXIT_SUCCESS;
}
