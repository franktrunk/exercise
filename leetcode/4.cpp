# include<iostream>
# include<vector>
# include<unordered_map>
# include<algorithm>
# include<unordered_set>
# include<climits>
# include<stack> 
# include<queue>
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