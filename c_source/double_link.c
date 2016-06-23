//
// Created by ragrok on 16-6-23.
//
#include "../c_header/double_link.h"
#include "stdio.h"
#include "malloc.h"


//双向链表节点
typedef struct tag_node{
    struct tag_node *prev;
    struct tag_node *next;
    void* p;
}node;

//表头，注意，表头不存放元素值！！！
static node *phead = NULL;
//节点个数
static int count = 0;

//新建节点，成功，返回节点指针，否则，返回null
static node* create_node(void *pval){

     node *pnode = NULL;
     pnode = (node *)malloc(sizeof(node));
    if (!pnode){
        printf("create node error!\n");
        return NULL;
    }

    //默认的，pnode的前一个节点和后一个节点都指向它自身
    pnode ->prev = pnode ->next = pnode;
    //带节点的值pval
    pnode ->p = pval;

    return pnode;
}

//
