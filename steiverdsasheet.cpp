#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// largest element in array
// int main(){
//     int arr[5]={1,2,3,4,5};
//     int greter=arr[0];
//     for(int i=0;i<5;i++){
//         if(arr[i]>greter)
//         greter=arr[i];
//     }
//     cout<<greter;
// }

// find kth largest element in array
// int kthlargest(vector<int>&nums,int k){
//     priority_queue<int,vector<int>,greater<int>>pq;
//     for(int i=0;i<k;i++){
//         pq.push(nums[i]);
//     }
    
//     for(int i=k;i<nums.size();i++){
//         if(pq.top()<nums[i]){
//             pq.pop();
//             pq.push(nums[i]);
//         }
//     }
//     return pq.top();
// }
// int main(){
//   vector<int>nums={1,5,8,9,7};
//   int k=2;
//   int ans=kthlargest(nums,k);
//   cout<<ans;
// }

// check if array is sorted
// bool check(int arr[],int n){
//     for(int i=0;i<n-1;i++){
//       if(arr[i]>arr[i+1]){
//           return false;
//       }
      
//     }
//     return true;
// }
// int main(){
//     int arr[5]={1,2,3,4,5};
//     int n=5;
//     bool ans=check(arr,n);
//     cout<<ans;
// }

//remove dublicate from sorted array
// int removedub(vector<int>&nums){
//     int i=0;
//     int j=1;
//     while(j<nums.size()){
//         if(nums[j]==nums[i]){
//             j++;
//         }
//         else{
//             i++;
//             nums[i]=nums[j];
//             j++;
//         }
//     }
//     return i+1;
// }
// int main(){
//     vector<int>nums={1,2,2,3,3,4};
//     int len=removedub(nums);
//     for(int i=0;i<len;i++){
//         cout<<nums[i];
//     }
// }

// left rotatae an array by one place
// int main(){
//     int arr[]={1,2,3,4,5};
//     int n=5;
//     int temp=arr[0];
//     for(int i=0;i<n;i++){
//         arr[i]=arr[i+1];
//     }
//     arr[n-1]=temp;
//     for(auto it:arr){
//         cout<<it;
//     }
// }

// left rotate an array by k places
// int main(){
//     vector<int>nums={1,2,3,4,5};
//     int k=3;
//     int n=5;
//     while(k!=0){
//         int temp=nums[0];
//         for(int i=0;i<n;i++){
//           nums[i]=nums[i+1]; 
//         }
//         nums[n-1]=temp;
//         k--;
//     }
//     for(auto it:nums){
//         cout<<it;
//     }
// }

    // void moveZeroes(vector<int>& nums) {
    //    int i=0;
    // int j=0;
    // while(j<nums.size()){
    //   if(nums[j]!=0){
    //       swap(nums[i],nums[j]);
    //       i++;
    //   }
    //   j++;
    // }
    // }

       vector<int> findUnion(vector<int> &a, vector<int> &b) {
       set<int>st;
       vector<int>ans;
       for(int i=0;i<a.size();i++){
           st.insert(a[i]);
       }
       
       for(int i=0;i<b.size();i++){
           st.insert(b[i]);
       }
       ans.assign(st.begin(),st.end());
       return ans;
    }

// int longestsubarray(vector<int>a,int k){
//     int left=0;
//     int right=0;
//     int sum=0;
//     int maxlen=0;
//     while(right<a.size()){
        
//         while(left<=right && sum>k){
//             sum-=a[left];
//             left++;
//         }
        
//         if(sum==k){
//             maxlen=max(maxlen,right-left+1);
//         }
        
        
        
        
//         right++;
//         if(right<a.size()) sum+=a[right];
//     }
//     return maxlen;
// }



// for negative also
   int lenOfLongSubarr(int a[],  int n, int k) 
    { 
           map<int,int>prefixsum;
    int maxlen=0;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
        if(sum==k){
            maxlen=max(maxlen,i+1);
        }
        int rem=sum-k;
        if(prefixsum.find(rem)!=prefixsum.end()){
            int len=i-prefixsum[rem];
            maxlen=max(maxlen,len);
        }
        
        if(prefixsum.find(sum)==prefixsum.end()){
            prefixsum[sum]=i;
        }
    }
    return maxlen;
    } 



// int maxsubarraysum(vector<int>&arr){
//     int maxi=0;
//     int sum=0;
//     for(int i=0;i<arr.size();i++){
//         sum+=arr[i];
        
//         maxi=max(maxi,sum);
        
//         if(sum<0){
//             sum=0;
//         }
//     }
//     return maxi;
// }

// int main(){
//     vector<int>arr={-2,1,-3,4,-1,2,1,-5,4};
//     int ans=maxsubarraysum(arr);
//     cout<<ans;
// }

// vector<int>rearrange(vector<int>&nums){
//     vector<int>pos;
//     vector<int>neg;
    
