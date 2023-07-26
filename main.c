#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the node structure for the queue
struct Node {
    char *data;
    struct Node *next;
};

// Function to create a new node for the queue
struct Node* createNode(char* line) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode) {
        newNode->data = strdup(line);
        newNode->next = NULL;
    }
    return newNode;
}

// Function to enqueue a new line into the queue
void enqueue(struct Node** front, struct Node** rear, char* line, int n) {
    struct Node* newNode = createNode(line);
    if (!newNode) {
        fprintf(stderr, "Memory allocation error!\n");
        exit(EXIT_FAILURE);
    }

    if (*front == NULL) {
        *front = *rear = newNode;
    } else {
        (*rear)->next = newNode;
        *rear = newNode;
    }

    // If the queue size exceeds n, dequeue the oldest line
    if (n > 0) {
        struct Node* temp = *front;
        *front = (*front)->next;
        free(temp->data);
        free(temp);
    }
}

// Function to print the contents of the queue
void printQueue(struct Node* front) {
    while (front != NULL) {
        printf("%s", front->data);
        front = front->next;
    }
}

// Function to free the memory allocated for the queue
void freeQueue(struct Node* front) {
    while (front != NULL) {
        struct Node* temp = front;
        front = front->next;
        free(temp->data);
        free(temp);
    }
}

int main(int argc, char* argv[]) {
    // Check if the correct number of arguments is provided
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <n>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int n = atoi(argv[1]);

    if (n <= 0) {
        fprintf(stderr, "Please provide a positive integer value for n.\n");
        return EXIT_FAILURE;
    }

    struct Node* front = NULL;
    struct Node* rear = NULL;
    char line[256];

    // Read lines from standard input until EOF
    while (fgets(line, sizeof(line), stdin) != NULL) {
        enqueue(&front, &rear, line, n);
    }

    // Print the last n lines from the queue
    printQueue(front);

    // Free the memory allocated for the queue
    freeQueue(front);

    return EXIT_SUCCESS;
}
