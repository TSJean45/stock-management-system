#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<conio.h>

struct user
{
  char user[50];
  char pass[50];
};

struct detail
{
	char code[50],name[50],brand[50];
	int qty;
	float price;
};

void welcomescreen();
void loginscreen();
void userregister(); 
void userlogin();
void add_stock();
void view_stock();
void menu();
void delete_stock();
void stock_menu();
void edit_stock();
void addqty();
void subqty();
void viewqty();

void welcomescreen()
{
	printf("\n\n\t\t        *************************");
	printf("\n\t\t      *****************************");
	printf("\n\t\t    *********************************");
	printf("\n\t\t  ************************************");
	printf("\n\t\t*****************************************");
    printf("\n\t\t **                                   **");
    printf("\n\t\t **             Welcome               **");
    printf("\n\t\t **               To                  **");
    printf("\n\t\t **          Grey Matter's            **");
    printf("\n\t\t **    Warehouse Inventory System     **");
    printf("\n\t\t **                                   **");
    printf("\n/|/\\ \|//  /\\/  \|/**                                   ** \\|// \///  \\/  // \|/ \|/"); 
    printf("\n********************************************************************************");
    printf("\n\t\tPress any key to enter the program.....");
    getch();
    system("cls");	
}

void loginscreen()
{		
	time_t t;
	time(&t);
	printf("==========================================================================");
	printf("\n\t\tGrey Matter's Warehouse Inventory System");
	printf("\n\t\t\t%s",ctime(&t));
	printf("==========================================================================");
	printf("\n\t\t1. Register A New Account\n"  
	          "\t\t2. Login To An Existing Account\n"
			  "\t\t3. Exit\n");
	printf("==========================================================================\n");
}

void userregister()
{
	time_t t;
	time(&t);
  	char checkpass[50];
  	char c=' ';
  	int check,wish;
  	struct user r;

  	FILE *reg;
  	reg = fopen("user.txt","a+");

	printf("==========================================================================");
	printf("\n\t\t\t\tRegister");
	printf("\n\t\t\t%s",ctime(&t));
	printf("==========================================================================");	
	
	fflush(stdin);
	printf("\nEnter Username\t\t: ");
	gets(r.user);
	check=0;

  	while(check==0)
  	{
  		int i=0;
  		printf("Enter Password\t\t: ");
  		while(i<50)
		{
	    	r.pass[i]=getch();
	    	c=r.pass[i];
	    	if(c==13)
			{
	    		break;
			} 
	    	else
			{
				printf("*");
			} 
			i++;
		}
		r.pass[i]='\0';
		int p=0;
  		printf("\nEnter Password(Again)\t: ");
  		while(p<50)
		{
	    	checkpass[p]=getch();
	    	c=checkpass[p];
	    	if(c==13) 
			{
				break;
			}
	    	else 
			{
				printf("*");
			}
			p++;
		}
		checkpass[p]='\0';
  	
  		if(strcmp(r.pass,checkpass) == 0)
  		{
    		check=1;
  		}
  		else
  		{
    		printf("\nPassword don't match. Please re-enter password.\n");
  		}
  	}

  	fprintf(reg,"%s %s\n",r.user,r.pass);
  	fflush(stdin);
  	fclose(reg);
  	printf("\nAccount created successfully! \n\n");
  	
	printf("Enter (1) to go back to the main menu: ");
  	scanf("%d",&wish);
	
	if(wish==1)
  	{
		system("cls");	
   	 	main();
  	}
  	else
  	{
    	exit(1);
  	}		
  		
}

