#include <stdio.h>
#include <string.h>
struct employee
{
    char name[20];
    int employeeid[6];
    float experience[5];
    float salary[5];
};
int main()
{
    int i=0;
    struct employee e1;
    for (i=0;i<5;i++)
    {
      printf("\nEnter details of employee %d",i+1);
      printf("\nEnter Name : ",i+1);
      scanf("%s",&e1.name[i]);
      printf("\nEnter employee ID : ",i+1);
      scanf("%d",&e1.employeeid[i]);
      printf("\nEnter experience : ",i+1);
      scanf("%f",&e1.experience[i]);
      printf("\nEnter Salary : ",i+1);
      scanf("%f",&e1.salary[i]);
    }
    for(i=0;i<5;i++)
    {
      printf("\nDetails of Employee %d",i+1);
      printf("\nEmployee Name : %s",e1.name[i]);
      printf("\nEmployee ID : %d",e1.employeeid[i]);
      printf("\nEmployee experience : %f years",e1.experience[i]);
      printf("\nEmployee Salary : %f",e1.salary[i]);
    }
return 0;
}
