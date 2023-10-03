//prorgam to sum 2 polynomials
#include <stdio.h>
struct poly
{
    int e,c;
}a[10],b[10],c[10];
void main()
{
    int i=0,j=0,k=0,t1,t2;
    printf("Enter number of tems in the first polynomial: ");
    scanf("%d",&t1);
    printf("Enter number of terms in 2nd polynomial: ");
    scanf("%d",&t2);
    printf("\nValues of the 1st polynomial.\n\n");
    for (i=0;i<t1;i++)
    {
        printf("Enter coefficients of term %d: ",i+1);
        scanf("%d",&a[i].c);
        printf("Enter expression of term %d: ",i+1);
        scanf("%d",&a[i].e);
    }
    printf("\nValues of the 2nd polynomial\n\n");
    for (j=0;j<t2;j++)
    {
        printf("Enter coefficients of term %d: ",j+1);
        scanf("%d",&b[j].c);
        printf("Enter expression of term %d: ",j+1);
        scanf("%d",&b[j].e);
    }
    i = 0;
    j = 0;
    k = 0;
    while (i<t1 || j<t2)
    {

        if (a[i].e == b[j].e)
        {
            c[k].c = a[i].c + b[j].c;
            c[k].e = a[i].e;
            i++;
            j++;
            k++;
        } 
        else if (a[i].e > b[j].e)
        {
           c[k].c = a[i].c;
           c[k].e = a[i].e;
           i++;
           k++; 
        }
        else if (a[i].e < b[j].e)
        {
           c[k].c = b[j].c;
           c[k].e = b[j].e;
           j++;
           k++; 
        }
    }
    /*while (i<t1)
    {
        c[k].c = a[i].c;
        c[k].e = a[i].e;
        i++;
        k++;  
    }
    while (j<t2)
    {
        c[k].c = b[j].c;
        c[k].e = b[j].e;
        j++;
        k++; 
    }*/
    printf("\n\tResultant polynomial is:\n ");
    for (i=0;i<k;i++)
    {
        if (i != k-1)
        {   
            printf("\t%dx^%d + ",c[i].c,c[i].e);
        }
        else
        printf("\t%dx^%d\n",c[i].c,c[i].e);
    }
    //works
}