#include<iostream>
#include<queue>
#include<vector>
using namespace std;


class info{
    public:
    int data;
    int rowindex;
    int colindex;
    
    info(int a,int b,int c){
        data=a;
        rowindex=b;
        colindex=c;
    }
};

class compare{
    public:
    bool operator()(info*a,info*b){
        return a->data>b->data;
    }
};


void merge(vector<vector<int>>arr,int k,vector<int>&ans){
    priority_queue<info*,vector<info*>,compare>pq;
    
    for(int i=0;i<k;i++){
        int elem=arr[i][0];
        info*temp=new info(elem,i,0);
        pq.push(temp);
    }
    
    while(!pq.empty()){
        info*top=pq.top();
        pq.pop();
        int topdata=top->data;
        int toprow=top->rowindex;
        int topcol=top->colindex;
        
        ans.push_back(topdata);
        if(topcol+1<arr[toprow].size()){
            info*newinfo=new info(arr[toprow][topcol+1],toprow,topcol+1);
            pq.push(newinfo);
        }
        
    }
}




int main(){
    vector<vector<int>>arr={
        {5,6,7,8},{9,10,12,13},{16,19,25,30}
    };
    int k=3;
    vector<int>ans;
    merge(arr,k,ans);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}

    class compare{
    public:
    bool operator()(ListNode*a,ListNode*b){
        return a->val>b->val;
    }
};



class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       priority_queue<ListNode*,vector<ListNode*>,compare>pq;
       
       for(int i=0;i<lists.size();i++){
        ListNode*listhead=lists[i];
        if(listhead!=NULL){
        pq.push(listhead);
        }
       }
       // for new linked list
      ListNode*head=NULL;
      ListNode*tail=NULL;
       while(!pq.empty()){
        ListNode*top=pq.top();
        pq.pop();

        if(head==NULL){
            // first node created
            head=top;
            tail=top;
            if(tail->next){
                pq.push(tail->next);
            }
        }

        else{
            // pehli k bd
            tail->next=top;
            tail=top;
            if(tail->next){
                pq.push(tail->next);
            }
        }

       }
       return head;
    }
};


class Info{
  public:
    int data;
    int rowIndex;
    int colIndex;

    Info(int a, int b, int c) {
      this->data = a;
      this->rowIndex = b;
      this->colIndex = c;
    }
};

class compare{
  public:
    bool operator()(Info* a, Info* b) {
      return a->data > b->data;
    } 
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        priority_queue<Info*, vector<Info*>, compare> pq;
        int maxi = INT_MIN;
        int mini = INT_MAX;

        //process first k elements ko 
        for(int i=0; i<nums.size(); i++) {
            int element = nums[i][0];
            int row = i;
            int col = 0;
            Info* temp = new Info(element, row, col);
            pq.push(temp);
            maxi = max(maxi, element);
            mini = min(mini,element);
        }

        int ansStart = mini;
        int ansEnd = maxi;

        while(!pq.empty()) {
            Info* topNode = pq.top();
            int topData = topNode->data;
            int topCol = topNode->colIndex;
            int topRow = topNode->rowIndex;

            pq.pop();

            mini = topNode->data;
            //maxi ki value pehle se padi hui h 
            //compare krlete h for smaller range
            if((maxi-mini) < (ansEnd-ansStart)) {
                //update ans;
                ansStart  = mini;
                ansEnd = maxi;
            }

            //insertion wala step
            if(topCol + 1 < nums[topRow].size()) {
                int newElement = nums[topRow][topCol+1];
                maxi = max(maxi, newElement);
                Info* newInfo = new Info(newElement, topRow, topCol+1);
                pq.push(newInfo);
            }
            else {
                //aggge koi element nahi h push krne ko
                break;
            }


        }
        vector<int> ans;
        ans.push_back(ansStart);
        ans.push_back(ansEnd);
        return ans;

    }
};