# include<iostream>
# include<vector>
# include<unordered_map>
# include<algorithm>
# include<unordered_set>
# include<climits>
# include<stack> 
using namespace std;

class Solution01 {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left =0,right=matrix[0].size()-1,top=0,base=matrix.size()-1;
        vector<int> result;
        while(true){
            for(int i =left;i<=right;i++) //left to right
            result.push_back(matrix[top][i]);
            if(++top>base) break;

            for(int i = top;i<=base;i++)
            result.push_back(matrix[i][right]);
            if(--right<left) break;

            for(int i = right;i>=left;i--)
            result.push_back(matrix[base][i]);
            if(--base<top)  break;

            for(int i =base;i>=top;i--)
            result.push_back(matrix[i][left]);
            if(++left>right) break;
        }
        return result;
    }
};

class Solution02 {
public:
    bool canConstruct(string ransomNote, string magazine) {
        bool flag =false;
        int n =ransomNote.length();
        int i;
        for( i =0;i<n && magazine.length()>0;i++){
            auto pos =magazine.find(ransomNote[i]);
            if(pos !=string::npos){
                magazine.erase(pos,1);
            }
            else{
                break;
            } 
        }
        if(i>=n) flag =true;
        return flag;
    }
};

class Solution03 {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> t2s,s2t;
        for(int i =0;s[i];i++){
            char a = s[i];
            char b =t[i];
            if((s2t.find(a)!=s2t.end()&&s2t[a]!=b)||(t2s.find(b)!=t2s.end()&&t2s[b]!=a)) 
            return false;

            s2t[a]=b;
            t2s[b]=a;
        }
        return true;
    }
};


class Solution04 {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int a[9][9] = {0};
        for(int i =0;i<9;i++){
            for(int j =0;j<9;j++){
                if(board[i][j]>='0'&&board[i][j]<='9'){
                    a[i][j]=board[i][j]-'0';
                }
            }
        }
        for(int i =0;i<9;i++){
            bool flag[10] = {false};
            for(int j =0;j<9;j++){
                if(a[i][j]!=0){
                    if(flag[a[i][j]]) return false;
                    else  flag[a[i][j]] = true;
                }
            }
        }

        for(int i =0;i<9;i++){
            bool flag[10] = {false};
            for(int j =0;j<9;j++){
                if(a[j][i]!=0){
                    if(flag[a[j][i]]) return false;
                    else  flag[a[j][i]] = true;
                }
            }
        }

        for(int up = 0; up<9;up +=3 ){
            for(int left =0 ; left<9;left+=3){
                bool flag[10] = {false};
                for(int i =up ;i<up+3;i++){
                    for(int j =left ;j<left+3; j++){
                        if(a[i][j] != 0){
                            if(flag[a[i][j]]) return false;
                            else flag[a[i][j]] = true;
                        }
                    }
                }
            }
        }
        return true;
    }
};

class Solution05 {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0;i<n/2;i++){
            for(int j =0 ;j<(n+1)/2;j++){
                int temp = matrix[i][j];
                
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-i-1] = temp;
            }
        }
    }
};

class Solution06 {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<bool> row(m, false);
        vector<bool> col(n, false);
        for(int i =0;i<m;i++){
            for(int j =0 ;j<n;j++){
                if(matrix[i][j]==0){
                    row[i]=true;
                    col[j]=true;
                }
            }
        }

        for(int i =0;i<m;i++){
            for(int j=0 ; j<n;j++ ){
                if(row[i]||col[j])
                matrix[i][j]=0;
            }
        }
    }
};

class Solution07 {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int colpos[8] = {-1,0,1,-1,1,-1,0,1};
        int rowpos[8] = {-1,-1,-1,0,0,1,1,1};
        vector<vector<int>> temp =board;
        int m = temp.size();
        int n = temp[0].size();
        for(int i =0;i<m;i++){
            for(int j =0 ; j<n;j++){
                if(temp[i][j]==0){
                    int cnt =0;
                    for(int k =0;k<8;k++){
                        int x= i+rowpos[k];
                        int y = j+ colpos[k];
                        if(x>=0&&x<m && y>=0 && y<n)
                            if(temp[x][y]==1) cnt ++;
                    }
                    if (cnt==3) board[i][j]=1;
                }
                else if(temp[i][j]==1){
                    int cnt =0;
                    for(int k =0;k<8;k++){
                        int x= i+rowpos[k];
                        int y = j+ colpos[k];
                        if(x>=0&&x<m && y>=0 && y<n)
                            if(temp[x][y]==1) cnt ++;
                    }
                    if(cnt<2||cnt>3) board[i][j]=0;
                }
            }
        }
    }
};

class Solution08 {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> strs;
        string temp= "";
        for(int i =0;s[i];i++){
            if(s[i]==' ') {
                strs.push_back(temp);
                temp = "" ;
                continue ;
            }
            temp += s[i];
        }
        strs.push_back(temp);
        if(pattern.length()!= strs.size()) return false;
        unordered_map<char,string> c2s;
        unordered_map<string,char> s2c;
     
        for(int i =0 ; pattern[i];i++){
            char c = pattern[i];
            string ss = strs[i];
            if((c2s.find(c)!=c2s.end() && c2s[c]!= ss)||(s2c.find(ss)!= s2c.end() && s2c[ss] != c))  
            return false;
            c2s[c] = ss;
            s2c[ss] = c;
        }
        return true;
    }

};

class Solution09 {
public:
    bool isAnagram(string s, string t) {
        int a[26] ={0};
        int b[26] = {0};
        int len = s.length();
        if(len != t.length()) return false;
        for(int i =0;i <len ;i++){
            int x = s[i] - 'a';
            int y = t[i] - 'a';
            a[x]++;
            b[y]++;
        }
        for(int i=0;i<26;i++){
            if(a[i]!=b[i]) return false;
        }
        return true;
    }
};

