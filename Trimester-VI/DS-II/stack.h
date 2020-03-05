using namespace std;

template<class T>
class stack {
private:
    struct node {
        T data;
        node* next;
    };
    node* head;
public:
    stack(): head(NULL) {}
    void push(T val) {
        node* temp = new node();
        temp->data = val;
        temp->next = head;
        head = temp;
    }

    void pop() {
        head = head->next;
    }
    T top() const {return head->data;}
    bool empty() {return head == NULL;}
};