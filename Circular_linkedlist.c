#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL; 
void create(); 
void traverse(); 
void insert_beg(); 
void insert_end(); 
void delete_beg(); 
void delete_end(); 

int main() {
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Create List\n");
        printf("2. Traverse List\n");
        printf("3. Insert at Beginning\n");
        printf("4. Insert at End\n");
        printf("5. Delete from Beginning\n");
        printf("6. Delete from End\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create();
                printf("List created successfully.\n");
                break;
            case 2:
                printf("Current list: ");
                traverse();
                break;
            case 3:
                insert_beg();
                printf("List after insertion at beginning: ");
                traverse();
                break;
            case 4:
                insert_end();
                printf("List after insertion at end: ");
                traverse();
                break;
            case 5:
                delete_beg();
                printf("List after deletion from beginning: ");
                traverse();
                break;
            case 6:
                delete_end();
                printf("List after deletion from end: ");
                traverse();
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}

void create() {
    struct Node *p;
    p = (struct Node *)malloc(sizeof(struct Node));
    
    printf("Enter the data of the first node: ");
    scanf("%d", &p->data);
    head = p;
    p->next = head;

    char ch;
    do {
        struct Node *q = (struct Node *)malloc(sizeof(struct Node));
        
        printf("Enter the data of next node: ");
        scanf("%d", &q->data);
        p->next = q; 
        q->next = head; 
        p = q; 
        
        printf("Press 'y' to continue or any other key to stop: ");
        getchar(); 
        ch = getchar(); 
    } while (ch == 'y');
}

void traverse() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node *p = head;
    do {
        printf("%d -> ", p->data);
        p = p->next;
    } while (p != head);
    printf("(head)\n");
}

void insert_beg() {
    int value;
    struct Node *q = (struct Node *)malloc(sizeof(struct Node));
    if (q == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter the value for the new node: ");
    scanf("%d", &value);
    q->data = value;

    if (head == NULL) {
        head = q;
        q->next = head; 
    } else {
        struct Node *p = head;
        while (p->next != head) {
            p = p->next; 
        }
        p->next = q; 
        q->next = head; 
        head = q; 
    }
}

void insert_end() {
    int value;
    struct Node *q = (struct Node *)malloc(sizeof(struct Node));
    if (q == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter the value for the new node: ");
    scanf("%d", &value);
    q->data = value;

    if (head == NULL) {
        head = q;
        q->next = head; 
    } else {
        struct Node *p = head;
        while (p->next != head) {
            p = p->next; 
        }
        p->next = q; 
        q->next = head; 
    }
}

void delete_beg() {
    if (head == NULL) {
        printf("The list is empty. Nothing to delete.\n");
        return;
    }

    struct Node *q = head;
    if (head->next == head) { 
        free(head);
        head = NULL;
    } else {
        struct Node *p = head;
        while (p->next != head) {
            p = p->next; 
        }
        p->next = head->next; 
        free(head);
        head = p->next; 
    }
}

void delete_end() {
    if (head == NULL) {
        printf("The list is empty. Nothing to delete.\n");
        return;
    }

    if (head->next == head) { 
        free(head);
        head = NULL;
        return;
    }

    struct Node *p = head;
    struct Node *q = NULL;

    while (p->next != head) {
        q = p;
        p = p->next;
    }
    q->next = head;
    free(p);
}


                
   