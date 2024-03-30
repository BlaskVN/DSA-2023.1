#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int id; // identifier of the node
    struct Node* leftChild;// pointer to the left child
    struct Node* rightChild;// pointer to the right child
}Node;

Node* root=NULL;

Node* makeNode(int id){
    Node* p = (Node*)malloc(sizeof(Node));
    p->id = id;
    p->leftChild = NULL; p->rightChild = NULL;
    return p;
}

Node* find(Node* r, int id){
    if(r == NULL) return NULL;
    if(r->id == id) return r;
    Node* p = find(r->leftChild,id);
    if(p != NULL) return p;
    return find(r->rightChild,id);
}

void addLeftChild(int u, int left){
    Node* pu = find(root,u);
    if(pu == NULL){
        //printf("Not found %d\n",u); 
        return;
    }
    if(pu->leftChild != NULL){
        //printf("Node %d has already leftChild\n",u); 
        return;
    }
    pu->leftChild = makeNode(left);
}

void addRightChild(int u, int right){
    Node* pu = find(root,u);
    if(pu == NULL){
        //printf("Not found %d\n",u); 
        return;
    } 
    if(pu->rightChild != NULL){
        //printf("Node %d has already rightChild\n",u); 
        return;
    }
    pu->rightChild = makeNode(right);
}

void PreOrder (Node* n){
    if(n == NULL) return;
    printf("%d ", n->id);
    PreOrder(n->leftChild);
    PreOrder(n->rightChild);
}

void InOrder (Node* n){
    if(n == NULL) return;
    InOrder(n->leftChild);
    printf("%d ", n->id);
    InOrder(n->rightChild);
}

void PostOrder (Node* n){
    if(n == NULL) return;
    PostOrder(n->leftChild);
    PostOrder(n->rightChild);
    printf("%d ", n->id);
}

int main(int argc, char const *argv[])
{
    char command[10];
    int id1,id2;
    while (1)
    {
        scanf("%s",command);
        if (strcmp(command,"MakeRoot") == 0)
        {
            scanf(" %d",&id1);
            root = makeNode(id1);
        } else if (strcmp(command,"AddLeft") == 0)
        {
            scanf("%d %d",&id1,&id2);
            addLeftChild(id2,id1);
        } else if (strcmp(command,"AddRight") == 0)
        {
            scanf("%d %d",&id1,&id2);
            addRightChild(id2,id1);
        } else if (strcmp(command,"PreOrder") == 0)
        {
            PreOrder(root);
            printf("\n");
        } else if (strcmp(command,"InOrder") == 0)
        {
            InOrder(root);
            printf("\n");
        } else if (strcmp(command,"PostOrder") == 0)
        {
            PostOrder(root);
            printf("\n");
        } else break;
    }
    return 0;
}
