#include<stdio.h>
struct Account{
	int accountNumber;
	char FirstName[50];
	char LastName[50];
	float balance;
};
struct Account Account[500];
int total_accounts=0;
void createaccount()
{
	printf("\nAdd account holder details: \n");
	printf("\nEnter the account number of customer\n");
	scanf("%d",&Account[total_accounts].accountNumber);
	printf("\nEnter the first Name of customer\n");
	scanf("%s",Account[total_accounts].FirstName);
	printf("\nEnter the Last Name of customer\n");
	scanf("%s",Account[total_accounts].LastName);
	printf("\nEnter the Balance of customer\n");
	scanf("%f",&Account[total_accounts].balance);
	total_accounts++;
	printf("Account created successfully\n");
}
void deposit()
{
	float deposit;
	int d;
	int found=0;
	printf("Enter the account number of account holder\n");
	scanf("%d",&d);
	printf("Enter the amount you want to deposit\n");
	scanf("%f",&deposit);
	if(deposit<=0)
	{
		printf("Invalid deposit amount\n");
		return;
	}
	for(int i=0;i<total_accounts;i++)
	{
		if(d==Account[i].accountNumber)
		{
				printf("Previous Balance:\n");
				printf("%.2f\n",Account[i].balance);
			        Account[i].balance += deposit;
				printf("New Balance: %.2f\n",Account[i].balance);
				found=1;
				break;
		}
	}
	if(found==0)
	{
		printf("Account not found\n");
	}
}
void withdrawl()
{
	int k,found=0;
	printf("Enter account number in which withdrawl should occur:\n");
	scanf("%d",&k);
	float withdrawl_amt;
	printf("Enter the amount to be withdrawn:");
	scanf("%f",&withdrawl_amt);
	if(withdrawl_amt<=0)
	{
		printf("Invalid amount entered\n");
		return;
	}
	for(int j=0;j<total_accounts;j++)
	{
		if(k==Account[j].accountNumber)
		{
			if(withdrawl_amt>Account[j].balance)
			{
				printf("Insufficient Balance\n");
			}
			else
			{
				printf("Previous Balance:\n");
				printf("%f\n",Account[j].balance);
				Account[j].balance -=withdrawl_amt;
				printf("New Balance: %.2f\n",Account[j].balance);
			}
			found=1;
				break;
		}
	}
	if(found==0)
	{
		printf("Account not found\n");
	}
}
void transfer()
{
	int found=0;
	int sender_account,reciever_account;
	float amount;
	printf("Enter sender's account number:\n");
	scanf("%d",&sender_account);
	printf("Enter reciever's account number: \n");
	scanf("%d",&reciever_account);
	printf("Enter the maount to be transferred:\n");
	scanf("%f",&amount);
	if(amount<=0)
	{
		 printf("Invalid transfer amount\n");
   		 return;
	}
			for(int k=0;k<total_accounts;k++)
		{
			if(sender_account==Account[k].accountNumber)
			{
				for(int p=0;p<total_accounts;p++)
				{
					if(reciever_account==Account[p].accountNumber)
					{
						if(sender_account==reciever_account)
						{
							printf("Cannot transfer to same account\n");
    							found = 1;
    							break;	
						}
						
							if(amount > Account[k].balance)
							{
							    printf("Insufficient balance\n");
								found=1;
								break;
							}
								printf("Sender's balance before transfer: %f",Account[k].balance);
								printf("Reciever's balance before transfer: %f",Account[p].balance);
							       Account[k].balance -=amount;
							       Account[p].balance +=amount;
								printf("Sender's balance after transfer: %f",Account[k].balance);
								printf("Reciever's balance after transfer: %f",Account[p].balance);
								found=1;
								break;
		 					}
						}
					 if(found == 1)
          		  		break;  
			}
		
		}
if(found==0)
{
	printf("Sender or receiver account not found\n");
}
}
		
void checkbalance()
{
	int accountno,found=0;
	printf("Enter the account number whose balance have to be checked: ");
	scanf("%d",&accountno);
	for(int l=0;l<total_accounts;l++)
	{
		if(accountno==Account[l].accountNumber)
		{
			printf("Current Balance: %f",Account[l].balance);
			found=1;
			break;
		}
	}
	if(found==0)
	{
	printf("Account not found\n");
	}
}
					
int main()
{
	int choice;
	do{
		
				printf("1.Create Account\n2.Deposit\n3.Withdraw\n4.Transfer\n5.Check Balance\n6.Exit\n");
		printf("Enter your choice\n");

		scanf("%d",&choice);
		if(choice==1)
		{
			createaccount();
		}
		else if(choice==2)
		{
			deposit();
		}
		else if(choice==3)
		{
			withdrawl();
		}
		else if(choice==4)
		{
			transfer();
		}
		else if(choice==5)
		{
			checkbalance();
		}
		else if(choice==6)
		{
			printf("EXIT DONE!");
			break;
		}
		else
		{
			printf("Invalid input");
		}
	}while(choice!=6);
return 0;
}