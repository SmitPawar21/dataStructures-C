#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *root;

void insert_element() {
    struct node *newnode, *parent, *temp;
    int new_value;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter the data for new Node: ");
    scanf("%d", &new_value);

    newnode -> data = new_value;
    newnode -> left = NULL;
    newnode -> right = NULL;

    if(root == NULL) {
        root = newnode;
    }
    else{
        temp = root;
        while(temp != NULL) {
            if(newnode -> data >= temp -> data) {
                parent = temp;
                temp = temp -> right;
            }
            else{
                parent = temp;
                temp = temp -> left;
            }
        }
        if(newnode -> data >= parent -> data) {
            parent -> right = newnode;
        }
        else{
            parent -> left = newnode;
        }
    }
}

void inorder(struct node *par) { 
    if(par != NULL) {
        inorder(par -> left);
        printf("%d ", par->data);
        inorder(par -> right);
    }
}

void preorder(struct node *par) {
    if(par != NULL) {
        printf("%d ", par -> data);
        preorder(par -> left);
        preorder(par -> right);
    }
}

void postorder(struct node *par) {
    if(par != NULL) {
        postorder(par -> left);
        postorder(par -> right);
        printf("%d ", par -> data);
    }
}

void delete() {
    struct node *temp, *parent, *pred, *pred_parent;
    int exist_value;

    printf("Enter value to be Deleted: ");
    scanf("%d", &exist_value);

    if(root == NULL) {
        printf("Tree is Empty!\n");
    }
    else {
        temp = root;
        parent = NULL;
        while(temp != NULL && (temp -> data != exist_value)) {
            parent = temp;
            if(exist_value > (temp -> data)) {
                temp = temp -> right;
            }
            else if(exist_value < (temp -> data)) {
                temp = temp -> left;
            }
        }
        if(temp == NULL) {
            printf("Value Not Found!\n");
        }
        else{
            // Condition 1: Deleting leaf node
            if((temp -> left == NULL) && (temp -> right == NULL)) {
                if(temp == root) {
                    root = NULL;
                }
                else if((temp -> data) >= (parent -> data)) {
                    parent -> right = NULL;
                }
                else {
                    parent -> left = NULL;
                }
            }

            // Condition 2: Temp has one child (Left Child)
            else if(temp -> right == NULL) {
                if(temp == root) {
                    root = temp -> left;
                }
                else if(temp -> data >= parent -> data) {
                    parent -> right = temp -> left;
                }
                else {
                    parent -> left = temp -> left;
                }
            }

            // Condition 3: Temp has one child (Right Child)
            else if(temp -> left == NULL) {
                if(temp == root) {
                    root = temp -> right;
                }
                else if(temp -> data >= parent -> data) {
                    parent -> right = temp -> right;
                }
                else {
                    parent -> left = temp -> right;
                }
            }

            // Condition 4: Temp has Two children
            else {
                pred_parent = temp;
                pred = temp -> left;

                while(pred -> right != NULL) {
                    pred_parent = pred;
                    pred = pred -> right;
                }
                temp -> data = pred -> data;
                pred_parent -> right = pred -> left;
            }
        }
    }
}

void main() {
    int exit = 0;   // Exit is False
    int choice;

    while(exit == 0) {
        printf("\n*********************************\n");
        printf("Enter 1 for Insert node in a tree\n");
        printf("Enter 2 for Inorder Traversal\n");
        printf("Enter 3 for Preorder Traversal\n");
        printf("Enter 4 for Postorder Traversal\n");
        printf("Enter 5 for Delete a node\n");
        printf("Enter 0 for Exit Application\n");
        printf("\n*********************************\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1: insert_element();
                    break;
            case 2: printf("Inorder traversal: ");
                    inorder(root);
                    break;
            case 3: printf("preorder traversal: ");
                    preorder(root);
                    break;
            case 4: printf("postorder traversal: ");
                    postorder(root);
                    break;
            case 5: delete();
                    break;
            case 0: exit = 1;   // Exit is True
                    break;
            default: printf("Kindly enter a valid choice\n");
        }
    }
}