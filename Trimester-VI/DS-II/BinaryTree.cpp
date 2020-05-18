#include<iostream>
#include "stack.h"

using namespace std;

class Node {
private:
    Node* left;
    Node* right;
    int val;
public:
    Node(int v) : val(v), left(NULL), right(NULL) {}
    friend class BinaryTree;
};

class BinaryTree {
private:
    Node* top;

public:
    BinaryTree() {
        this->top = NULL;
    }
    void AddNode();
    void Rec_Traverse(int);
    void Pre_Order_Rec_Traverse(Node*);
    void In_Order_Rec_Traverse(Node*);
    void Post_Order_Rec_Traverse(Node*);
    void In_Order_Non_Rec_Traverse();
    void Post_Order_Non_Rec();
    void Pre_Order_Non_Rec();
};

void BinaryTree::AddNode() {
    int val, choice;
    cout << "\nEnter value of new node: ";
    cin >> val;
    if(this->top == NULL) {
        this->top = new Node(val);
    } else {
        Node* current = this->top;
        while(true) {
            cout << "\n1. Place Node on Left of " << current->val << "\n2. Place node on right of " << current->val << "\nEnter choice: ";
            int choice;
            cin >> choice;
            if(choice == 1) {
                if(current->left == NULL) {
                    current->left = new Node(val);
                    break;
                }
                current = current->left;
            }
            else if(choice == 2) {
                if(current->right == NULL) {
                    current->right = new Node(val);
                    break;
                }
                current = current->right;
            }
        }
    }
}

void BinaryTree::Rec_Traverse(int c) {
    switch(c) {
        case 1: this->Pre_Order_Rec_Traverse(this->top); break;
        case 2: this->In_Order_Rec_Traverse(this->top); break;
        case 3: this->Post_Order_Rec_Traverse(this->top); break;
    }
}

void BinaryTree::Pre_Order_Rec_Traverse(Node* top) {
    if(top == NULL)
        return;
    cout << top->val << " ";
    this->Pre_Order_Rec_Traverse(top->left);
    this->Pre_Order_Rec_Traverse(top->right);
}

void BinaryTree::In_Order_Rec_Traverse(Node* top) {
    if(top == NULL)
        return;
    this->In_Order_Rec_Traverse(top->left);
    cout << top->val << " ";
    this->In_Order_Rec_Traverse(top->right);
}

void BinaryTree::Post_Order_Rec_Traverse(Node* top) {
    if(top == NULL)
        return;
    this->Post_Order_Rec_Traverse(top->left);
    this->Post_Order_Rec_Traverse(top->right);
    cout << top->val << " ";
}

void BinaryTree::In_Order_Non_Rec_Traverse() {
    stack<Node*> stk;
    stk.push(this->top);
    Node* current = this->top->left;
    while(!stk.empty() || current != NULL) {
        if(current == NULL) {
            current = stk.top();
            stk.pop();
            cout << current->val << " ";
            current = current->right;
        } else {
            stk.push(current);
            current = current->left;
        }
    }
}     

void BinaryTree::Post_Order_Non_Rec() {
    stack<Node*> stk;
    Node* current = this->top;
    while (!stk.empty() || current != NULL) {
        if(current == NULL) {
            current = stk.top();
            stk.pop();
            if(current->right != NULL && !stk.empty() && stk.top()->val == current->right->val) {
                stk.pop();
                stk.push(current);
                current = current->right;
            } else  {
                cout << current->val << " ";
                current = NULL;
            }
        } else {
            if(current->right != NULL) {
                stk.push(current->right);
            }
            stk.push(current);
            current = current->left;
        }
    }
    
} 

void BinaryTree::Pre_Order_Non_Rec() {
    stack<Node*> stk;
    Node* current = this->top;
    while(!stk.empty() || current != NULL) {
        if(current == NULL) {
            current = stk.top();
            stk.pop();
        } else {
            if(current->right != NULL) {
                stk.push(current->right);
            }
            cout << current->val << " ";
            current = current->left;
        }
    }
}

//    1
//  2   3
//     4  5

int main() {
    BinaryTree tree;
    int choice;
    while(true) {
        cout << "\nMENU\n";
        cout << "1. Add Node\n";
        cout << "2. Recursive Traverse(Pre Order)\n";
        cout << "3. Recursive Traverse(In Order)\n";
        cout << "4. Recursive Traverse(Post Order)\n";
        cout << "5. Non Recursive Traverse(Pre Order)\n";
        cout << "6. Non Recursive Traverse(In Order)\n";
        cout << "7. Non Recursive Traverse(Post Order)\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1: tree.AddNode(); break;
        case 2: tree.Rec_Traverse(1); break;
        case 3: tree.Rec_Traverse(2); break;
        case 4: tree.Rec_Traverse(3); break;
        case 5: tree.Pre_Order_Non_Rec(); break;
        case 6: tree.In_Order_Non_Rec_Traverse(); break;
        case 7: tree.Post_Order_Non_Rec(); break;
        default:
            break;
        }
    }
}