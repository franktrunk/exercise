# include<iostream>
# include<vector>
# include<unordered_map>
# include<algorithm>
# include<unordered_set>
# include<climits>
# include<stack> 
# include<queue>
# include <cstring>
# include<optional>
using namespace std;

class Solution01 {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length();
        int n = s2.length();
        int len = s3.length();
        if(m+n!=len) return false;
        vector<vector<bool>>dp(m+1,vector<bool>(n+1,false));
        dp[0][0] = true;
        for(int i =0;i<=m;i++){
            for(int j=0;j<=n;j++){
                int pos = i+j-1;
                if(i>0)
                dp[i][j] = dp[i][j]||(dp[i-1][j]&&s1[i-1]==s3[pos]);
                if(j>0)
                dp[i][j] = dp[i][j]||(dp[i][j-1]&&s2[j-1]==s3[pos]);
            }
        }
        return dp[m][n];
    }
};


class Solution02 {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int  n= word2.length();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++)
        dp[i][0] = i;
        for(int j=1;j<=n;j++)
        dp[0][j] =j;

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = min({dp[i][j-1],dp[i-1][j],dp[i-1][j-1]})+1;
                }
            }
        }
        return dp[m][n];
    }
};

class Solution03 {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        int max = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1'){
                    if(i==0||j==0){
                        dp[i][j]=1;
                        if(max<1) max=1;
                    }
                    else{
                        dp[i][j] = min({dp[i-1][j-1],dp[i][j-1],dp[i-1][j]})+1;
                        if(dp[i][j]>max) max = dp[i][j];
                    }
                }
            }
         }
        
        return max*max;
    }
};