/*--------- INCOME TAX CALCULATOR -----------
_______________ By: Akash Kumar _____________
_________________ 11702349 __________________
___________________ K17DQ ___________________
______ Lovely Professional University _______
---------------------------------------------*/
#include <stdio.h>
#include <process.h>
#include <conio.h>
#include <string.h>
//============================================================================================
//structure to store details
struct student
{
 int id,age,phno;
 char name[30],address[30];
 double income,tax;
 char str[20];
}stud;
//=============================================================================================
//function to calculate tax
void calc()
{

		 if(stud.age<60)
		 {											//for general tax payer
	 		strcpy(stud.str,"General tax payer");
	 		if(stud.income<=250000)
	 			stud.tax=0;										//slab 0
		 	else if((stud.income>=250001)&&(stud.income<=500000))
		 		stud.tax=(stud.income-250001)*(0.10);				//slab 1
		 	else if((stud.income>=500001)&&(stud.income<=1000000))
			 	stud.tax=(stud.income-500001)*(0.2);				//slab 2
		 	else if(stud.income>=1000001)
		 		stud.tax=(stud.income-1000001)*(0.30);				//slab 3
				 }			
	 	else if((stud.age>=60)&&(stud.age<80))
	 	{											//for senior citizen
	 		strcpy(stud.str,"Senior citizen");
	 		if(stud.income<=300000)									//slab 0
		 			stud.tax=0;
		 	else if((stud.income>=300001)&&(stud.income<=500000))
			 		stud.tax=(stud.income-300001)*(0.10);				//slab 1
		 	else if((stud.income>=500001)&&(stud.income<=1000000))
			 		stud.tax=(stud.income-500001)*(0.20);				//slab 2
		 	else if(stud.income>=1000001)
					stud.tax=(stud.income-1000001)*(0.30);				//slab 3
		 	}
		 else if(stud.age>=80)
	 	{											//for very senior citizen
	 		strcpy(stud.str,"Very senior citizen");
	 		if(stud.income<=500000)
	 				stud.tax=0;										//slab 0
		 	else if((stud.income>=500001)&&(stud.income<=1000000))
			 		stud.tax=(stud.income-500001)*(0.10);				//slab 1
		 	else if(stud.income>=1000001)
			 		stud.tax=(stud.income-1000001)*(0.30);				//slab 2
			}

}
//=============================================================================================
//    FUNCTION TO INSERT RECORDS TO THE FILE
void insert()
{
 printf("\n\t****************************** Welcome to add records **********************************");
 FILE *fp;
 fp = fopen("Record.txt", "a");
 printf("\n\tEnter the Name : ");
 fflush(stdin);					//to clear out standard inputs
 gets(stud.name);
 printf("\n\tEnter the id : ");
 scanf("%d", &stud.id);
 printf("\n\tEnter the phone number : ");
 scanf("%f", &stud.phno);
 printf("\n\tAge : ");
 scanf("%d",&stud.age);
 printf("\n\tEnter the address : ");
 fflush(stdin);					//to clear out standard inputs
 gets(stud.address);
 printf("\n\tEnter the Income : ");
 scanf("%lf",&stud.income);
 calc();
 fwrite(&stud, sizeof(stud), 1, fp);
 fclose(fp);
}
//====================================================================================
//    FUNCTION TO DISPLAY RECORDS
void disp()
{
  printf("\n\t****************************** Welcome to display records **********************************");
  int i=1;
  FILE *fp1;
  fp1 = fopen("Record.txt", "r");
 while ((fread(&stud, sizeof(stud), 1, fp1)==1))
{
		printf("\n\n\n\t\t************** DETAILS OF CUSTOMER %d ***************",i);
		printf("\n\tName : %s",stud.name);
    	printf("\n\tid number : %d",stud.id);
		printf("\n\tPhone number : %d",stud.phno);
		printf("\n\tAge : %d",stud.age);
		printf("\n\tAddress : %s",stud.address);
		printf("\n\tINCOME : %lf",stud.income);
		printf("\n\tTHE INCOME TAX PAYABLE OF A PERSON IS : %.2lf",stud.tax);
		printf("\n\tFalls under : %s",stud.str);
		i++;
	}
 fclose(fp1);
}
//FUNCTION TO SEARCH THE GIVEN RECORD
void search()
{
 printf("\n\t****************************** Welcome to search records **********************************");
 FILE *fp2;
 int r, s, avl;
 printf("\nEnter the Id no you want to search  :");
 scanf("%d", &r);
 avl = avlidno(r);
 if (avl == 0)
  printf("Id No %d is not available in the file\n",r);
 else
 {
  fp2 = fopen("Record.txt", "r");
  while (fread(&stud, sizeof(stud), 1, fp2))
  {
   s = stud.id;
   if (s == r)
   {
   			printf("\n\t\t\t\t***************Details of customer ****************");
			printf("\n\tName : %s",stud.name);
    		printf("\n\tid number : %d",stud.id);
			printf("\n\tPhone number : %d",stud.phno);
			printf("\n\tAge : %d",stud.age);
			printf("\n\tAddress : %s",stud.address);
			printf("\n\tINCOME : %lf",stud.income);
			printf("\n\tTHE INCOME TAX PAYABLE OF A PERSON IS : %.2lf",stud.tax);
			printf("\n\tFalls under : %s",stud.str);

   }
  }
  fclose(fp2);
 }
}
//====================================================================================
//    FUNCTION TO DELETE A RECORD
void deletefile()
{
 printf("\n\t****************************** Welcome to delete records **********************************");
 FILE *fpo;
 FILE *fpt;
 int r, s;
 printf("\nEnter the Id no you want to delete :");
 scanf("%d", &r);
 if (avlidno(r) == 0)
  printf("Id no %d is not available in the file\n", r);
 else
 {
  fpo = fopen("Record.txt", "r");
  fpt = fopen("TempFile.txt", "w");
  while (fread(&stud, sizeof(stud), 1, fpo))
  {
   s = stud.id;
   if (s != r)
    fwrite(&stud, sizeof(stud), 1, fpt);
  }
  fclose(fpo);
  fclose(fpt);
  fpo = fopen("Record.txt", "w");
  fpt = fopen("TempFile.txt", "r");
  while (fread(&stud, sizeof(stud), 1, fpt))
   fwrite(&stud, sizeof(stud), 1, fpo);
  printf("\nRECORD DELETED\n");
  fclose(fpo);
  fclose(fpt);
  remove("Record.txt");
  rename("TempFile.txt","Record.txt");
 }

}
//====================================================================================
//    FUNCTION TO UPDATE THE RECORD
void update()
{
 printf("\n\t****************************** Welcome to Update records **********************************");
 int avl;
 FILE *fpt;
 FILE *fpo;
 int s, r, ch;
 printf("\nEnter Id number to update: ");
 scanf("%d", &r);
 avl = avlidno(r);
 if (avl == 0)
 {
  printf("Id number %d is not Available in the file", r);
 }
 else
 {
  fpo = fopen("Record.txt", "r");
  fpt = fopen("TempFile.txt", "w");
  while (fread(&stud, sizeof(stud), 1, fpo))
  {
   s = stud.id;
   if (s != r)
    fwrite(&stud, sizeof(stud), 1, fpt);
   else
   {
    printf("\n\t\tPress 1 to Update Name of Id %d", r);
    printf("\n\t\tPress 2 to Update Id (NEW ID)");
    printf("\n\t\tPress 3 to Update everything of Id %d", r);
    printf("\nEnter your choice:");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
     printf("Enter new name	: ");
     fflush(stdin);					//to clear out standard inputs
     gets(stud.name);
     break;
    case 2:
     printf("Enter new id: ");
     scanf("%d", &stud.id);
     break;
    case 3:
     printf("\n\tEnter new Name	: ");
     fflush(stdin);					//to clear out standard inputs
     gets(stud.name);
     printf("\n\tEnter new Id : ");
     scanf("%d", &stud.id);
     printf("\n\tEnter new Phone number : ");
	 scanf("%d",&stud.phno);
	 printf("\n\tEnter new Age : ");
	 scanf("%d",&stud.age);
	 printf("\n\tEnter new Address : ");
	 fflush(stdin);					//to clear out standard inputs
	 gets(stud.address);
	 printf("\n\tEnter new INCOME	:");
	 scanf("%lf",&stud.income);
     break;
    default:
     printf("Invalid Selection");
     break;
    }
    calc();
    fwrite(&stud, sizeof(stud), 1, fpt);
   }
  }
  fclose(fpo);
  fclose(fpt);
  fpo = fopen("Record.txt", "w");
  fpt = fopen("TempFile.txt", "r");
  while (fread(&stud, sizeof(stud), 1, fpt))
  {
   fwrite(&stud, sizeof(stud), 1, fpo);
  }
  fclose(fpo);
  fclose(fpt);
  remove("Record.txt");
  rename("TempFile.txt","Record.txt");
  printf("RECORD UPDATED");
 }
}
//====================================================================================
//    FUNCTION TO CHECK GIVEN ID NO IS AVAILABLE OR NOT 
int avlidno(int id)
{
 FILE *fp;
 int c = 0;
 fp = fopen("Record.txt", "r");
 while (!feof(fp))
 {
  fread(&stud, sizeof(stud), 1, fp);
  if (id == stud.id)
  {
   fclose(fp);
   return 1;
  }
 }
 fclose(fp);
 return 0;
}
//====================================================================================
//FUNCTION TO CHECK THE FILE IS EMPTY OR NOT
int empty()
{
 int c = 0;
 FILE *fp;
 fp = fopen("Record.txt", "r");
 while (fread(&stud, sizeof(stud), 1, fp))
  c = 1;
 fclose(fp);
 return c;
}
//====================================================================================
//FUNCTION TO TERMINATE THE PROGRAM
void terminate()
{
	printf("\n\n\t\tClosing...........");
	printf("\n\t\t\t\t\t\t............Closing\n");
	printf("\n\t\t\t\t*************** THANK YOU ***************\n");
	printf("\n\t****************************** Income Tax Calculator closed **********************************");
	exit(1);
}
//====================================================================================
// MAIN PROGRAM
void main()
{
 int c, emp;
 do
 {	
  printf("\n\n\n\t\t\t\t  ----------- INCOME TAX CALCULATOR -----------\n");
  printf("\t\t\t\t  _______________ By: Akash Kumar _____________\n");
  printf("\t\t\t\t  _________________ 11702349 __________________\n");
  printf("\t\t\t\t  ___________________ K17DQ ___________________\n");
  printf("\t\t\t\t  _______ Lovely Professional University ______\n");
  printf("\t\t\t\t  ---------------------------------------------\n");
  printf("\n\tPress Enter to continue...");
  getchar();
  system("cls");												//Menu driven program
  printf("\n\t\t\t\tDate :%s\n", __DATE__ );
  printf("\t\t\t\tTime :%s\n", __TIME__ );
  printf("\n\t****************************** Welcome to ICOME TAX Calculator *******************************");
  		printf("\n\t\t\tPress 1 to Add Record");
		printf("\n\t\t\tPress 2 to Display Record");
		printf("\n\t\t\tPress 3 to Search Record");
		printf("\n\t\t\tPress 4 to Delete Record");
		printf("\n\t\t\tPress 5 to Update Record");
		printf("\n\t\t\tPress 0 to Exit\n");
  printf("\n\t**********************************************************************************************\n");
  printf("\nEnter your choice : ");
  scanf("%d", &c);
  printf("\n");
  switch (c)
  {
  case 1:
   insert();
   break;
  case 2:
   emp = empty();
   if (emp == 0)
    printf("\nThe file is EMPTY\n");
   else
    disp();
   break;
  case 3:
   search();
   break;
  case 4:
   deletefile();
   break;
  case 5:
   update();
   break;
  case 0:
   terminate();
   break;
  default:
   printf("\n**************** Your choice is wrong ****************\nPlease try again...\n");
   break;
  }
 } while (c != 6);
getch();
}
