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

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution01 {
public:
    void flatten(TreeNode* root) {
        mfunc(root);
        TreeNode* dimmy = new TreeNode(0);
        TreeNode* last =dimmy;
        while(!q.empty()){
            TreeNode* temp = q.front();
            last->right = temp;
            last->left = nullptr;
            last = temp;
            q.pop();
        }
    }
private:
   queue<TreeNode*>q;
   void mfunc(TreeNode* root){
        if(!root) return ;
        q.push(root);
        mfunc(root->left);
        mfunc(root->right);
   }
};


class Solution02 {
public:
    int countNodes(TreeNode* root) {

        if(!root) return 0;
        int left = countlevels(root->left);
        int right = countlevels(root->right);
        if(left == right) return countNodes(root->right) + (1<<left) ;
        else return countNodes(root->left) + (1<<right);
    }
private:
    int countlevels(TreeNode* root){
        int levels =0;
        while(root){
            root = root->left;
            levels++;
        }
        return levels;
    }
};

class BSTIterator03 {
private:
    stack<TreeNode*> mstack;
    
public:
    BSTIterator03( TreeNode* root) {
        while(root){
            mstack.push(root);
            root = root->left;
        }
    }
    
    int next() {
        TreeNode* temp=mstack.top();
        mstack.pop();
        int ans = temp->val;
        temp = temp->right;
        while(temp){
            mstack.push(temp);
            temp = temp->left;
        }
        return ans;
    }
    
    bool hasNext() {
        return !mstack.empty();
    }
};

class Solution04 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root||root==p||root==q) return root;
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        if(!left) return right;
        if(!right) return left;
        return root;
    }
};

class Solution05 {
private:
    void dfs(vector<vector<char>>& grid, int i , int j){
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size()||grid[i][j]=='0')
        return ;
        grid[i][j]='0';
        dfs(grid,i-1,j);
        dfs(grid,i+1,j);
        dfs(grid,i,j-1);
        dfs(grid,i,j+1);
    }    
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt =0;
        for(int i =0;i<m;i++){
            for(int j = 0;j <n ;j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j);
                    cnt++;
                }

            }
        }
        return cnt;
    }
};

class Solution06 {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return vector<vector<int>>({});
        vector<vector<int>> result;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> temp;
            for(int i =0;i<n;i++){
                TreeNode* node = q.front();
                temp.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right); 
                q.pop();
            }
            result.push_back(temp);
        }
        return result;
    }
};

class Solution07 {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return vector<int>();
        vector<int>result;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            int last =0;
            for(int i =0;i<n;i++){
                TreeNode* temp = q.front();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                q.pop();
                last = temp->val; 
            }
            result.push_back(last);
        }
        return result;
    }
};

class Solution08 {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        if(!root) return result;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            double sum =0.0;
            for(int i =0;i<n;i++){
                TreeNode* temp = q.front();
                q.pop();
                sum += temp->val;
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);                 
            }
            sum = sum/(1.0*n);
            result.push_back(sum);
        } 
        return result;
    }
};

class Solution09 {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return vector<vector<int>>({});
        vector<vector<int>>result;
        queue<TreeNode*>q;
        q.push(root);
        bool flag = true;
        while(!q.empty()){
            int n = q.size();
            vector<int> temp;
            for(int i =0;i<n;i++ ){
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(!flag)
            reverse(temp.begin(),temp.end());
            result.push_back(temp);
            flag = !flag;
        }
        return result;
    }
};

class Solution10 {
private: 
    int ans ;
    int pre;
    void inorder(TreeNode* root){
        if(!root) return ;
        if(root->left) inorder(root->left);
        if(ans>root->val-pre) ans = root->val - pre;
        pre = root->val;
        if(root->right) inorder(root->right);
        
    }
public:
    int getMinimumDifference(TreeNode* root) {
        ans = INT_MAX;
        pre = INT_MIN/2;
        inorder(root);
        return ans;
    }
};

class Solution11 {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*>s;
        vector<int> values;
        while(root){
            s.push(root);
            root=root->left;
        }
        while(!s.empty()){
            TreeNode*temp = s.top();
            s.pop();
            values.push_back(temp->val);
            if(values.size()==k) return values.back();
            if(temp->right){
                temp = temp->right;
                while(temp){
                    s.push(temp);
                    temp = temp->left;
                }
            }
        }
        return values[k-1];
    }
};

