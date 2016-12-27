#include <stdio.h>
#include <stdlib.h>

#define MAX 100
void add(int*,int,int*,int*);
int remove1(int*,int*,int*);
void display(int*,int*,int*);

int main()
{
    int arr[MAX];
    int front = -1 ,rear = -1;
    int i,j,n,ele,n_remove;


    printf("enter total number of elements TO BE ADDED\n");
    scanf("%d",&n);


    //ADDING THE ELEMENTS


    for(i=0;i<n;i++)
    {
      printf("enter %d element\n",i+1);
      scanf("%d",&ele);
      add(arr,ele,&front,&rear);
    }

    printf("enter the total number of elements to be  REMOVED\n");
    scanf("%d",&n_remove);


    //REMOVING THE ELEMENTS

    for(i=0;i<n_remove;i++)
    {
        j=remove1(arr,&front,&rear);
        if(j!=NULL)
        {
            printf("%d element is removed\n",j);

        }


    }


    printf("\n\n\n");
    printf("RESULTANT QUEUE IS\n");
    printf("front\n");
    display(arr,&front,&rear);
    printf("rear\n");
    return 0;
}

void add(int*arr,int item,int*pfront,int*prear)
{
    if(*prear == MAX-1)
    {
        printf("queue is full");
        return;
    }
    (*prear)++;
    arr[*prear] = item;

    if(*pfront == -1)
        (*pfront) = 0;

}

int remove1(int*arr,int*pfront,int*prear)
{
    int data;
    if(*pfront == -1)
    {
        printf("nothing can be removed queue is empty\n");
        return NULL;
    }

    data = arr[*pfront];
    arr[*pfront] = 0;

    if(*pfront == *prear)
        *pfront = *prear = -1;
    else
    (*pfront)++;

    return data;

}

void display(int*arr,int*pfront,int*prear)
{
    int i;

    for(i=(*pfront);i<=(*prear);i++)
    {
        printf("%d\n",arr[i]);
    }
}
