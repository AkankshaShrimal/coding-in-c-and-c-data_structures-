#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*header;

void insert_beg(int num)
{
    if(header==NULL)
    {
        printf("no list\n");
        return;
    }
    else
    {
    struct node *temp;
    temp =(struct node *)malloc(sizeof(struct node));
    temp->data=num;
    temp->next=header;
    header=temp;
    }

}

void insert_end(int num)
{
    if(header==NULL)
    {
        printf("no list\n");
        return;
    }
    else
    {
    struct node *temp,*ptr;
    temp =(struct node *)malloc(sizeof(struct node));
    temp->data=num;
    ptr=header;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    temp->next=NULL;
    ptr->next=temp;

    }

}

int main()
{
    int n ,ele,num,ch,i;
    struct node *ptr;
    header =NULL;
    printf("total nodes\n");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("\nenter the element to b inserted");
        scanf("%d",&ele);
        if(header==NULL)
        {
            header=(struct node*)malloc(sizeof(struct node));
            header->data=ele;
            header->next=NULL;
        }
        else
        {
            insert_end(ele);
        }
    }
    printf("enter coice 1 insert_beg 2insert_end\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            printf("enter ele\n");
            scanf("%d",&num);
            insert_beg(num);
            break;
        case 2:
              printf("enter ele\n");
            scanf("%d",&num);
            insert_end(num);
            break;

    }
    printf("displaying a link list\n");
    ptr=header;
    while(ptr!=NULL)
    {
        printf("%d -> ",ptr->data);
        ptr=ptr->next;
    }
    printf("end");
    return 0;
}
