// symmetrical or not
class Solution {
public:
// isme jo hmare ek mirroe k left m h vo dusre k uske right m hona chaiye

    bool isMirror(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(p && q){
            return (p->val==q->val)
            && isMirror(p->left,q->right)
            && isMirror(p->right,q->left);
        }
        // mtlb ek null ho gya ek nhii
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        return isMirror(root->left,root->right);
    }
};

// same treee

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(p && q){
            return (p->val==q->val)
            && isSameTree(p->left,q->left)
            && isSameTree(p->right,q->right);
        }
        // mtlb ek null ho gya ek nhii
        return false;
    }
};


// zigzag tree
// logic ek flag variable bnayenge kuki hme pehli br left to right print krana hai phir tight to lrft
// ist level p-left to right jayenge
// 2nd level p right to left jayenge
// 3rd level p let to right
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root) return ans;
        bool lefttoright=true;
        queue<TreeNode*>q;
         q.push(root);
        while(!q.empty()){
           int width=q.size();
           vector<int>onelevel(width);
           for(int i=0;i<width;i++){
            TreeNode*front=q.front(); q.pop();
            int index=lefttoright?i:width-i-1; // agar ye false hota hai to size -1 s loop chlayenge
            onelevel[index]=front->val;
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
           }

           lefttoright=!lefttoright; // change the direction
           ans.push_back(onelevel);

            
        

    }
    return ans;
    }
};


/// Transform to a sum tree
// logic- hme left aur right k sum ko root k sath change krna hain
int sum(Node*root){
      if(root==NULL) return 0;
      if(!root->left && !root->right){
        // sar leaf node zero hogii kuki iske left m 0 pda hain aur right m bhi 0 pda hain
          int temp=root->data;
          root->data=0;
          return temp;
      }
      int lsum=sum(root->left);
      int rsum=sum(root->right);
      int temp=root->data;
      root->data=lsum+rsum;
      return root->data+temp;
  }
  
    void toSumTree(Node *node)
    {
        sum(node);
        
    }


    /// path sum
    // 



class Solution {
public:
// yeh function sirf hm 1 root s dekhe rhe hain
 int ans=0;
   void pathfromoneroot(TreeNode*root,long long  sum){
    if(!root) return;
    // pre order traversal
    // hm jisko visit krte rhnge usko usme se bubtract kardengge
    if(sum==root->val) ans++;
    pathfromoneroot(root->left,sum-root->val);
    pathfromoneroot(root->right,sum-root->val);
   }

    int pathSum(TreeNode* root, long long  targetSum) {
        if(root){
        pathfromoneroot(root,targetSum);
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);
        }

        // ab sabko root bnake deknge
        return ans;

    }
};

   int csum=0;
   void sum(TreeNode*root){
    if(!root) return;
    sum(root->right);
    csum+=root->val;
    root->val=csum;
    sum(root->left);
    


   

   }

    TreeNode* bstToGst(TreeNode* root) {
     sum(root);
     return root;
    }

/// MORRRIS TRAVERSAL
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
       TreeNode*curr=root;
       while(curr){
        // left node is null then visit to right
         if(curr->left==NULL){
            ans.push_back(curr->val);
            curr=curr->right;
         }
         else{
            // find inorder predecssor
            // ek br left jao phir right hi jate rhoo
            TreeNode*pred=curr->left;
            while(pred->right!=curr && pred->right){
                pred=pred->right;
            }
            // if pred right nodr is null then o after establishing from pred to curr
            if(pred->right==nullptr){
                pred->right=curr;
                curr=curr->left;
            }
            else{
                pred->right=NULL;
                ans.push_back(curr->val);
                curr=curr->right;
            }

         }
       }
       return ans;
    }

/// sum of longest root to lef memthod

    pair<int,int>height(Node*root){
        if(!root) return {0,0};
        auto lh=height(root->left);
        auto rh=height(root->right);
        
        int sum=root->data;
        if(lh.first==rh.first){ // heigtt same hai
            sum+=lh.second>rh.second?lh.second:rh.second;
        }
        
        else if(lh.first<rh.first){
            sum+=rh.second;
        }
        else{
            sum+=lh.second;
        }
        return {max(lh.first,rh.first)+1,sum};
    }
    
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        // pair bnalenge pehle height aur phir sum
        auto h=height(root);
        return h.second;
    
    
    }



      //Function to return the maximum sum of non-adjacent nodes.
    
    pair<int,int>helper(Node*root){
        if(!root) return {0,0};
        
        auto left=helper(root->left);
        auto right=helper(root->right);
        
        // including vala sum
        int a=root->data+left.second+right.second;
        // excluding the node
        int b=max(left.first,left.second)+max(right.first,right.second);
        return {a,b};
        
    }
    
    
    int getMaxSum(Node *root) 
    {
        auto ans=helper(root);
        return max(ans.first,ans.second);
        
    }


    


