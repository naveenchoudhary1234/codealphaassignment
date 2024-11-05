#include <iostream>
#include<vector>
using namespace std;

// diagonal tree traversal
// appraoch- hm na jb jb bhi left m jayenge +1 krte rhnege 
// right ki ide m jayenge kuch ni krnhe 
// sab ki numbering ho jayegii
// to hm pehle 0 vali line ko print krdenege phir 1 vali phir 2 vali
// hm isme map use krenge whivh is pehle s hi sorted rhti hain vo key pair 

// second approach
// hm level order ki trh hi push krte rhenge
// hm bs righ vale element print rkate rhehe
// left valo ko q m push krte rhenge

vector<int>diagonal(Node*root){
    vector<int>ans;
    if(!root) return ans;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node*temp=q.front();
        q.pop();
        while(temp){
            ans.push_back(temp->data);
            if(temp->left){
                q.push(temp->left);
            }
            temp=temp->right;
        }
    }
    return ans;
}

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        queue<pair<TreeNode*, pair<int, int>>> q; // node, {row, col}
        q.push({root, {0, 0}});
        map<int, map<int, multiset<int>>> mp; // col

        while (!q.empty()) {
            auto front = q.front();
            q.pop();

            TreeNode*& node = front.first;
            auto coordinate = front.second;
            int& row = coordinate.first;
            int& col = coordinate.second;

            mp[col][row].insert(node->val);

            if (node->left) {
                q.push({node->left, {row + 1, col - 1}});
            }
            if (node->right) {
                q.push({node->right, {row + 1, col + 1}});
            }
        }

        for (auto it : mp) {
            auto& colmap = it.second;
            vector<int> vline;
            for (auto colmapit : colmap) {
                auto& mset = colmapit.second;
                vline.insert(vline.end(), mset.begin(), mset.end());
            }
            ans.push_back(vline);
        }
        return ans;
    }
};