#include <stdio.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root;

//  returns total number of nodes in Tree
int countNodes(struct node *temp) {
    if(temp == NULL) {
        return 0;
    }

    return (countNodes(temp -> left) + countNodes(temp -> right) + 1);
}

//  Internal nodes
int internalNodes(struct node *temp) {
    if(temp != NULL) {
        if((temp -> left != NULL || (temp -> right) != NULL)) {
            return (internalNodes(temp -> left) + internalNodes(temp -> right) + 1);
        }
        else{
            return 0;
        }
    }
    return 0;
}

//  External nodes
int externalNodes(struct node *temp) {
    return (countNodes(root) - internalNodes(root));
}

void main() {
    
    //  Assume that Tree is already created

    int total_nodes = countNodes(root);
    int internal_nodes = internalNodes(root);
    int external_nodes = externalNodes(root);

    printf("Total: %d", total_nodes);
    printf("Internal: %d", internal_nodes);
    printf("External: %d", external_nodes);
}