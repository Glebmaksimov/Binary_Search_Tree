
#include "Declarations.h"

int main() {
    Node<int>* root = nullptr;
    root = insert(root,10);
    insert(root,2);
    insert(root,50);
    insert(root,1);
    insert(root,3);
    insert(root,4);
    print_tree(root);

    Node<int>* need_node = search(root,3);
    cout<<"Found "<<need_node->key<<endl;
    delete_node(root,2);
    print_tree(root);
    cout<<root->left_child->right_child->key<<endl;
    return 0;
}

