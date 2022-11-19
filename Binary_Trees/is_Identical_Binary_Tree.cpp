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
    cout<<"----------------------------"<<endl;
}

int isIdentical(node* root1,node* root2){
    if(root1==NULL && root2==NULL) return true;
    if((root1==NULL && root2!=NULL) || (root1!=NULL && root2==NULL))
        return false;
    if(root1->data!=root2->data) return false;
    bool op1 = isIdentical(root1->left,root2->left);
    bool op2 = isIdentical(root1->right,root2->right);
    return op1 && op2;
}

bool checkIdentical(node* root1,node* root2){
    if(isIdentical(root1,root2))
        cout<<"Trees are Identical."<<endl;
    else
        cout<<"Trees are Not Identical."<<endl;
}


int main() {
    int arr1[] = {1,2,3,-1,-1,4,-1,-1,5,6,7};
    int arr2[] = {1,2,3,4,5,6};
    int arr3[] = {1,2,3,4,5,6};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    int n3 = sizeof(arr3)/sizeof(arr3[0]);
    node* root1 = buildTreeFromLevelOrderTraversal(arr1,n1);
    node* root2 = buildTreeFromLevelOrderTraversal(arr2,n2);
    node* root3 = buildTreeFromLevelOrderTraversal(arr3,n3);
    cout<<"Tree 1 ";levelOrderTraversal(root1);
    cout<<"Tree 2 ";levelOrderTraversal(root2);
    cout<<"Tree 3 ";levelOrderTraversal(root3);
    cout<<"1 and 2 ";checkIdentical(root1,root2);
    cout<<"2 and 3 ";checkIdentical(root2,root3);
    cout<<"1 and 3 ";checkIdentical(root1,root3);
    
    /*
    ----------------------- Root 1 Tree ---------------------
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
    /*
    ------------------- Root 2 & Root 3 Tree -----------------
                            1
                          /   \
                         2     3
                        / \   / 
                       4   5 6   
    */
    return 0;
}
