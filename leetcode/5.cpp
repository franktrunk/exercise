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

class Solution02 {
private:
vector<int> candidates;
void dfs(int loc,int target,vector<int>& path,vector<vector<int>>& ans){
    if(target==0) {
        ans.push_back(path);
        return;
    }
    
    for(int i = loc;i<candidates.size();i++){
        if(target<candidates[i]) return ;
        path.push_back(candidates[i]);
        dfs(i,target-candidates[i],path,ans);
        path.pop_back();
    }
}
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        this->candidates = candidates;
        vector<vector<int>> ans;
        vector<int>path;
        dfs(0,target,path,ans);
        return ans;
    }
};

class Solution03 {
private:
    int n;
    void dfs(int left,int right,string& path,vector<string>& ans){
        if(left==n&&right==n){
            ans.push_back(path);
            return ;
        }
        if(left<right||left>n) return;
        path.push_back(')');
        dfs(left,right+1,path,ans);
        path.pop_back();
        path.push_back('(');
        dfs(left+1,right,path,ans);
        path.pop_back();
    }
public:
    vector<string> generateParenthesis(int n) {
      this->n = n;
      string path="";
      vector<string> ans;
      dfs(0,0,path,ans);
      return ans;
    }
};

class Solution04 {
    vector<vector<char>> board;
    string word;
    vector<int> dx = {0,0,-1,1};
    vector<int> dy = {1,-1,0,0};
    bool dfs(int x ,int y,int k){
        if(x<0||x>=board.size()||y<0||y>=board[0].size()||word[k]!=board[x][y]) 
        return false;
        if(k==word.size()-1)
        return true;
        bool flag = false;
        for(int i=0;i<4;i++){
            board[x][y] = 0;
            if( dfs(x+dx[i],y+dy[i],k+1))
            flag = true;
            board[x][y]=word[k];
        }
        return flag;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
           string path ="";
           this->board = board;
           this->word = word;
           for(int i =0;i<board.size();i++){
            for(int j =0 ;j<board[0].size();j++){
                if(dfs(i,j,0))
                return true;
            }
           }
           return false;
    }
};

class Solution05 {

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        vector<vector<int>>graph(numCourses);
        for(int i =0;i<prerequisites.size();i++){
            int cur = prerequisites[i][0];
            int pre = prerequisites[i][1];
            indegree[cur]++;
            graph[pre].push_back(cur);
        }
        queue<int> q;
        for(int i =0;i<numCourses;i++)
        if(indegree[i]==0)
        q.push(i);
        int taken =0;
        while(!q.empty()){
            int now = q.front();
            q.pop();
            for(int i =0;i<graph[now].size();i++){
                indegree[graph[now][i]]--;
                if(indegree[graph[now][i]]==0)
                q.push(graph[now][i]);
            }
            taken++;
        }
        return taken==numCourses;
    }

class Solution2 {
private: 
    bool dfs(int i,vector<int>& flag,vector<vector<int>>& graph){
        if(flag[i]==-1) return true;
        if(flag[i]==1) return false;
        flag[i] = 1;
        for(int j =0;j<graph[i].size();j++){
            if(!dfs(graph[i][j],flag,graph))
            return false;
        }
        flag[i] = -1;
        return true;
    }
public:
    bool canFinish2(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> flag(numCourses,0);
        vector<vector<int>> graph(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            int cur = prerequisites[i][0];
            int pre = prerequisites[i][1];
            graph[pre].push_back(cur);
        } 
        for(int i =0;i<numCourses;i++){
            if(flag[i]==0){
                if(!dfs(i,flag,graph))
                return false;
            }
        }
        return true;
    }
};
};

class Solution06 {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses,0);
        vector<vector<int>>graph(numCourses);
        vector<int> ans;
        queue<int> q;
        for(int i = 0;i<prerequisites.size();i++){
            int cur = prerequisites[i][0];
            int pre = prerequisites[i][1];
            indegree[cur]++;
            graph[pre].push_back(cur);
        }
        for(int i =0;i<numCourses;i++){
            if(indegree[i]==0)
            q.push(i);
        }
        int taken =0;
        while(!q.empty()){
            int now = q.front();
            q.pop();
            ans.push_back(now);
            taken ++;
            for(int i =0;i<graph[now].size();i++){
                indegree[graph[now][i]]--;
                if(indegree[graph[now][i]]==0)
                q.push(graph[now][i]);
            }
        }
        return taken==numCourses ? ans: vector<int>();
    }

