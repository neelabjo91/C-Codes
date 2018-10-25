#include<stdio.h>
#include<conio.h>

struct treenode
{
    int treevalue;
    struct treenode *left;
    struct treenode *right;
    struct treenode *next;
};

int arr[100];
int maxleft=0;
int maxright=0;
int nodearr[100];

int first=0;

struct treenode *head = NULL;
struct treenode *traverse = NULL;

struct treenode *head1;
struct treenode *head2;


struct treenode *root=NULL;
int leftbool=0;
int rightbool=0;

void inserttreenode(struct treenode *node, int num)
{
    if(node==NULL)
    {
        struct treenode *newnode= (struct treenode*) malloc (sizeof(struct treenode));
        newnode->treevalue=num;
        newnode->left=NULL;
        newnode->right=NULL;
        root=newnode;
    }
    else if(num < node->treevalue && node->left!=NULL)
    {
        node=node->left;
        inserttreenode(node,num);
    }
    else if(num>node->treevalue && node->right!=NULL)
    {
        node=node->right;
        inserttreenode(node,num);
    }
    else
    {
        struct treenode *newnode= (struct treenode*) malloc (sizeof(struct treenode));
        newnode->treevalue=num;
        newnode->left=NULL;
        newnode->right=NULL;
        if(num < node->treevalue )
            node->left=newnode;
        else
            node->right=newnode;
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

int height(struct treenode* node)
{
    int leftht=0,rightht=0;
    if(node->left==NULL && node->right==NULL)
        return(0);
    if(node->left!=NULL)
        leftht=height(node->left);
    if(node->right!=NULL)
        rightht=height(node->right);

    if(leftht>rightht)
        return(leftht+1);
    else if(rightht>=leftht)
        return(rightht+1);
}



int findancestor(struct treenode *node, int value1, int value2)
{
    int val=0;
    if(root==NULL)
        return(-1);

    else if(value1>=node->treevalue && value2<=node->treevalue)
        return(node->treevalue);
    else if(value1<=node->treevalue && value2>=node->treevalue)
        return(node->treevalue);

    else if(value1<node->treevalue && value2<node->treevalue)
    {
        if(node->left==NULL)
            return(-1);
        else
        {
            val=findancestor(node->left,value1,value2);
            return(val);
        }
    }
    else if(value1>node->treevalue && value2>node->treevalue)
    {
        if(node->right==NULL)
            return(-1);
        else
        {
            val=findancestor(node->right,value1,value2);
            return(val);
        }
    }
    return(-1);
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
    inserttreenode(root,arr[i]);
}
printtree(root);

int value1 = 0, value2 = 0;

printf("Enter the number = ");
scanf("%d",&value1);
printf("Enter the number = ");
scanf("%d",&value2);

int ancestor = findancestor(root,value1,value2);
if(ancestor == -1)
    printf("No common ancestor");
else
    printf("The common ancestor is = %d",ancestor);
}
