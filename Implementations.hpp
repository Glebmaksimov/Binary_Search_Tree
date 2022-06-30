#include "Declarations.h"

template<typename T>
Node<T>* new_node(T key){
    auto new_node = new Node<T>(key);
    return new_node;
}
template<typename T>
Node<T>* insert(Node<T>* root,T key){
    if(root == nullptr)return new_node(key);
    if(key < root->key)root->left_child = insert(root->left_child,key);
    else if(key > root->key)root->right_child = insert(root->right_child,key);
    return root;
}
template<typename T>
Node<T>* search(Node<T>* root,T key){
    if(root == nullptr || root->key == key)return root;
    if(root->key > key)return search(root->left_child,key);
    return search(root->right_child,key);
}
template<typename T>
Node<T>* min_tree_value(Node<T>* root){
    Node<T>* temporary_node = root;
    while (temporary_node->left_child != nullptr && temporary_node){
        temporary_node = temporary_node->left_child;
    }
    return temporary_node;
}
template<typename T>
Node<T>* delete_node(Node<T>* root,T key){
    if(root == nullptr)return root;
    else if(root->key > key)root->left_child = delete_node(root->left_child,key);
    else if(root->key < key)root->right_child = delete_node(root->right_child,key);
    else{
        if(root->left_child == nullptr){
            Node<T>* temporary_node = root->right_child;
            free(root);
            return temporary_node;
        }else if(root->right_child == nullptr){
            Node<T>* temporary_node = root->left_child;
            free(root);
            return temporary_node;
        }
        Node<T>* temporary_node = min_tree_value(root->right_child);
        root->key = temporary_node->key;
        root->right_child = delete_node(root->right_child,temporary_node->key);
    }
    return root;
}
template<typename T>
void print(Node<T> *root, int space)
{
    if (root == nullptr)return;

    space += COUNT;

    print(root->right_child, space);

    cout<<endl;
    for (int i = COUNT; i < space; i++)cout<<" ";
    cout<<root->key<<endl;

    print(root->left_child, space);
}
template<typename T>
void print_tree(struct Node<T> *root){
    cout<<endl<<endl;
    cout<<"BINARY_TREE: "<<endl;
    print(root, 0);
    cout<<endl<<endl;
}
