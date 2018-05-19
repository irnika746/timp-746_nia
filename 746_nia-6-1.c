#include <stdio.h>
#include <stdlib.h>
typedef struct list
{
int key;
int value;
struct list *right;
struct list *left;
struct list *parent;
}list;

list *head = NULL;
list *tail = NULL;

int isEmpty()
{
if (head==NULL && tail==NULL)
return 1;
else return 0;
}

list *init ()
{
list *ptr=malloc(sizeof(list));
ptr->value=0;
ptr->key=-100;
ptr->left=NULL;
ptr->right=NULL;
ptr->parent=NULL;
return ptr;
}

void insert (list *ptr, int k, int v )
{
if (ptr->key==-100)
{
ptr->key=k;
ptr->value=v;
}
else
{
while (1)
{
if (k < ptr->key)
{
if (ptr->left==NULL)
{
list *ptr1=init();
ptr->left=ptr1;
ptr1->key=k;
ptr1->value=v;
ptr1->parent=ptr;
break;
}
else
{ptr=ptr->left;
continue;}
}
else if ( k > ptr->key )
{
if (ptr->right==NULL)
{
list *ptr1=init();
ptr->right=ptr1;
ptr1->key=k;
ptr1->value=v;
ptr1->parent=ptr;
break;
}
else
{ptr=ptr->right;
continue;}
}
else if (k==ptr->key)
{ptr->value=v;
break;}
}
}
}

void  push( list *ptr)
{
if (ptr->left!=NULL)
push (ptr->left);
printf ("%d ", ptr->value);
if (ptr->right!=NULL)
push (ptr->right);
}

void delit (list *ptr)
{
list *ptr1=NULL;
while (1)
{
if (ptr->right!=NULL)
{
ptr=ptr->right;
continue;
}
if (ptr->left!=NULL)
{
ptr=ptr->left;
continue;
}
ptr1=ptr->parent;
if (ptr1!=NULL)
{
if (ptr1->key < ptr->key)
ptr1->right=NULL;
else
ptr1->left=NULL;
free(ptr);
ptr=ptr1;
}
else
{
free(ptr);
break;
}
}
} 


int main () 
{ 
list *tree=init(); 
int n, key, value; 
scanf ("%d", &n); 
for (int i=0; i<n; i++) 
{ 
scanf ("%d", &key); 
scanf ("%d", &value); 
insert (tree, key, value); 
} 

push (tree);
printf ("\n");
delit (tree);
return 0; 
}
