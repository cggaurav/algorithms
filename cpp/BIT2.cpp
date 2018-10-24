#include<iostream>
#include<algorithm>
#include<vector>

#define MAXN 50
using namespace std;
/* 	Binary Index Tree in one dimensions
	to find the prefix sum is the aim!
	
	Let BIT[i] denote the sum of a[i],a[i-1],a[i-1].......,a[i-2^k+1] where k is the number of trailing zeroes in the binary 
	representation of i.
	i&(-i) gives the 2^k! 
*/
int n,m,q,x1,y1,x2,y2;
vector<int> BIT[MAXN+1];

void updateBIT(int i,int j,int value)
{	
    //cout<<" Update "<<endl;		
	
	int x,y;
	for(x=i;x<=n;x+=(x&(-x)))
        for(y=j;y<=m;y+=(y&(-y)))   
	    {      //cout<<"x "<<x<<endl<<"y "<<y<<endl;
	   	       BIT[x][y]+=value;
	    }
}
int findsum(int i,int j)
{	
    int sum=0;
    int x,y;
    
	for(x=i;x>=1;x-=(x&(-x)))
	   for(y=j;y>=1;y-=(y&(-y)))
	   {	  sum+=BIT[x][y];
	   }
	cout<<"sum "<<sum<<endl;
	return sum;
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	int i,j;
	for(i=0;i<=n;i++)
	   BIT[i].reserve(m+1);
	for(i=0;i<=n;i++)
	   for(j=0;j<=m;j++)
	       BIT[i][j]=0;
	for(i=1;i<=n;i++)
	{	
        for(j=1;j<=m;j++)
        {
          int get;  
		  scanf("%d",&get);
		  updateBIT(i,j,get);
        }
	}
	cout<<" BIT "<<endl;
	for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
            cout<<BIT[i][j]<<" ";
        cout<<endl;
    }
    		
	for(i=1;i<=q;i++)
	{	cout<<"x1,y1,x2,y2:"<<endl;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		printf("%d\n",findsum(x2,y2)-findsum(x1-1,y2)-findsum(x2,y1-1)+findsum(x1-1,y1-1));
	}
	
	system("PAUSE");
	return 0;
}
