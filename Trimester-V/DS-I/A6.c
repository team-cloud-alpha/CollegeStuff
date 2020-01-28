#include <stdio.h>
#include <stdlib.h>

typedef struct {
    struct Node* next;
    int value;
} Node;

void addNode(struct Node** start) {
    int n;
    printf("Enter value of node: ");
    scanf("%d", &n);
    if (*start == NULL) {
        *start = (struct Node *) malloc(sizeof(struct Node));
        (*start)->value = n;
        (*start)->next = NULL;
    }
    else {
        struct Node* current = (*start);
        while(current->next != NULL) {
            current = current->next;
        }
        current->next = (struct Node *) malloc(sizeof(struct Node));
        current->next->next = NULL;
        current->next->value = n;
    }
    
}

void deleteNode(struct Node** start) {
    if((*start) == NULL) {
        printf("Linked list is empty");
    }
    else {
        int n;
        printf("Enter value of node to delete");
        scanf("%d", &n);
        struct Node *current = *start, *previous = NULL;
        while(current->value != n) {
            if(current->next == NULL)
                return;
            previous = current;
            current = current->next;
        }
        if(*start == current) {
            *start = (*start)->next;
        }
        else {
            previous->next = current->next;
        }
    }
}

void displayNodes(struct Node** start) {
    if((*start) == NULL) {
        printf("Linked list is empty");
    }
    else {
        struct Node* current = *start;
        while (current != NULL) {
            printf("%d\t", current-> value);
            current = current->next;
        }
        printf("\n");
    }
}

void reverseList(struct Node** start) {
    struct Node *previous = NULL, *current = *start, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    *start = previous;
}

void sortList(Node** start) {
    int a;
    Node* t1, *t2;
    for(t1 = *start; t1 != NULL ; t1 = t1->next) {
        for(t2 = t1; t2 != NULL; t2 = t2->next) {
            if(t2->value < t1->value) {
                a = t1->value;
                t1->value = t2->value;
                tp2->value = a;
            }
        }
    }
}

void mergeList(struct Node** start, struct Node** to_merge_start) {
    if((*start) == NULL) {
        *start = *to_merge_start;
    }
    else {
        struct Node* current = *start;
        while(current->next != NULL) 
            current = current->next;
        current->next = *to_merge_start;
    }
}

int main() {
    struct Node *start = NULL, *to_merge_start = NULL;
    int n = 0;
    while(1) {
        printf("MENU\n1. Add Node\n2. Remove Node\n3. Display list\n4. Reverse list\n5. Sort list\n6. Merge lists\nEnter your choice: ");
        scanf("%d", &n);
        switch(n) {
            case 1: {
                addNode(&start);
                break;
            }
            case 2: {
                deleteNode(&start);
                break;
            }
            case 3 : {
                displayNodes(&start);
                break;
            }
            case 4: {
                reverseList(&start);
                break;
            }
            case 5: {
                sortList(&start);
                break;
            }
            case 6: {
                printf("Enter length of linked list to be merged: ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    addNode(&to_merge_start);
                }
                mergeList(&start, &to_merge_start);
            }
        }
    }  
}
