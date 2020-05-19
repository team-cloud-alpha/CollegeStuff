#include <iostream>
#include <vector>

using namespace std;

class Student {
private:
    int marks;
    int roll;
    friend class Heap;
public:
    Student(): marks(-1), roll(-1) {}
    Student(int m, int r): marks(m), roll(r) {}
};

class Heap {
private:
    vector<Student> students;
    bool minimum;
    void Heapify(int);
public:
    Heap(bool m) : students(vector<Student>(0)), minimum(m) {}
    void Insert(Student);
    void Display();
    int Extract();
};

void Heap::Heapify(int key) {
    int parent = (key - 1)/2;
    if (parent >= 0) {
        if (minimum) {
            if (students[parent].marks > students[key].marks) {
                auto temp = students[parent];
                students[parent] = students[key];
                students[key] = temp;
                Heapify(parent);
            }
        } else {
            if (students[parent].marks < students[key].marks) {
                auto temp = students[parent];
                students[parent] = students[key];
                students[key] = temp;
                Heapify(parent);
            }
        }
    }
}

void Heap::Display() {
    for (int i = 0; i < students.size(); i++) {
        cout << students[i].marks << " ";
    }
    cout << "\n";
}

void Heap::Insert(Student s) {
    students.push_back(s);
    Heapify(students.size()-1);
}

int Heap::Extract() {
    return students[0].marks;
}

int main() {
    Heap min_heap(true);
    Heap max_heap(false);
    int choice;
    while(true) {
        cout << "MENU\n";
        cout << "1. Add Student \n";
        cout << "2. Display Max Heap\n";
        cout << "3. Display Min Heap\n";
        cout << "4. Get Max & Min marks\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1: {
                int roll, marks;
                cout << "Enter student details:\n";
                cout << "Enter student roll: ";
                cin >> roll;
                cout << "Enter student marks: ";
                cin >> marks;
                Student s(marks, roll);
                max_heap.Insert(s);
                min_heap.Insert(s);
                break;
            }
            case 2: {
                max_heap.Display();
                break;
            }
            case 3:{
                min_heap.Display();
                break;
            }
            case 4: {
                cout << "The max marks are: " << max_heap.Extract() << "\n";
                cout << "The min marks are: " << min_heap.Extract() << "\n";
            }
            default:
                break;
        }
    }
}