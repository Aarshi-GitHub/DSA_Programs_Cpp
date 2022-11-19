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

node* buildTreeFromLevelOrderTraversal(int arr[],int n){
    if(n==0) return NULL;
    queue<node*> q;
    node* root = new node(arr[0]);
    q.push(root);
    node* cur = NULL;
    bool left = true;
    for(int i=1;i<n;i++){
        node* temp = NULL;
        if(arr[i]!=-1){
            temp = new node(arr[i]);
            q.push(temp);
        }
        if(left){
            cur = q.front();
            q.pop();
            cur->left = temp;
            left = false;
        }
        else{
            cur->right = temp;
            left = true;
        }
    }
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
    int arr[] = {1,2,3,-1,-1,4,-1,-1,5,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    node* root = buildTreeFromLevelOrderTraversal(arr,n);
    levelOrderTraversal(root);
    /*
                         1
                        / \
                       2   3
                          /
                         4
                          \
                           5
                          / \
                         6   7
    */
    return 0;
}
