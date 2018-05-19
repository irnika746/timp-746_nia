#include <stdio.h>
#include <stdlib.h>
typedef struct list
{
int key;
int value;
struct list *right;
struct list *left;
}list;


list *init ()
{
list *ptr=malloc(sizeof(list));
ptr->value=0;
ptr->key=-100;
ptr->left=NULL;
ptr->right=NULL;
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


int find (list *tmp, int key)
{
int level=0;
int a=1;
while (a)
{
if (tmp->key==key)
{printf ("%d ", level);
printf ("%d", tmp->value);
break;}
else if (key > tmp->key && tmp->right!=NULL)
{
tmp=tmp->right;
level++;
}
else if (key < tmp->key && tmp->left!=NULL)
{ tmp=tmp->left;
level++;}
else
{
int p=-1;
printf ("%d", p);
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
for (int i=0; i<3; i++)
{
scanf ("%d", &key);
find (tree, key);
printf("\n");
}
return 0;
}

