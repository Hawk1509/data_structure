//prorgam to cretate structure of students to display details in descending order and name in alphabetical order
#include <stdio.h>
struct stud
{
    float m1,m2,m3,m;
    int numb;
    char name;
}s[20],t;
void main()
{   int n,i,j;
    printf("Enter limit: ");
    scanf("%d",&n);
    printf("Enter elements of the structure: ");
    for (i=0;i<n;i++)
    {
        scanf("%d",&s[i].numb);
        scanf("%s",&s[i].name);
        scanf("%f%f%f",&s[i].m1,&s[i].m2,&s[i].m3);
        s[i].m=s[i].m1+s[i].m2+s[i].m3;
    }
    for (i=0;i<n;i++)
    {

        for(j=0;j<n-1;j++)
        {
            if (s[j].m<s[j+1].m)
            {
                t=s[j+1];
                s[j+1]=s[j];
                s[j]=t;
            }
        }
    }
    printf("Roll Number\t\tName\t\tMarks\n");
    for (i=0;i<n;i++)
    {
        printf("%d\t%s\t%f",s[i].numb,s[i].name,s[i].m);
    }
}