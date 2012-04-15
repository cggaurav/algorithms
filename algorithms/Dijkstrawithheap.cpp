#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
/*
DIJKSTRA a (E+V)logV solution
*/

int m,n;
int weight[101][101];
int i,j,q,heapsize;

struct binaryminheap
{	int node;// the vertice
	int sdistance;//sdistance
	int visited;// visited
};
/* here vertice[i] denoted the details of the ith vertice!
*/ 
binaryminheap vertice[101];

void minheapify(int i)
{
	int lc=2*i;
	int rc=2*i+1;
	int smallest=i;// indice of the smallest sdistance 
	if(lc<=heapsize && vertice[lc].sdistance<vertice[smallest].sdistance)
	 smallest=lc;
	if(rc<=heapsize && vertice[rc].sdistance<vertice[smallest].sdistance)
	 smallest=rc;
	if(smallest!=i)
	  {swap(vertice[i],vertice[smallest]);
	   minheapify(smallest);
	  }
}
void buildminheap()
{
	int i;
	for(i=heapsize/2;i>=1;i--)
	 minheapify(i);
}
void printheap()
{	cout<<"vertice    "<<" sdistance    "<<" visited    "<<endl;
	for(i=1;i<=n;i++)
	{
		cout<<vertice[i].node<<" "<<vertice[i].sdistance<<" "<<vertice[i].visited<<endl;
		
	}
}
void getminheap()
{
  swap(vertice[1],vertice[heapsize]);
  heapsize--;
  minheapify(1);
  
}
void seepup(int i)
{
	if(vertice[i].sdistance<vertice[i/2].sdistance)
	 swap(vertice[i],vertice[i/2]);
}
int main()
{	
	cout<<"Number of Vertices"<<endl;
	scanf("%d",&n);
	cout<<"Number of Edges "<<endl;
	scanf("%d",&m);
	cout<<"The edges and the corresponding weights are "<<endl;
	int a,b,c;
	for(i=1;i<=m;i++)	 
	{	
		scanf("%d%d%d",&a,&b,&c);
		weight[a][b]=c;
		weight[b][a]=c;
	}
	cout<<"Adjacency Matrix! "<<endl;
	for(i=1;i<=n;i++)
	{for(j=1;j<=n;j++)
		cout<<weight[i][j]<<" ";
		cout<<endl;
	}	 
	cin>>q;	   	   	    
	/*initialize*/
	for(i=1;i<=n;i++)
	{
		vertice[i].node=i;
		vertice[i].sdistance=200000000;
		vertice[i].visited=0;
		if(i==1)
		{  vertice[i].sdistance=0;	   
		   vertice[i].visited=1;
        }
	}
	
	heapsize=n;
	buildminheap();	   

	while(heapsize!=0)
	{
		
		printheap();
		cin>>q;
		cout<<"Processing "<<vertice[1].node<<endl;
		cin>>q;
		for(j=1;j<=n;j++)
		 if(vertice[j].sdistance>vertice[1].sdistance+weight[vertice[j].node][vertice[1].node] && weight[vertice[j].node][vertice[1].node]>0)
		 {
		 	vertice[j].sdistance=vertice[1].sdistance+weight[vertice[j].node][vertice[1].node];
			seepup(j);	   	  
		 
		 }
		printheap();
		cin>>q;
		vertice[1].visited=1;
		getminheap();	 
	}	 
	printheap();
	return 0;
	
}


