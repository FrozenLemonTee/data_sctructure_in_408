//
// Created by Lenovo on 2022/5/13.
//

#ifndef C_C___BINARY_TREE_H
#define C_C___BINARY_TREE_H

#endif //C_C___BINARY_TREE_H
#include <main body/c3/linked_queue/linked_queue.h>

#define LEFT_CHILD 0
#define RIGHT_CHILD 1

// 树节点定义
T struct tree_node{
    TYPE data; // 树节点数据域
    tree_node<TYPE>* left; // 树节点左孩子指针域
    tree_node<TYPE>* right; // 树节点右孩子指针域
};

// 判断传入的是否为空指针
T bool node_check_null(tree_node<TYPE>* node){
    return !node;
}

// 打印节点
T void node_print(tree_node<TYPE>* node){
    if (node_check_null(node)){
        NULL_PTR;
    }
    std::cout << "(#" << node << ", " << node->data << ")";
}

// 树节点构造函数
T tree_node<TYPE>* node_init(TYPE data){
    tree_node<TYPE>* node = (tree_node<TYPE>*)malloc(sizeof(tree_node<TYPE>));
    node->data = data;
    node->left = (tree_node<TYPE>*)nullptr;
    node->right = (tree_node<TYPE>*)nullptr;
    return node;
}

// 设置孩子节点
T void node_set_child(tree_node<TYPE>* node, bool pos, tree_node<TYPE>* child){
    if (!pos){
        node->left = child;
    } else{
        node->right = child;
    }
}

// 二叉树定义
T struct binary_tree{
    tree_node<TYPE>* root; // 二叉树根节点
    int cnt; // 二叉树总非空节点数量
};

// 检查二叉树是否为空树
T bool tree_check_empty(binary_tree<TYPE>* tree){
    return !tree->cnt;
}

// 二叉树的空树构造函数
T binary_tree<TYPE>* tree_init(){
    binary_tree<TYPE>* tree = (binary_tree<TYPE>*)malloc(sizeof(binary_tree<TYPE>));
    tree->root = (tree_node<TYPE>*)nullptr;
    tree->cnt = 0;
    return tree;
}

// 二叉树构造函数
T binary_tree<TYPE>* tree_init(array<TYPE>* arr){
    linked_queue::linked_queue<tree_node<TYPE>*>* queue_node = linked_queue::queue_init<tree_node<TYPE>*>();
    linked_queue::linked_queue<int>* queue_index = linked_queue::queue_init<int>();
    binary_tree<TYPE>* tree = tree_init<TYPE>();
    if (arr->size()){
        tree->root = node_init<TYPE>(arr->get(0));
        tree->cnt += 1;
        linked_queue::queue_push(queue_node, linked_queue::node_init<tree_node<TYPE>*>(tree->root));
        linked_queue::queue_push(queue_index, linked_queue::node_init(0));
    }
    while (queue_check_empty(queue_node)){
        linked_queue::queue_node<tree_node<TYPE>*>* cur_node = linked_queue::queue_pop(queue_node);
        int cur_index = linked_queue::queue_pop(queue_index)->data;
        if (cur_index * 2 < arr->size()){
            tree_node<TYPE>* left_child = node_init<TYPE>(arr->get(cur_index * 2));
            linked_queue::queue_push(queue_node, linked_queue::node_init<tree_node<TYPE>*>(left_child));
            linked_queue::queue_push(queue_index, linked_queue::node_init<int>(cur_index * 2));
            node_set_child(cur_node, LEFT_CHILD, left_child);
            tree->cnt += 1;
        }
        if (cur_index * 2 + 1 < arr->size()){
            tree_node<TYPE>* right_child = node_init<TYPE>(arr->get(cur_index * 2 + 1));
            linked_queue::queue_push(queue_node, linked_queue::node_init<tree_node<TYPE>*>(right_child));
            linked_queue::queue_push(queue_index, linked_queue::node_init<int>(cur_index * 2 + 1));
            node_set_child(cur_node, RIGHT_CHILD, right_child);
            tree->cnt += 1;
        }
    }
    free(queue_node);
    free(queue_index);
    return tree;
}