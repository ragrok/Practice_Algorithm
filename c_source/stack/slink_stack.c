//
// Created by deepin-linux on 16-6-29.
//
#include "stdio.h"
#include "malloc.h"

/*
 * 单向链表实现的栈,只能存储int数据
 * */

//单向链表的节点
struct node{
    int val;
    struct node* next;
};

//单向链表的表头
static struct node *phead = NULL;
//创建节点，val为节点值
static struct node* create_node(int val){

    struct node *pnode = NULL;
    //分配内存空间
    pnode = (struct node*)malloc(sizeof(struct node));
    if(!pnode){
        return  NULL;
    }
    pnode -> val = val;
    pnode -> next = NULL;
    //返回创建成功的节点
    return pnode;
}

//销毁单向链表
static int destory_single_link(){

    struct node *pnode = NULL;
    while (phead != NULL){
          pnode = phead;
          phead = phead -> next;
        free(pnode);
    }
    return 0;
}

//将val插入到链表的表头位置
static struct node* push(int val){
   struct node *pnode = NULL;

    pnode = create_node(val);
    pnode -> next = phead;
    phead = pnode;
    return phead;
}

//删除链表的表头
static int pop(){
    if(!phead){
        printf("remove failed! link is empty");
        return -1;
    }

    int ret;
    struct node *pnode;
    //得到头结点的值
    ret = phead -> val;
    //将头结点赋给新建的节点
    pnode = phead;
    //头节点的下一个节点覆盖原来的头节点，形成新的头节点
    phead = phead -> next;
    //释放原头节点的内存
    free(pnode);

    return  ret;
}

//返回链表的表头节点的值
static int peek(){
    if (!phead){
        printf("peek failed! link is empty");
        return -1;
    }
    return phead -> val;
}

//返回链表的个数
static int size(){

    int count = 0;
    struct node *pnode = phead;

    while (pnode != NULL){
        //移动到下一位
        pnode = pnode -> next;
        count++;
    }
    return count;
}

//链表是否为空
static int is_empty(){
    return phead == NULL;
}

//打印栈
static void print_single_link(){

    if (is_empty()){
        printf("stack is empty\n");
        return;
    }

    printf("stack size()=%d\n",size());
    struct node *pnode = NULL;
    //将表头赋给另一个指针，不破坏数据
    pnode = phead;

    while (pnode != NULL){
        //打印当前指针指向地址的数据
        printf("valueis %d\n",pnode -> val);
        //移动到下一个节点
        pnode = pnode -> next;
    }
    //运行完，释放空间
    free(pnode);
}

//void main(){
//    int tmp = 0;
//    //将10，20,30一次推入栈中
//    push(10);
//    push(20);
//    push(30);
//
//    print_single_link();
//    //将栈顶元素赋值给tmp，删除该元素
//    tmp = pop();
//    printf("tmp=%d\n",tmp);
//    print_single_link();
//
//    //只将栈顶赋值给tmp，不删除元素
//    tmp = peek();
//    printf("tmp=%d\n",tmp);
//    push(40);
//    print_single_link();
//
//    //destory
//    destory_single_link();
//}