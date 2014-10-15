#include<stdio.h>
#include<stdlib.h>
typedef struct treeNode
{
    int data;
    struct treeNode *left;
    struct treeNode *right;
}treeNode;

treeNode *Insert(treeNode *node, int data)
{
    // root
    if(node==NULL)
    {
        node = (treeNode *)malloc(sizeof(treeNode));
        node->data = data;
        node->left = node->right = NULL;
        return node;
    }
    // right big
    if(data > (node->data))
    {
        node->right = Insert(node->right,data);
    }
    // left small
    else if(data < (node->data))
    {
        node->left = Insert(node->left,data);
    }
    return node;
}

treeNode *Find(treeNode *node, int data)
{
    if(node==NULL)
        return NULL;
    if(data > node->data)
        return Find(node->right,data);
    else if(data < node->data)
        return Find(node->left,data);
    else
        return node;
}

treeNode *Max(treeNode *node)
{
    if(node==NULL)
        return NULL;
    if(node->right)
        Max(node->right);
    else
        return node;
}

/* delete */
treeNode *Delete(treeNode *node, int data)
{
    if(node==NULL)
        return node;
    else if(data < node->data)
        node->left = Delete(node->left,data);
    else if(data > node->data) 
        node->right = Delete(node->right,data);
    //get it
    else
    {
        // node has 2 child
        if(node->left&&node->right)
        {
            node->data = Max(node->left)->data;
            //or node->data = Min(node->right)->data;
            node->left = Delete(node->left,node->data); // down condiction
        }
        else
        {
            if(node->left==NULL)
                node = node->right;
            else if(node->right=NULL)
                node = node->left;
            free(node);
        }
    }
    return node;
}

/* traversal */
void Pre_order(treeNode *node) //root left right
{
    if(node==NULL)
        return;
    printf("%d ",node->data);
    Pre_order(node->left);
    Pre_order(node->right);
}

void In_order(treeNode *node) //root left right
{
    if(node==NULL)
        return;
    In_order(node->left);
    printf("%d ",node->data);
    In_order(node->right);
}

void Post_order(treeNode *node) //root left right
{
    if(node==NULL)
        return;
    Post_order(node->left);
    Post_order(node->right);
    printf("%d ",node->data);
}

int main(int argc, char **argv)
{
    treeNode *root = NULL;
    root = Insert(root, 5);
    root = Insert(root, 6);
    root = Insert(root, 7);
    root = Insert(root, 8);
    root = Insert(root, 3);
    root = Insert(root, 1);
    root = Insert(root, 100);
    printf("%d\n",Find(root,7)->data);
    printf("%d\n",Max(root)->data);
    root = Delete(root, 100);
    Pre_order(root);printf("\n");
    In_order(root);printf("\n");
    Post_order(root);printf("\n");
    return 0;
}