class Solution10 {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        string temp = "";
        unordered_map<string , int> groupindex;
        int n = strs.size();
        for(int i =0;i<n;i++){
            temp = strs[i];
            sort(temp.begin(),temp.end());
            if(groupindex.find(temp)!= groupindex.end()){
                int idx = groupindex[temp];
                result[idx].push_back(strs[i]);
            }
            else {
                groupindex[temp] = result.size();
                result.push_back({strs[i]});
            }
        }
        return result;
    }
};

class Solution11 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>ned2idx;
        int n = nums.size();
        for(int i =0;i<n;i++){
            if(ned2idx.find(nums[i])!=ned2idx.end()){
                return vector<int>{ned2idx[nums[i]],i};
            }
            else{
                ned2idx[target-nums[i]] =i;
            }
        }
        return vector<int>{0,0};
        
    }
};

class Solution12 {
public:
    int calcu_n(int n){
        int ans =0;
        while(n){
            int temp = n%10;
            ans += temp*temp;
            n /=10;
        }
        return ans;
    }
    bool isHappy(int n) {
        unordered_set<int> seen;
        while(n!=1&& seen.find(n)==seen.end()){
            seen.insert(n);
            n = calcu_n(n);
        }
        return n==1;
    }
};

class Solution13 {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int , int> lastidx;
        int n = nums.size();
        for(int i =0;i<n;i++){
            if(lastidx.find(nums[i])!= lastidx.end()){
                if(i-lastidx[nums[i]]<=k) return true;
                else lastidx[nums[i]] = i;
            }
            else{
                lastidx[nums[i]] = i;
            }
        }
        return false;
    }
};

class Solution14 {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans =0;
        unordered_set<int> s(nums.begin(),nums.end());
        for(auto it = s.begin();it!=s.end();it++){
            if(s.find(*it -1) != s.end()) continue;
            int x = *it +1;
            while(s.find(x)!=s.end()) x++;
            ans = max(ans,x-*it);
            if(2*ans> s.size()) break;
        }
        return ans;
    }
};

class Solution15 {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int now;
        int last=0;
        int n = nums.size();
        vector<string> result;
        if(n == 0) return result;
        for( now =1;now<n;now++){
            
            if((long)nums[now]-(long)nums[now-1]!=1){
                string temp = "";
                if(now-1==last) temp += to_string(nums[last]);
                else {
                   temp += to_string(nums[last]);
                   temp += "->";
                   temp += to_string(nums[now-1]);
                }
                result.push_back(temp);
                last = now;
            }
        }
        
                string temp = "";
                if(now-1==last) temp += to_string(nums[last]);
                else {
                   temp += to_string(nums[last]);
                   temp += "->";
                   temp += to_string(nums[now-1]);
                }
                result.push_back(temp);
                return result;
    
    }
};

class Solution16 {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
         sort (intervals.begin(), intervals.end());
         vector<vector<int>> result;
         int n = intervals.size();
         for(int i =0 ;i<n ;i++){
            if(result.empty()||intervals[i][0]>result.back()[1]){
                result.push_back(vector<int>{intervals[i][0],intervals[i][1]});
            }else{
                result.back()[1]=max(result.back()[1],intervals[i][1]);
            }
         }
         return result;
    }
};


class Solution17 {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int i =0;
        int len =intervals.size();
        while(i<len && intervals[i][1]<newInterval[0])
        {
            result.push_back(intervals[i]);
            i++;
        }

        while(i<len && intervals[i][0]<=newInterval[1]){
            newInterval[0] = min(newInterval[0],intervals[i][0]);
            newInterval[1] = max(newInterval[1],intervals[i][1]);
            i++;
        }
        result.push_back(newInterval);
        while(i<len) {
            result.push_back(intervals[i]);
            i++;
        }
        return result;
    }
};

class Solution18 {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int ans =0;
        sort(points.begin(),points.end(),[](const vector<int>& a , const vector<int>& b){
            return a[1] < b[1];
        });
        long long pre =LLONG_MIN;
        int n = points.size();
        for(int i=0 ; i<n; i++){
            if(points[i][0]<=pre) continue;
            ans ++;
            pre = points[i][1];
        }
        return ans;
    }
};

class Solution19 {
public:
    bool isValid(string s) {
        unordered_map<char, char> c2c{{'(',')'},{'{','}'},{'[',']'}};
        stack<char> mstack;
        for(int i=0;s[i];i++){
            if(c2c.find(s[i])!=c2c.end()){
                mstack.push(s[i]);
            }else{
                if(mstack.empty()) return false;
                else{
                    char temp = mstack.top();
                    if(s[i]!=c2c[temp]) return false;
                    mstack.pop();
                }
            }
        }
        return mstack.empty();
    }
};


class Solution20 {
public:
    string simplifyPath(string path) {
        vector<string>strs;
        int n = path.size();
        for(int i =0;i<n;i++){
            if(path[i]=='/') continue;
            int j;
            string temp ="";
            for(j = i;path[j]!='/'&&j<n;j++){
                temp += path[j];
            }
            if(temp=="."){}
            else if(temp ==".."){
                if(!strs.empty()) strs.pop_back();
            }
            else{
                strs.push_back(temp);
            }
            i = j;
        }
        string ans ="";
        for(int i =0;i<strs.size();i++)
        {
            ans +='/';
            ans += strs[i];
        }
        if(ans == "") ans +='/';
        return ans;
    }
};