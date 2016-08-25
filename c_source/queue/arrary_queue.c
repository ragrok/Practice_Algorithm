//
// Created by deepin-linux on 16-6-30.
//

#include "stdio.h"
#include "malloc.h"

/*
 * c语言：数组实现的队列，只能存储int数据
 * */

//保存数据的数组
static int *arr = NULL;
//队列的实际大小
static int count;

//创建队列
int create_array_queue(int sz){

    arr = (int *)malloc(sz*sizeof(int));
    if (!arr){
       printf("arr malloc error");
        return -1;
    }
    count = 0;
    return 0;
}

//销毁队列
int destory_array_queue(){
    if (arr){
        free(arr);
        arr = NULL;
    }
    return 0;
}

//将val添加到队列的末尾
void add(int val){
    arr[count++] = val;
}

//返回队列开头元素
int front(){
    return arr[0];
}


//返回并删除队列开头元素
int queue_pop(){
    int i = 0;
    int ret = arr[0];

    count -- ;
    while (i++ < count){
        //整体前移一位
        arr[i-1] = arr[i];
    }
    return ret;
}

//返回队列的大小
int queue_size(){
    return count;
}


//返回队列是否为空
int queue_is_empty(){
    return  count == 0;
}

void main(){
    int tmp = 0;
    //创建队列
    create_array_queue(12);
    //插入数据
    add(10);
    add(20);
    add(30);
    add(40);
    add(50);

    //将队列开头的元素赋值给tmp，并删除该元素
    tmp = queue_pop();
    printf("tmp=%d\n",tmp);

    //只将队列开头的元素赋值给tmp，不删除钙元素
    tmp = front();
    printf("tmp=%d\n",tmp);

    add(60);

    //打印队列
    printf("is_empty()= %d\n",queue_is_empty());
    printf("size()=%d\n",queue_size());
    //循环删除队列里的元素
    while (!queue_is_empty()){
         printf("%d\n",queue_pop());
    }
    //销毁队列
    destory_array_queue();
}

