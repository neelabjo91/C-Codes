#include<stdio.h>
#include<conio.h>


struct treenode
{
    int treevalue;
    struct treenode *left;
    struct treenode *right;
};
int arr[100];
int nodearr[100];
int j=0;
struct treenode *root=NULL;

void inserttreenode(int num, int nodenum)
{
    if(nodenum==1)
    {
        struct treenode *newnode= (struct treenode*) malloc (sizeof(struct treenode));
        newnode->treevalue=num;
        newnode->left=NULL;
        newnode->right=NULL;
        root=newnode;
    }
    else
    {
        int k=1;
        while(nodenum>1)
        {
            if(nodenum%2==0)
            {
                nodearr[k]=0;
                nodenum=nodenum/2;
            }
            else
            {
                nodearr[k]=1;
                nodenum=nodenum/2;
            }
            k++;
        }
        int p=0;
        struct treenode* temp=root;
        for(p=k-1;p>1;p--)
        {
            if(nodearr[p]==0)
                temp=temp->left;
            else
                temp=temp->right;
        }
        struct treenode *newnode= (struct treenode*) malloc (sizeof(struct treenode));
        newnode->treevalue=num;
        newnode->left=NULL;
        newnode->right=NULL;
        if(nodearr[1]==0)
            temp->left=newnode;
        else
            temp->right=newnode;
    }
}

void printtree(struct treenode* node)
{
    if(node->left!=NULL)
        printtree(node->left);
    printf("%d ",node->treevalue);
    if(node->right!=NULL)
        printtree(node->right);
}

void main()
{
int num=0;
int n=0;
int val=0;
printf("Enter the number of numbers you want to enter = ");
scanf("%d",&num);
int i;
for(i=1;i<=num;i++)
{
    printf("Enter the number = ");
    scanf("%d",&arr[i]);
}
for(i=1;i<=num;i++)
{
    inserttreenode(arr[i],i);
}
printtree(root);
/*printf("\nEnter the value for the sum of 2 numbers = ");
scanf("%d",&val);*//*
val=height(root);//);
printf("\nHeight=%d",val);*/
}
