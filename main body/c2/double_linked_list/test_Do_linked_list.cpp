//
// Created by Lenovo on 2022/4/4.
//
#include "Do_linked_list.h"
#define LEN 40

list_node* new_node(){
    return node_init(rand_range(0, LEN));
}

// flag: 是否输出提示信息
void test_insert(Do_linked_list* list, int num, int flag){
    for (int i = 0; i < num; ++i) {
        int index = rand_range(0, list_length(list));
        list_node* node = new_node();
        if (flag){
            std::cout << "cur index: " << index << ", " << "cur node: ";
            node_print(node);
            std::cout << ", ";
        }
        list_insert(list, index, node);
        if (flag){
            list_print(list);
            std::cout << std::endl;
        }
    }
}

void test_pop(Do_linked_list * list, int num){
    for (int i = 0; i < num; ++i) {
        int index = rand_range(0, list_length(list));
        list_node* node = list_pop(list, index);
        std::cout << "cur index: " << index << ", " << "cur node: ";
        node_print(node);
        std::cout << " ";
        list_print(list);
        std::cout << std::endl;
    }
}

void test_find_val(Do_linked_list * list, int num){
    list_print(list);
    std::cout << std::endl;
    for (int i = 0; i < num; ++i) {
        int val = rand_range(0, int(LEN * 1.2));
        list_node* node = list_find_by_val(list, val);
        std::cout << "cur val: " << val << ", " << "cur elem: ";
        if (node){
            node_print(node);
        } else{
            std::cout << "NULL";
        }
        std::cout << std::endl;
    }
}

void test_delete(Do_linked_list * list){
    std::cout << "before: ";
    list_print(list);
    std::cout << std::endl;
    list_delete(list);
    std::cout << "after: ";
    list_print(list);
    std::cout << std::endl;
}

int main(){
    Do_linked_list * list = list_init();
    test_insert(list, 20, 1);
    std::cout << "-----------------------" << std::endl;
    test_find_val(list, 20);
    std::cout << "-----------------------" << std::endl;
    test_pop(list, 20);
    std::cout << "-----------------------" << std::endl;
    test_delete(list);
    return 0;
}