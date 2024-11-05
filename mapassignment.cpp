string isSubset(int a1[], int a2[], int n, int m) {
 unordered_map<int,int>mp;
 string ans="yes";
 for(int i=0;i<n;i++){
     mp[a1[i]]++;
 }
 for(int i=0;i<m;i++){
     if(mp[a2[i]]>0){
  mp[a2[i]]--;
     }
     else{
         return "No";
     }
 }
 return "Yes";
 

 
 
}


  struct Node* makeUnion(struct Node* head1, struct Node* head2) {
        map<int,Node*>map;
        Node*curr=head1;
        while(curr){
            map[curr->data]=curr;
            curr=curr->next;
        }
        

        curr=head2;
    
         while(curr){
            map[curr->data]=curr;
            curr=curr->next;
        }
        
        Node*ans=NULL;
        curr=0;
        // iterate map and make final list
        for(auto it=map.begin();it!=map.end();it++){
            if(!ans){
                ans=it->second;
                curr=ans;
            }
            else{
                curr->next=it->second;
                curr=curr->next;
            }
        }
        curr->next=0;
       return ans;
        
    }