void userlogin()
{
	time_t t;
	time(&t);
  	char user[50]; char pass[50];
  	char c=' ';
  	int check,check2,wish;
  	struct user l;
  	
  	FILE *log;
  	log= fopen("user.txt","r");

  	printf("==========================================================================");
  	printf("\n\t\t\t\tLogin");
  	printf("\n\t\t\t%s",ctime(&t));
  	printf("==========================================================================");	
  
  	fflush(stdin);
  	printf("\nEnter username\t: ");
  	gets(user);
  
  	int i;
  	printf("Enter password\t: ");
  	for(i=0;i<50;i++)
	{
		pass[i]=getch();
	    c=pass[i];
	    if(c==13)
		{
	    	break;
		}
		else
		{
			printf("*");
		}
	}
	pass[i]='\0';

  	check=0;
  	check2=0;
  
  	while(fscanf(log,"%s %s",&l.user,&l.pass)!=EOF)
	{
    	if(strcmp(user,l.user)==0 && strcmp(pass,l.pass)==0)
    	{
          printf("\nLogin sucessfully\n");
          
          check=1;
          check2=1;
          
          fclose(log);
          printf("\nPress any key to continue.....");
          getch();
          system("cls");
          stock_menu();
        }
	}
	
	if(check==0)
    {
    	if(check2==0)
    	{
    		printf("\nIncorrect login details. \n\nEnter (1) to try again or any key to exit to the main menu: ");
    		scanf("  %d",&wish);
    		printf("\n");
    		
    		if(wish == 1)
    		{
    			system("cls");
    			userlogin();
			}
			else
			{
				system("cls");
				main();
			}
		}
	}
}

void add_stock()
{
	time_t t;
	time(&t);	
	int amount,i,wish;
	struct detail stock;
	
	do{
		system("cls");
		FILE *add_stock; 
		add_stock= fopen("stock.txt","a+");
		
		printf("==========================================================================");
	  	printf("\n\t\t\tEnter Stock's Detail");
	  	printf("\n\t\t\t%s",ctime(&t));
	  	printf("==========================================================================");	
		fflush(stdin);
		printf("\nEnter stock's brand\t\t: ");
		gets(stock.brand);
		
		printf("Enter stock's name\t\t: ");
		gets(stock.name);
		
		printf("Enter stock's code\t\t: ");
		gets(stock.code);
		
		printf("Enter stock's quantity\t\t: ");
		scanf("%d",&stock.qty);
		
		printf("Enter stock's price\t\t: RM ");
		scanf("%f",&stock.price);
		printf("\n\n");
			
		fprintf(add_stock,"%s %s %s %d %.2f\n",stock.brand,stock.name,stock.code,stock.qty,stock.price);
		system("cls");
		fclose(add_stock);
		fflush(stdin);
		printf("==========================================================================");
	  	printf("\n\t\t\tEnter Stock's Detail");
	  	printf("\n\t\t\t%s",ctime(&t));
	  	printf("==========================================================================");	
		printf("\nEnter (1) to view current stock or (0) to add more stock: ");
		scanf("%d",&wish);
	}while(wish==0);
	
	if(wish==1)
	{
		system("cls");
		view_stock();

	}
	else
	{
		system("cls");
		stock_menu();
	}
}

void view_stock()
{
	time_t t;
	time(&t);	
	struct detail stock;
	struct detail*ptr;
	ptr=&stock;
	
	FILE *view;
	view=fopen("stock.txt","r");
	
	printf("============================================================================");
  	printf("\n\t\t\t\tStock's Detail");
  	printf("\n\t\t\t%s",ctime(&t));
  	printf("============================================================================");	
	printf("\nBrand\t\tName\t\tCode\t\tQuantity\tPrice\n");
	
	while(!feof(view))
	{
		fscanf(view,"%s %s %s %d %f\n",&ptr->brand,&ptr->name,&ptr->code,&ptr->qty,&ptr->price);
		
		printf("%s\t\t%s\t\t%s\t\t%d\t\tRM%.2f\n",ptr->brand,ptr->name,ptr->code,ptr->qty,ptr->price);
	}
	printf("============================================================================");
	fclose(view);
	
	printf("\n\nPress any key to return to the main menu....");
	getch();
	system("cls");
	stock_menu();
}

