#include <stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *link;
} *newnode, *first = NULL, *last = NULL;
int count = 0;
void i_start()
{
newnode = (struct node *) malloc (sizeof (struct node));
count++;
printf ("Enter Data : ");
scanf ("%d", &newnode->data);
if (first == NULL)
// empty LL
{
newnode->link = NULL;
first = newnode;
last = newnode;
}
else
{
newnode->link = first;
first = newnode;
}
}
void display ()
{

struct node *temp;
temp = first;
printf("The Linked List Is : ");
while (temp != NULL)
{
printf (" %d ", temp->data);
temp = temp->link;
}
}
void i_last ()
{
newnode = (struct node *) malloc (sizeof (struct node));
count++;
printf ("Enter Data : ");
scanf ("%d", &newnode->data);
if (first == NULL)
// empty LL
{
newnode->link = NULL;
first = newnode;
last = newnode;
}
else
{
newnode->link = NULL;
last->link = newnode;
last = newnode;
}
}
void i_mid ()
{
int pos, i;
struct node *temp;
printf ("Enter Position : ");
scanf ("%d", &pos);
if (pos == 1)
i_start();
else if (pos == count + 1)
i_last();
else if (pos > count + 1)
printf ("Invalid Postion");
else
{
newnode = (struct node *) malloc (sizeof (struct node));
count++;
printf ("Enter Data : ");
scanf ("%d", &newnode->data);
temp = first;
i = 1;
while (i < pos - 1)
{
temp = temp->link;
i++;
}
newnode->link = temp->link;
temp->link = newnode;
}
}
void d_first()
{
struct node *temp = first;
if (first == NULL)
{
printf ("EMPTY LL...");
}
else
{
printf ("Deleting Node %d ", first->data);
if (first == last)
{
first = NULL;
last = NULL;
}
else
{
first = first->link;
free (temp);
count--;
}
}
}

void d_last ()
{
    struct node *temp = first;
    struct node *prev = NULL;

    if (first == NULL)
    {
        printf ("EMPTY LL...");
    }
    else
    {
        while (temp->link != NULL)
        {
            prev = temp;
            temp = temp->link;
        }

        if (temp == first)
        {
            first = NULL;
            last = NULL;
        }
        else
        {
            prev->link = NULL;
            last = prev;
        }

        printf ("Deleting Node %d\n", temp->data);
        free (temp);
        count--;
    }
}


void d_mid ()
{
int pos, i;
struct node *temp, *temp1;
printf ("Enter Position : ");
scanf ("%d", &pos);
if (pos == 1)
d_first ();
else if(pos==count)
d_last();
else if (pos >= count + 1)
printf ("Invalid Postion...");
else
{
//newnode=(struct node*)malloc(sizeof(struct node));
temp = first;
i = 1;
while (i < pos - 1)
{
temp = temp->link;
i++;
}
temp1 = temp->link;
temp->link = temp1->link;
printf ("Deleting %d Data", temp1->data);
free(temp1);
count--;
}
}
void search ()
{
int sch, i = 1;
struct node *temp = first;
int flag = 0;
printf ("Enter The Value : \n");
scanf ("%d", &sch);
while (temp != NULL)
{
if (temp->data == sch)
{
flag = 1;
break;
}
temp = temp->link;
i++;
}
if (i > count && flag == 0)
{
printf ("Value Not Found...\n");
}
else
{
printf ("Value Found...\n");
}
}

int main ()
{
int ch;
do
{
printf("LINKED LIST OPERATIONS :- \n");
printf("1: Insert At Start \n2: Insert At Mid \n3: Insert At Last\n4: Delete From First \n5: Delete From Mid \n6: Delete From Last \n7: Display\n8: Search\n9: Exit\n");
printf("Enter Your Choice : ");
scanf ("%d", &ch);
switch (ch)
{
case 1:
i_start();
break;
case 2:
i_mid();
break;
case 3:
i_last();
break;
case 4:
d_first();
break;
case 5:
d_mid();
break;
case 6:
d_last();
break;
case 7:
display();
break;
case 8:
search();
break;
case 9:
return 0;
}
printf ("\nPress 1 To Continue...\n");
scanf ("%d", &ch);
}
while (ch == 1);
return 0;
}