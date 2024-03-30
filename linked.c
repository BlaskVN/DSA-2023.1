#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the end of the linked list
void addNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}



// Function to free the memory allocated for the linked list
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}


// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    freeList(head);
}

struct Node* F(struct Node* h,int v){
    if (h==NULL)
    {
        return NULL;
    }
    if (h->data == v)
    {
        h = h->next;
        if (h == NULL)
        {
            return h;
        }
        
    }
    h->next = F(h->next,v);
    return h;
    
}

int main() {
    struct Node* head = NULL;

    addNode(&head, 1);
    addNode(&head, 3);
    addNode(&head, 2);
    addNode(&head, 4);
    addNode(&head, 3);
    addNode(&head, 2);
    addNode(&head, 5);
    
    F(head,3);
    printList(head);
    return 0;
}
