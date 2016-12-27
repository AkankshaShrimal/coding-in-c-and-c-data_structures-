#include <stdio.h>
#include <stdlib.h>



struct node
{
    int data;
    struct node* link;
};

struct queue
{
    struct node* front;
    struct node * rear;
};

void add(struct queue* , int );
int remove1(struct queue*);
void deallocate(struct queue*);
void display(struct queue *);

int main()
{
    struct queue q;
    int no_ele ,i,j,ele,no_remove;
    q.front = q.rear = NULL; //empty stack


    printf("enter no of elements to be inserted\n");
    scanf("%d",&no_ele);

    //inserting required number of elements

    for(i=0;i<no_ele;i++)
    {
        printf("enter %d element\n",i+1);
        scanf("%d",&ele);
        add(&q,ele);

    }

    //removing elements

    printf("enter number of elements to be removed\n");
    scanf("%d",&no_remove);
    for(i=0;i<no_remove;i++)
    {
        j = remove1(&q);
        if(j!=NULL)
        {
            printf("%d element removed\n",j);
        }

    }

    display(&q);

    deallocate(&q);
    return 0;
}

void add(struct queue *s, int item )
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));

    if(temp == NULL)
    {
        printf("queue is full\n");
        return;
    }

    temp->data = item;
    temp->link = NULL;

    if(s->front == NULL)
    {
        s->front = s->rear = temp;
        return;
    }

    s->rear->link = temp;
    s->rear = s->rear->link;

}

int remove1(struct queue*s)
{
    int item;
    struct node* temp;

    if(s->front == NULL)
    {
        printf("queue is empty\n");
        return NULL;
    }
    temp = s->front;
    item = temp->data;
    s->front = s->front->link;
    free(temp);
    return item;
}

void display(struct queue *s)
{
    struct node* i;
    printf("front\n");
    i=s->front;
    while(i!= NULL)

    {
        printf("%d\n",i->data);
        i = i->link;
    }
    printf("rear\n");
}


 void deallocate(struct queue*s)
 {
     struct node* temp;
     if(s->front== NULL)
     {
         printf("nothing to deallocate queue is empty\n");
         return;
     }
     while(s->front!=NULL)
     {
         temp = s->front;
     s->front = s->front->link;
     free(temp);

     }

 }










