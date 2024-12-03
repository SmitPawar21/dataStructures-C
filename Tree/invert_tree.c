#include <stdio.h>

struct node{
    int data;
    struct node *left;
    struct node * right;
};

struct node *root;

struct node *invert_tree(struct node *temp) {
    struct node *p;

    if(temp != NULL) {
        invert_tree(temp -> left);
        invert_tree(temp -> right);

        p = temp -> left;
        temp -> left = temp -> right;
        temp -> right = p;
    }
    return temp;
}

void main() {

    //  Assume Tree is already created
    struct node *inverted_newnode = invert_tree(root);

    //  We can write a display function to print this Tree (if we want)
}