class Solution {
private:
    vector<vector<int>> result;  // 存储所有合法的学习顺序
    vector<int> path;            // 当前正在构造的路径
    vector<int> indegree;        // 入度数组（作为成员变量，避免传参）
    vector<vector<int>> graph;   // 邻接表
    int numCourses;              // 课程总数

    // 回溯函数：尝试构造所有拓扑排序
    void backtrack() {
        // 如果已经选了所有课程，保存当前路径
        if (path.size() == numCourses) {
            result.push_back(path);
            return;
        }

        // 遍历所有课程，找当前入度为 0 的（可选的）
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                // 选择课程 i
                indegree[i] = -1;  // 标记为已访问（避免重复选）
                path.push_back(i);

                // 更新所有后继课程的入度（模拟“学完 i”）
                for (int next : graph[i]) {
                    indegree[next]--;
                }

                // 递归构造后续路径
                backtrack();

                // 回溯：恢复现场
                for (int next : graph[i]) {
                    indegree[next]++;
                }
                path.pop_back();
                indegree[i] = 0;  // 恢复原入度
            }
        }
    }

public:
    vector<vector<int>> findAllCourseOrders(int numCourses, vector<vector<int>>& prerequisites) {
        // 初始化成员变量
        this->numCourses = numCourses;
        this->indegree.assign(numCourses, 0);
        this->graph.assign(numCourses, vector<int>());

        // 建图
        for (auto& pre : prerequisites) {
            int cur = pre[0];
            int pre_course = pre[1];
            indegree[cur]++;
            graph[pre_course].push_back(cur);
        }

        // 清空结果
        result.clear();
        path.clear();

        // 开始回溯
        backtrack();

        return result;
    }
};

};

class Solution07 {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<bool>visited(n*n+1,false);
        visited[1] = true;
        queue<int> q;
        q.push(1);
        int step =0;
        while(!q.empty()){
            int size = q.size();
            for(int i =0 ;i<size;i++){
                int cur = q.front();
                q.pop();
                if(cur==n*n) return step;
                for(int next = cur+1; next<= min(cur+6,n*n);next++){
                    int row ,col;
                    int r = (next-1)/n;
                    int c = (next-1)%n;
                    if(r%2){
                        col= n-1-c;
                    }
                    else{
                        col =c;
                    }
                    row = n-1-r;
                    int final;
                    if(board[row][col]==-1){
                        final = next;
                    }
                    else{
                        final = board[row][col];
                    }
                    if(!visited[final]){
                        visited[final] = true;
                        q.push(final);
                    }
                }
            }


            step++;
        }

        return -1;
    }
};

class Solution08 {

public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        auto it = find(bank.begin(),bank.end(),endGene);
        if(it ==bank.end()) return -1;
        
        if(startGene == endGene) return 0;    
        it = find(bank.begin(),bank.end(),startGene);
        if(it!= bank.end()) bank.erase(it);
        it = find(bank.begin(),bank.end(),endGene);
        int loc = it -bank.begin()+1;
        int n = bank.size()+1;
        vector<bool> visited(n,false);
        vector<vector<int>> graph(n);
        for(int i =0;i<n-1;i++){
            int cnt =0;
           
            for(int j =0;j<8;j++){
                if(bank[i][j]!=startGene[j])
                cnt++;
            }
            if(cnt==1){
                graph[0].push_back(i+1);
                graph[i+1].push_back(0);
            }
        }
        for(int i =0;i<n-2;i++){
            int j;
            for( j =i+1;j<n-1;j++){
                int cnt =0;
                for(int k =0;k<8;k++){
                    if(bank[i][k]!=bank[j][k]){
                        cnt++;
                    }
                }
                if(cnt==1){
                    graph[i+1].push_back(j+1);
                    graph[j+1].push_back(i+1);
                }
            }
        }
        visited[0] = true;
        queue<int> q;
        q.push(0);
        int step =0;
        while(!q.empty()){
            int size = q.size();
            for(int i =0 ;i<size;i++){
                int now = q.front();
                q.pop();
                if(now ==loc) return step;
                for(int j=0;j<graph[now].size();j++){
                    if(!visited[graph[now][j]]){
                        visited[graph[now][j]]=true;
                        q.push(graph[now][j]);
                    }
                }
            }
            step++;
        }
        return -1;
    }