void delete_stock()
{
	time_t t;
	time(&t);
	FILE *fread; FILE *fwrite;
	struct detail stock;
	char delete_code[50];
	int wish,find,test,test2;;
	
	fread=fopen("stock.txt","r"); 
	fwrite=fopen("temp.txt","w");
	
	fflush(stdin);
	printf("==========================================================================");
  	printf("\n\t\t\tEnter Stock's Detail");
  	printf("\n\t\t\t%s",ctime(&t));
  	printf("==========================================================================");	
  	printf("\nBrand\t\tName\t\tCode\t\tQuantity\tPrice\n");
	
	while(fscanf(fread,"%s %s %s %d %f",&stock.brand,&stock.name,&stock.code,&stock.qty,&stock.price)!=EOF)
	{	
		printf("%s\t\t%s\t\t%s\t\t%d\t\tRM%.2f\n",stock.brand,stock.name,stock.code,stock.qty,stock.price);
	}
	printf("==========================================================================");	
	printf("\nEnter the stock's code that you want to delete: ");
	gets(delete_code);
	
	rewind(fread);
	while(fscanf(fread,"%s %s %s %d %f",&stock.brand,&stock.name,&stock.code,&stock.qty,&stock.price)!=EOF)
	{
		if(strcmp(delete_code,stock.code)==0)
		{
			find=1;
		}
		else
		{
			fprintf(fwrite,"%s %s %s %d %.2f\n",stock.brand,stock.name,stock.code,stock.qty,stock.price);
		}
	}
	
	if(find==1)
	{
		printf("Stock deleted successfully!");
	}
	else
	{
	printf("\nStock's code does not exist");
	printf("\nPress any key to return to the menu.....");
	getch();
	system("cls");
	stock_menu();
	}
	
	fflush(stdin);
	
	fclose(fread);
	fclose(fwrite);
	remove("stock.txt");
	rename("temp.txt","stock.txt");
	
	printf("\nEnter (1) to view current stock or (0) to exit to the menu: ");
	scanf("%d",&wish);
	
	if(wish==1)
	{
		system("cls");
		view_stock();

	}
	if(wish==0)
	{
		system("cls");
		stock_menu();
	}
	else
	{
		system("cls");
		main();
	}	
}

