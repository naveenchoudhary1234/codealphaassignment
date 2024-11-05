#include<iostream>
using namespace std;

Node*findpredecessor(Node*root,Node*p){
    Node*pred=0;
    Node*curr=root;
    while(curr){
        if(curr->data<p-<data){
            pred=curr;
            curr=curr->right;
        }
        else{
            curr=curr->left;
        }
        return pred;
    }
}

Node * inOrderSuccessor(Node *root, Node *x)
    {
      Node*curr=root;
      Node*succ=NULL;
      while(curr){
      if(curr->data>x->data){
          succ=curr;
          curr=curr->left;
      }
      else{
          curr=curr->right;
      }
      
      }
      return succ;
      
        
        
}

 TreeNode*insertintobst(TreeNode*root,int x){
    if(!root){
        return new TreeNode(x);
    }
    if(x>root->val){
        root->right=insertintobst(root->right,x);
    }
    else if(x<root->val){
        root->left=insertintobst(root->left,x);
    }
    return root;
   }
   
    TreeNode* bstFromPreorder(vector<int>& preorder) {
     TreeNode*root=new TreeNode(preorder[0]);
     for(int i=1;i<preorder.size();i++){
        insertintobst(root,preorder[i]);
     }
     return root;
    }





        int countPairs(Node* root1, Node* root2, int x)
    {
 
      int ans=0;
      stack<Node*>s1;
      stack<Node*>s2;
      Node*a=root1;
      Node*b=root2;
      while(1){
          // inorder traversal
          while(a){
              s1.push(a);
              a=a->left;
          }
          // reverse inorder
          while(b){
              s2.push(b);
              b=b->right;
          }
          
          if(s1.empty() || s2.empty()){
              break;
          }
          
          auto atop=s1.top();
          auto btop=s2.top();
          int sum=atop->data+btop->data;
          if(sum==x){
              ans++;
              s1.pop();
              s2.pop();
              a=atop->right;
              b=btop->left;
          }
          
          else if(sum<x){
              // bst 1 k pointer ko aage bdayenge
              s1.pop();
              a=atop->right;
          }
          else{
              s2.pop();
              b=btop->left;
          }
          
          
      }
      return ans;
      
      
 
   
    }

    class Solution {
public:
bool isbalanced=true;
   int height(TreeNode*root){
    if(!root) return 0;
    int l=height(root->left);
    int r=height(root->right);
     if(abs(l-r)>1){
        isbalanced=false;
     }
     return max(l,r)+1;
   }

   void inordertraversal(TreeNode*root,vector<int>&nodes){
    if(!root) return;
    inordertraversal(root->left,nodes);
    nodes.push_back(root->val);
    inordertraversal(root->right,nodes);
   }

   TreeNode*buildbalance(vector<int>&nodes,int start,int end){
    if (start > end) return nullptr;
        
        int mid = start + (end - start) / 2;
        TreeNode* root = new TreeNode(nodes[mid]);
        
        root->left = buildbalance(nodes, start, mid - 1);
        root->right = buildbalance(nodes, mid + 1, end);
        
        return root;
   }
    
    TreeNode* balanceBST(TreeNode* root) {
        height(root);
        if(isbalanced){
            return root;
        }
        else{

       vector<int>nodes;
       inordertraversal(root,nodes);
       return buildbalance(nodes,0,nodes.size()-1);

        }
    }


};

void inorder(struct Node*root,vector<int>&nodes){
    if(!root) return ;
    inorder(root->left,nodes);
    nodes.push_back(root->data);
    inorder(root->right,nodes);
}


float findMedian(struct Node *root)
{      vector<int>nodes;
      inorder(root,nodes);

    int n = nodes.size();

    if (n % 2 != 0) {
        return nodes[n / 2];
    }

    else {
        return (nodes[n / 2] + nodes[(n / 2) - 1]) / 2.0;
    }

        
}

// dead end-means ab uske niche koi bhi value add ni ho sktii

   bool help(Node*root,int min,int max){
        if(!root) return false;
     if(!root->left && !root->right){
         if(min==max){
             return true;
         }
     }
     return help(root->left,min,root->data-1) || help(root->right,root->data+1,max);
   }
    
    bool isDeadEnd(Node *root)
    {
    return help(root,1,INT_MAX);
    
    }



       void inorder(TreeNode*root,vector<int>&ans){
        if(!root) return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
        
    }

   
    int rangeSumBST(TreeNode* root, int low, int high) {
        vector<int>ans;
        inorder(root,ans);
        int sum=0;
        for(int val:ans){
            if(val>=low && val<=high){
                sum+=val;
            }
        }
        return sum;
    }

// convert flaten search tree to linked list in which left pointer sshould point to null and right pointer next to it element
    class Solution {
public:

void inorder(TreeNode*root,vector<TreeNode*>&ans){
    if(!root) return;
    ans.push_back(root);
    inorder(root->left,ans);
    inorder(root->right,ans);
}


    void flatten(TreeNode* root) {
        if(!root) return;
      vector<TreeNode*>ans;
      inorder(root,ans); 
      for(int i=0;i<ans.size()-1;i++){
        ans[i]->left=NULL;
        ans[i]->right=ans[i+1];
      
      }       
    }
};

    Node* insert(Node* root, int val, int& succ) {  
        if (!root) {
            //
            return new Node(val);
        }
        
        if (val >= root->data) {

            root->right = insert(root->right, val, succ);
        } else {
            succ = root->data;  
            root->left = insert(root->left, val, succ);
        }
        
        return root;
    }
    
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        vector<int> ans(arr.size());
        Node* root = NULL;  
        

        for (int i = n - 1; i >= 0; i--) {
            int succ = -1;  
            root = insert(root, arr[i], succ);  
            ans[i] = succ;
        }
        
        return ans;
    }