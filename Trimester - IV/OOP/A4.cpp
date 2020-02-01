#include<iostream>
#include<string>

using namespace std;

class Employee {
public:
    static int Count;
    int id;
    string name;
    int age;
    int income;
    string City;
    bool FourWheeler;
    Employee() : id(Count), name("N/A"), age(18), income(50000), City("Pune"), FourWheeler(true) {
        Count++;
    };
    void display();
};

int Employee::Count = 0;

int main() {
    try
    {
        Employee e;
        cout << "Enter Employee Name: ";
        getline(cin, e.name);
        cout << "Enter Employee Age: " ;
        cin >> e.age;
        if (e.age < 18 || e.age > 55)
        {
            throw "Employee age must be between 18 and 55";
        }
        cout << "Enter Employee Income: ";
        cin >> e.income;
        if (e.income < 50000 || e.income > 100000)
        {
            throw "Employee Income must be between 50000 and 100000";
        }
        
    }
    catch(const exception& e)
    {
        cout << e.what() << '\n';
    }
}