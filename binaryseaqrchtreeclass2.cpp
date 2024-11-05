// lowest common ancestor in binary search tree
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         if(!root) return NULL;
    if(root->val>p->val && root->val>q->val){
        return lowestCommonAncestor(root->left,p,q);
    }
     if(root->val<p->val && root->val<q->val){
        return lowestCommonAncestor(root->right,p,q);
    }
    return root;



    }

// valid binary searcxh tree
class Solution {
public:
   bool solve(TreeNode*root,long long int lowerbound,long long int upperbound){
       if(!root) return true;
       bool cond1=(root->val>lowerbound);
       bool cond2=(root->val<upperbound);
       bool leftans=solve(root->left,lowerbound,root->val);
       bool rightans=solve(root->right,root->val,upperbound);
       if(cond1 && cond2 && leftans && rightans){
        return true;
       }
       else{
        return false;
       }
   }
     
    bool isValidBST(TreeNode* root) {
      
        long long int lowerbound=-2147483657;
        long long int upperbound=2147483657;

        bool ans=solve(root,lowerbound,upperbound);
        return ans;
    }
};

// kth smallest
class Solution {
public:
  
  void inorder(TreeNode*root,int &k,int &result){
    if(!root) return;
    inorder(root->left,k,result);
    k--;
    if(k==0){
      result=root->val;
      return;
    }
    inorder(root->right,k,result);

  }
   
    int kthSmallest(TreeNode* root, int k) {
        int result=-1;
        inorder(root,k,result);
        return result;
    }
};

// two sum
class Solution {
public:
   
   void storeinorder(TreeNode*root,vector<int>&inorder){
    if(root==NULL){
        return;
    }
   storeinorder(root->left,inorder);
   inorder.push_back(root->val);
   storeinorder(root->right,inorder);

   }

    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return false;
        vector<int>inorder;
        storeinorder(root,inorder);
        int left=0;
        int right=inorder.size()-1;
        while(left<right){
            int sum=inorder[left]+inorder[right];
            if(sum==k){
                return true;
            }
            else if(k>sum){
                left++;
            }
            else{
                right--;
            }
        }
        return false;
    }
};

//convert linked list to binary tree
// n- no of nodes
Node*convertDLLTOBST(Node*&head,int n){
    if(!head || n<=0){
        return NULL;
    }
    
    // LNR
    Node*leftsubtree=convertDLLTOBST(head,n/2);
    
    Node*root=head;
    root->left=leftsubtree;
    head=head->right;
    
    Node*rightsubtree=convertDLLTOBST(head,n-n/2-1);
    root->right=rightsubtree;
    return root;
}



  void convert(Node*root,Node*&head){
      if(!root) return ;
      // rnl
      convert(root->right,head);
      
      root->right=head;
      if(head){
      head->left=root;
      }
      head=root;
      
      convert(root->left,head);
      
      
  }
    Node* bToDLL(Node* root) {
        Node*head=NULL;
        convert(root,head);
        return head;
    }