class Solution12 {
private:
    int pre;
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> values;
        while(root){
            s.push(root);
            root=root->left;
        }
        while(!s.empty()){
            TreeNode* temp = s.top();
            s.pop();
            values.push_back(temp->val);
            if(temp->right){
                temp = temp->right;
                while(temp){
                    s.push(temp);
                    temp = temp->left;
                }
            }
        }
        int n = values.size();
        if(n<2) return true;
        for(int i=0,j=1;j<n;i++,j++ ){
            if(values[j]<=values[i])
            return false;
        }
        return true;
    }

    bool isValidBST2(TreeNode* root) {
        if(!root) return true;
        bool fleft =isValidBST2(root->left);
        if(root->val<=pre) return false;
        pre = root->val;
        bool fright = isValidBST2(root->right);
        return fleft&&fright;
    }
    bool isValidBST3(TreeNode* root,  long left =LONG_MIN,long right = LONG_MAX) {
        if(!root) return true;
         long x = root->val;
        return x>left &&x<right &&isValidBST3(root->left,left,x)&&isValidBST3(root->right,x,right); 
    }


};

class Solution13 {
private:
    void bfs(int i , int j , vector<vector<bool>>& flag, vector<vector<char>>& board){
         queue<pair<int,int>>q;
         q.push({i,j});
         vector<int>dx ={0,0,-1,1};
         vector<int>dy ={1,-1,0,0};
         while(!q.empty()){
            auto[x,y] = q.front();
            q.pop();
            if(x>=0&&x<board.size()&&y>=0&&y<board[0].size()&&board[x][y]=='O'&&!flag[x][y]){
                flag[x][y]=true;
                for(int i =0;i<4;i++){
                    q.push({x+dx[i],y+dy[i]});
                }
            }
         }
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>>flag(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j =0;j<n;j++){
                if((i==0||i==m-1||j==0||j==n-1)&&board[i][j]=='O'&&!flag[i][j])
                bfs(i,j,flag,board);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!flag[i][j]) board[i][j]='X';
            }
        }
    }
};


class Node14 {
public:
    int val;
    vector<Node14*> neighbors;
    Node14() {
        val = 0;
        neighbors = vector<Node14*>();
    }
    Node14(int _val) {
        val = _val;
        neighbors = vector<Node14*>();
    }
    Node14(int _val, vector<Node14*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};



class Solution14 {
public:
    Node14* cloneGraph(Node14* node) {
        unordered_map<Node14*,Node14*> n2n;
        vector<Node14*> pre;
        queue<Node14*>q;
        if(!node) return node;
        q.push(node);
        while(!q.empty()){
            Node14* temp = q.front();
            q.pop();
            if(find(pre.begin(),pre.end(),temp)==pre.end())
            pre.push_back(temp);

            for(int i=0 ;i<temp->neighbors.size();i++ )
            if(find(pre.begin(),pre.end(),temp->neighbors[i])==pre.end())
            q.push(temp->neighbors[i]);
        }
        for(int i =0;i<pre.size();i++){
            Node14* newnode = new Node14(pre[i]->val);
            n2n[pre[i]]= newnode;
        }
        for(int i =0;i<pre.size();i++){
            Node14* temp = n2n[pre[i]];
            for(int j =0;j<pre[i]->neighbors.size();j++){
                Node14* newnei= n2n[pre[i]->neighbors[j]];
                temp->neighbors.push_back(newnei);
            }
        }
        return n2n[node];
    }

    unordered_map<Node14*, Node14*> lookup;
    Node14* dfs2(Node14* node){
        if(!node) return nullptr;
        if(lookup.find(node)!= lookup.end()) return lookup[node];
        Node14* clone = new Node14(node->val);
        lookup[node] = clone;
        for(int i=0;i<node->neighbors.size();i++){
            Node14* neibor = node->neighbors[i];
            clone->neighbors.push_back(dfs2(neibor));
        } 
        return clone;
    }
    
    Node14* cloneGraph2(Node14* node) {
        return dfs2(node);//(return bfs(node))
    }

};

class Solution15 {
private:
    unordered_map<string,vector<pair<string,double>>> graph;
    unordered_set<string> exists;
    double query(string a, string b){
        if(exists.find(a) == exists.end()||exists.find(b) == exists.end())
        return -1;
        if(a == b) return 1.0;

        queue<pair<string, double>> q;
        unordered_set<string> visited;
        q.push(make_pair(a,1.0));
        visited.insert(a);

        while(!q.empty()){
            string u =q.front().first;
            double x = q.front().second;
            q.pop();
            if(u==b){
                return x;
            }
            for(int i =0;i<graph[u].size();i++){
                string v = graph[u][i].first;
                double w = graph[u][i].second;
                if(visited.find(v)==visited.end()){
                    visited.insert(v);
                    q.push(make_pair(v,x*w));
                }
            }
        }
        return -1.0;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = values.size();
        for(int i =0;i<n;i++){
            string a = equations[i][0];
            string b = equations[i][1];
            double c = values[i];
            exists.insert(a);
            exists.insert(b);
            graph[a].push_back(make_pair(b,c));
            graph[b].push_back(make_pair(a,1.0/c));
        }
        vector<double> ans;
        for(int i =0;i<queries.size();i++){
            string a = queries[i][0];
            string b = queries[i][1];
            double result = query(a,b);
            ans.push_back(result);
        }
        return ans;
    }
};

class Trie16 {
private:
    bool isEnd;
    Trie16* next[26];
public:
    Trie16() {
        isEnd = false;
        memset(next,0,sizeof(next));
    }
    
