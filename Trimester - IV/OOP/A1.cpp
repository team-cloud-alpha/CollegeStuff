/**
Name: Gautam Abhyankar
Panel: B
Roll No. : PB - 49 
*/

//Develop an object oriented program to create a database of student info system containing the following info:-
//Name, Roll No, CLass, Division, DOB, Aadhaar, Blood Group, Contact Address, Telephone.
//Construct the database with suitable member functions for initializing and destroying the data via constructor, default constructor,
//copy constructor, destructor.
//Also display the info.
#include<iostream>
#include<string>

using namespace std;

class Student {
	string name;
	int rollNo;
	string Class;
	char Division;
	string DOB;
	long int Aadhaar;
	string Blood;
	string Address;
	int Telephone;
public:
	Student();
	Student(const Student& s);
	void Display();
};

Student::Student() {
	cout << "Enter Student Details\n";
	cout << "Enter Student Name:- ";
	getline(cin, name);
	cout << "Enter Roll No:- ";
	cin >> rollNo;
	cout << "Enter Class:- ";
	cin >> Class;
	cout << "Enter Division:- ";
	cin >> Division;
	cout << "Enter Date of Birth:- ";
	cin >> DOB;
	cout << "Enter Aadhar:- ";
	cin >> Aadhaar;
	cout << "Enter Blood Group:- ";
	cin >> Blood;
	cin.ignore();
	cout << "Enter Address:- ";
	getline(cin, Address);
	cout << "Enter Telephone:- ";
	cin >> Telephone;
	cin.ignore();
}

Student::Student(const Student& s) {
	name = s.name;
	rollNo = s.rollNo;
	Class = s.Class;
	Division = s.Division;
	DOB = s.DOB;
	Aadhaar = s.Aadhaar;
	Blood = s.Blood;
	Address = s.Address;
	Telephone = s.Telephone;
}

void Student::Display() {
	cout << "\nName:- " << name << "\n";
	cout << "Roll No:- " << rollNo << "\n";
	cout << "Class:- " << Class << "\n";
	cout << "Division:- " << Division << "\n";
	cout << "DOB:- " << DOB << "\n";
	cout << "Aadhar:- " << Aadhaar << "\n";
	cout << "Blood Group:- " << Blood << "\n";
	cout << "Address:- " << Address << "\n";
	cout << "Telephone:- " << Telephone << "\n";
}

int main() {
	Student S[5];
	for(int i = 0; i < 5; i++) {
		cout<< "Displaying Student Details:-\n";
		S[i].Display();
	}
}

/**
mitwpu@C04L0830:~/Downloads$ g++ two.cpp -std="c++17"
mitwpu@C04L0830:~/Downloads$ ./a.out
Enter Student Details:-
Enter Student Name:- Gautam
Enter Roll No:- 18
Enter Class:- A
Enter Division:- 1
Enter Date of Birth:- 30/01/01
Enter Aadhar:- 569879877
Enter Blood Group:- A+
Enter Address:- oidffdhg dsfboiudhd skdhksdf
Enter Telephone:- 4537984785

Displaying Student Details:-
Name:- Gautam
Roll No:- 18
Class:- A
Division:- 1
DOB:- 30/01/01
Aadhar:- 569879877
Blood Group:- A+
Address:- oidffdhg dsfboiudhd skdhksdf
Telephone:- 2147483647 
*/