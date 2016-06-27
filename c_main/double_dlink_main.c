//
// Created by ragrok on 16-6-23.
//
#include "stdio.h"
#include "../c_header/double_link.h"

void int_test(){
    int iarr[4] = {10,20,30,40};

    printf("\n-----%s--------\n",__func__);
    create_dlink();//创建

    //插入数据
    dlink_insert(0,&iarr[0]);
    dlink_insert(0,&iarr[1]);
    dlink_insert(0,&iarr[2]);
    dlink_insert(0,&iarr[3]);

    //判空，判链表的大小
    printf("dlink_is_empty()=%d\n",dlink_is_empty());
    printf("dlink_size()=%d\n",dlink_size());

    //打印全部数据
    int i;
    int *p;
    int sz = dlink_size();
    for (i = 0;i < sz;i++){
        p = (int *)dlink_get(i);
        //这里是输出*P
        printf("dlink_get(%d)=%d\n",i,*p);
    }
    destory_dlink();
}


void string_test(){

    char* sarr[4] = {"ten","base","five","forty"};
    printf("\n----%s----\n",__func__);
    create_dlink();

    dlink_insert(0,sarr[0]);
    dlink_insert(0,sarr[1]);
    dlink_insert(0,sarr[2]);
    dlink_insert(0,sarr[3]);

    //判空，判链表的大小
    printf("dlink_is_empty()=%d\n",dlink_is_empty());
    printf("dlink_size()=%d\n",dlink_size());

    //打印全部数据
    int i;
    int *p;
    int sz = dlink_size();
    for (i = 0;i < sz;i++){
        p = (char *)dlink_get(i);
        //这里是输出P
        printf("dlink_get(%d)=%s\n",i,p);
    }
    destory_dlink();
}

typedef struct tag_stu{
    int id;
    char name[20];
}stu;

static stu arr_stu[] ={
        {10,"sky"},
        {20,"sky1"},
        {30,"sky2"},
        {40,"sky3"},
        {50,"sky4"},
};

#define ARR_STU_SIZE ((sizeof(arr_stu)) / (sizeof(arr_stu[0])))

void object_test(){
    printf("\n-----%s----\n",__func__);
    create_dlink();

    dlink_insert(0,&arr_stu[0]);
    dlink_insert(0,&arr_stu[1]);
    dlink_insert(0,&arr_stu[2]);
    dlink_insert(0,&arr_stu[3]);
    dlink_insert(0,&arr_stu[4]);

    //判空，判链表的大小
    printf("dlink_is_empty()=%d\n",dlink_is_empty());
    printf("dlink_size()=%d\n",dlink_size());

    //打印全部数据
    int i;
    stu *p;
    int sz = dlink_size();
    for (i = 0;i < sz;i++){
        p = (stu *)dlink_get(i);
        //这里是输出P
        printf("dlink_get(%d)=[%d,%s]\n",i,p ->id,p ->name);
    }
    destory_dlink();
}
int main(){
//    int_test();
//    string_test();
//    object_test();

    return 0;
}