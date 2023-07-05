#include<stdio.h>
int n,w,c[30],x[30];
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void sort()
{
	int i,j,temp;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(c[i]>c[j])
			{
				swap(&c[i],&c[j]);
			}
		}
	}
}
void containerload()
{
	int i,temp=w;
	for(i=0;i<n;i++)
	{
		temp=temp-c[i];
		if(temp<=w && temp>=0)
		{
			x[i]=1;
		}
		else
		{
			return;
		}
	}
}
int main()
{
	int i;
	printf("Enter no. of items        : ");
	scanf("%d",&n);
	printf("Enter weight of container : ");
	scanf("%d",&w);
	printf("Enter weight of item      : \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&c[i]);
		x[i]=0;
	}
	sort();
	containerload();
	printf("\nWe can load the following weights in cargo...\n\n");
	for(i=0;i<n;i++)
	{
		if(x[i]==1)
			printf("%d\n",c[i]);
	}
}
