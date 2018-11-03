#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;
int heapsize,n,minheap[10001],value;
int q;
void printheap()
{
	for(int i=1;i<=heapsize;i++)
 		cout<<minheap[i]<<" ";
		cout<<endl;
		cin>>q;
}
void minheapify(int i)
{	/*cout<<" minheapify "<<endl;*/
	int smallest=i,lc=2*i,rc=2*i+1;
	if(lc<=heapsize && minheap[lc]<minheap[smallest])
		smallest=lc;
	if(rc<=heapsize && minheap[rc]<minheap[smallest])
		smallest=rc;
	if(smallest!=i)
	  {	swap(minheap[i],minheap[smallest]);
		minheapify(smallest);
	  }
}
void buildminheap()
{	cout<<" buildminheap "<<endl;
	for(int i=(heapsize/2);i>=1;i--)
	  minheapify(i);
}
void heapsort()

{	cout<<" heapsort "<<endl;
	int i;
	for(i=1;i<=n;i++)
	{
	swap(minheap[1],minheap[heapsize]);
	heapsize--;
	minheapify(1);
	}	
}
void insertheap()
{	/*cout<<" Insertheap "<<endl;*/
	buildminheap();
	heapsize++;
	minheap[heapsize]=value;
	int i=heapsize;
	while(minheap[i]<minheap[i/2] && i>=1)
	{
		swap(minheap[i],minheap[i/2]);
		i=i/2;
	}
	
}
int main()
{
	scanf("%d",&n);
	heapsize=n;
	int i;
	for(i=1;i<=n;i++)
 	   scanf("%d",&minheap[i]);
	buildminheap();
	printheap();
	heapsort();
	heapsize=n;	
	printheap();
	
	printf("Enter value to be entered\n");
	scanf("%d",&value);
	insertheap();
	printheap();
	return 0;
}
