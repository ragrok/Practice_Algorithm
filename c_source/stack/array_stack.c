//
// Created by deepin-linux on 16-6-29.
//
#include "stdio.h"
#include "malloc.h"

/*
 * c语言实现的栈，只能存储int类型的数据
 * */

//保存数据的数组
static int *arr = NULL;
//栈的实际大小
static int count;

//创建栈，默认大小是2
int create_array_stack(int sz){
    //申请内存空间
    arr = (int *)malloc(sz* sizeof(int));
    if(!arr){
      printf("arr malloc error!");
        return -1;
    }
    return 0;
}

//销毁栈
int destrory_array_stack(){
    if (arr){
        //释放内存空间
        free(arr);
        arr = NULL;
    }
    return 0;
}

//将val添加到栈中
void push(int val){
    arr[count++] = val;
}

//返回栈顶元素值
int peek(){
    return arr[count - 1];
}

//返回栈顶元素值，并删除栈顶元素
int pop(){
    int ret = arr[count - 1];
    count--;
    return ret;
}

//返回栈的大小
int size(){
    return count;
}

//返回栈是否为空
int is_empty(){
    return size() == 0;
}

//打印栈
void print_array_stack(){
    if(is_empty()){
      printf("stack is empty\n");
        return;
    }

    printf("stack size()=%d\n",size());

    int i = size() - 1;
    while (i >= 0){
        printf("%d\n",arr[i]);
        i--;
    }
}

/*void main(){
    int tmp = 0;
    //创建栈
    create_array_stack(12);
    push(10);
    push(20);
    push(30);

    print_array_stack();
    //将栈顶元素赋值给tmp，并删除栈顶元素
    tmp = pop();
    printf("tmp=%d\n",tmp);
    print_array_stack();
    //只将栈顶元素复制给tmp，不删除元素
    tmp = peek();
    printf("tmp=%d\n",tmp);
    print_array_stack();

    push(40);
    print_array_stack();
    //销毁栈
    destrory_array_stack();
}*/

