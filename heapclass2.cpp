int main()
{
// create max heap
priority_queue<int>pq;
pq.push(10);
pq.push(20);
pq.push(30);
pq.push(40);

cout<<pq.top();
pq.pop();
cout<<pq.top();
cout<<pq.size();



// create min heap
priority_queue<int,vector<int>,greater<int>>p;
p.push(20);
p.push(10);
p.push(30);
cout<<p.top();
}



/// kth greatest ekement
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
      priority_queue<int,vector<int>,greater<int>>pq;
       for(int i=0;i<k;i++){
        pq.push(nums[i]);
       }

       for(int i=k;i<nums.size();i++){
        if(pq.top()<nums[i]){
            pq.pop();
            pq.push(nums[i]);
        }
       }
       return pq.top();
    }
};


// kth smallest elemnt
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int>pq;
        for(int i=0;i<matrix.size();i++){
          for(int j=0;j<matrix[i].size();j++){
            int elem=matrix[i][j];
            if(pq.size()<k){
                pq.push(elem);
            }
            else{
                if(elem<pq.top()){
                    pq.pop();
                    pq.push(elem);
                }
            }
          }
        }
        return pq.top();

    }
};


// cbt is a valid heap or not

class info{
    public:
    int maxval;
    bool isheap;
    
    info(int a,bool b){
        maxval=a;
        isheap=b;
    }
};


info checkmaxheap(Node*root){
    if(root==NULL){
        info temp;
        temp.maxval=INT_MIN;
        temp.isheap=true;
        return temp;
    }
    
    if(root->left==NULL && root->right==NULL){
        info temp;
        temp.maxval=root->data;
        temp.isheap=true;
        return temp;
    }
    
    info leftans=checkmaxheap(root->left);
    info rightans=checkmaxheap(root->right);
    
    if(root->data>leftans.maxval&& root->data>rightans.maxval && leftans.isheap && rightans.isheap){
        info ans;
        ans.maxval=root->data;
        ans.isheap=true;
        return ans;
    }
    else{
        info ans;
        ans.maxval=max(root->data,max(leftans.maxval,rightans.maxval));
        ans.isheap=false;
        return ans;
    }
    
}


class Solution {
public:
    
    bool levelorder(TreeNode*root){
        if(!root) return false;
        queue<TreeNode*>q;
        q.push(root);
        bool nullfound=false;
        while(!q.empty()){
          TreeNode*front=q.front();
          q.pop();
          if(front==NULL){
           nullfound=true;
          }
        else{
           if(nullfound){
            return false;
           }

          
            q.push(front->left);
            q.push(front->right);
          
        }
        }
        return true;
    }


   
  
    bool isCompleteTree(TreeNode* root) {
        return levelorder(root);



    }
};




// convert tree into max heap






void replaceusingpostorder(Node*root,vector<int>&in,int &index){
    if(root==NULL) return;
    replaceusingpostorder(root->left,in,index);
    replaceusingpostorder(root->right,in,index);
    root->data=in[index];
    index++;
}



Node*convertbstintomaxheap(Node*root){
    vector<int>inorder;
    storeinorder(root,inorder);
    int index=0;
    replaceusingpostorder(root,inorder,index);
    return root;
    
    
}


