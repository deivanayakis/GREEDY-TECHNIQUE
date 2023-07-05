#include<stdio.h>
struct edge_list
{
	int s,d,w;
};
struct edge_list res_edge[30];
void sort(struct edge_list e[30],int n)
{
	struct edge_list temp;
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(e[i].w>e[j].w)
			{
				temp=e[i];
				e[i]=e[j];
				e[j]=temp;
			}
		}
	}
}
int find(int parent[],int v)
{
	if(parent[v-1]==v)
		return v;
	else
		return parent[v-1]=find(parent,parent[v-1]);
}
void unionOf(int u,int v,int parent[],int rank[],int n)
{
	if(rank[u-1]<rank[v-1])
		parent[u-1]=v;
	else if(rank[u-1]>rank[v-1])
		parent[v-1]=u;
	else
	{
		parent[v-1]=u;
		rank[u-1]++;
	}
}
int kruskal(struct edge_list e[],int n,int v)
{
	sort(e,n);
	int min_cost=0,ps,pd,w;
	int parent[v],rank[v],i,j=0;
	for(i=1;i<v+1;i++)
	{
		parent[i-1]=i;
		rank[i-1]=0;
	}
	for(i=0;i<n,j!=v-1;i++)
	{
		ps=find(parent,e[i].s);
		pd=find(parent,e[i].d);
		w=e[i].w;
		if(ps!=pd)
		{
			unionOf(ps,pd,parent,rank,n);
			res_edge[j].s=e[i].s;
			res_edge[j].d=e[i].d;
			res_edge[j].w=e[i].w;
			min_cost=min_cost+w;
			j++;
		}
	}
	return min_cost;
}
int main()
{
	int i,no_of_edges,no_of_vertices,result;
	printf("Enter number of vertices: ");
	scanf("%d",&no_of_vertices);
	printf("Enter number of edges   : ");
	scanf("%d",&no_of_edges);
	struct edge_list e[no_of_edges];
	for(i=0;i<no_of_edges;i++)
	{
		printf("Enter source vertex      : ");
		scanf("%d",&e[i].s);
		printf("Enter destination vertex : ");
		scanf("%d",&e[i].d);
		printf("Enter Weight             : ");
		scanf("%d",&e[i].w);
	}
	result=kruskal(e,no_of_edges,no_of_vertices);
	printf("SOURCE\t\tDESTINATION\t\tWEIGHT\n");
	printf("--------------------------------------------------------------------------------------------\n");
	for(i=0;i<no_of_vertices-1;i++)
	{
		printf("   %d\t\t     %d\t\t\t   %d\n",res_edge[i].s,res_edge[i].d,res_edge[i].w);
	}
	printf("--------------------------------------------------------------------------------------------\n");
	printf("MINIMUM COST IS %d\n",result);
	printf("--------------------------------------------------------------------------------------------\n");
	return 0;
}
