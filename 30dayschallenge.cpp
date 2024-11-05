//1 Converrt 1 d into 2d array
   vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>>ans(m,vector<int>(n));
        if(m*n!=original.size()) return {};

        for(int i=0;i<original.size();i++){
            int row=i/n;
            int col=i%n;
           ans[row][col]=original[i];
            
        }
        return ans;
    }


/// 2 chalk 
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
     
        long long total = 0;
        for (int n : chalk) {
            total += n;
        }
        
 
        k %= total;
        
      
        for (int i = 0; i < chalk.size(); i++) {
            if (chalk[i] > k) {
                return i;  
            }
            k -= chalk[i];
        }
        
        return 0;  
    }
};



class Solution {
public:
    int getLucky(string s, int k) {
  
        string numStr = "";
        for (char c : s) {
            numStr += to_string(c - 'a' + 1);
        }

        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum = 0;
            for (char digit : numStr) {
                sum += digit - '0';
            }
            numStr = to_string(sum);  
        }
        
        return sum;
    }
};