//     for(auto num:nums){
//         if(num<0){
//             neg.push_back(num);
//         }
//         else{
//             pos.push_back(num);
//         }
//     }
    
//     vector<int>res;
//     int i=0;
//     int j=0;
//     while(i<pos.size() && j<neg.size()){
//         res.push_back(pos[i++]);
//         res.push_back(neg[j++]);
//     }
//     return res;
// }
// int main(){
//     vector<int>nums={1,2,-3,-1,-2,-3};
//     vector<int>ans;
//     ans=rearrange(nums);
//     for(auto it:ans){
//         cout<<it;
//     }
// }

//  void nextPermutation(vector<int>& nums) {
//      next_permutation(nums.begin(),nums.end());
//     }


// leader

// int main(){
//     vector<int>arr={4,7,1,0};
//     vector<int>ans;
//     int maxfromright=arr[n-1];
//     ans.push_back(maxfromright);
//     for(int i=arr.size()-2;i>=0;i--){
//         if(arr[i]>=maxfromright){
//             maxfromright=arr[i];
//             ans.push_back(maxfromright);
//         }
//     }
//     reverse(ans.begin(),ans.end());
// }

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        vector<bool> zerorow(row, false);
        vector<bool> zerocol(col, false);


        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]==0){
                    zerorow[i]=true;
                    zerocol[j]=true;
                }
            }
        }

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(zerorow[i]||zerocol[j]){
                    matrix[i][j]=0;
                }
            }
        }
    }
};

// find maximum consecutive ones
// int main(){
//     vector<int>nums={3, 8, 5, 7, 6};
//     sort(nums.begin(),nums.end());
//     int count=1;
//     int maxcount=1;
//     for(int i=1;i<nums.size();i++){
//         if(nums[i]==nums[i-1]+1){
//             count++;
//         }
//         else{
//             count=1;
//         }
//         maxcount=max(maxcount,count);
//     }
//     cout<<maxcount;
// }

   int subarraySum(vector<int>& nums, int k) {
     int n=nums.size();
     int count=0;
     int sum=0;
     unordered_map<int,int>prevsum;

     for(int i=0;i<n;i++){
        sum+=nums[i];

        if(sum==k){
            count++;
        }

        if(prevsum.find(sum-k)!=prevsum.end()){
            count+=prevsum[sum-k];
        }

        prevsum[sum]++;
     }
        return count;
    }

       int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        sort(nums.begin(),nums.end());
        int count=1;
        int maxcount=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]+1){
                count++;
            }
            else if(nums[i]!=nums[i-1]){
                count=1;
            }
            maxcount=max(maxcount,count);
        }
        return maxcount;
    }



    // pascal triangle
    // 1 print the specific row
     long long int ncr(int n,int r){
        long long int res=1;
        for(int i=0;i<r;i++){
         res=res*(n-i);
         res/=(i+1);

        }
        return res;
    }

    
    vector<int> getRow(int rowIndex) {
        vector<int>ans;
        for(int c=0;c<=rowIndex;c++){
            ans.push_back(ncr(rowIndex,c));
        }
        return ans;
    }

    // print the full pascal triangle
    class Solution {
public:

   long long int ncr(int n,int r){
        long long int res=1;
        for(int i=0;i<r;i++){
         res=res*(n-i);
         res/=(i+1);

        }
        return res;
    }
    vector<vector<int>> generate(int n) {
        vector<vector<int>>ans;
        for(int row=0;row<n;row++){
            vector<int>sol;
            for(int c=0;c<=row;c++){
                sol.push_back(ncr(row,c));
            }
            ans.push_back(sol);
        }
        return ans;
    }
};


    vector<int> majorityElement(vector<int>& nums) {
       int n=nums.size();
       vector<int>ans;
      sort(nums.begin(),nums.end());
      unordered_map<int,int>mp;
      for(int i=0;i<nums.size();i++){
        mp[nums[i]]++;
      }
      for(auto it:mp){
        if(it.second>n/3){
            ans.push_back(it.first);
        }
      }
      return ans;
    }


// merge interval
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>&arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>>ans;
        for(int i=0;i<arr.size();i++){
        // first case jb hmara answer abhi khali hain aur aagli value s chori hain t hme ek nyi create krni pdegii
         if(ans.empty() || arr[i][0]>ans.back()[1]){
            ans.push_back(arr[i]);
         }
         else{
            ans.back()[1]=max(ans.back()[1],arr[i][1]);
         }
        }

        return ans;
    }
};

 int maxProduct(vector<int>& nums) {
        int result = nums[0]; 
        for(int i = 0; i < nums.size(); i++) {
            int p = nums[i];
            result = max(result, p); 
            for(int j = i + 1; j < nums.size(); j++) {
                p *= nums[j];
                result = max(result, p); 
            }
        }
        return result;
    }


