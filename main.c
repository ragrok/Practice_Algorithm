//
// Created by ragrok on 16-6-23.
//
#include "stdio.h"
#include "./c_header/double_link.h"

void int_test(){
    int iarr[4] = {10,20,30,40};

    printf("\n-----%s--------\n",__func__);
    create_dlink();//创建

    //插入数据
    dlink_insert(0,&iarr[0]);
    dlink_insert(0,&iarr[1]);
    dlink_insert(0,&iarr[2]);

    //判空，判链表的大小
    printf("dlink_is_empty()=%d\n",dlink_is_empty());
    printf("dlink_size()=%d\n",dlink_size());

    //打印全部数据
    int i;
    int *p;
    int sz = dlink_size();
    for (i = 0;i < sz;i++){
        p = (int *)dlink_get(i);
        printf("dlink_get(%d)=%d\n",i,*p);
    }
    destory_dlink();
}


void string_test(){

}