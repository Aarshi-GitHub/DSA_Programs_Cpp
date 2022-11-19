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

int height(node* root){
    if(root==NULL) return 0;
    return max(height(root->left),height(root->right))+1;
}

bool checkBalanced(node* root){
    if(root==NULL) return true;
    bool leftBalanced = checkBalanced(root->left);
    bool rightBalanced = checkBalanced(root->right);
    bool curBalanced = abs(height(root->left)-height(root->right)) <=1;
    if(leftBalanced && rightBalanced && curBalanced) return true;
    return false;
}

pair<bool,int> checkBalancedFast(node* root){
    if(root==NULL){
        pair<bool,int> p = make_pair(true,0);
        return p;
    }
    pair<bool,int> left = checkBalancedFast(root->left);
    pair<bool,int> right = checkBalancedFast(root->right);
    bool leftBal = left.first;
    bool rightBal = right.first;
    bool isBal = abs(left.second - right.second) <=1;
    pair<bool,int> res;
    if(leftBal && rightBal && isBal) res.first = true;
    else res.first = false;
    res.second = max(left.second,right.second)+1;
    return res;
}

void isBalanced(node* root){
    // Complexity O(n^2)
    if(checkBalanced(root)){
        cout<<"Binary Tree is Balanced."<<endl;
    }
    else cout<<"Binary Tree is not Balanced."<<endl;
    
    // Using Faster Approach O(n)
    if(checkBalancedFast(root).first){
        cout<<"Binary Tree is Balanced by Faster approach."<<endl;
    }
    else cout<<"Binary Tree is not Balanced Faster approach."<<endl;
}


int main() {
    int arr1[] = {1,2,3,-1,-1,4,-1,-1,5,6,7};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    node* root = buildTreeFromLevelOrderTraversal(arr1,n1);
    levelOrderTraversal(root);
    isBalanced(root);
    
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
    cout<<"---------------------------------"<<endl;
    int arr2[] = {1,2,3,4,5,6};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    root = buildTreeFromLevelOrderTraversal(arr2,n2);
    levelOrderTraversal(root);
    isBalanced(root);
    /*
                            1
                          /   \
                         2     3
                        / \   / 
                       4   5 6   
    */
    return 0;
}
