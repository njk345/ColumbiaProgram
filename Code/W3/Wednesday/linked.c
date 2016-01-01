#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node *next;
}Node;

void addNode(int data, Node *head) {
    Node *n = malloc(sizeof(Node));
    n->data = data;
    Node *c = head;
    while (c->next != NULL) {
        c = c->next;
    }
    c->next = n;
    n->next = NULL;
}

void display (Node *head) {
    Node *conductor = head;
    int i = 1;
    
    while (conductor != NULL) {
        printf("Node %d: Data = %d\n", i, conductor->data);
        i++;
        conductor = conductor->next;
    }
}

void insertAtIndex(Node *head, int val) {
    Node *curr = head;
    Node *temp;
    Node *new = malloc(sizeof(Node));
    new->data = val;
    while (curr->next != NULL) {
                
        if (curr->next->data > val) {
            break;
        }
        curr = curr->next; //should stop one before node with node.data > val

    }
    if (curr == NULL) {
        curr = new;
    }
    else {
        temp = curr->next;
        curr->next = new;
        new->next = temp;
    }
}

int main (void) {
    int n;
    printf("How Many Data Nodes? ");
    scanf("%d", &n);
    
    int data[n];
    Node *head = malloc(sizeof(Node*));

    int i;
    for (i = 0; i < n; i++) {
        printf("Enter Data %d: ", i+1);
        scanf("%d",&data[i]);
    }
    head->data = data[0];
    for (i = 1; i < n; i++) {
        addNode(data[i], head);
    }

    int newval;
    printf("Insert Node With What Value? ");
    scanf("%d",&newval);

    insertAtIndex(head,newval);
    if (head == NULL) {
        printf("I'm null bitch\n");
    }
    display(head);
    return 0;
}
