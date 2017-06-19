// OOPS PROJECT

#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

using namespace std;

void menu();
void password();

class customer
{
	public:
		
		char name[20];
		char type[10];
		long int cnum;
		long int balance;
		
	void getdata()
	{
		cout<<"\n\tENTER THE FIRST NAME OF THE CUSTOMER:\t";
		cin>>name;
		cout<<"\n\tENTER TYPE OF ACCOUNT:\t";
		cin>>type;
		cout<<"\n\tENTER THE CUSTOMER NUMBER:\t";
		cin>>cnum;
		cout<<"\n\tENTER THE FIRST DEPOSIT AMOUNT:\t";
		cin>>balance;
	}
	
	void putdata()
	{
		  cout<<"\n\tNAME OF CUSTOMER:\t"<<name;
		  cout<<"\n\tACCOUNT TYPE:\t\t"<<type;
		  cout<<"\n\tCUSTOMER NUMBER:\t"<<cnum;
		  cout<<"\n\tBALANCE AMOUNT:\t\t"<<balance;
	}
	
	void deposit()
	{
		long int d;
		cout<<"\n\tMAXIMUM ONE TIME DEPOSIT Rs.50000";
		cout<<"\n\tENTER AMOUNT TO BE DEPOSITED:\t";
		cin>>d;
		balance+=d;
	}
	
	int check(int s)
	{
		if(s==cnum)
		{
			return 1;
		}
		
		else
		{
			return 0;
		}
	}
	
	int retno()
	{
		return cnum;
	}
	
	void withdraw()
	{
		long int w;
		cout<<"\n\tMAXIMUM WITHDRAWAL AMOUNT RS 50000";
		cout<<"\n\tNOTE MINIMUM BALANCE SHOULD NOT GO BELOW RS 1000";
		cout<<"\n\tENTER WITHDRAWAL AMOUNT:\t";
		cin>>w;
		try
		{
			if((balance-1000)<w)
			{
				 throw 1;
			}
			
			else
			{
				balance-=w;
			}
		}
		
		catch(int)
		{
			 cout<<"\n\tWITHDRAWAL AMOUNT GREATER THAN BALANCE AMOUNT";
		}
		
	}
	
	
};

int main()
{
	 cout<<"\n\tWELCOME TO PRAKA BANK PVT. LTD\n\n";
	 cout<<"\n\tENTER THE PASSWORD:\t";
	 password();
	 for(;;)
	 {
	 	menu();
	 }
	 
 getch();	 	 
}

void menu()
{
	int choice;
	int ch=0;
	int pos=0;
	int flag=0;
	int a=1;
	
	customer *c2=new customer;
	customer *c3=new customer;
	customer *cus=new customer;
	long int bno;
	customer c1;
	 cout<<"\n\n\n\n\t1. NEW BANK ACCOUNT";
	 cout<<"\n\t2. DEPOSIT IN ACCOUNT";
	 cout<<"\n\t3. WITHDRAW FROM ACCOUNT";
	 cout<<"\n\t4. CLOSE ACCOUNT";
	 cout<<"\n\t5. DISPLAY ACCOUNT DETAILS";
	 cout<<"\n\t6. EXIT";
	 cout<<"\n\n\tENTER CHOICE:\t";
	 cin>>choice;
	 
	 switch(choice)
	 {
	 	case 1: { 
		          ofstream of1("cust.dat");
		 	  	  c1.getdata();
		 		  of1.write((char*)&c1,sizeof(customer));
		 		  cout<<"\n\n\n\t\tCONGRATS ON OPENING AN ACCOUNT IN PRAKA BANK";
		 		  getch();
		 		  of1.close();
	 		      break;
			    }
	 		    
	 	case 2: { 
		         	 fstream if1("cust.dat");
	 				 cout<<"\n\tENTER ACCOUNT NUMBER:\t";
	 			 	cin>>bno;
	 				 if1.seekg(0);
	 				 while(!if1.eof())
	 			 	{	
	 			  	  	pos=if1.tellg();
	 					if1.read((char*)c2,sizeof(customer));
	 				
	 					if(c2->retno()==bno)
	 					{
	 						flag=1;
	 						break;
						}
				 	}	
				
				 	if(flag==0)
					 {
							cout<<"\n\tRECORD NOT FOUND";
				 	 }
		 		
		 		 	else
		 			 {
		 		 		c2->deposit();
		 				 if1.seekp(pos);
		 			 	if1.write((char*)c2,sizeof(customer));
					 }
				  
				     if1.close();
	 	 	         break;
			    }
	 	 	    
	 	case 3:	{
		  	    	fstream f1("cust.dat");
	 				cout<<"\n\tENTER ACCOUNT NUMBER:\t";
	 			  	cin>>bno;
	 				f1.seekg(0);
	 				while(!f1.eof())
	 				{	
	 			    	pos=f1.tellg();
	 					f1.read((char*)c3,sizeof(customer));
	 					
	 					if(c3->retno()==bno)
	 					{
	 						flag=1;
	 						break;
						}
					}	
				
					if(flag==0)
					{
							cout<<"\n\tRECORD NOT FOUND";
					}
		 		
		 			else
		 			{
		 				c3->withdraw();
		 				f1.seekp(pos);
		 				f1.write((char*)c3,sizeof(customer));
					 	
					}
					f1.close();
	 		    	break;
			 }
	 		    
	 	case 4: {
					cout<<"\n\nENTER THE ACCOUNT NUMBER:\t";
					cin>>bno;
					fstream fp("cust.dat",ios::in|ios::out);
					fstream fp2;
					fp2.open("Temp.dat",ios::out);
					fp.seekg(0);
					while(fp.read((char*)&c1,sizeof(customer)))
					{
		
						if(c1.retno()!=bno)
						{
								fp2.write((char*)&c1,sizeof(customer));
						}

					}

					fp2.close();
					fp.close();
					remove("cust.dat");
					rename("Temp.dat","cust.dat");
					cout<<"\n\n\tACCOUNT HAS BEEN CLOSED";
					getch();
					break;
		  	    }
	 			
	 	case 5: {
		 		 	fstream if2("cust.dat");
		 			if2.seekg(0);
	 				while(if2)
	 				{
	 					if2.read((char*)cus,sizeof(customer));
	 					if(!if2.eof())
	 					{
	 						cout<<"\n\n"<<a;
	 						cus->putdata();
	 						a++;
	 						getch();
				 	    }
				
						if(a==1)
						{
							cout<<"\n\tNO RECORDS EXIST";
							getch();
						}
				    }
					if2.close();
					break; 
				}
	 			
	 	default: exit(0);
	 }
}

void password()
{
	int pass1;
	char p1,p2,p3,p4,p5;
	p1=getch();
	cout<<"*";
	p2=getch();
	cout<<"*";
	p3=getch();
	cout<<"*";
	p4=getch();
	cout<<"*";
	p5=getch();
	cout<<"*";
	if((p1=='p'||p1=='P')&&(p2=='r'||p2=='R')&&(p3=='a'||p3=='R')&&(p4=='k'||p4=='K')&&(p5=='a'||p5=='A'))
	{
		menu();
		
	}
	
	else
	{
		cout<<"\n\tWRONG PASSWORD ENTERED";
		cout<<"\n\t1.RE-ENTER PASSWORD\n\n\n\t2.EXIT:\t";
		cin>>pass1;
		if(pass1==1)
		{
			password();
		}
		
		else
		{
			cout<<"\n\tPROGRAM TERMINATING...";
			getch();
			exit(0);
		}
		
	}
}
