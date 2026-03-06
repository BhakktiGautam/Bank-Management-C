#include<stdio.h>
/* Structure to store account details */
struct Account{
	int accountNumber;		 // Unique account number
	char FirstName[50];		// Account holder first name
	char LastName[50];	        // Account holder last name
	float balance;		       // Current account balance
};

/* Array to store multiple accounts */
struct Account Account[500];

/* Variable to track total number of accounts */
int total_accounts=0;

/* Function to create a new account */
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

	/* Increase total account count after adding new account */
	total_accounts++;

	printf("Account created successfully\n");
}

/* Function to deposit money into an account */
void deposit()
{
	float deposit;		// amount to deposit
	int d;			//account number
	int found=0;		//flag to check if account exits 
	printf("Enter the account number of account holder\n");
	scanf("%d",&d);
	printf("Enter the amount you want to deposit\n");
	scanf("%f",&deposit);

	/* Validate deposit amount */
	if(deposit<=0)
	{
		printf("Invalid deposit amount\n");
		return;
	}

	/* Search account */
	for(int i=0;i<total_accounts;i++)
	{
		if(d==Account[i].accountNumber)
		{
				printf("Previous Balance:\n");
				printf("%.2f\n",Account[i].balance);

				/* Add deposit amount to balance */
			        Account[i].balance += deposit;
				printf("New Balance: %.2f\n",Account[i].balance);
				found=1;
				break;
		}
	}

	/* If account not found */
	if(found==0)
	{
		printf("Account not found\n");
	}
}

/* Function to withdraw money */
void withdrawl()
{
	int k,found=0;		// k = account number
	printf("Enter account number in which withdrawl should occur:\n");
	scanf("%d",&k);
	float withdrawl_amt;
	printf("Enter the amount to be withdrawn:");
	scanf("%f",&withdrawl_amt);
	
	/* Validate withdrawal amount */
	if(withdrawl_amt<=0)
	{
		printf("Invalid amount entered\n");
		return;
	}

	/* Search account */
	for(int j=0;j<total_accounts;j++)
	{
		if(k==Account[j].accountNumber)
		{

			/* Check if sufficient balance exists */
			if(withdrawl_amt>Account[j].balance)
			{
				printf("Insufficient Balance\n");
			}
			else
			{
				printf("Previous Balance:\n");
				printf("%f\n",Account[j].balance);

				
				/* Deduct withdrawal amount */
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

/* Function to transfer money between two accounts */
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

	/* Validate transfer amount */
	if(amount<=0)
	{
		 printf("Invalid transfer amount\n");
   		 return;
	}

		/* Search sender account */
			for(int k=0;k<total_accounts;k++)
		{
			if(sender_account==Account[k].accountNumber)
			{

				/* Search receiver account */
				for(int p=0;p<total_accounts;p++)
				{
					if(reciever_account==Account[p].accountNumber)
					{

						* Prevent transferring to same account */
						if(sender_account==reciever_account)
						{
							printf("Cannot transfer to same account\n");
    							found = 1;
    							break;	
						}
						
							/* Check if sender has enough balance */
							if(amount > Account[k].balance)
							{
							    printf("Insufficient balance\n");
								found=1;
								break;
							}

								/* Display balances before transfer */
								printf("Sender's balance before transfer: %f",Account[k].balance);
								printf("Reciever's balance before transfer: %f",Account[p].balance);
				
				/* Perform transfer */
			       Account[k].balance -=amount;
							       Account[p].balance +=amount;

								/* Display balances after transfer */
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
/* Function to check account balance */
void checkbalance()
{
	int accountno,found=0;
	printf("Enter the account number whose balance have to be checked: ");
	scanf("%d",&accountno);

	/* Search account */
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

/* Main function with menu-driven system */				
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
