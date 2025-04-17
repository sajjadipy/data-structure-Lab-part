#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list {
    float value;
    struct linked_list *next;
} node;

int main() {
    node *first, *second, *third, *fourth;

    first = (node*)malloc(sizeof(node));
    second = (node*)malloc(sizeof(node));
    third = (node*)malloc(sizeof(node));
    fourth = (node*)malloc(sizeof(node));

    first->value = 10.5;
    first->next = second;

    printf("Enter Your SGPA: ");
    float sgpa;
    scanf("%f", &sgpa);

    float XX = sgpa + 3.21;

    second->value = XX;
    second->next = third;

    third->value = 15.7;
    third->next = fourth;

    fourth->value = 34.3;
    fourth->next = NULL;

    node *i = first;
    printf("Original Linked List: ");
    while (i != NULL) {
        printf("%.1f ", i->value);
        i = i->next;
    }

    i = first;
    node *temp = NULL;
    while (i != NULL) {
        if (i->value == XX) {
            if (temp != NULL) {
                temp->next = i->next;
                free(i);
                break;
            }
        }
        temp = i;
        i = i->next;
    }

    i = first;
    printf("\nUpdated Linked List: ");
    while (i != NULL) {
        printf("%.1f ", i->value);
        i = i->next;
    }

    return 0;
}
