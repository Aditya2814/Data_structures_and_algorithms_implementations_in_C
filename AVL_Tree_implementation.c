#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    int height;
};

int max(int a, int b){
    return (a>b)?a:b;
}

int getHeight(struct Node* n){
    if(n == NULL){
        return 0;
    }
    return n->height;
}

struct Node* getNewNode(int x){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

int getBalanceFactor(struct Node* n){
    if(n == NULL){
        return 0;
    }
    return getHeight(n->left) - getHeight(n->right);
}

struct Node* rightRotate(struct Node* y){ // y is the root node.
    struct Node* x = y->left;
    struct Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;

    return x;
}

struct Node* leftRotate(struct Node* x){ // x is the root node.
    struct Node* y = x->right;
    struct Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;

    return y;
}
 
struct Node* Insert(struct Node* node, int x){
    if(node == NULL){
        return getNewNode(x);
    }
    
    if(x < node->data){
        node->left = Insert(node->left, x);
    }
    else{
        node->right = Insert(node->right, x);
    }

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int bf = getBalanceFactor(node);

    // left left case
    if(bf > 1 && x < node->left->data){
        return rightRotate(node);
    }

    // right right case
    if(bf < -1 && x > node->right->data){
        return leftRotate(node);
    }

    // left right case
    if(bf > 1 && x > node->left->data){
        node->left = leftRotate(node->left); // left rotate w.r.t the first child of unbalanced node along the path.
        return rightRotate(node);
    }

    // right left case
    if(bf < -1 && x < node->right->data){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void preOrder(struct Node* root){
    if(root == NULL){
        return;
    }
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

int main(int argc, char const *argv[])
{
    struct Node* root = NULL;
    root = Insert(root, 1);
    root = Insert(root, 2);
    root = Insert(root, 4);
    root = Insert(root, 5);
    root = Insert(root, 6);
    root = Insert(root, 3);

    preOrder(root);

    return 0;
}
