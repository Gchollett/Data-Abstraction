class node{
    public:
        node *left;
        int val;
        node *right;
};
node* root;
int min(){
    node* current = root;
    while(current->left != nullptr){ // while has a left child
        current = current->left;
    }
    return current->val;
}

int max(){
    node* current = root;
    while(current->right != nullptr){ // while has a right child
        current = current->right;
    }
    return current->val;
}