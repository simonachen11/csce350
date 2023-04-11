#ifndef TREE_H
#define TREE_H
#include<bits/stdc++.h>
using namespace std; 
template<typename T>
struct BST_Node {
T val;
BST_Node* left;
BST_Node* right;

BST_Node(T v) : val(v),left(NULL),right(NULL)
{}

void insert(T v) {
    if(v>val){
        if (right==NULL) right = new BST_Node<T>(v);
        else right->insert(v);
    }
    else{
        if (left==NULL) left = new BST_Node<T>(v);
        else left->insert(v);
    }
}

};


template<typename T>
void delete_tree(BST_Node<T>* root){
    if (root==NULL) return;
    delete_tree(root->left);
    delete_tree(root->right);
    delete root;
}


//your work starts here
template<typename T>
int num_nodes(BST_Node<T>* root){
    queue<BST_Node<T>*>q; 
    q.push(root); 
    int ans=0; 
    while(!q.empty()){
       auto t=q.front();
       q.pop(); 
       ans++;
       if(t->left)q.push(t->left); 
       if(t->right)q.push(t->right); 
    }
    return ans;
}


template<typename T>
bool has_duplicate_val(BST_Node<T>* root){
    set<T>s; 
    queue<BST_Node<T>*>q; 
    q.push(root);
    
    while(!q.empty()){
       auto t=q.front(); 
       if(s.count(t->val))return 1; 
       s.insert(t->val); 
       q.pop(); 
       if(t->left)q.push(t->left); 
       if(t->right)q.push(t->right); 
    }
    return 0;

}


template<typename T>
bool trees_identical(BST_Node<T>* a, BST_Node<T>* b){
     queue<BST_Node<T>*>q1;
      queue<BST_Node<T>*>q2;
     q1.push(a);
     q2.push(b); 
     while(!q1.empty()||!q2.empty()){
       if(q1.empty()&&!q2.empty())return 0; 
        if(q2.empty()&&!q1.empty())return 0; 
        auto t1=q1.front(); 
        auto t2=q2.front(); 
        q1.pop();
        q2.pop(); 
         if(t1->val!=t2->val)return 0; 
         if(t1->left)q1.push(t1->left); 
         if(t1->right)q1.push(t1->right); 
         
         if(t2->left)q2.push(t2->left);
         if(t2->right)q2.push(t2->right); 
         
     }
    return true;
}



#endif //TREE_H
