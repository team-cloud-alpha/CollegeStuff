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
    void Pre_Order_Rec_Traverse(Node*);
    void In_Order_Rec_Traverse(Node*);
    void Post_Order_Rec_Traverse(Node*);
public:
    BinaryTree() {
        this->top = NULL;
    }
    void Insert(string, string);
    Node* Search(string);
    void Mirror();
    BinaryTree Copy();
    void Display();
    void Helper(int);
    Node* Delete(Node*, string);
    Node* Delete(string);
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

void BinaryTree::Pre_Order_Rec_Traverse(Node* top) {
    if(top == NULL)
        return;
    cout << top->key << " ";
    this->Pre_Order_Rec_Traverse(top->left);
    this->Pre_Order_Rec_Traverse(top->right);
}

void BinaryTree::In_Order_Rec_Traverse(Node* top) {
    if(top == NULL)
        return;
    this->In_Order_Rec_Traverse(top->left);
    cout << top->key << " ";
    this->In_Order_Rec_Traverse(top->right);
}

void BinaryTree::Post_Order_Rec_Traverse(Node* top) {
    if(top == NULL)
        return;
    this->Post_Order_Rec_Traverse(top->left);
    this->Post_Order_Rec_Traverse(top->right);
    cout << top->key << " ";
}

void BinaryTree::Helper(int type) {
    switch(type) {
        case 1: this->Pre_Order_Rec_Traverse(this->top); break;
        case 2: this->In_Order_Rec_Traverse(this->top); break;
        case 3: this->Post_Order_Rec_Traverse(this->top); break;
    }
}

Node* BinaryTree::Delete(Node* root, string key) {
    if (root == NULL)
        return root;
    if (key < root->key)
        root->left = Delete(root->left, key);
    else if (key > root->key)
        root->right = Delete(root->right, key);
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(temp);
            return temp;
        }
        else if(root->right == NULL) {
            Node* temp = root->left;
            free(temp);
            return NULL;
        }
        else {
            Node* temp = root->right;
            while (temp->left != NULL) 
                temp = temp->left;
            root->key = temp->key;
            root->right = Delete(root->right, temp->key);
        }
    }
    return root;
}

Node* BinaryTree::Delete(string key) {
    return this->Delete(this->top, key);
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
        cout << "6. Display preorder\n7. Display in order\n8. Display post order\n";
        cout << "9. Delete word\n";
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
                break;
            }
            case 6: {
                tree.Helper(1);
                break;
            }
            case 7: {
                tree.Helper(2);
                break;
            }
            case 8:{
                tree.Helper(3);
                break;
            }
            case 9:{
                string key;
                cout << "Enter the word to delete: ";
                cin >> key;
                tree.Delete(key);
            }
        }
    }
}

//      m
//   e    n
// d   f