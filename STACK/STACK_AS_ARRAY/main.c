#include <stdio.h>
#include <stdlib.h>
#define MAX 10

struct stack
{
    int arr[MAX];
    int top;
};
void push(struct stack * , int);
int pop(struct stack *);
void display(struct stack *);
void init(struct stack *);

int main()
{
    struct stack s;
    int i;
     init(&s);
     push(&s , 12);
     push(&s , 13);
     push(&s , 8);
     push(&s , 3);

    i = pop(&s);
    printf("%d element is popped out\n" , i);

    i =  pop(&s);
    printf("%d element is popped out\n" , i);

    display(&s);
    return 0;
}

void init(struct stack * s)
{
 s ->top= -1;
}

void push(struct stack * s , int data)
{
    if (s ->top == MAX-1)
    {
        printf("not possible");
        return;
    }

    s->top++ ;
    s ->arr[s->top] = data;

}

int pop(struct stack * s)
{
    int item;
    if(s->top == -1)
        return NULL;
    item = s->arr[s->top];
    s->top--;
    return item;

}

void display(struct stack *s)
{
    int i;
    printf("TOP\n");
    for(i = s->top;i >= 0;i--)
    {
        printf("%d\n", s->arr[i]);

    }
    printf("END\n");

}