void edit_stock()
{
	time_t t;
	time(&t);
	struct detail stock;
	int choice,wish,find;
	char code[50];
	
	FILE *fread, *fwrite;
	fread=fopen("stock.txt","r");
	fwrite=fopen("temp.txt","w");
	
	printf("==========================================================================");
  	printf("\n\t\t\tEnter Stock's Detail");
  	printf("\n\t\t\t%s",ctime(&t));
  	printf("==========================================================================");	
  	printf("\nBrand\t\tName\t\tCode\t\tQuantity\tPrice\n");
	
	while(fscanf(fread,"%s %s %s %d %f",&stock.brand,&stock.name,&stock.code,&stock.qty,&stock.price)!=EOF)
	{	
		printf("%s\t\t%s\t\t%s\t\t%d\t\tRM%.2f\n",stock.brand,stock.name,stock.code,stock.qty,stock.price);
	}
	printf("==========================================================================");	
	fflush(stdin);
	printf("\nEnter the stock's code: ");
	gets(code);
	

	rewind(fread);
	while(fscanf(fread,"%s %s %s %d %f",&stock.brand,&stock.name,&stock.code,&stock.qty,&stock.price)!=EOF)
	{
		if(strcmp(code,stock.code)==0){
			
			system("cls");
			printf("==========================================================================");
  			printf("\n\t\t\tStock's Detail");
  			printf("\n\t\t\t%s",ctime(&t));
 			printf("==========================================================================\n");
 			printf("Brand\t\tName\t\tCode\t\tQuantity\tPrice\n");
 			printf("%s\t\t%s\t\t%s\t\t%d\t\tRM%.2f\n",stock.brand,stock.name,stock.code,stock.qty,stock.price);
 			printf("==========================================================================\n");
 			printf("\t\t\t1. Update stock's brand");
			printf("\n\t\t\t2. Update stock's name");
 			printf("\n\t\t\t3. Update stock's code");
 			printf("\n\t\t\t4. Update stock's price");
 			printf("\n==========================================================================\n");
 			do
 			{
		
			fflush(stdin);
			printf("Enter your choice: ");
			scanf("%d",&choice);
			
			switch(choice)
			{
				case 1:
					fflush(stdin);
					printf("Enter new stock's brand: ");
					gets(stock.brand);
					break;
				case 2:
					fflush(stdin);
					printf("Enter new stock's name: ");
 					gets(stock.name);
 					break;
 				case 3:
 					fflush(stdin);
 					printf("Enter new stock's ID: ");
 					gets(stock.code);
 					break;
 				case 4:
 					fflush(stdin);
 					printf("Enter new stock's price: RM ");
 					scanf("%f",&stock.price);	
					break;	
			}
 		
 				printf("Enter (1) to continue editing or (0) to stop: ");
				scanf("%d",&wish);
				printf("\n");
				
			}while(wish==1);
			
			fprintf(fwrite,"%s %s %s %d %.2f\n",stock.brand,stock.name,stock.code,stock.qty,stock.price);
			find=1;
		}
		else
		{
			fprintf(fwrite,"%s %s %s %d %.2f\n",stock.brand,stock.name,stock.code,stock.qty,stock.price);
		}	
	}
	
	if(find==1)
	{
		fclose(fread);
		fclose(fwrite);
		remove("stock.txt");
		rename("temp.txt","stock.txt");
		printf("\n\nStock updated successfully");
		printf("\n\nPress any key to return to the main menu....");
		getch();
		system("cls");
		stock_menu();	
	}
	else
	{
		printf("\nStock code does not exist!");
		printf("\nPress any key to return to the menu.....");
		getch();
		system("cls");
		stock_menu();
	}
}

void addqty()
{
	time_t t;
	time(&t);
	char wish, choice;
	char code[50];
	int qty,find;
	struct detail stock;
	FILE *fread, *fwrite;
	
	fread=fopen("stock.txt","r");
	fwrite=fopen("temp.txt","w");
	
	printf("==========================================================================");
  	printf("\n\t\t\tStock's Detail");
  	printf("\n\t\t\t%s",ctime(&t));
 	printf("==========================================================================\n");
 	printf("Brand\t\tName\t\tCode\t\tQuantity\tPrice\n");
	
	while(fscanf(fread, "%s %s %s %d %f",&stock.brand,&stock.name,&stock.code,&stock.qty,&stock.price)!=EOF)
    {
		printf("%s\t\t%s\t\t%s\t\t%d\t\tRM%.2f\n",stock.brand,stock.name,stock.code,stock.qty,stock.price);
	}
	printf("==========================================================================");
	printf("\nAdd Quantity");
	printf("\nEnter stock's code: ");
	scanf("%s", &code);
	rewind(fread);
	while(fscanf(fread, "%s %s %s %d %f",&stock.brand,&stock.name,&stock.code,&stock.qty,&stock.price)!=EOF)
	{
	    if(strcmp(code, stock.code)==0)
	    {
	        printf("Enter the quantity you want to add: ");
	        scanf("%d", &qty);
	        stock.qty=stock.qty+qty;
	        fprintf(fwrite, "%s %s %s %d %.2f\n",stock.brand,stock.name,stock.code,stock.qty,stock.price);
	        find=1;
	    }
	    else
	    {
	    	stock.qty=stock.qty;
	    	fprintf(fwrite, "%s %s %s %d %.2f\n",stock.brand,stock.name,stock.code,stock.qty,stock.price);
		}
	}
		
	if(find==1)
		{
			printf("\nQuantity added successfully!");
		}
		else
		{
			printf("\nStock code does not exist!");
			printf("\nPress any key to return to the menu.....");
			getch();
			system("cls");
			stock_menu();
		}
		
	fclose(fread);
	fclose(fwrite);
	remove("stock.txt");
	rename("temp.txt", "stock.txt");
		
	printf("\nEnter (1) return to menu or (0) to exit: ");
	scanf("%d", &choice);
	
	if(choice==1)
	{
		system("cls");
		stock_menu();
	}
	else
	{
		system("cls");
		exit(1);
	}
	
}

