//program to add triplet matrix
#include <stdio.h> 
void main()
{
    int a[10][10],b[10][10],i,j,r,c,r1,c1;
    int count = 0, k = 1,count1 = 0;
    //values of the first matrix.
    printf("\nEnter values of the Matrix A.\n");
    printf("Enter number of rows of the 1st matrix: ");
    scanf("%d",&r);
    printf("Enter number of columns of the 1st matrix: ");
    scanf("%d", &c);
    //values of the 2nd matrix
    printf("\nEnter values of the Matrix B.\n");
    printf("Enter number of rows of the 2nd matrix: ");
    scanf("%d",&r1);
    printf("Enter number of columns of the 2nd matrix: ");
    scanf("%d", &c1);
    
    if(r != r1 && c != c1)
    {
    	printf("Addition is not possible\n");
    	//break;
    }
    else
    { 
    	printf("\nElements of the sparse matrix A \n");
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
      trp[0][0] = r;
      trp[0][1] = c;
      trp[0][2] = count;
     	 //triplet row value entries.
		 printf("\nThe Triplet values of matrix A are:\n");
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
//matrix B		 
		 printf("\nElements of the sparse matrix B \n");
    	 for (i=0;i<r1;i++)
    	{
      	  for(j=0;j<c1;j++)
       	 {
         	   printf("Enter values of B%d%d: ",i+1,j+1);
         	   scanf("%d",&b[i][j]);
        	}
    	}
    	for (i=0;i<r1;i++)
    	{
      	  for(j=0;j<c1;j++)
      	  {
      	      if (b[i][j] != 0)
      	      {
      	          count1 += 1;
      	      }
      	  }
    	}		
    	//triplet row 0 entries.
    	int trp1[count1+1][3];
    	k = 1;
    	trp1[0][0] = r1;
      trp1[0][1] = c1;
   	trp1[0][2] = count1;
      //triplet row value entries.
		 printf("\nThe Triplet values of matrix B are:\n");
		 for (i=0;i<r1;i++)
		 {
		     for(j=0;j<c1;j++)
		     {
		         if (b[i][j] != 0)
		         {
		             trp1[k][0] = i;
		             trp1[k][1] = j;
		             trp1[k][2] = b[i][j];
		             k=k+1;
		         }
		         //printf("%d\t",trp[i][j]);
		     }
		     //printf("\n");
		 }
		 for (i=0;i<count1+1;i++)
		 {
		     for(j=0;j<3;j++)
		     {
		         printf("%d\t",trp1[i][j]);
		     }
		     printf("\n");
		}		 
		 printf("\nSum of the triplets of matrix A and B are:\n");
		 int trp2[count1 + 1][3],k = 1;
		 while(i<=count && j<=count1)
		 {
		 	if ((trp[i][0] < trp1[j][0]) || (trp[i][0] == trp1[j][0] && trp[i][1] < trp1[j][1]))
		 	{
		 		trp2[k][0] = trp[i][0];
		 		trp2[k][1] = trp[i][1];
		 		trp2[k][2] = trp[i][2];
		 		i = i + 1;
		 	} 
		 	else if ((trp[i][0] > trp1[j][0]) || (trp[i][0] == trp1[j][0] && trp[i][1] > trp1[j][1]))
		 	{
		 		trp2[k][0] = trp1[j][0];
		 		trp2[k][1] = trp1[j][1];
		 		trp2[k][2] = trp1[j][2];
		 		j = j + 1;
		 	}
		 	else if (trp[i][0] == trp1[j][0] && trp[i][1] == trp1[j][1])
		 	{
		 		trp2[k][0] = trp[i][0];
		 		trp2[k][1] = trp[i][1];
		 		trp2[k][2] = trp[i][2] + trp1[j][2];
		 		i = i + 1;
		 		j = j + 1;
		 	}
            k++;
		 }
		 k = 1;
         i = 0;
		 while (i <= count)
		 {
		 	trp2[k][0] = trp[i][0];
		 	trp2[k][1] = trp[i][1];
		 	trp2[k][2] = trp[i][2];
		 	k = k + 1;
		 	i = i + 1;
		 }
		 k = 1;
         j = 0;
		 while (j <= count1)
		 {
		 	trp2[k][0] = trp1[j][0];
		 	trp2[k][1] = trp1[j][1];
		 	trp2[k][2] = trp1[j][2];
		 	j = j + 1;
		 	k = k + 1;
		 }
         trp2[0][0] = r;
         trp2[0][1] = c;
		 trp2[0][2] = k-1;
		 for (i = 0; i < k; i++)
		 {
		 	for(j = 0; j < 3; j++)
		 	{
		 		printf("%d\t",trp2[i][j]);
		 	}
		 	printf("\n");
		 }
         
		}
		 
		}

	