    void insert(string word) {
        Trie16* node = this;
        for(int i =0; word[i];i++){
            char c = word[i];
            if(node->next[c-'a']==nullptr){
                node->next[c-'a'] = new Trie16();
            }
            node = node->next[c-'a'];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        Trie16* node = this;
        for(int i =0;word[i];i++){
            char c = word[i];
            if(node->next[c-'a'] ==nullptr) return false;
            node = node->next[c-'a'];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        Trie16* node =this;
        for(int i=0;prefix[i];i++){
            char c =  prefix[i];
            if(node->next[c-'a']==nullptr) return false;
            node = node->next[c-'a'];
        }
        return true;
    }
};

class WordDictionary17 {
private:
    bool isend;
    WordDictionary17* next[26];
    bool dfs(string& word,WordDictionary17* node, int start){
        if(!node) return false;
        if(start==word.length()) return node->isend;
        if(word[start]=='.'){
            for(int i=0;i<26;i++){
                if(node->next[i]){
                    if(dfs(word,node->next[i],start+1))
                    return true;
                }
            }
        }else{
           return  dfs(word,node->next[word[start]-'a'],start+1);
        }
        return false;
    }
public:
    WordDictionary17() {
        isend = false;
        memset(next,0,sizeof(next));
    }
    
    void addWord(string word) {
        WordDictionary17* node =this;
        int len = word.length();
        for(int i =0;i<len;i++){
            char c = word[i];
            if(!node->next[c-'a']){
                node->next[c-'a'] = new WordDictionary17();
            }
            node = node->next[c-'a'];
        }
        node->isend = true;
    }
    
    bool search(string word) {
        WordDictionary17* node = this;
        return dfs(word,node,0);
    }
};

class Solution18 {
private:
   string MAPPING[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
   void dfs(string digits,string& path,int loc,vector<string>& ans){
        if(loc == digits.length()) 
        {
            ans.push_back(path);
            return;
        }
        string temp = MAPPING[digits[loc]-'0'];
        for(int i =0;i<temp.length();i++){
            path[loc] = temp[i];
            dfs(digits,path,loc+1,ans); 
        }
     }
public:
    vector<string> letterCombinations(string digits) {
        int n = digits.length();
        if(!n) return {};
        string path(n,' ');
        vector<string>ans;
        dfs(digits,path,0,ans);
        return ans;
    }
};

class Solution19 {
private:
    void dfs(int n,int i,int k,vector<int>& path,vector<vector<int>>&ans){
        if(k==0)
        {
         ans.push_back(path);
         return ;
        }
        if(i>n) return ;
        if(k>n-i+1) return;
        dfs(n,i+1,k,path,ans);
        path.push_back(i);
        dfs(n,i+1,k-1,path,ans);
        path.pop_back();
    }
    void dfs2(int n,int start,int k,vector<int>& path,vector<vector<int>>&ans){
        if(k==0)
        {
         ans.push_back(path);
         return ;
        }
        for(int i= start;i<=n-k+1;i++ ){
            path.push_back(i);
            dfs2(n,i+1,k-1,path,ans);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> path;
        vector<vector<int>> ans;
        dfs(n,1,k,path,ans);
        return ans;
    }
};

class Solution20 {
private:
    vector<int> nums;
    void dfs(int n ,int k,vector<bool>&flag,vector<int>& path,vector<vector<int>>& ans){
        if(k==0){
            ans.push_back(path);
            return;
        }
        for(int i =0;i<n;i++){
            if(flag[i]){
                path.push_back(nums[i]);
                flag[i] = false;
                dfs(n,k-1,flag,path,ans);
                flag[i] = true;
                path.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        this->nums = nums;      
        int n =nums.size();
        vector<bool>flag(n,true);
        vector<vector<int>> ans;
        vector<int>path;    
        dfs(n,n,flag,path,ans);
        return ans;
    }
};