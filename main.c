#include <stdio.h>
#include <stdlib.h>

//chat gpt que fez , estuda um pouco depois ...

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* insert_node(Node* head, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }

    return head;
}

Node* partition(Node* head, int k) {
    Node* smaller_head = NULL;
    Node* equal_head = NULL;
    Node* greater_head = NULL;
    Node* smaller_tail = NULL;
    Node* equal_tail = NULL;
    Node* greater_tail = NULL;

    while (head != NULL) {
        if (head->data < k) {
            if (smaller_head == NULL) {
                smaller_head = head;
                smaller_tail = head;
            } else {
                smaller_tail->next = head;
                smaller_tail = smaller_tail->next;
            }
        } else if (head->data == k) {
            if (equal_head == NULL) {
                equal_head = head;
                equal_tail = head;
            } else {
                equal_tail->next = head;
                equal_tail = equal_tail->next;
            }
        } else {
            if (greater_head == NULL) {
                greater_head = head;
                greater_tail = head;
            } else {
                greater_tail->next = head;
                greater_tail = greater_tail->next;
            }
        }
        head = head->next;
    }

    if (smaller_head != NULL) {
        smaller_tail->next = equal_head;
    }
    if (equal_head != NULL) {
        equal_tail->next = greater_head;
    }

    return smaller_head != NULL ? smaller_head : equal_head != NULL ? equal_head : greater_head;
}

void print_list(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n = 20;
    int numbers[20] = {9, 2, 3, 4, 0, -1, -3, -4, 10, 11, -5, 12, 7, 6, 8, 5, -2, -6, 1, -7};
    Node* head = NULL;

    for (int i = 0; i < n; i++) {
        head = insert_node(head, numbers[i]);
    }

    Node* smaller_head = NULL;
    Node* equal_head = NULL;
    Node* greater_head = NULL;

    Node* current = head;
    while (current != NULL) {
        if (current->data < 0) {
            smaller_head = insert_node(smaller_head, current->data);
        } else if (current->data >= 0 && current->data <= 5) {
            equal_head = insert_node(equal_head, current->data);
        } else {
            greater_head = insert_node(greater_head, current->data);
        }
        current = current->next;
    }

    printf("Smaller numbers: ");
    print_list(smaller_head);
    printf("Equal numbers: ");
    print_list(equal_head);
    printf("Greater_numbers: ");
    print_list(greater_head);
    // Now we can partition the greater list into two sublists
Node* second_greater_head = NULL;
Node* current_greater = greater_head;
int count = 0;

while (current_greater != NULL) {
    if (current_greater->data > 5 && current_greater->data < 10) {
        count++;
        if (count <= 5) {
            equal_head = insert_node(equal_head, current_greater->data);
        } else {
            second_greater_head = insert_node(second_greater_head, current_greater->data);
        }
    } else if (current_greater->data >= 10) {
        second_greater_head = insert_node(second_greater_head, current_greater->data);
    }
    current_greater = current_greater->next;
}

printf("Equal numbers after partition: ");
print_list(equal_head);
printf("Greater numbers (first 5): ");
print_list(greater_head);
printf("Greater numbers (remaining): ");
print_list(second_greater_head);

return 0;
}

