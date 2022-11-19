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

int height(node* root){
    if(root==NULL) return 0;
    return max(height(root->left),height(root->right))+1;
}

int diameter(node* root){
    if(root==NULL) return 0;
    int leftMax = diameter(root->left);
    int rightMax = diameter(root->right);
    int overallMax = height(root->left) + height(root->right) + 1;
    return max(leftMax,max(rightMax,overallMax));
}

pair<int,int> diameterFast(node* root){
    if(root==NULL){
        pair<int,int> p = make_pair(0,0);
        return p;
    }
    pair<int,int> left = diameterFast(root->left);
    pair<int,int> right = diameterFast(root->right);
    
    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;
    pair<int,int> res;
    res.first = max(op1,max(op2,op3));
    res.second = max(left.second,right.second)+1;
    return res;
}

int main() {
    int arr[] = {1,2,3,-1,-1,4,-1,-1,5,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    node* root = buildTreeFromLevelOrderTraversal(arr,n);
    cout<<"Height of Binary Tree : "<<height(root)<<endl;  // Complexity O(n)
    cout<<"Diameter of Binary Tree : "<<diameter(root)<<endl;  //Complexity O(n2)
    cout<<"Fast Diameter of Binary Tree : "<<diameterFast(root).first<<endl; //Complexity O(n)
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
