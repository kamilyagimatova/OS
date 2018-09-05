#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

typedef struct LinkedList {
    node* head;
} LinkedList;


void print_list(LinkedList list) {
    if (list.head == NULL) {
        printf("List doesn't have elements");
    } else {
        node* element = list.head;
        while (element != NULL) {
            printf("%d ", element->data);
            element = element->next;
        }
    }
}

void insert_node(LinkedList* list, int data_of_new_node, node* current_node) {
    if (list->head == NULL) {
        node* new_node = malloc(sizeof(node));
        new_node->data = data_of_new_node;
        new_node->next = NULL;
        list->head = new_node;
    } else {
        node* new_node = malloc(sizeof(node));
        new_node->data = data_of_new_node;
        new_node->next = current_node->next;
        current_node->next = new_node;
    }
}

void delete_node(LinkedList* list, node* current_node) {
    if (list->head != NULL && current_node != NULL) {
        if (list->head == current_node) {
            list->head = list->head->next;
        } else {
            node* element = list->head;
            while (element->next != current_node) {
                element = element->next;
            }
            node* previous_element = element;
            previous_element->next = current_node->next;
        }
    }
}


int main() {
    LinkedList list = {NULL};
    insert_node(&list, 1, list.head);
    insert_node(&list, 2, list.head);
    insert_node(&list, 3, list.head->next);
    print_list(list);
    return 0;
}