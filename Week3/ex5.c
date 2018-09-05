#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
} node;

typedef struct DoublyLinkedList {
    node* head;
} DoublyLinkedList;


void print_list(DoublyLinkedList list) {
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

void insert_node(DoublyLinkedList* list, int data_of_new_node, node* current_node) {
    if (list->head == NULL) {
        node* new_node = malloc(sizeof(node));
        new_node->data = data_of_new_node;
        new_node->next = NULL;
        new_node->prev = NULL;
        list->head = new_node;
    } else {
        node* new_node = malloc(sizeof(node));
        new_node->data = data_of_new_node;
        new_node->next = current_node->next;
        new_node->prev = current_node;
        if (current_node->next != NULL) {
            current_node->next->prev = new_node;
        }
        current_node->next = new_node;
    }
}

void delete_node(DoublyLinkedList* list, node* current_node) {
    if (list->head != NULL && current_node != NULL) {
        if (list->head == current_node) {
            list->head = list->head->next;
            list->head->prev = NULL;
        } else {
            node* element = list->head;
            while (element->next != current_node) {
                element = element->next;
            }
            node* previous_element = element;
            if (current_node->next != NULL) 
                current_node->next->prev = previous_element;
            previous_element->next = current_node->next;
        }
    }
}


int main() {
    DoublyLinkedList list = {NULL};
    insert_node(&list, 1, list.head);
    insert_node(&list, 2, list.head);
    insert_node(&list, 3, list.head->next);
    delete_node(&list, list.head->next->next->next);
    print_list(list);
    return 0;
}