class Solution082 {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        // 1. 极端情况判断
        if (start.empty() || end.empty() || bank.empty()) {
            return -1; // 如果起点、终点或基因库为空，无法变异
        }

        // 检查目标基因是否在基因库中
        if (find(bank.begin(), bank.end(), end) == bank.end()) {
            return -1; // 不在 → 无法到达
        }

        // 2. BFS 初始化
        vector<int> visit(bank.size(), 0); // 标记 bank[i] 是否已被访问过（0=未访问，1=已访问）
        int step = 0;                      // 当前变异步数
        queue<string> q;                   // 队列：存储当前层的所有基因
        q.push(start);                     // 起点入队

        // 3. 开始 BFS（广度优先搜索）
        while (!q.empty()) {
            step++; // 每一层代表一次基因突变
            int n = q.size(); // 当前层有多少个基因要处理

            // 处理当前层的所有基因
            for (int i = 0; i < n; i++) {
                string temp = q.front(); // 取出队头基因
                q.pop();

                // 遍历整个基因库，找“只差一个字符”的基因
                for (int j = 0; j < bank.size(); j++) {
                    if (visit[j] == 1) continue; // 已经访问过，跳过

                    // 计算 temp 和 bank[j] 之间有多少个字符不同
                    int diff = 0;
                    for (int k = 0; k < temp.size(); k++) {
                        if (temp[k] != bank[j][k]) {
                            diff++;
                        }
                    }

                    // 如果只差一个字符，说明可以变异过去
                    if (diff == 1) {
                        // 如果这个基因就是目标基因 end
                        if (bank[j] == end) {
                            return step; // 找到了！返回当前步数
                        }

                        // 否则标记为已访问，并加入队列，等待下一轮变异
                        visit[j] = 1;
                        q.push(bank[j]);
                    }
                }
            }
        }

        // 如果 BFS 结束都没找到 end，说明无法到达
        return -1;
    }
};

};


  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
class Solution09 {
private:
    vector<int>nums;
    TreeNode* dfs(int left , int right ){
         if(left>right) return nullptr;
         int mid = left+ (right-left)/2;
         TreeNode* root = new TreeNode(nums[mid]);
         root->left = dfs(left,mid-1);
         root->right = dfs(mid+1,right);
         return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums){
        this->nums = nums;
        return dfs(0,nums.size()-1);      
    }
};


  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };


class Solution10 {
public:
    ListNode* sortList(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode* slow= head;
        ListNode* fast =head->next;
        while(fast&&fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* temp= slow->next;
        slow->next = nullptr;
        ListNode* left  = sortList(head);
        ListNode* right = sortList(temp);
        ListNode* dimmy = new ListNode(0);
        ListNode* cur = dimmy;
        cur->next = left;
        while(left && right){
            if(left->val<right->val){
                cur->next = left;
                left = left->next;
                cur = cur->next;
            }
            else{
                cur->next = right;
                right = right->next;
                cur = cur->next;
            }
        }
        cur->next = left ? left: right;
        return dimmy->next;
    }
};

class Solution11 {
public:
    int maxSubArray(vector<int>& nums) {
        int totalmax = nums[0];
        int currentmax =nums[0];
        for(int i =1;i<nums.size();i++){
            currentmax = max(currentmax+nums[i],nums[i]);
            totalmax = max(totalmax,currentmax);
        }
        return totalmax;
    }
};

class Solution12 {
private:
     int maxsub(vector<int> nums){
        int totalmax =nums[0];
        int currentmax = nums[0];
        for(int i =1;i<nums.size();i++){
            currentmax = max(currentmax+nums[i],nums[i]);
            totalmax = max(totalmax,currentmax);
        }
    return totalmax;
     }
    int minsub(vector<int> nums){
        int totalmin =nums[0];
        int currentmin = nums[0];
        for(int i = 1;i<nums.size();i++){
            currentmin = min(currentmin+nums[i],nums[i]);
            totalmin = min(currentmin,totalmin);
        }
        return totalmin;
    }

public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum =0;
        for(int i=0;i<nums.size();i++)
            sum += nums[i];
        int maxs = maxsub(nums);
        int mins = minsub(nums);
        if(mins == sum) return maxs;
        return max(maxs,sum-mins);
    }
};

