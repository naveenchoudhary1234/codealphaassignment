  
  // valid heap or not
   bool iscomptree(struct Node*root){
       if(!root) return false;
       queue<Node*>q;
       q.push(root);
       bool nullfound=false;
       while(!q.empty()){
           Node*front=q.front();
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
   
   
   bool heaps(struct Node*root){
       
     if(!root) return true;
     bool left=heaps(root->left);
     bool right=heaps(root->right);
     if(!root->left && !root->right){
         return true;
     }
    if (root->left && root->data < root->left->data) return false;
    if (root->right && root->data < root->right->data) return false;

    return left && right;
 }
  
bool isHeap(struct Node* tree) {
      
      return iscomptree(tree) && heaps(tree);
 }


 // merge two binary max heaps
     
void heapify(vector<int>& arr, int n, int index) {
    int leftindex = 2 * index + 1;
    int rightindex = 2 * index + 2;
    int greater = index;

    if (leftindex < n && arr[leftindex] > arr[greater]) {
        greater = leftindex;
    }

    if (rightindex < n && arr[rightindex] > arr[greater]) {
        greater = rightindex;
    }

    if (index != greater) {
        swap(arr[index], arr[greater]);
        heapify(arr, n, greater); 
    }
}

vector<int> mergeHeaps(vector<int>& a, vector<int>& b, int n, int m) {
    vector<int> ans(a.begin(), a.end());
    ans.insert(ans.end(), b.begin(), b.end());

    int totalSize = n + m;
    
    for (int index = totalSize / 2 - 1; index >= 0; index--) {
        heapify(ans, totalSize, index);
    }

    return ans;
}

// find k closest point to origin
class Solution {
public:

    class mycomp{
        public:
        bool operator()(pair<int,int>&a,pair<int,int>&b){
          // jiska distance ks square kam hoga usse queue m upr rakhna hai
          int dista=a.first*a.first+a.second*a.second;
          int distb=b.first*b.first+b.second*b.second;
          return dista>distb;
        }
    };
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,mycomp>pq;
        for(auto p:points){
            pq.push({p[0],p[1]}); //p[0]-x p[1]-y
        }
        while(!pq.empty() && k--){
            auto &top=pq.top();
            ans.push_back({top.first,top.second});
            pq.pop();
        }
        return ans;

    }
};