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



int createll(struct treenode* node, int curlevel, int level)
{
    int val1=0, val2=0;
    if(curlevel<level)
    {
        if(node->left==NULL && node->right==NULL)
            return(0);
        else if(node->left!=NULL && node->right==NULL)
            createll(node->left,curlevel+1,level);
        else if(node->left==NULL && node->right!=NULL)
            createll(node->right, curlevel+1,level);
        else if(node->left!=NULL && node->right!=NULL)
        {
            createll(node->left,curlevel+1,level);
            createll(node->right,curlevel+1,level);
        }
        return(0);
    }
    else if(curlevel==level && first==0)
    {
        head=node;
        first=1;
        traverse=node;
        traverse->next=NULL;
        return(0);
    }
    else if(curlevel==level && first!=0)
    {
        traverse->next=node;
        traverse=traverse->next;
        traverse->next=NULL;
        return(0);
    }
}

void printll(struct treenode *firstnode)
{
    while(firstnode!=NULL)
    {
        printf("%d\t",firstnode->treevalue);
        firstnode=firstnode->next;
    }
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
int ht=height(root);

printf("\n%d\n",ht);
int value1 = 0, value2 = 0;

for(i=0;i<=ht;i++)
{
    int k=0;
    k = createll(root,0,i);
    first=0;
    printll(head);
    printf("\n");
    head=NULL;
}
}
