
#include <stdio.h>
#include <conio.h>
#include <string.h>

struct phonebook
{
  char name[30];
  char address[50];
  char father[30];
  char mother[30];
  long int mob;
  char sex[20];
  char email[30];
  long int citizen_no;

};
void mainmenu();
void gotomainmenu();
void get();
void back();
void create();
void show();
void update();
void erase();
void search();
int main()
{
    system("color 5f");
    gotomainmenu();
    return 0;
}

void back()
{
    gotomainmenu();
}
void gotomainmenu()
{
    mainmenu();
}
void mainmenu()
{
    int n;
   system("cls");
   printf("\t\t\t\t********************WELCOME TO PHONEBOOK********************");
   printf("\n\n\n\t\t\t               \t\t\tMENU\n\n\n\t\t\t");
   printf("\t1. Add New\t\t2.List\t\t3. Exit \n\t\t\t\t4. Modify\t\t5.Search\t6.Delete\n");
   scanf("%d",&n);
   switch(n)
   {
   case 1:
     create();
     break;
   case 2:
     show();
    break;
   case 3:
     Exit(0);
     break;
   case 4:
     update();
     break;
   case 5:
     search();
     break;
   case 6:
     erase();
     break;

   default :
     printf("Invalid selection");
     system("cls");
     getch();
     mainmenu();
    }
}
void create()
{
    system("cls");
    FILE *f;
    struct phonebook p;
    f=fopen("details","ab+");
    printf("\nEnter Name\t");
    get(p.name);
    printf("\nEnter Address\t");
    get(p.address);
    printf("\nEnter Father's Name\t");
    get(p.father);
    printf("\nEnter Mother's Name\t");
    get(p.mother);
    printf("\nEnter Mobile number\t");
    scanf("%ld",&p.mob);
    printf("\nEnter sex\t");
    get(p.sex);
    printf("\nEnter Email-Id\t");
    get(p.email);
    printf("\nEnter Citizenship no.\t");
    scanf("%ld",&p.citizen_no);
    fwrite(&p,sizeof(p),1,f);
    fflush(stdin);
    printf("\nRecord saved");
    fclose(f);

    printf("\nPress Enter key for mainmenu");
    getch();


    system("cls");
    mainmenu();
}
void show()
{
    struct phonebook p;
    FILE *f;
    f=fopen("details","rb");
    if(f==NULL)
    {
      printf("\n No records to show :");
      exit(1);
    }
    while(fread(&p,sizeof(p),1,f)==1)
    {

     printf("\n\n\n YOUR RECORD IS\n\n ");
     printf("\nName=%s\nAddress=%s\nFather name=%s\nMother name=%s\nMobile no=%ld\nSex=%s\nE-mail=%s\nCitizenship no=%ld",p.name,p.address,p.father,p.mother,p.mob,p.sex,p.email,p.citizen_no);
     getch();
    }
    fclose(f);
    printf("\nPress Enter key for mainmenu");
    getch();
    system("cls");
    mainmenu();
}
void update()
{
    int c;
    FILE *f;
    int flag=0;
    struct phonebook p,s;
	char  name[70];
	f=fopen("details","rb+");
	if(f==NULL)
		{

			printf("CONTACT'S DATA NOT FOUND");
			exit(1);


		}
	else
	{
	    system("cls");
		printf("\nEnter CONTACT'S NAME TO MODIFY:\n");
            get(name);
            while(fread(&p,sizeof(p),1,f)==1)
            {
                if(strcmp(name,p.name)==0)
                 {
                    printf("\n Enter name:");
                    get(s.name);
                    printf("\nEnter the address:");
                    get(s.address);
                    printf("\nEnter father's name:");
                    get(s.father);
                    printf("\nEnter mother's name:");
                    get(s.mother);
                    printf("\nEnter phone no:");
                    scanf("%ld",&s.mob);
                    printf("\nEnter sex:");
                    get(s.sex);
                    printf("\nEnter e-mail:");
                    get(s.email);
                    printf("\nEnter citizenship no\n");
                    scanf("%ld",&s.citizen_no);
                    fseek(f,-sizeof(p),SEEK_CUR);
                    fwrite(&s,sizeof(p),1,f);
                    flag=1;
                    break;



                }
                fflush(stdin);


            }
            if(flag==1)
            {
                printf("\n Your data is modified");

            }
            else
            {
                    printf(" \n data is not found");

            }
            fclose(f);
	}
	 printf("\nPress Enter key for mainmenu");
	 getch();
    system("cls");
	mainmenu();
}
void search()
{
    struct phonebook p;
    FILE *f;
    char name[100];

    f=fopen("details","rb");
    if(f==NULL)
     {
       printf("\n NO RECORDS FOUND \n");
       exit(1);

     }
       printf("\nEnter person's name to search\n");
       get(name);
       while(fread(&p,sizeof(p),1,f)==1)
        {
         if(strcmp(p.name,name)==0)
          {
            system("cls");
            printf("\n\tInformation of %s is : ",name);
            printf("\nName:%s\nAddress:%s\nFather name:%s\nMother name:%s\nMobile no:%ld\nsex:%s\nE-mail:%s\nCitizenship no:%s",p.name,p.address,p.father,p.mother,&p.mob,p.sex,p.email,&p.citizen_no);
          }
        else
          {
         printf("file not found");

          }
         fclose(f);
         printf("\nPress Enter key for mainmenu");
         getch();
        }


    system("cls");
mainmenu();
}
void erase()
{
   struct phonebook p;
    FILE *f,*ft;
	int flag;
	char name[100];
	f=fopen("details","rb");
	if(f==NULL)
		{

			printf("THERE IS NO CONTACT'S DATA ADDED YET.");

		}
	else
	{
		ft=fopen("temp","wb+");
		if(ft==NULL)
        {
          printf("Error");
		}
		else
        {
          printf("Enter CONTACT'S NAME:");
		  get(name);

		  fflush(stdin);
		  while(fread(&p,sizeof(p),1,f)==1)
		   {
			 if(strcmp(p.name,name)!=0)
              {
                fwrite(&p,sizeof(p),1,ft);
              }
             if(strcmp(p.name,name)==0)
              {
                flag=1;
              }

		  }
	fclose(f);
	fclose(ft);
	if(flag!=1)
	{
		printf("\nNO CONtACT'S RECORD TO DELETE.");
		remove("temp.txt");
	}
		else
		{
			remove("details");
			rename("temp.txt","details");
			printf("\nRECORD DELETED SUCCESSFULLY.");

		}
	}
}
 printf("\nPress Enter key for mainmenu");
 getch();
 system("cls");
mainmenu();
}

void get(char *name)
{

   int i=0,j;
    char c,ch;
    do
    {
        c=getch();
                if(c!=8&&c!=13)
                {
                    *(name+i)=c;
                        putch(c);
                        i++;
                }
                if(c==8)
                {
                    if(i>0)
                    {
                        i--;
                    }

                    system("cls");
                    for(j=0;j<i;j++)
                    {
                        ch=*(name+j);
                        putch(ch);

                    }

                }
    }
    while(c!=13);
      *(name+i)='\0';
}





