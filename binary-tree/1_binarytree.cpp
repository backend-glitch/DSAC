/*
terminal : 
g++ 
*/

#include<iostream>
#include <vector>
#include<queue>

using namespace std;


class Node{
    public :
    int data;
    Node *left;
    Node *right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

static int index = -1;
Node* buildTree(vector<int> preorder){
    index++;

    if(preorder[index] == -1) return NULL;

    Node* root = new Node(preorder[index]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);

   return root;
}

void preorder(Node* root){ 

    if(root == NULL) return;

   cout<<root->data<<" ";
   preorder(root->left);
   preorder(root->right);
}

// level by level traversal
void levelorder(Node* root){
    queue<Node*> q;

    q.push(root);

    while(q.size() > 0){
 
 Node* curr = q.front();
 q.pop();
 
 cout<<curr -> data<< " ";
 
 if(curr -> left == NULL) q.push(curr -> left);
  if(curr -> right == NULL) q.push(curr -> right);
    }
    cout<<endl;
}

int main(){

 vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};

 Node* root = buildTree(preorder);
 cout<<root->data<<endl;
 cout<<root->left->data<<endl;
 cout<<root->right->data<<endl;

 //preoder
 //preorder(root);
 //cout<<endl;

//level by level
//Node* root = levelorder(root);

 return 0;

}