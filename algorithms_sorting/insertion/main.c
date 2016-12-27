#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[20],n,i,k,temp,ptr;
    printf("total ele\n");
    scanf("%d",&n);
    printf("enter elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(k=1;k<n;k++)
    {
        ptr=k-1;
        temp=a[k];
        while(temp<a[ptr]&&ptr!=-1)
        {
            a[ptr+1]=a[ptr];
            ptr--;
        }
        a[ptr+1]=temp;
        printf("\narray is:-\n");
        for(i=0;i<n;i++)
        {
            printf("%d\t",a[i]);
        }
    }

    return 0;
}
