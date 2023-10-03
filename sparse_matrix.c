//program to input a sparse matrix and display a triplet matrix
#include <stdio.h> 
void main()
{
    int a[10][10],i,j,r,c;
    int count = 0, k = 1;
    printf("Enter number of rows: ");
    scanf("%d",&r);
    printf("Enter number of columns: ");
    scanf("%d", &c);
    printf("\nElements of the sparse matrix \n");
    for (i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("Enter values of A%d%d: ",i+1,j+1);
            scanf("%d",&a[i][j]);
        }
    }
    for (i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if (a[i][j] != 0)
            {
                count += 1;
            }
        }
    }
    //triplet row 0 entries.
    int trp[count+1][3];
    for (i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            trp[0][0] = r;
            trp[0][1] = c;
            trp[0][2] = count;
        }
    }
    //triplet row value entries.
    printf("\nThe Triplet values are:\n");
    for (i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if (a[i][j] != 0)
            {
                trp[k][0] = i;
                trp[k][1] = j;
                trp[k][2] = a[i][j];
                k=k+1;
            }
            //printf("%d\t",trp[i][j]);
        }
        //printf("\n");
    }
    for (i=0;i<count+1;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d\t",trp[i][j]);
        }
        printf("\n");
    }
    
    

     
}
