#include <iostream>
#define MAX 20

using namespace std;

template<class T>
class Stack {
    private:
        T Items[MAX];
        int top;
    public:
        void Push(T);
        T Pop();
        void Create();
        void Display();
};

template <class T>
void Stack<T>::Create() {
    top = -1;
    for (size_t i = 0; i < MAX; i++)
    {
        Items[i] = NULL;
    }
    
}

template <class T>
void Stack<T>::Display() {
    if (top == -1)
    {
        cout << "There are no elements in the stack.\n";
        return;
    }
    for (int i = top; i >= 0; i--)
    {
        cout << Items[i] << "\n";
    }
    cout << "\n";
}

template <class T>
void Stack<T>::Push(T item) {
    top++;
    Items[top] = item;
}

template <class T>
T Stack<T>::Pop() {
    if (top == -1)
    {
        cout << "There are no elements in the stack.\n";
        return NULL; 
    }
    T item = Items[top--];
    return item;
}

int main() {
    Stack<char> S;
    S.Create();
    while (true)
    {
        cout << "MENU\n1. Push onto stack\n2. Pop from stack\n3. Display stack\n4. Exit\n\nEnter Choice: ";
        int n;
        char c;
        cin >> n;
        switch (n)
        {
        case 1:
            cout << "Enter the item to be pushed onto the stack: ";
            cin >> c;
            S.Push(c);
            break;
        case 2:
            c = S.Pop();
            if (c != NULL)
            {            
                cout << "The item removed from the stack was " << c << "\n\n";
            }
            break;
        case 3:
            S.Display();
            break;
        case 4:
            exit(0);
        default:
            break;
        }
    }
}