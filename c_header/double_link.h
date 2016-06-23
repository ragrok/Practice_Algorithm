//
// Created by ragrok on 16-6-23.
//

#ifndef ALGORITHM_DOUBLE_LINK_H
#define ALGORITHM_DOUBLE_LINK_H

//新建双向链表,成功返回表头，否则返回null
extern int create_dlink();
//撤销双向链表，成功返回0，否则，返回-1
extern int destory_dlink();

//双向链表是否为空，为空返回1；否则，返回0;
extern int dlink_is_empty();
//返回双向链表的大小
extern int dlink_size();

//获取双向链表中第index位置的元素，成功，返回节点指针；否则，返回null
extern void* dlink_get(int index);
//获取 双向链表中的第一个元素，成功，返回节点指针，否则，返回null
extern void* dlink_get_first();
//获取双向链表最后一个元素，成功，返回节点指针，否则，返回null

extern void* dlink_get_last();
//将value插入到index的位置，成功，返回0；否则，返回-1;
extern int dlink_insert(int index, void *pval);
//将value插入到表头的位置，成功，返回0，否则，返回-1；
extern int dlink_insert_first(void *pval);
//讲value插入到表尾的位置，成功，返回0，否则，返回-1；

extern int dlink_append_last(void *pval);
//删除双向链表index位置的节点，成功，返回0，否则，返回-1；
extern int dlink_delete(int index);
//删除第一个节点，成功，返回0，否则，返回-1；
extern int dlink_delete_first();
//删除最后一个节点，成功，返回0，否则，返回-1'；
extern int dlink_delete_last();

#endif //ALGORITHM_DOUBLE_LINK_H
