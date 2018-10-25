#include<stdio.h>
#include<conio.h>


struct treenode
{
    int treevalue;
    struct treenode *left;
    struct treenode *right;
};
int arr[100];
int maxleft=0;
int maxright=0;
int nodearr[100];

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

int printouterleft(struct treenode* node, int curlevel, int level)
{
    int val1=0, val2=0;
    if(curlevel<level && leftbool==0)
    {
        if(node->left!=NULL && leftbool==0 && (val1!= -1 || val2!=-1))
        {
            val1 = printouterleft(node->left,curlevel+1,level);
            if(val1 != -1 )
                return(val1);
        }
        if(node->left==NULL && node->right!=NULL && leftbool==0 && (val1!= -1 || val2!=-1))
        {
            val2 = printouterleft(node->right,curlevel+1,level);
            if(val2!=-1 )
                return(val2);
        }
        if(node->left==NULL && node->right==NULL)
            return(-1);
        return(0);
    }

    else if(curlevel==level && leftbool==0)
    {
        leftbool=1;
        return(node->treevalue);
    }
}

int printouterright(struct treenode* node, int curlevel, int level)
{
    int val1=0, val2=0;
    if(curlevel<level && rightbool==0)
    {
        if(node->right!=NULL && rightbool==0 && (val1!= -1 || val2!=-1))
        {
            val2 = printouterright(node->right,curlevel+1,level);
            if(val2!=-1)
                return(val2);
        }
        if(node->left!=NULL && rightbool==0 && (val1!= -1 || val2!=-1))
        {
            val1 = printouterright(node->left,curlevel+1,level);
            if(val1!=-1)
                return(val1);
        }
        if(node->left==NULL && node->right==NULL)
            return(-1);
        return(0);
    }

    else if(curlevel==level && rightbool==0)
    {
        rightbool=1;
        return(node->treevalue);
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

printf("\n%d",ht);
int value1 = 0, value2 = 0;
for(i=0;i<=ht;i++)
{
    value1 = printouterleft(root,0,i);
    leftbool=0;
    printf("\t%d",value1);
    value2 = printouterright(root,0,i);
    rightbool=0;
    if(value2!=value1)
        printf("\t%d",value2);
}

}
