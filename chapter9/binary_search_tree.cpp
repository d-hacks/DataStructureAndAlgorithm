//
// Created by yusuke on 2019-04-28.
//

#include <iostream>
#include <string>
#include "binary_search_tree.h"
using namespace std;

struct Node{
    int key;
    Node *parent, *left, *right;
};

Node *NIL, *root;

void insert(int key){
    Node *y = NIL;
    Node *x = root;
    Node *z;

    z = new Node;
    z->key = key;
    z->left = NIL;
    z->right = NIL;

    // rootから適切な位置まで二分木をたどる
    while(x != NIL){
        y = x;
        if(z->key < x->key){
            x = x->left;
        }else{
            x = x->right;
        }
    }

    // 新しい要素を配置する場所を決定
    z->parent = y;
    if(y == NIL){
        root = z;
    }else if(z->key < y->key){
        y->left = z;
    }else{
        y->right = z;
    }
}


Node* find(int key){
    Node *x = root;

    while(x != NIL && x->key != key){
        if(key < x->key){
            x = x->left;
        }else{
            x = x->right;
        }
    }
    return x;
}


Node* next_node(Node *node){
    Node *x;

    if(node->right != NIL){
        x = node->right;
        while (x->left != NIL){
            x = x->left;
        }
    }else{
        x = node;
        while(x->parent != NIL && x == x->parent->right){
            x = x->parent;
        }
        x = x->parent;
    }
    return x;
}


void delete_node(int key){
    Node *x, *y, *z;

    //削除するキーを持ったノード
    z = find(key);

    // yを決める
    if(z->left == NIL || z->right == NIL){  // zが子を持たないか１個もつ
        y = z;
    }else{  // zが子を２個もつ
        y = next_node(z);
    }

    // xを決める
    if(y->left != NIL){
        x = y->left;
    }else{
        x = y->right;
    }

    // ポインタつなぎ替え
    if(x != NIL){
        x->parent = y->parent;
    }

    if(y->parent == NIL){
        root = x;
    }else if(y == y->parent->left){
        y->parent->left = x;
    }else{
        y->parent->right = x;
    }

    if(z != y){
        z->key = y->key;
    }

    // yのメモリを解放
    delete y;
}


// 先行順巡回
void pre_order(Node* node){
    if(node == NIL){
        return;
    }

    cout << " " << node->key;

    if(node->left != NIL){
        pre_order(node->left);
    }
    if(node->right != NIL){
        pre_order(node->right);
    }
}


// 中間順巡回
void in_order(Node* node){
    if(node == NIL){
        return;
    }
    if(node->left != NIL){
        in_order(node->left);
    }

    cout << " " << node->key;

    if(node->right != NIL){
        in_order(node->right);
    }
}


void print(){
    pre_order(root);
    cout << endl;
    in_order(root);
    cout << endl;
}


int tree_main(){
    int i, m, key;
    string command;

    cin >> m;
    for(i = 0; i < m; i++){
        cin >> command;
        if(command == "insert") {
            cin >> key;
            insert(key);
        }else if(command == "find"){
            cin >> key;
            if(find(key) != NIL){
                cout << "yes" << endl;
            }else{
                cout << "no" << endl;
            }
        }else if(command == "delete"){
            cin >> key;
            delete_node(key);
        }else if (command == "print") {
            print();
        }else{
            // pass
        }
    }
}
