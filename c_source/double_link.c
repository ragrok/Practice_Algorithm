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

//新建链表
int create_dlink(){
    //创建表头
    phead = create_node(NULL);
    if (!phead){
        return -1;
    }
    count = 0;
    return 0;
}

//检查双向链表是否为空
int dlink_is_empty(){
    return count == 0;
}

//返回双向链表的大小
int dlink_size(){
    return count;
}

//获取双向链表中第index位置的节点
static node* dlink_node(int index){
     if(index < 0 || index >= count){
         printf("%s failed! index out of bound \n",__func__);
         return NULL;
     }

    //正向查找
    if(index <= (count/2)){
        int i = 0;
        node *pnode = phead ->next;
        while ((i++) < index){
            pnode = pnode ->next;
        }
        return pnode;
    }

    //反向查找
    int j = 0;
    int rindex = count - index -1;
    node *rnode = phead ->prev;
    while ((j++) < rindex){
        rnode = rnode -> prev;
    }
    return  rnode;
}





