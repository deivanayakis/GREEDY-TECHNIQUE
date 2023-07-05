#include<stdio.h>
#include<stdlib.h>
struct node
{
	char data;
	int freq;
	struct node *l,*r;
};
struct MHeap
{
	int size;
	struct node** a;
};
struct node* new_node(char data,int freq)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->l=NULL;
	temp->r=NULL;
	temp->data=data;
	temp->freq=freq;
	return temp;
}
void swap(struct node** a,struct node** b)
{
	struct node* t=*a;
	*a=*b;
	*b=t;
}
void Heapify(struct MHeap* mH,int ind)
{
	int min=ind,l=2*ind+1,r=2*ind+2;
	if (l < mH->size && mH->a[l]->freq < mH->a[min]->freq)
		min=l;
	if (r < mH->size && mH->a[r]->freq < mH->a[min]->freq)
		min=r;
	if (min!=ind)
	{
		swap(&mH->a[min],&mH->a[ind]);
		Heapify(mH,min);
	}
}
void buildHeap(struct MHeap* mH)
{
	int i=(mH->size-2)/2;
	for(;i>=0;i--)
	{
		Heapify(mH,i);
	}
}
struct MHeap* createMHeap(char d[],int f[],int n)
{
	struct MHeap* mH=(struct MHeap*)malloc(sizeof(struct MHeap));
	mH->size=n;
	mH->a=(struct node**)malloc(mH->size*sizeof(struct node*));
	int i;
	for(i=0;i<n;i++)
	{
		mH->a[i]=new_node(d[i],f[i]);
	}
	buildHeap(mH);
	return mH;
}
struct node* extractMin(struct MHeap* mH)
{
	struct node* temp=mH->a[0];
	mH->a[0]=mH->a[mH->size-1];
	mH->size--;
	Heapify(mH,0);
	return temp;
}
void insertMHeap(struct MHeap* mH,struct node* n_rootnode)
{
	int i=mH->size;
	mH->size++;
	while(i!=0 && n_rootnode->freq<mH->a[(i-1)/2]->freq)
	{
		mH->a[i]=mH->a[(i-1)/2];
		i=(i-1)/2;
	}
	mH->a[i]=n_rootnode;
}
struct node* buildHTree(char data[],int freq[],int n)
{
	struct MHeap* mH=createMHeap(data,freq,n);
	struct node *left,*right,*root;
	while(mH->size!=1)
	{
		left=extractMin(mH);
		right=extractMin(mH);
		root=new_node('$',left->freq+right->freq);
		root->l=left;
		root->r=right;
		insertMHeap(mH,root);
	}
	return extractMin(mH);
}
void HuffmanCode(char data[],int freq[],int n)
{
	struct node* root=buildHTree(data,freq,n);
	int arr[30];
	printHCode(root,arr,0);
}
void printHCode(struct node* n,int arr[],int ind)
{
	if(n->l)
	{
		arr[ind]=0;
		printHCode(n->l,arr,ind+1);
	}
	if(n->r)
	{
		arr[ind]=1;
		printHCode(n->r,arr,ind+1);
	}
	if(n->l==NULL && n->r==NULL)
	{
		int i;
		printf("%c",n->data);
		for(i=0;i<ind;i++)
		{
			printf("%d",arr[i]);
		}
		printf("\n");
	}
}
int main()
{
	int n;
	printf("Enter no. of data : ");
	scanf(" %d",&n);
	char data[n];
	int freq[n],i;
	for(i=0;i<n;i++)
	{
		printf("Enter data :");
		scanf("%s",&data[i]);
		printf("Enter frequency : ");
		scanf("%d",&freq[i]);
	}
	HuffmanCode(data,freq,n);
	return 0;
}