class Solution13 {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left =0;
        int right =nums.size();
       
        while(left<right){
            int mid = left + (right-left)/2;
            if(nums[mid]<target){
                left = mid+1;
                
            }
            else{
                right = mid;
            }
        }
        return left;
    }
};






class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};


class Solution14 {
private:
    vector<vector<int>> grid;
    Node* dfs(int lx,int ly,int rx,int ry){
        bool flag = true;
        int start = grid[lx][ly];
        for(int i = lx;i<=rx;i++){
            for(int j = ly; j<=ry&&flag; j++){
                if(grid[i][j]!=start)
                flag = false;
            }
        }
        if(flag) return new Node(start==1,true);
        Node* root = new Node(start==1 , false);
        int dx = (rx-lx)/2;
        int dy = (ry-ly)/2;
        root->topLeft = dfs(lx,ly,lx+dx,ly+dy);
        root->topRight = dfs(lx,ly+dy+1,lx+dx,ry);
        root->bottomLeft = dfs(lx+dx+1,ly,rx,ly+dy);
        root ->bottomRight = dfs(lx+dx+1,ly+dy+1,rx,ry);
        return root;
    }
public:
    Node* construct(vector<vector<int>>& grid) {
        this->grid = grid;
        int n = grid.size();
        return dfs(0,0,n-1,n-1);
    }
};


class Solution15 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left =0;
        int m = matrix.size();
        int n = matrix[0].size();
        int right = m*n;
        while(left<right){
            int mid = (left+right)/2;
            int row = mid/n;
            int col = mid%n;
            if(matrix[row][col]<target){
                left = mid +1;
            }else{
                right = mid;
            }   
        }
        if(left>=m*n) return false;
        return  target == matrix[left/n][left%n];
    }
};

class Solution16 {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        while(left<right){
            int m = (left+right)/2;
            if(nums[m]<nums[m+1]){
                left = m+1;
            }else{
                right = m;
            }
        }
        return left;
    }
};

class Solution17 {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        while(left<=right){
            int mid = left +(right-left)/2;
            if(nums[mid] == target) return mid;
            if(nums[mid]>=nums[left]){
                if(nums[left]<=target&& nums[mid]>target){
                    right = mid-1;
                }
                else{
                    left = mid +1;
                }
            }
            else{
                if(nums[right]>=target && nums[mid]<target){
                    left = mid +1;
                }
                else 
                right = mid -1;
            }
        }
        return -1;
    }
};

class Solution18 {

private:
int lower_bound(vector<int>& nums, int target) {
    int left = -1;
    int right = nums.size();
    while(left+1<right){
        int mid = left +(right-left)/2;
        if(nums[mid]>=target){
            right = mid;
        }  else{
            left = mid;
        }
    }
    return right;
}
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = lower_bound(nums,target);
        if(start == nums.size()||nums[start]!=target)
        return {-1,-1};
        int end = lower_bound(nums,target+1)-1;
        return {start,end};
    }
};


class Solution19 {
public:
    int findMin(vector<int>& nums) {
        int left = -1;
        int right = nums.size()-1;
        while(left+1<right){
            int mid = left +(right-left)/2;
            (nums[mid] < nums.back()? right:left) = mid;
        }
        return nums[right];
    }
};

class Solution20 {
public:
    vector<int> plusOne(vector<int>& digits) {
        int cnt =1;
        for(int i = digits.size()-1;i>=0;i--){
            int temp = digits[i] +cnt;
            digits[i] = temp%10;
            cnt = temp/10;
        }
        if(cnt ==1)
        digits.insert(digits.begin(),1);
        return digits;
    }
};