#include <iostream>
#include<queue>
using namespace std;

void solveForMedian(double &median, priority_queue<int> &maxi, priority_queue<int,vector<int>, greater<int> > &mini, int element) {

	
	if(maxi.size() == mini.size()) {
		if(element > median) {
			mini.push(element);
			median = mini.top();
		}
		else {
			maxi.push(element);
			median = maxi.top();
		}
	}
	else if(maxi.size() == mini.size()+1) {
		if(element > median) {
			mini.push(element);
		}
		else {
			int maxTop = maxi.top();
			maxi.pop();
			mini.push(maxTop)
			maxi.push(element);
		}
		median = (mini.top() + maxi.top())/2.0;
	}
	else if(mini.size() == maxi.size()+1) {
		if(element > median) {
			int minTop = mini.top();
			mini.pop();
			maxi.push(minTop);
			mini.push(element);
		}
		else {
			maxi.push(element);
		}
		median = (mini.top() + maxi.top())/2.0;
	}
}

int main() {

	int arr[] = {12,10,8,4,2,3,15};
	int n = 7;

	//12 -> 12
	//10 12 -> 11
	//8 10 12 -> 10
	//4 8 10 12 -> 9
	//2 4 8 10 12 -> 8
	//2 3 4 8 10 12 0 -> 6
	//2 3 4 8 10 12 15 -> 8

	double median  = 0;
	priority_queue<int> maxi;
	
	priority_queue<int,vector<int>, greater<int> > mini;
	
	for(int i=0; i<n; i++) {
		int element = arr[i];
		solveForMedian(median, maxi, mini, element);
		cout << "Median found: " << median << endl;
	}



	return 0;
}


//Remove Stones to Minimize the Total- max heap m s n-n/2 remove karte rhoo
int minstonesum(vector<int>&piles,int k){
    priority_queue<int>maxheap;
    for(int i=0;i<piles.size();i++){
        maxheap.push(piles[i]);
    }
    
    while(k--){
        int maxtop=maxheap.top();
        maxheap.pop();
        maxtop=maxtop-(maxtop/2);
        maxheap.push(maxtop);
    }
    
    int sum=0;
    while(!maxheap.empty()){
        int maxtop=maxheap.top();
        sum+=maxtop;
        maxheap.pop();
    }
    return sum;
}

int main(){
    vector<int>piles={4,3,6,7};
    int k=3;
    int ans=minstonesum(piles,k);
    cout<<ans;
}

//  Reorganize String
class info{
    public:
    char val;
    int count;

info(char ch,int b){
    this->val=ch;
    this->count=b;
}
};
class compare{
    public:
    bool operator()(info a,info b){
        return a.count<b.count;
    }
};
class Solution {
public:
    string reorganizeString(string s) {
        int freq[26]={0};
        for(int i=0;i<s.length();i++){
         char ch=s[i];
         freq[ch-'a']++;
        }

        // push all character in max heap
         priority_queue<info,vector<info>,compare>maxheap;
         for(int i=0;i<26;i++){
            if(freq[i]>0){
                info temp(i+'a',freq[i]);
                maxheap.push(temp);
            }
         }

         string ans="";
         while(maxheap.size()>1){
            info first=maxheap.top();
            maxheap.pop();
            info second=maxheap.top();
            maxheap.pop();
            ans.push_back(first.val);
            first.count--;
            ans.push_back(second.val);
            second.count--;

            if(first.count>0){
                maxheap.push(first);
            }
            if(second.count>0){
                maxheap.push(second);
            }
         }
            // only for one 
            if(maxheap.size()==1){
                info first=maxheap.top();
                maxheap.pop();

                ans.push_back(first.val);
                first.count--;

                if(first.count!=0){
                    return "";
                }
            }

         return ans;
    }
};

// longest happy string
class info{
    public:
    char val;
    int count;

info(char ch,int b){
    this->val=ch;
    this->count=b;
}
};
class compare{
    public:
    bool operator()(info a,info b){
        return a.count<b.count;
    }
};

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
            priority_queue<info,vector<info>,compare>maxheap;
            if(a>0){
                info temp('a',a);
                maxheap.push(temp);
            }

            if(b>0){
                info temp('b',b);
                maxheap.push(temp);
            }
            if(c>0){
                info temp('c',c);
                maxheap.push(temp);
            }

            string ans="";
            while(maxheap.size()>1){
                  info first=maxheap.top();
            maxheap.pop();
            info second=maxheap.top();
            maxheap.pop();
            if(first.count>=2){
                ans.push_back(first.val);
                ans.push_back(first.val);
                first.count-=2;
            }
            else{
                ans.push_back(first.val);
                first.count--;
            }

             if(second.count>=2 && second.count>=first.count){
                ans.push_back(second.val);
                ans.push_back(second.val);
                second.count-=2;
            }
            else{
                ans.push_back(second.val);
                second.count--;
            }

            if(first.count>0){
                maxheap.push(first);
            }

            if(second.count>0){
                maxheap.push(second);
            }

            
            }
            if(maxheap.size()==1){
                info first=maxheap.top();
                if(first.count>=2){
                ans.push_back(first.val);
                ans.push_back(first.val);
                first.count--;
                }
                else{
                   ans.push_back(first.val);
                first.count--;
                }
            }
            return ans;
    }
};
