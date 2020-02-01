/*
Name:Gautam Abhyankar
Batch:B4
Roll no. PB49
*/
#include<iostream>
using namespace std;

class Employee
{
	public:
		int sal;
		int workhr;
		int hrsal;
		int extrahrsal;
		int extrasal;
		Employee() : sal(0) {};
		virtual void GetSalary()=0;
};

class SalariedEmployee : virtual public Employee
{	public:
		void GetSalary()
		{ 
			sal=500;
			cout<<"You are a Salaried Employee. Your Salary is "<<sal<<"$"<<endl;
		}
};

class HourlyEmployee : public Employee
{	
public:
	HourlyEmployee()
	{
		workhr=0;
		hrsal=10;
		extrahrsal=15;
		extrasal=0;
	}
	void GetSalary()
	{
		cout<<"You are an Hourly Employee. Please enter the number of hours worked"<<endl;
		cin>>workhr;
		if (workhr <= 40)
		{
			sal=workhr*hrsal;
		}
		else
		{
			sal=40*hrsal;
			extrasal=(workhr-40)*extrahrsal;
			sal=sal+extrasal;
		}
		cout<<"Your salary is "<<sal<<"$"<<endl;	
	}
};

class CommissionEmployee : virtual public Employee
{ 	
protected:	
	int sales;
public:
	void GetSalary()
	{
		cout<<"You are a Commission Employee. Please enter your total sales"<<endl;
		cin>>sales;
		sal=(int)sales*(0.08);
		cout<<"Your salary is "<<sal<<"$"<<endl;	
	}
};

class SalariedCommissionEmployee  : public SalariedEmployee, CommissionEmployee
{ 		
public:
	void GetSalary()
	{
		cout<<"You are Salaried Commission Employee. Please enter your total sales"<<endl;
		cin>>sales;
		sal=200+(int)sales*(0.05)+20;
		cout<<"Your salary is "<<sal<<"$"<<endl;
		cout<<"You got a Reward of additional 10 percent of your base salary"<<endl;	
	}
};
int main()
{	Employee * e;
    while(true){
		int n;
		cout<<"Enter your type:"<<endl;
		cout<<"1. Salaried"<<endl;
		cout<<"2. Hourly based"<<endl;
		cout<<"3. Commission Employee"<<endl;
		cout<<"4. Salaried Commission Employee"<<endl;
		cout<<"5. Exit"<<endl;
		cin>>n;
		switch(n)
		{
			case 1:
			{
				SalariedEmployee emp1;
				e=&emp1;
				e->GetSalary();
				break;
			}
			case 2:
			{
				HourlyEmployee emp2;
				e=&emp2;
				e->GetSalary();
				break;
			}
			case 3:
			{
				CommissionEmployee  emp3;
				e=&emp3;
				e->GetSalary();
				break;
			}
			case 4:
			{
				SalariedCommissionEmployee  emp4;
				e=&emp4;
				e->GetSalary();
				break;
			}
			case 5:
				exit(0);
			default:
				cout<<"Invalid choice\n";
		}
	}
	return 0;
}
/*
Output:
asianintel@DESKTOP-993RJB3:/mnt/c/Users/gauta/OneDrive/Desktop/MITWPU/Trimester - IV/OOP$ g++ A3.cpp
asianintel@DESKTOP-993RJB3:/mnt/c/Users/gauta/OneDrive/Desktop/MITWPU/Trimester - IV/OOP$ ./a.out
Enter your type:
1. Salaried
2. Hourly based
3. Commission Employee
4. Salaried Commission Employee
5. Exit
1
You are a Salaried Employee. Your Salary is 500$
Enter your type:
1. Salaried
2. Hourly based
3. Commission Employee
4. Salaried Commission Employee
5. Exit
2
You are an Hourly Employee. Please enter the number of hours worked
50
Your salary is 550$
Enter your type:
1. Salaried
2. Hourly based
3. Commission Employee
4. Salaried Commission Employee
5. Exit
3
You are a Commission Employee. Please enter your total sales
120
Your salary is 9$
Enter your type:
1. Salaried
2. Hourly based
3. Commission Employee
4. Salaried Commission Employee
5. Exit
4
You are Salaried Commission Employee. Please enter your total sales
15000
Your salary is 970$
You got a Reward of additional 10 percent of your base salary
Enter your type:
1. Salaried
2. Hourly based
3. Commission Employee
4. Salaried Commission Employee
5. Exit
5
*/