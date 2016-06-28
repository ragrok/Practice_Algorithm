//
// Created by ragrok on 16-6-23.
//
#include "../c_header/double_link.h"
#include "stdio.h"
#include "malloc.h"


//双向链表节点
typedef struct tag_node{
    //指向自身的前驱节点
    struct tag_node *prev;
    //指向自身的后继节点
    struct tag_node *next;
    //一个无值型的指针
    void* p;
}node;

//表头，注意，表头不存放元素值！！！
static node *phead = NULL;
//节点个数
static int count = 0;

//新建节点，成功，返回节点指针，否则，返回null
static node* create_node(void *pval){

     node *pnode = NULL;
    //向系统申请分配内存空间，sizeof计算节点大小，默认为null
    //(node *)转换为node类型
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
static node* get_node(int index){
      //判定是否越界
     if(index < 0 || index >= count){
         printf("%s failed! index out of bound \n",__func__);
         return NULL;
     }

    //正向查找，通过后继节点查找。
    if(index <= (count/2)){
        int i = 0;
        //拿到双向表的后继节点
        node *pnode = phead ->next;
        //循环，拿到第index个后继节点
        while ((i++) < index){
            pnode = pnode ->next;
        }
        return pnode;
    }

    //反向查找，通过前驱节点查找。
    if(index > (count/2)) {
        int j = 0;
        //查找的次数，总数减去查找位置再减去1(从0开始算)。
        int rindex = count - index - 1;
        //得到双向表的前驱节点
        node *rnode = phead->prev;
        //循环到rindex位置
        while ((j++) < rindex) {
            rnode = rnode->prev;
        }
        return rnode;
    }
}

//获取第一个节点
static node* get_first_node(){
    return get_node(0);
}

//获取最后一个节点
static node* get_last_node(){
    return get_node(count-1);
}

//获取双向链表中第index的位置的元素，成功，返回节点值，否则，返回-1
void* dlink_get(int index){
    node *pindex = get_node(index);
    if(!pindex){
        printf("%s failed \n",__func__);
        return NULL;
    }
    //p指针指向index位置的元素
    return pindex -> p;

}


//获取双链表中第一个元素的值
void* dlink_get_first(){
    return dlink_get(0);
}

//获取双链表中最后一个元素的值
void* dlink_get_last(){
    return dlink_get(count -1);
}

//将pval插入到index位置，成功，返回0，否则，返回-1
int dlink_insert(int index,void *pval){
     //插入表头
    if (index == 0){
        return dlink_insert_first(pval);
    }
    //获取要插入位置的对应节点
    node *pindex = get_node(index);
    if (!pindex){
        return -1;
    }
    //创建节点
    node *pnode = create_node(pval);
    if (!pnode){
        return -1;
    }
    //插入节点的前节点覆盖原先节点的前节点
    pnode ->prev = pindex ->prev;
    //插入节点的后节点指向原节点
    pnode ->next = pindex;
    //原节点的前节点的后继节点指向插入节点
    //(原节点前驱节点的后继节点还是指向原节点，没有断)
    pindex -> prev -> next = pnode;
    //原节点的前节点指向插入节点
    pindex -> prev = pnode;
    //节点数+1
    count++;

    return 0;
}

//将pval插入表头位置
int dlink_insert_first(void *pval){
    node *pnode = create_node(pval);
    if (!pnode){
        return -1;
    }

    //新建节点的前节点指向表头
    pnode -> prev = phead;
    //新建节点的下一个节点覆盖表头的后节点
    pnode -> next = phead -> next;
    //表头的后节点的前节点指向新建节点（还是没断）
    phead -> next -> prev = pnode;
    //表头的下一个节点指向新建节点
    phead -> next = pnode;
    count ++;
    return 0;
}

//将pval插入末尾的位置
int dlink_append_last(void *pval){
    node *pnode = create_node(pval);
    if(!pnode){
        return -1;
    }
    //新建节点的下一个节点指向头节点
    pnode -> next = phead;
    //新建节点的前驱节点覆盖头节点的前节点
    pnode -> prev = phead -> prev;
    //头节点的前节点的后继节点指向新建节点（这个后继节点还没被覆盖）
    phead -> prev -> next = pnode;
    //头节点的前节点指向新建节点
    phead -> prev = pnode;
    count++;
    return 0;
}

//删除双链表中index位置的节点,成功，返回0，否则，返回-1
int dlink_delete(int index){
    node *pindex = get_node(index);
    if (pindex){
        printf("%s failed! the index of out of bound \n",__func__);
        return -1;
    }
    //删除节点的后一个节点的前驱节点覆盖该删除节点的前驱节点
    pindex -> next -> prev = pindex -> prev;
    //删除节点的前节点的后继节点覆盖该删除节点的后继节点
    pindex -> prev -> next = pindex -> next;
    //释放内存
    free(pindex);
    //节点数减一
    count --;
    return 0;
}

//删除第一个节点
int dlink_delete_first(){
    return dlink_delete(0);
}

//删除组后一个节点
int dlink_delete_last(){
    return  dlink_delete(count - 1);
}

//撤销双向链表，成功，返回0，否则，返回-1
int destory_dlink(){
    if (!phead){
        printf("%s failed! dlink is null! \n",__func__);
        return -1;
    }
    //得到头节点
    node *pnode = phead -> next;
    node *ptmp = NULL;
    //删除头节点以外的节点
    //这里有个疑问：为什么是从头节点的下一个节点删，而不是从尾节点开始删,其实我们可以从
    //头节点的前驱节点开始删，也就是从尾节点开始删。
    /*
     * node *pnode = phead -> prev;
     *
     * //删除方式
     * while(pnode != phead){
     *    ptmp = pnode;
     *    pnode = pnode -> prev;
     *    free (ptmp);
     *    count --;
     * }
     * */
    //这样的效果是一样的。
    while (pnode != phead){
        //ptmp得到头节点的下一个节点
        ptmp = pnode;
        //pnode的下一个节点给pnode
        pnode = pnode -> next;
        //释放pnode的内存
        free(ptmp);
        //这里，节点数应该要减一，作者没写。
        count--;
    }
    //释放头节点内存
    free(phead);
    phead = NULL;
    count = 0;

    return 0;
}