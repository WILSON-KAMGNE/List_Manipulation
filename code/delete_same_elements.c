#include<stdio.h>
#include<stdlib.h>

// definition of the list struct
typedef struct list {
    int data;
    struct list *next;
}list;

//definition of the type bool
typedef enum bool {
    FALSE,
    TRUE
}bool;

//function to init list
void init_list(list *list){
    list = NULL;
}

//function to check if the list is empty
bool is_empty(list list){
    return NULL?TRUE:FALSE;
}

// function to add an element on the top of the list

list* front_add(list *head, int data) {
    list *new_elem = malloc(sizeof(list));
    if(new_elem == NULL) {
        printf("Erreur allocation dynamique\n");
        return NULL;
    }
    new_elem->data = data;
    new_elem->next = head;
    return new_elem;
}


// function to print element of the list

void print(list *head) {
    list *temp = head;
    while(temp != NULL) {
        printf("[%d]->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

//function for deleting a data value from the list

list* dell(list *head, int data) {
    // Handle case: head itself needs deletion
    while (head != NULL && head->data == data) {
        list *tmp = head;
        head = head->next;
        free(tmp);
    }

    list *current = head;
    while (current != NULL && current->next != NULL) {
        if (current->next->data == data) {
            list *tmp = current->next;
            current->next = current->next->next;
            free(tmp);
        } else {
            current = current->next;
        }
    }
    return head;
}


//function to free list

void free_list(list *head) {
    list *current = head;
    list *next;

    while (current != NULL) {
        next = current->next;     // save next node
        printf("[%d] freed successfully!\n", current->data);
        free(current);            // release memory
        current = next;           // move forward
    }

    printf("All memory freed successfully.\n");
}





int main() {
    list *list = NULL;   // initialize list
    int choice, data;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Add element to front\n");
        printf("2. Delete element by value\n");
        printf("3. Print list\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to add: ");
                scanf("%d", &data);
                list = front_add(list, data);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &data);
                list = dell(list, data); // update head
                break;

            case 3:
                print(list);
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    free_list(list);
    return 0;
}



