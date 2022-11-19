#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

node* buildTree(){
    int data;
    cout<<"Enter data of root : ";
    cin>>data;
    if(data==-1) return NULL;
    node* root = new node(data);
    cout<<"Left Side of "<<data<<" : "<<endl;
    root->left = buildTree();
    cout<<"Right Side of "<<data<<" : "<<endl;
    root->right = buildTree();
    return root;
}

void levelOrderTraversal(node* root){
    cout<<"Level Order Traversal : "<<endl;
    queue<node*> q;
    q.push(root);
    int l=0;
    while(!q.empty()){
        int n = q.size();
        cout<<"Level "<<l<<" : ";
        for(int i=0;i<n;i++){
            node* temp = q.front();
            cout<<temp->data<<" ";
            q.pop();
            if(temp->left!=NULL) q.push(temp->left);
            if(temp->right!=NULL) q.push(temp->right);
        }
        cout<<endl;
        l++;
    }
}


int main() {
    // node* root = new node(1);
    // root->left = new node(2);
    // root->right = new node(3);
    // root->left->left = new node(4);
    // root->left->right = new node(5);
    // root->right->left = new node(6);
    // root->right->right = new node(7);
    node* root = buildTree();
    levelOrderTraversal(root);
    /*
                            1
                          /   \
                         2     3
                        / \   / \
                       4   5 6   7
    */
    return 0;
}
