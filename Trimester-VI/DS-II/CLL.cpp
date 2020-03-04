#include <iostream>
#include <cmath>

using namespace std;

class Node {
private:
        Node* next;
        int coeff;
        int power;
public:
    Node(int p, int c, Node* n) : coeff(c), power(p), next(n) {} 
    friend class Polynomial;
};

class Polynomial {
private:
    Node* start;
public:
    void AddNode(int, int);
    void Display();
    Polynomial Add(Polynomial);
    void Create();
    int Evaluate(int);

    Polynomial() {
        this->start = new Node(-1, 0, NULL);
        this->start->next = this->start;
    }
};

void Polynomial::AddNode(int power, int coeff) {
    Node* current = this->start;
    while(current->next->power > power) {
        current = current->next;
    }
    current->next = new Node(power, coeff, current->next);
}

void Polynomial::Display() {
    Node* current = this->start->next;
    if(current->power == -1) {
        cout << "Polynomial has no terms.\n";
    } else {
        while(current->next != this->start) {
            cout << current->coeff << "x^" << current->power << " + ";
            current = current->next;
        }
        cout << current->coeff << "x^" << current->power << "\n";
    }
}

Polynomial Polynomial::Add(Polynomial poly2) {
    Node* c1 = this->start->next, *c2 = poly2.start->next;
    bool flag1 = false, flag2 = false;
    Polynomial poly3;
    while (!flag1 || !flag2) {
        if(c1->power > c2->power) {
            poly3.AddNode(c1->power, c1->coeff);
            c1 = c1->next;
            if(c1 == this->start) flag1 = true;
        }
        else if(c1->power < c2->power) {
            poly3.AddNode(c2->power, c2->coeff);
            c2 = c2->next;
            if(c2 == poly2.start) flag2 = true;
        }
        else {
            poly3.AddNode(c1->power, c1->coeff + c2->coeff);
            c1 = c1->next; c2 = c2->next;
            if(c1 == this->start) flag1 = true;
            if(c2 == poly2.start) flag2 = true;
        }
    }

    return poly3;
}

void Polynomial::Create() {
    int n, power, coeff;
    cout << "Enter number of terms in the Polynomial: ";
    cin >> n;
    for(int i = 0; i < n; i++) {
        cout << "Enter power of new term: ";
        cin >> power;
        cout << "Enter coefficient of new term: ";
        cin >> coeff;
        this->AddNode(power, coeff);
    }
}

int Polynomial::Evaluate(int x) {
    Node* current = this->start->next;
    int result = 0;
    while(current != this->start) {
        result += current->coeff * pow(x, current->power);
        current = current->next;
    }
    return result;
}

int main () {
    Polynomial poly;
    int choice;
    while(true) {
        cout << "\nMENU\n";
        cout << "1. Add Term\n";
        cout << "2. Display Polynomial\n";
        cout << "3. Add Polynomial\n";
        cout << "4. Evaluate Polynomial\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1: {
            int power, coeff;
            cout << "Enter power of new term: ";
            cin >> power;
            cout << "Enter coefficient of new term: ";
            cin >> coeff;
            cout << "\n";
            poly.AddNode(power, coeff);
            break;
        }
        case 2: {
            poly.Display();
            break;
        }
        case 3: {
            Polynomial poly2;
            poly2.Create();
            Polynomial poly3 = poly.Add(poly2);
            cout << "Polynomial 1: ";
            poly.Display();
            cout << "\nPolynomial 2: ";
            poly2.Display();
            cout << "\nAddition: ";
            poly3.Display();
            break;
        }
        case 4: {
            int x;
            cout << "Enter the value to evaluate polynomial on: ";
            cin >> x;
            int res = poly.Evaluate(x);
            cout << "Evaluation: " << res;
            break;
        }
        default:
            break;
        }
    }
}