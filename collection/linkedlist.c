#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

enum {INVALID_INDEX = -1};

typedef struct node node_t;

typedef struct node {
    int data;
    node_t *next;
} node_t;

node_t *s_head;

void print_linkedlist() {
    const node_t *n = s_head;

    while (n != NULL) {
        printf("%d\n ->", n->data);
        n = n->next;
    }
}

void destoryed() {
    const node_t* n = s_head;

    while (n != NULL) {
        const node_t* next = n->next;
        free((void*)n);
        n = next;
    }
}

void insert_node(node_t **p_head, const int data) {
    node_t *new_node;

    new_node = malloc(sizeof(node_t));
    new_node->data = data;

    new_node->next = *p_head;
    *p_head = new_node;
}

void insert_dsc_node(node_t** p_head, const int data) {
    const node_t** pp;

    node_t* new_node = malloc(sizeof(node_t));
    new_node->data = data;

    pp = p_head;
    while (*pp != NULL) {
        if ((*pp)->data >= data) {
            break;
        }
        pp = &(*pp)-> next;
    }

    new_node->next = *pp;
    *pp = new_node;
}

void delete_last_node(const node_t** p_head) {
    node_t** pp = p_head;
    node_t* next = (*pp)->next;
    free(*pp);
    *pp = next;
}

bool is_contains(const node_t* const head, int data) {
    const node_t* n = head;
    while (n != NULL) {
        if (n->data == data) {
            return true;
        }
        n = head->next;
    }
    return INVALID_INDEX;
}

int delete_index_of_data(const node_t** p_head, int data) {
    node_t** pp;
    pp = p_head;
    int result;

    while (*pp!= NULL) {
        if ((*pp)->data == data) {
            node_t* tmp = *pp;
            *pp = tmp->next;
            result = tmp->data;
            free(tmp);
            return result;
        }
        pp = &(*pp)->next;
    }


    return INVALID_INDEX;
}

int main(void) {

    insert_dsc_node(&s_head,2);
    insert_dsc_node(&s_head,5);
    insert_dsc_node(&s_head,3);
    print_linkedlist();
    delete_last_node(&s_head);
    puts("");
    print_linkedlist();
    printf("\n==%d==\n", is_contains(s_head,5));
    insert_dsc_node(&s_head,2);
    insert_dsc_node(&s_head,7);
    print_linkedlist();
    printf("\n==%d==\n", delete_index_of_data(&s_head, 5));
    puts("");
    print_linkedlist();

    destoryed();
}
