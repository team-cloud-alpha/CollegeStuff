#include <iostream>
#define MAX 10

using namespace std;

class Student {
private:
    int roll;
    string name;
    char grade;
public:
    Student(): roll(-1), name(""), grade('\0') {}
    Student(int r, string n, char g) : roll(r), name(n), grade(g) {}
    friend class Hash;
};

class Hash {
private:
    Student table[MAX];
    void Display();
public:
    void probing(Student);
    void probing_with_rep(Student);
};

void Hash::Display() {
    cout << "Index\tRoll Number\tName\tGrade\n";
    for (int i = 0; i < MAX; i++) {
        if (table[i].roll == -1)
            cout << i << "\t\t" << table[i].name << "\t" << table[i].grade << "\n";
        else 
            cout << i << "\t" << table[i].roll << "\t" << table[i].name << "\t" << table[i].grade << "\n";
    }
}

void Hash::probing(Student s) {
    int index, location;
    bool flag = false, cx = false;
    index = location = s.roll % MAX;
    while(!flag && table[index].roll != -1) {
        index = (index+1)%MAX;
        cx = true;
        flag = index == location;
    }
    if (flag && cx) 
        cout << "No space available";
    else 
        table[index] = s;
    Display();
}

void Hash::probing_with_rep(Student s) {
    int index, location;
    bool flag = false, cx = false;
    index = location = s.roll % MAX;

    if (table[index].roll != -1) {
        if (table[index].roll % MAX != index) {
            auto temp = table[index];
            table[index] = s;
            s = temp;
        }
    }

    while(!flag && table[index].roll != -1) {
        index = (index+1)%MAX;
        cx = true;
        flag = index == location;
    }
    if (flag && cx) 
        cout << "No space available";
    else 
        table[index] = s;
    Display();
}

int main() {
    Hash hash;
    int choice;
    while(true) {
        cout << "MENU\n";
        cout << "1. Add Student (Linear probing without replacement)\n";
        cout << "2. Add Student (Linear probing with replacement)\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1: {
                int roll; string name; char grade;
                cout << "Enter student details:\n";
                cout << "Enter student roll: ";
                cin >> roll;
                cout << "Enter student name: ";
                cin >> name;
                cout << "Enter student grade: ";
                cin >> grade;
                Student s(roll, name, grade);
                hash.probing(s); 
                break;
            }
            case 2: {
                int roll; string name; char grade;
                cout << "Enter student details:\n";
                cout << "Enter student roll: ";
                cin >> roll;
                cout << "Enter student name: ";
                cin >> name;
                cout << "Enter student grade: ";
                cin >> grade;
                Student s(roll, name, grade);
                hash.probing_with_rep(s); 
                break;
            }
            default:
                break;
        }
    }
}