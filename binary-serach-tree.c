#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *left,*right;
};
typedef struct node node;
node* insert(node*,int);
void inorder(node*);
void preoder(node*);
void postorder(node*);
node* del(node*,int);
node* largest(node*);
int height(node*);
node* smallest(node*);
int total(node*);
int inter(node*);
int exter(node*);
void deltree(node*);
void mirror(node*);
void search(node*,int);
node *tree=NULL,*temp,*temp1,*ptr;
int item,items;
void main()
{
int c;
while(1)
{
printf("\n1. insert\n");
printf("2. inorder traversal\n");
printf("3. preorder traversal \n");
printf("4. postorder traverseal\n");
printf("5. delete\n");
printf("6. largest node in tree\n");
printf("7. smallest node in tree\n");
printf("8. height of the tree\n");
printf("9. total number of nodes\n");
printf("10. total number of internal nodes\n");
printf("11. total number of external nodes\n");
printf("12. delete full tree\n");
printf("13. create mirror of the tree\n");
printf("14. search\n");
printf("15. exit\n");
printf("enter your choice=");
scanf("%d",&c);
switch(c)
{
case 1:
printf("enter the element to insert=");
scanf("%d",&item);
tree=insert(tree,item);
break;
case 2:
inorder(tree);
break;
case 3:
preorder(tree);
break;
case 4:
postorder(tree);
break;
case 5:
printf("enter value you want to delete from tree=");
scanf("%d",&items);
del(tree,items);
break;
case 6:
temp1=largest(tree);
printf("%d is largest node in the tree\n",temp1->data);
break;
case 7:
temp=smallest(tree);
printf("%d is smallest node in the tree\n",temp->data);
break;
case 8:
item=height(tree);
printf("height of the tree is =%d\n",item);
break;
case 9:
item=total(tree);
printf("total number of nodes is =%d\n",item);
break;
case 10:
item=inter(tree);
printf("total number of internal nodes is =%d\n",item);
break;
case 11:
item=exter(tree);
printf("total number of external nodes is =%d\n",item);
break;
case 12:
deltree(tree);
break;
case 13:
mirror(tree);
break;
case 14:
printf("enter element you want to search=");
scanf("%d",&item);
search(tree,item);
break;
case 15:
exit(0);
default:
printf("invalid choice");
}
}
}
node* insert(node* tree,int val)
{
if(tree==NULL)
{
tree=(node*)malloc(sizeof(node));
tree->data=val;
tree->left=NULL;
tree->right=NULL;
}
else if(val<=tree->data)
tree->left=insert(tree->left,val);
else
tree->right=insert(tree->right,val);
return tree;
}
void inorder(node* tree)
{
if(tree!=NULL)
{
inorder(tree->left);
printf(" %d",tree->data);
inorder(tree->right);
}
}
void preorder(node* tree)
{
if(tree!=NULL)
{
printf(" %d",tree->data);
preorder(tree->left);
preorder(tree->right);
}
}
void postorder(node* tree)
{
if(tree!=NULL)
{
postorder(tree->left);
postorder(tree->right);
printf(" %d",tree->data);
}
}
node* del(node* tree,int a)
{
if(tree==NULL)
return tree;
else if(a<tree->data)
tree->left=del(tree->left,a);
else if(a>tree->data)
tree->right=del(tree->right,a);
else if(tree->left!=NULL&&tree->right!=NULL)
{
temp=largest(tree->left);
tree->data=temp->data;
del(tree->left,tree->data);
}
else
{
temp=tree;
if(tree->left==NULL&&tree->right==NULL)
tree=NULL;
else if(tree->left!=NULL)
tree=tree->left;
else
tree=tree->right;
free(temp);
}
return tree;
}
node* largest(node* tree)
{
if(tree==NULL||tree->right==NULL)
return tree;
else
largest(tree->right);
}
node* smallest(node* tree)
{
if(tree==NULL||tree->left==NULL)
return tree;
else
largest(tree->left);
}
int height(node* tree)
{
int l,r;
if(tree==NULL)
return 0;
else
{
l=height(tree->left);
r=height(tree->right);
if(l>r)
return l+1;
else
return r+1;
}
}
int total(node* tree)
{
if(tree==NULL)
return 0;
else
return total(tree->left)+total(tree->right)+1;
}
int inter(node* tree)
{
if(tree==NULL)
return 0;
else if(tree->left==NULL&& tree->right==NULL)
return 0;
else
return inter(tree->left)+inter(tree->right)+1;
}
int exter(node* tree)
{
if(tree==NULL)
return 0;
else if(tree->left==NULL&& tree->right==NULL)
return 1;
else
return inter(tree->left)+inter(tree->right);
}
void deltree(node* tree)
{
if(tree!=NULL)
{
deltree(tree->left);
deltree(tree->right);
free(tree);
}
}
void mirror(node* tree)
{
if(tree!=NULL)
{
mirror(tree->left);
mirror(tree->right);
temp=tree->left;
tree->left=tree->right;
tree->right=temp;
}
}
void search(node* tree, int val)
{
if(tree==NULL)
{
printf("not found\n");
return 0;
}
if(tree->data==val)
{
printf("element found in the tree\n");
return 0;
}
else if(val>tree->data)
 search(tree->right,val);
else
 search(tree->left,val);
}
