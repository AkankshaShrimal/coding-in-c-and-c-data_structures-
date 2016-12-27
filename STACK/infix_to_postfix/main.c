#include <stdio.h>
#include <stdlib.h>


#define MAX 50
int z = 0,y = 0;
char target[MAX];
struct stack
{
    char data;
    struct stack *link;

};

//FUNCTIONS USED IN PROGRAM


int priority(char);
void push(struct stack **, char );
char pop(struct stack **);
char peak(struct stack**);
void comparision(struct stack ** ,char);
int is_stack_empty(struct stack**);

int main()
{
    char str[MAX];
    struct stack *s = '\0';
    printf("put the string in infix\n");
    gets(str);


    printf("Input string is\t\t");
    puts(str);



    //SCANNING THE ELEMENTS
        while(str[z]!='\0')
        {
            switch(str[z])
            {
                case ('+'):
                    comparision(&s, '+');
                    break;
                case ('-'):
                    comparision(&s, '-');
                    break;
                case ('*'):
                    comparision(&s, '*');
                    break;
                case ('/'):
                    comparision(&s, '/');
                    break;
                case ('$'):
                    comparision(&s, '$');
                    break;
                case ('('):
                    comparision(&s, '(');
                    break;
                case (')'):
                    comparision(&s, ')');
                    break;
                default:

                    target[y] =str[z];
                    y++;


            }
            z++;
        }

    while(is_stack_empty(&s)!= 0)
    {

        target[y]= pop(&s);
        y++;
    }



printf("Resultant string is\t");
puts(target);

return 0;

}

//CHECKING PRIORITY

int priority(char c)
{
     if (c == '(' || c ==')')
        return 4;
   if (c == '$')
        return 3;
   if (c == '/' || c == '*')
        return 2;
   if (c == '+' || c == '-')
        return 1;

    return 0;

}





//TO ADD ELEMENTS INTO THE STACK

void push(struct stack **s,char ele)
{
    struct stack *temp;
    temp =(struct stack*)malloc(sizeof(struct stack));


    if(temp == NULL)
        printf("element cant be inserted");

    temp->data = ele;
    temp->link = *s;
    *s = temp;

}


//TO GET THE TOP ELEMENT IN STACK
char peak(struct stack **s)
{

    char item;

    if(*s == NULL)
    {
        return 'x';
    }
    item = (*s)->data;
    return item;
}

//TO REMOVE THE TOP ELEMENT IN STACK

char pop(struct stack **s)
{
    struct stack *temp;
    char item;

    if(*s == NULL)
    {
        return 'x';
    }
    item = (*s)->data;
    temp = *s;
    (*s) = (*s)->link;

    free(temp);
    return item;
}


void comparision(struct stack **s,char c)
{

    char opr;
    int flag = 0;

    if( c!= '(' && c!= ')')
    {
        if (is_stack_empty(s) == 0)
        {

            push(s,c);
            return ;
        }
        else
        {
            opr = peak(s);
        }

         if(priority(opr) == 4)
            {

                push(s,c);
                return;
            }


        while(priority(c) <= priority(opr))
        {
            opr = pop(s);
            target[y] = opr;
            y++;

            if(peak(s)!= 'x' && priority(peak(s))!=4)
            {

                opr = peak(s);
            }
            else
            {
                push(s,c);
                flag++;
                return;
            }

        }
         if(flag == 0)
        {

            push(s,c);
            return;

        }


    }

    if ( c == '(')
    {
        push(s,c);
        return;

    }


    if ( c == ')')
    {

        opr = pop(s);
        while(opr != '(' && is_stack_empty(s)!=0)
        {
                target[y] = opr;
                y++;
                if(peak(s)!= 'x')
                    opr = pop(s);

        }

    }


}

int is_stack_empty(struct stack **s)
{
        if(*s == NULL)
        return 0;
        else
        return 1;
}