void subqty()
{
	time_t t;
	time(&t);
    char wish, choice;
	char code[50];
	int qty,find;
	struct detail stock;
	FILE *fread, *fwrite;
	
	fread=fopen("stock.txt","r");
	fwrite=fopen("temp.txt","w");
	
	printf("==========================================================================");
  	printf("\n\t\t\tStock's Detail");
  	printf("\n\t\t\t%s",ctime(&t));
 	printf("==========================================================================\n");
 	printf("Brand\t\tName\t\tCode\t\tQuantity\tPrice\n");
	
	while(fscanf(fread, "%s %s %s %d %f",&stock.brand,&stock.name,&stock.code,&stock.qty,&stock.price)!=EOF)
    {
		printf("%s\t\t%s\t\t%s\t\t%d\t\tRM%.2f\n",stock.brand,stock.name,stock.code,stock.qty,stock.price);
	}
	printf("==========================================================================");
	printf("\nSubtract Quantity");
	printf("\nEnter stock's code: ");
	scanf("%s", &code);
	rewind(fread);
	while(fscanf(fread, "%s %s %s %d %f",&stock.brand,&stock.name,&stock.code,&stock.qty,&stock.price)!=EOF)
	{
	    if(strcmp(code,stock.code)==0)
	    {
	        printf("Enter the quantity you want to subtract: ");
	        scanf("%d", &qty);
	        stock.qty=stock.qty-qty;
	        fprintf(fwrite, "%s %s %s %d %.2f\n",stock.brand,stock.name,stock.code,stock.qty,stock.price);
	        find=1;
	    }
	    else
	    {
	    	stock.qty=stock.qty;
	    	fprintf(fwrite, "%s %s %s %d %.2f\n",stock.brand,stock.name,stock.code,stock.qty,stock.price);
		}
	}
	
	if(find==1)
	{
		printf("\nQuantity subtracted successfully!");
	}
	else
	{
		printf("\nStock code does not exist!");
		printf("\nPress any key to return to the menu.....");
		getch();
		system("cls");
		stock_menu();
	}
	
	fclose(fread);
	fclose(fwrite);
	remove("stock.txt");
	rename("temp.txt", "stock.txt");
	
	printf("\nEnter (1) return to menu or (0) to exit: ");
	scanf("%d", &choice);
	
	if(choice==1)
	{
		system("cls");
		stock_menu();
	}
	else
	{
		system("cls");
		exit(1);
	}
}

