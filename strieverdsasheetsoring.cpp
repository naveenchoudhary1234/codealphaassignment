#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// vector<int>floorandcell(vector<int>arr,int x){
//     int left=0;
//     int right=arr.size()-1;
//     int f=-1;
//     int c=-1;
//     while(left<=right){
//         int mid=(left+right)/2;
//         if(arr[mid]==x){
//             f=arr[mid];
//             c=arr[mid];
//         }
        
//         if(arr[mid]<x){
//           f=arr[mid];
//             left=mid+1;
//         }
//         else if(arr[mid]>x){
//             c=arr[mid];
//             right=mid-1;
//         }
//     }
//     return {f,c};
// }

// int main(){
//     vector<int>arr={3,4,4,7,8,10};
//     int x=5;
//     vector<int>ans=floorandcell(arr,x);
//     for(auto it:ans){
//         cout<<it;
//     }
// }



int hashing(vector<int>&arr, int x) {
    unordered_map<int, int> mp;
    int count = 0;
    for (int i = 0; i < arr.size(); i++) {
        mp[arr[i]]++;
    }
    return mp[x];
}
int main() {
    vector<int> arr = {2, 2, 3, 3, 3, 3, 4};
    int x = 3;
    int ans=hashing(arr, x);
    cout<<ans;
}

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
       int left=0;
       int right=nums.size()-1;
       while(left<=right){
        int mid=(left+right)/2;
        if(nums[mid]==target){
            return true;
        }
        else if(target>nums[mid]){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
       } 
       return false;
    }
};

int count(vector<int>arr){
    int ans[arr.size()];
    for(int i=0;i<arr.size();i++){
        ans[i]=arr[i];
    }
    sort(ans,ans+arr.size());
    int firstelem=ans[0];
    for(int i=0;i<arr.size();i++){
        if(arr[i]==firstelem){
            return i;
            break;
        }
    }
    return -1;
    
}

int main(){
    vector<int>arr={4,5,6,7,0,1,2,3};
    int ans=count(arr);
    cout<<ans;
}

// find the nth root of a number

int square(int m,int n){
   int left=1;
   int right=m;
   while(left<=right){
       int mid=left+((right-left)/2);
       
        double num=pow(mid,n);
        if(num==m){
            return mid;
        }
        
        else if(num>m){
            right=mid-1;
        }
        else{
            left=mid+1;
        }
        
   }
   return -1;
}
int main(){
    int n=3;
    int m=25;
    int ans=square(m,n);
    cout<<ans;
}


/// koko eating bananas
bool ispossiblesolution(vector<int>& piles, int h,int sol){
int counter=0;
for(int i=0;i<piles.size();i++){
    counter+=(piles[i]+sol-1)/sol;
    if(counter>h) return false;
    
}
return true;

}
int minEatingSpeed(vector<int>& piles, int h) {
        int left=1;
        int right=*max_element(piles.begin(),piles.end());
        int ans=-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(ispossiblesolution(piles,h,mid)){
                ans=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return ans;

    }

      bool isPossibleSolution(vector<int>& bloomDay, int m, int k, int sol) {
        int bouquets = 0;
        int flowers = 0;
        
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= sol) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    if (bouquets == m) return true;
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }
        }
        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int left = 1;
        int right = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isPossibleSolution(bloomDay, m, k, mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }

        bool ispossiblesolution(vector<int>&nums, int t,int sol){
int counter=0;
for(int i=0;i<nums.size();i++){
    counter+=(nums[i]+sol-1)/sol;
    if(counter>t) return false;
    
}
return true;

}

   
    int smallestDivisor(vector<int>& nums, int t) {
         int left=1;
        int right=*max_element(nums.begin(),nums.end());
        int ans=-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(ispossiblesolution(nums,t,mid)){
                ans=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return ans;

    }

      int findKthPositive(vector<int>& arr, int k) {
    for(int i=0;i<arr.size();i++){
        if(arr[i]<=k) k++;
        else break;
    }
    return k;
    }

    class Solution {
public:
   bool help(vector<int>& weights, int days, int sol) {
       int daycount = 0;
       int currweight = 0;

       for (int i = 0; i < weights.size(); i++) {
           if (currweight + weights[i] > sol) {
               daycount++;
               currweight = weights[i];
           } else {
               currweight += weights[i];
           }
       }
       if (currweight > 0) {
           daycount++;
       }

       return daycount <= days;
   }

   int shipWithinDays(vector<int>& weights, int days) {
       int left = *max_element(weights.begin(), weights.end());
       int right = accumulate(weights.begin(), weights.end(), 0);
       int ans = -1;

       while (left <= right) {
           int mid = (left + right) / 2;
           if (help(weights, days, mid)) {
               ans = mid;
               right = mid - 1;
           } else {
               left = mid + 1;
           }
       }
       return ans;
   }
};

