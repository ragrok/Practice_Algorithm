#include <malloc.h>
#include <stdio.h>

typedef int Type;

//定义节点
typedef struct BSTreeNode{
    //键值
    Type key;
    //指向当节点的左孩子
    struct BSTreeNode *left;
    //指向当前节点的右孩子
    struct BSTreeNode *right;
    //指向当前节点的父节点
    struct BSTreeNode *parents;
}Node, *BSTree;

//创建节点
static Node* create_bstree_node(Type key,Node *parent,Node *left,Node *right){
    Node *p;
    //分配内存
    if((p = (Node *)malloc(sizeof(Node))) == NULL){
        return NULL;
    }
    p -> key = key;
    p -> left = left;
    p -> parents = parent;
    p -> right = right;

    return  p;
}

//前序遍历,递归实现
void preorder_bstree(BSTree tree){
   if (tree != NULL){
       printf("%d",tree -> key);
       preorder_bstree(tree -> left);
       preorder_bstree(tree -> right);
   }
}


//中序遍历，递归实现
void inorder_bstree(BSTree tree){
    if (tree != NULL){
        inorder_bstree(tree -> left);
        printf("%d",tree -> key);
        inorder_bstree(tree -> right);
    }
}

//后续遍历，递归实现
void postorder_bstree(BSTree tree){
     if (tree != NULL){
         postorder_bstree(tree ->left);
         postorder_bstree(tree -> right);
         printf("%d",tree -> key);
     }
}

//递归实现查询
Node* bstree_search(BSTree x,Type key){
     if (x == NULL || x -> key == key){
         return  x;
     }
    if (key < x -> key){
        return bstree_search(x -> left,key);
    } else{
        return bstree_search(x -> right,key);
    }
}

//非递归实现查询
Node* iterative_bstree_search(BSTree x,Type key){
     while ((x != NULL) && (x -> key != key)){
           if (key < x -> key){
               x = x -> left;
           } else{
               x = x -> right;
           }
     }
}

//查找最大值
Node* bstree_maxinum(BSTree tree){
    if (tree == NULL){
        return NULL;
    }
    while (tree -> right != NULL){
        tree = tree -> right;
    }
    return tree;
}

//查找最小值
Node* bstree_minimum(BSTree tree){
    if (tree == NULL){
        return NULL;
    }
    while (tree -> left != NULL){
        tree = tree -> left;
    }
    return  tree;
}

//查找前驱节点
Node* bstree_left_node(Node *x){
    //如果存在左孩子，则"x的前驱节点"为"以其左孩子为根的子数的最大节点”
    if(x -> left != NULL){
        return  bstree_maxinum(x -> left);
    }
    //如果没有x没有左孩子，则x有以下两种可能
    //x是一个右孩子，则x的前驱节点为它的父节点
    //x是一个左孩子，则查找x的最低的父节点，并且该父节点要具有右孩子，
    //找到的这个最低的父节点就是x的前驱几点
    Node* y = x -> parents;
    //父节点不为空，并且判断x为父节点的左孩子
    while ((y != NULL) && (x == y -> left)){
        x = y;
        y = y -> parents;
    }
    return y;
}

//查找后继结点
Node* bstree_right_node(Node *x){
     //如果存在右节点,则x的前驱节点,为其右孩子为根的子数的最小节点
    if (x -> right != NULL){
        return bstree_minimum(x -> right);
    }
    //如果x没有右孩子,则x有以下两种可能
    //x是一个左孩子，则x的后继结点为它的父节点
    //x是一个右孩子，这查找的x的最低的父节点，并且该父节点要有左孩子
    //找到的这个父节点就是x的后继结点
    Node* y = x -> parents;
    //父节点不为空，并且判断x为父节点的右节点
    while ( (y != NULL) && (x == y -> right)){
          x = y;
          y = y -> parents;
    }
    return  y;
}

//插入
static Node* bstree_insert(BSTree tree,Node *z){
     Node *y = NULL;
     Node *x = tree;

    //查找z的插入位置
    while (x != NULL){
        y = x;
        if (z -> key < x -> key){
             x = x -> left;
        } else{
            x = x-> right;
        }
    }

    z -> parents = y;

    if (y == NULL){
       tree = z;
    } else if(z -> key < y -> key){
        y -> left = z;
    } else{
        y -> right = z;
    }
    return  tree;
}


Node* insert_bstree(BSTree tree,Type key){
     Node *z;
    //节点建立失败，则返回
    if((z = create_bstree_node(key, NULL,NULL,NULL)) == NULL){
        return tree;
    }
    return bstree_insert(tree,z);
}