void viewqty()
{
	time_t t;
	time(&t);
	int max=0, min;
	char choice;
	struct detail stock;
	FILE *fread;
	fread=fopen("stock.txt", "r");
	
	printf("==========================================================================");
  	printf("\n\t\t\tStock's Detail");
  	printf("\n\t\t\t%s",ctime(&t));
 	printf("==========================================================================\n");
 	printf("\nBrand\t\tName\t\tCode\t\tQuantity\tPrice\n");
	
	while(fscanf(fread, "%s %s %s %d %f",&stock.brand,&stock.name,&stock.code,&stock.qty,&stock.price)!=EOF)
    {
		printf("%s\t\t%s\t\t%s\t\t%d\t\tRM%.2f\n",stock.brand,stock.name,stock.code,stock.qty,stock.price);
	}
	printf("==========================================================================\n");
	
	rewind(fread);
	max=stock.qty;
	while(fscanf(fread, "%s %s %s %d %f",&stock.brand,&stock.name,&stock.code,&stock.qty,&stock.price)!=EOF)
	{
		if(max<stock.qty)
		    max=stock.qty;
		else
		    max=max;
	}
	
	rewind(fread);
	while(fscanf(fread, "%s %s %s %d %f",&stock.brand,&stock.name,&stock.code,&stock.qty,&stock.price)!=EOF)
	{
		if(max==stock.qty)
		{
			printf("The stock with the highest quantity is: ");
			printf("\n==========================================================================\n");
			printf("\nBrand\t\tName\t\tCode\t\tQuantity\tPrice\n");
			printf("%s\t\t%s\t\t%s\t\t%d\t\tRM%.2f\n",stock.brand,stock.name,stock.code,stock.qty,stock.price);
			printf("==========================================================================\n");
		}
	}
	
	rewind(fread);
	min=stock.qty;
	while(fscanf(fread, "%s %s %s %d %f",&stock.brand,&stock.name,&stock.code,&stock.qty,&stock.price)!=EOF)
	{
		if(min<stock.qty)
		    min=min;
		else
		    min=stock.qty;
	}
	
	rewind(fread);
	while(fscanf(fread, "%s %s %s %d %f",&stock.brand,&stock.name,&stock.code,&stock.qty,&stock.price)!=EOF)
	{
		if(min==stock.qty)
		{
			printf("The stock with the lowest quantity is: ");
			printf("\n==========================================================================\n");
			printf("\nBrand\t\tName\t\tCode\t\tQuantity\tPrice\n");
			printf("%s\t\t%s\t\t%s\t\t%d\t\tRM%.2f\n",stock.brand,stock.name,stock.code,stock.qty,stock.price);
			printf("==========================================================================\n");
		}
	}
	
	fclose(fread);
	printf("\nEnter (1) return to menu or (0) to exit: ");
	scanf("%d", &choice);
	
	if(choice==1)
	{
		system("cls");
		stock_menu();
	}
	else
	{
		system("cls");
		exit(1);
	}
	
}

void menu()
{
	time_t t;
	time(&t);
  	printf("==========================================================================");
  	printf("\n\t\tGrey Matter's Warehouse Inventory System");
  	printf("\n\t\t\t%s",ctime(&t));
  	printf("==========================================================================");
  	printf("\n\t\t1. View Stock\n"  
          "\t\t2. Add Stock\n"
          "\t\t3. Delete Stock\n"
          "\t\t4. Edit Stock's Details\n"
          "\t\t5. Add Stock's Quantity\n"
          "\t\t6. Subtract Stock's Quantity\n"
          "\t\t7. View Stock With Lowest and Highest Quantity\n"
		  "\t\t8. Log out\n");
  	printf("==========================================================================\n");
}

void stock_menu()
{
	int choice;
	
	menu();
	fflush(stdin);
	printf("Enter your choice: ");
  	scanf("%d",&choice);
	
	switch(choice)
  {
    case 1: 
	  system("cls");
      view_stock();
      break;
    
    case 2: 
      system("cls");
      add_stock();
      break;
      
    case 3:
    	system("cls");
    	delete_stock();
    	break;
    	
    case 4:
    	system("cls");
    	edit_stock();
    	break;
    
	case 5:
    	system("cls");
    	addqty();
    	break;	
    
    case 6:
    	system("cls");
    	subqty();
    	break;
    	
    case 7:
    	system("cls");
    	viewqty();
    	break;	
    
    case 8: 
    	system("cls");
    	main(0);
    	break;
  }
}
    
void main()
{
  int choice;
  welcomescreen();
  loginscreen();
  fflush(stdin);
  printf("Enter your choice: ");
  scanf("%d",&choice);

  switch(choice)
  {
    case 1: 
	  system("cls");
      userregister();
      break;
    
    case 2: 
      system("cls");
      userlogin();
      break;
      
    case 3:
    	exit(1);
    	break;
    	
    default:
    	printf("Invalid choide!");
    	exit(1);
    	break;
  }
}
