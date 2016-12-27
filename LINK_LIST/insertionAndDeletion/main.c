#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*header;

void create_linklist();
void display();
void insert_beg(int num);
void insert_end(int num);
void insert_after(int after_num,int num);
void insert_before(int before_num,int num);
void delete_beg();
void delete_end();
void delete_pos(int pos);



int main()
{
    int num,ch,i,element,pos;

    header =NULL;  //link list empty initially
   while(1)
   {

        printf("\n\nenter coice\n");
        printf("\n1. CREATE LINK LIST");
        printf("\n2. INSERT A NODE");
        printf("\n3. DELETE A NODE");
        printf("\n4. DISPLAY LINK LIST");
        printf("\n5. EXIT");
        scanf("%d",&ch);


        switch(ch)
        {
            case 1:
                clearenv();
                create_linklist();
                break;
            case 2:
                system("cls");
                printf("choose one option of these\n");
                printf("\n1.INSERT AT BEGINNING");
                printf("\n2.INSERT AT END");
                printf("\n3.INSERT AFTER A VALUE");
                printf("\n4.INSERT BEFORE A VALUE");
                scanf("%d",&ch);

                switch(ch)
                {
                                case 1:
                                    system("cls");
                                    printf("\nenter the value to be inserted\n");
                                    scanf("%d",&num);
                                    insert_beg( num);

                                    break;

                                case 2:
                                    system("cls");
                                    printf("\nenter the value to be inserted\n");
                                    scanf("%d",&num);
                                    insert_end( num);

                                    break;

                                case 3:
                                    system("cls");
                                    printf("\nenter the value to be inserted\n");
                                    scanf("%d",&num);
                                    printf("\nenter the value after which you want to insert\n");
                                    scanf("%d",&element);
                                    insert_after(element, num);

                                    break;

                                case 4:
                                    system("cls");
                                    printf("\nenter the value to be inserted\n");
                                    scanf("%d",&num);
                                    printf("\nenter the value before which you want to insert\n");
                                    scanf("%d",&element);
                                    insert_before(element, num);

                                    break;

                                default:break;
                }


            case 3:
                system("cls");

                 printf("choose one option of these\n");
                printf("\n1.DELETE AT BEGINNING");
                printf("\n2.DELETE AT END");
                printf("\n3.DELETE AT POSITION");

                scanf("%d",&ch);

                switch(ch)
                {
                                case 1:
                                    system("cls");
                                    delete_beg();
                                    break;

                                case 2:
                                    system("cls");
                                    delete_end();
                                    break;

                                 case 3:
                                    system("cls");
                                    printf("\nenter the pos at which to be deleted\n");
                                    scanf("%d",&pos);
                                    delete_pos(pos);
                                    break;
                }

                break;


            case 4:
                system("cls");
                display();
                break;

            case 5:
                exit(0);

            default:
                break;



        }
    }
    return 0;
}



void create_linklist()
{
    system("cls");
    int n,ele,i;
     printf("enter total nodes to be created\n");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("\nenter the element to be inserted at %d position\n",i+1);
        scanf("%d",&ele);
        if(header==NULL)
        {
            header=(struct node*)malloc(sizeof(struct node));
            header->data=ele;
            header->next=NULL;
            printf("\nINSERTION COMPLETED\n");
        }
        else
        {
            insert_end(ele);
        }
    }
    printf("\nlist successfully created\n");
}

void display()
{
    struct node *ptr;
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


void insert_beg(int num)
{
    struct node *temp;
    temp =(struct node *)malloc(sizeof(struct node));

    if(header==NULL)
    {

        temp->data=num;
        header =temp;
    }
    else
    {

    temp->data=num;
    temp->next=header;
    header=temp;
    }
    printf("\nINSERTION COMPLETED\n");

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
    printf("\nINSERTION COMPLETED\n");

    }

}

void insert_after(int after_num,int num)
{
    if(header==NULL)
    {
        printf("\nno list\n");
        return;
    }
    struct node *temp,*preptr;
    temp =(struct node *)malloc(sizeof(struct node));
    temp->data=num;
    preptr=header;
    while(  preptr!=NULL && preptr->data!=after_num )
    {

        preptr = preptr->next;
    }
    if(preptr==NULL)
    {
        printf("\ninsertion not possible number does not exist after which to insert\n");
    }
    else
    {
    temp->next = preptr->next;
    preptr->next = temp;
    printf("\n insertion completed\n");}
}

void insert_before(int before_num,int num)
{
    if(header==NULL)
    {
        printf("\nno list\n");
        return;
    }
    struct node *temp,*ptr,*preptr;
    temp =(struct node *)malloc(sizeof(struct node));
    temp->data=num;
    preptr=ptr=header;
    while(  ptr!=NULL && ptr->data!=before_num  )
    {

        ptr = ptr->next;
    }
    if(ptr==NULL)
    {
        printf("\ninsertion not possible as element does not exist before which to insert\n");
    }
    else
    {
    preptr->next=temp;
    temp->next = ptr;
    printf("\n insertion completed\n");
    }
}

void delete_beg()
{
        if(header==NULL)
        {
            printf("\tno lost\n");
            return;
        }
        else
        {
            struct node *temp;
            temp=header;
            header=header->next;
            free(temp);
            printf("\n node deleted\n");
        }

}


void delete_end()
{
        if(header==NULL)
        {
            printf("\tno lost\n");
            return;
        }
        else
        {
            struct node *temp,*ptr,*preptr;
            ptr=header;
        while(ptr->next!=NULL)
        {preptr=ptr;
        ptr=ptr->next;
        }
        temp =ptr;
        preptr->next=NULL;
        free(temp);
        printf("\n node deleted\n");
        }
}



void delete_pos(int pos)
{
        if(header==NULL)
        {
            printf("\tno lost\n");
            return;
        }
        else
        {
            struct node *ptr,*temp;int i;
            i=1;
            ptr=header;
            while( ptr!=NULL && i!=pos-1)
            {
                ptr=ptr->next;
                i++;
            }
            if(ptr==NULL)
            {
                printf("\ndeletion not possible\n");
            }
            else
            {
                temp = ptr->next;
                ptr->next = temp->next;
                free(temp);
                printf("\n deletion completed\n");

            }
        }
}
