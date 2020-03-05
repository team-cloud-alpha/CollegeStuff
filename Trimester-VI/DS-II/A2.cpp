#include<iostream>
#include <queue>

using namespace std;

class Node {
private:
    Node* left;
    Node* right;
    string key;
    string meaning;
public:
    Node(string k, string m) : key(k), meaning(m), left(NULL), right(NULL) {}
    friend class BinaryTree;
    string getKey() const {return key;}
    string getMeaning() const {return meaning;}
};

class BinaryTree {
private:
    Node* top;
    Node* Clone(Node*);
    void MirrorUtil(Node*);
public:
    BinaryTree() {
        this->top = NULL;
    }
    void Insert(string, string);
    Node* Search(string);
    void Mirror();
    BinaryTree Copy();
    void Display();
};

void BinaryTree::Insert(string key, string meaning) {
    if(this->top == NULL) {
        this->top = new Node(key, meaning);
    } else {
        Node* current = this->Search(key);
        if(key == current->key)
            cout << "Key already exists";
        else if(key > current->key) 
            current->right = new Node(key, meaning);
        else 
            current->left = new Node(key, meaning);
    }
}

Node* BinaryTree::Search(string key) {
    if(this->top == NULL) 
        return NULL;
    Node* current = this->top;
    while(current != NULL) {
        if(key == current->key)
            return current;
        else if(key > current->key) {
            if(current->right == NULL) return current;
            current = current->right;
        }  
        else {
            if(current->left == NULL) return current;
            current = current->left;
        }  
    }
    return current;
}

void BinaryTree::MirrorUtil(Node* root) {
    if(root == NULL) return;
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    this->MirrorUtil(root->left);
    this->MirrorUtil(root->right);
}

void BinaryTree::Mirror() {
    this->MirrorUtil(this->top);
}

Node* BinaryTree::Clone(Node* root) {
    if(root == NULL) return NULL;
    Node* temp = new Node(root->key, root->meaning);
    temp->left = this->Clone(root->left);
    temp->right = this->Clone(root->right);
    return temp;
}

BinaryTree BinaryTree::Copy() {
    BinaryTree tree2;
    tree2.top = this->Clone(this->top);
    return tree2;
}

void BinaryTree::Display() {
    queue<Node*> q;
    q.push(this->top);
    while(!q.empty()) {
        Node* current = q.front();
        cout << current->key << " ";
        q.pop();
        if(current->left != NULL) 
            q.push(current->left);
        if (current->right != NULL)
            q.push(current->right);
    }
}

int main() {
    BinaryTree tree;
    int choice;
    while(true) {
        cout << "\nMENU\n";
        cout << "1. Add Word\n";
        cout << "2. Search word\n";
        cout << "3. Mirror current tree\n";
        cout << "4. Clone tree\n";
        cout << "5. Display tree level-wise\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1: {
                string key, meaning;
                cout << "Enter the word: ";
                cin >> key;
                cout << "Enter the meaning of " << key << ": ";
                cin >> meaning;
                tree.Insert(key, meaning);
                break;
            }
            case 2: {
                string key;
                cout << "Enter the search word: ";
                cin >> key;
                Node* ans = tree.Search(key);
                if(ans == NULL || ans->getKey() != key)
                    cout << "The given search word does not exist in the tree\n";
                else
                    cout << "The meaning of the given search word is " << ans->getMeaning() << "\n";
                break;
            }
            case 3: {
                tree.Mirror();
                tree.Display();
                break;
            }
            case 4: {
                BinaryTree tree2 = tree.Copy();
                tree2.Display();
                break;
            }
            case 5: {
                tree.Display();
            }
        }
    }
}

//      m
//   e    n
// d   f