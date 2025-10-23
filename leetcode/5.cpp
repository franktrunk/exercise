# include<iostream>
# include<vector>
# include<unordered_map>
# include<algorithm>
# include<unordered_set>
# include<climits>
# include<stack> 
# include<queue>
# include <cstring>
using namespace std;

class Solution01 {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        string s =to_string(x);
        for(int i =0,j=s.length()-1;i<j;i++,j--){
            if(s[i]!=s[j]) return false;
        }
        return true;
    }
};