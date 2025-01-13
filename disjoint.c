#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *rep;
    struct node *next;
    int data;
} *heads[50], *tails[50];

static int countRoot = 0;

void makeSet(int x) {
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->rep = new;   // The representative of a single-element set is itself
    new->next = NULL; // No next element in the set
    new->data = x;

    heads[countRoot] = new;  // Add the new set to the list of heads
    tails[countRoot] = new;  // The tail is the same as the head for a single-element set
    countRoot++;
}

struct node* find(int a) {
    for (int i = 0; i < countRoot; i++) {
        struct node *current = heads[i];
        while (current != NULL) {
            if (current->data == a) {
                return current->rep; // Return the representative of the set
            }
            current = current->next;
        }
    }
    return NULL; // Element not found
}

void unionSets(int a, int b) {
    struct node *rep1 = find(a);
    struct node *rep2 = find(b);

    if (rep1 == NULL || rep2 == NULL) {
        printf("\nOne or both elements not present in the sets.\n");
        return;
    }

    if (rep1 != rep2) {
        for (int i = 0; i < countRoot; i++) {
            if (heads[i] == rep2) { // Merge the set of `b` into the set of `a`
                tails[i]->next = NULL; // Detach the merged set from the list
                for (int j = i; j < countRoot - 1; j++) {
                    heads[j] = heads[j + 1];
                    tails[j] = tails[j + 1];
                }
                countRoot--;
                break;
            }
        }
        for (int i = 0; i < countRoot; i++) {
            if (heads[i] == rep1) {
                tails[i]->next = rep2; // Attach the second set to the first set
                struct node *current = rep2;
                while (current != NULL) {
                    current->rep = rep1; // Update representative of all nodes in the merged set
                    tails[i] = current;
                    current = current->next;
                }
                break;
            }
        }
    }
}

int search(int x) {
    return find(x) != NULL;
}

void displaySetRepresentatives() {
    printf("\nSet Representatives: ");
    for (int i = 0; i < countRoot; i++) {
        printf("%d ", heads[i]->data);
    }
    printf("\n");
}

int main() {
    int choice, x, y;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Make Set\n");
        printf("2. Display Set Representatives\n");
        printf("3. Union\n");
        printf("4. Find Set\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter element to create a set: ");
                scanf("%d", &x);
                if (search(x)) {
                    printf("Element already exists in a set.\n");
                } else {
                    makeSet(x);
                }
                break;
            case 2:
                displaySetRepresentatives();
                break;
            case 3:
                printf("\nEnter the first element: ");
                scanf("%d", &x);
                printf("Enter the second element: ");
                scanf("%d", &y);
                unionSets(x, y);
                break;
            case 4:
                printf("\nEnter the element to find: ");
                scanf("%d", &x);
                struct node *rep = find(x);
                if (rep) {
                    printf("The representative of %d is %d.\n", x, rep->data);
                } else {
                    printf("Element not found in any set.\n");
                }
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
