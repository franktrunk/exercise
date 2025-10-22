# include<iostream>
# include<vector>
# include<unordered_map>
# include<algorithm>
# include<unordered_set>
# include<climits>
# include<stack> 
# include<queue>
using namespace std;

class MinStack01 {
public:
    int min = INT_MAX;
    stack<int> mstack;
    MinStack01() {
    }
    void push(int val) {
        if(val<=min){
        mstack.push(min);
        min = val;
        }
        mstack.push(val);
    }
    
    void pop() {
        int temp = mstack.top();
        mstack.pop();
        if(temp == min){
            min = mstack.top();
            mstack.pop();
        }
    }
    int top() {
        return mstack.top();
    }
    
    int getMin() {
        return min;
    }
};

class Solution02 {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> mst;
        int n =tokens.size();
        for(int i =0;i<n;i++){
            if(tokens[i].length()==1){
                if(tokens[i][0]=='+'){
                    int r = mst.top();
                    mst.pop();
                    int l = mst.top();
                    mst.pop();
                    mst.push(l+r);
                }
                else if(tokens[i][0]=='-'){
                    int r = mst.top();
                    mst.pop();
                    int l = mst.top();
                    mst.pop();
                    mst.push(l-r);               
                }
                else if(tokens[i][0]=='*'){
                    int r = mst.top();
                    mst.pop();
                    int l = mst.top();
                    mst.pop();
                    mst.push(l*r);
                }
                else if(tokens[i][0]=='/'){
                    int r = mst.top();
                    mst.pop();
                    int l = mst.top();
                    mst.pop();
                    mst.push(l/r);
                }
                else{
                int temp = stoi(tokens[i]);
                mst.push(temp);           
                }

            }else{
                int temp = stoi(tokens[i]);
                mst.push(temp);
            }        
        }
        return mst.top();
    }
};


  struct ListNode03 {
      int val;
      ListNode03 *next;
      ListNode03(int x) : val(x), next(NULL) {}
  };

class Solution03 {
public:
    bool hasCycle(ListNode03 *head) {
        if(head==NULL||head->next==NULL) return false;
        ListNode03 *fast = head->next;
        ListNode03 *last = head;
        while(fast!=NULL&&fast->next!=NULL){
            if(fast == last) return true;
            last = last->next;
            fast = fast->next->next;
        }
        return false;
    }
};


  
  struct ListNode04 {
      int val;
      ListNode04 *next;
      ListNode04() : val(0), next(nullptr) {}
      ListNode04(int x) : val(x), next(nullptr) {}
      ListNode04(int x, ListNode04 *next) : val(x), next(next) {}
  };
 
class Solution04 {
public:
    ListNode04* addTwoNumbers(ListNode04* l1, ListNode04* l2) {
        ListNode04* pre =new ListNode04(0);
        ListNode04* cur = pre;
        int carry = 0;
        while(l1!=nullptr||l2!=nullptr){
            int x = l1 == nullptr ? 0 : l1->val;
            int y = l2 == nullptr ? 0 : l2->val;
            int sum = x + y +carry;
            carry = sum/10;
            sum = sum%10;
            cur->next = new ListNode04(sum);
            cur = cur->next;
            if(l1!= nullptr) l1 = l1->next;
            if(l2!= nullptr) l2 = l2->next;
        }
        if(carry==1) cur->next = new ListNode04(carry);
        return pre->next;
    }
};


  
  struct ListNode05 {
      int val;
      ListNode05 *next;
      ListNode05() : val(0), next(nullptr) {}
      ListNode05(int x) : val(x), next(nullptr) {}
      ListNode05(int x, ListNode05 *next) : val(x), next(next) {}
  };
 
class Solution05 {
public:
    ListNode05* mergeTwoLists(ListNode05* list1, ListNode05* list2) {
        ListNode05 * pre = new ListNode05(0);
        ListNode05 * cur = pre;
        while(list1!=nullptr && list2!=nullptr){
            if(list1->val<=list2->val){
                cur->next=list1;
                list1=list1->next;
                cur=cur->next;
            }else{
                cur->next = list2;
                list2 = list2 ->next;
                cur = cur->next;
            }
        }
        while(list1!=nullptr){
            cur->next = list1;
            list1=list1->next;
            cur= cur->next;
        }
        while(list2!=nullptr){
            cur ->next = list2;
            list2 = list2 ->next;
            cur = cur->next;
        }
        return pre->next;
    }
};



class Node06 {
public:
    int val;
    Node06* next;
    Node06* random;
    
    Node06(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution06 {
public:
    Node06* copyRandomList(Node06* head) {
        Node06* pre = new Node06(0);
        Node06* cur = pre;
        Node06* th = head;
        int cnt =0;
        while(th!=nullptr){
            cnt++;
            th=th->next;
        }
       
        vector<int> temp(cnt);
        th = head;
        int m =0;
        while(th!=nullptr){
            cur->next = new Node06(th->val);
            if(th->random==nullptr){
                 temp[m]=-1;
                 
            }
            else{
                Node06 * ftp = head;
                cnt =0;
                while(ftp!=th->random){
                    ftp=ftp->next;
                    cnt++;
                }
                temp[m]=cnt;
               
            }
            th = th->next;
            cur = cur->next;
            m++;
        }
        cur = pre->next;
     
        for(int i =0 ;i<temp.size();i++,cur=cur->next){
            if(temp[i]==-1){
                cur->random = nullptr;
            }else{
                Node06* ftp =pre->next;
                for(int j =0;j<temp[i];j++){
                    ftp = ftp->next;
                   
                }
                cur->random = ftp;
            }
        }

        return pre->next ;
    }
};



  struct ListNode07 {
      int val;
      ListNode07 *next;
      ListNode07() : val(0), next(nullptr) {}
      ListNode07(int x) : val(x), next(nullptr) {}
      ListNode07(int x, ListNode07 *next) : val(x), next(next) {}
  };
 
class Solution07 {
public:
    ListNode07* reverseBetween(ListNode07* head, int left, int right) {
        if(left == right) return head;
        ListNode07* dimmy = new ListNode07(0);
        dimmy->next = head;
        ListNode07 * p0 = dimmy;
        for(int i =0 ;i<left-1;i++) p0 = p0->next;
        ListNode07 * cur = p0->next;
        ListNode07 * pre = nullptr;
        for(int i =0 ; i<right-left+1 ; i++){
            ListNode07* tempnext = cur->next;
            cur->next = pre;
            pre =  cur;
            cur = tempnext;
        }
        p0->next->next=cur;
        p0 -> next = pre;
        return dimmy->next;
    }
};



struct ListNode08 {
      int val;
      ListNode08 *next;
      ListNode08() : val(0), next(nullptr) {}
      ListNode08(int x) : val(x), next(nullptr) {}
      ListNode08(int x, ListNode08 *next) : val(x), next(next) {}
  };
 
class Solution08 {
public:
    ListNode08* removeNthFromEnd(ListNode08* head, int n) {
        stack<ListNode08*>lstack;
        ListNode08* dimmy = new ListNode08(-1);
        dimmy->next = head;
        ListNode08 * cur =head;
        lstack.push(dimmy);
        while(cur!=nullptr){
            lstack.push(cur);
            cur = cur->next;
        }
        cur= lstack.top();
        ListNode08 * next = nullptr;
        for(int i =1;i<n;i++){
            next = cur;
            lstack.pop();
            cur = lstack.top();
        }
        lstack.pop();
        ListNode08 * pre = lstack.top();
        pre->next = next;
        delete(cur);
        return dimmy->next;
    }
};



  struct ListNode09 {
      int val;
     ListNode09 *next;
      ListNode09() : val(0), next(nullptr) {}
      ListNode09(int x) : val(x), next(nullptr) {}
      ListNode09(int x, ListNode09 *next) : val(x), next(next) {}
  };
 
class Solution09 {
public:
    ListNode09* deleteDuplicates(ListNode09* head) {
        ListNode09* dimmy = new ListNode09(0);
        dimmy->next = head;
        ListNode09* cur = dimmy;
        while(cur->next!=nullptr&&cur->next->next!=nullptr){
            int val = cur->next->val;
            if(val==cur->next->next->val){
                while(cur->next!=nullptr&&cur->next->val==val){
                    ListNode09* todel = cur->next;
                    cur->next = cur->next->next;
                    delete todel;
                }
            }else{
                cur=cur->next;
            }
        }
        return dimmy->next;
    }
};



 
  struct ListNode10 {
      int val;
      ListNode10 *next;
      ListNode10() : val(0), next(nullptr) {}
      ListNode10(int x) : val(x), next(nullptr) {}
      ListNode10(int x, ListNode10 *next) : val(x), next(next) {}
  };
 
class Solution10 {
public:
    ListNode10* rotateRight(ListNode10* head, int k) {
        if(head==nullptr||head->next==nullptr) return head;
        int cnt =0;
        ListNode10* cur = head;
        while(cur){
            cnt++;
            cur = cur->next;
        }
        k = k%cnt;
        cur = head;
        ListNode10* slow = head;
        for(int i =0;i<k;i++) cur=cur->next;
        while(cur->next){
            cur = cur->next;
            slow = slow->next;
        }
        cur->next = head;
        ListNode10* newhead = slow->next;
        slow->next = nullptr;
        return newhead;
    }
};


 
  struct ListNode11 {
      int val;
      ListNode11 *next;
      ListNode11() : val(0), next(nullptr) {}
      ListNode11(int x) : val(x), next(nullptr) {}
      ListNode11(int x, ListNode11 *next) : val(x), next(next) {}
  };
 
class Solution11 {
public:
    ListNode11* partition(ListNode11* head, int x) {
        ListNode11* dims = new ListNode11(0);
        ListNode11* dimb = new ListNode11(0);
        ListNode11* pres =dims;
        ListNode11* preb = dimb;
        ListNode11* cur = head;
        while(cur){
            if(cur->val < x){
                pres->next = cur;
                pres = cur;
            }
            else{
                preb->next =cur;
                preb = cur;
            }
            cur = cur->next;
        }
        pres->next = dimb->next;
        preb->next = nullptr;
        return dims->next;
    }
};

struct Node{
    int key ;
    int value ;
    Node* prev;
    Node* next;
    Node (int k, int v) : key(k), value(v),prev(nullptr),next(nullptr){}
};

class LRUCache12 {
private:
    int cap;
    unordered_map<int ,Node*> k2n;
    Node* head;
    Node* tail;

void add2front(Node* node){
    node->next = head;
    node->prev =nullptr;
    if(head!=nullptr){
        head->prev = node;
    }else{
        tail = node;
    }
    head = node;
}

void removeNode(Node* node){
    if(node->prev){
        node->prev->next=node->next;
    }else{
        head = node->next;
    }
    if(node->next){
        node->next->prev = node->prev;
    }else{
        tail = node->prev;
    }
}

void move2head(Node* node){
    removeNode(node);
    add2front(node);
}
public:
    LRUCache12(int capacity) {
        cap = capacity;
        head = nullptr;
        tail = nullptr;
    }
    
    int get(int key) {
        if(k2n.find(key)==k2n.end()) return -1;
        Node* node = k2n[key];
        move2head(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(k2n.find(key)!=k2n.end()){
            Node* node = k2n[key];
            node->value = value;
            move2head(node);
            return ;
        }
        Node* newnode = new Node(key,value);
        if(k2n.size()>=cap ){
            Node* last = tail;
            int tk = last->key;
            k2n.erase(tk);
            removeNode(last);
            delete last;
        }
        k2n[key] = newnode;
        add2front(newnode);
    }

    ~LRUCache12(){
        while(head){
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};


 
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution13 {
public:
    int maxDepth(TreeNode* root) {
        if(root ==nullptr) return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return max(left,right) +1;
    }
};

class Solution14 {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p&&!q) return true;
        if(!p||!q) return false;
        queue<TreeNode*>q1,q2;
        q1.push(p);
        q2.push(q);
        while(!q1.empty()&&!q2.empty()){
            TreeNode* node1= q1.front();
            TreeNode* node2 = q2.front();
            if(!node1 && !node2){ 
                q1.pop();
                q2.pop();
                continue;
            }
            if(!node1||!node2||node1->val!=node2->val) return false;
            q1.pop();
            q1.push(node1->left);
            q1.push(node1->right);
            q2.pop();
            q2.push(node2->left);
            q2.push(node2->right);
        }

        return q1.empty()&&q2.empty();
    }

};

class Solution15 {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return root;
        swap(root->left,root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};


class Solution16 {
public:
    bool isSymmetric(TreeNode* root) {
        if(root->left==nullptr&&root->right==nullptr) return true;
        if(!root->left||!root->right||root->left->val!=root->right->val) return false;
        queue<TreeNode*> ql,qr;
        ql.push(root->left);
        qr.push(root->right);
        while(!ql.empty()&&!qr.empty()){
            TreeNode* nodel = ql.front();
            TreeNode* noder = qr.front();
            if(!nodel&&!noder){
                ql.pop();
                qr.pop();
                continue; ;
            }
            if(!nodel||!noder||nodel->val!=noder->val) return false;
            ql.pop();
            ql.push(nodel->left);
            ql.push(nodel->right);
            qr.pop();
            qr.push(noder->right);
            qr.push(noder->left);
        }
        return ql.empty()&&qr.empty();
    }
};

class Solution17 {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->preorder = preorder;
        for(int i =0;i<inorder.size();i++) dic[inorder[i]] = i;
        return recur(0,0,inorder.size()-1);
    }

private:
    vector<int> preorder;
    unordered_map<int,int> dic;
    TreeNode* recur(int root, int left, int right){
        if(left > right) return nullptr;
        TreeNode* node = new TreeNode(preorder[root]);
        int i = dic[preorder[root]];
        node->left = recur(root+1,left,i-1);
        node->right = recur(root+i-left+1,i+1,right);
        return node;
    }

};

class Solution18 {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr ) return false;
        if(root->left==nullptr && root->right==nullptr && root->val == targetSum) 
        return true;
        return hasPathSum(root->left,targetSum-root->val)||hasPathSum(root->right,targetSum-root->val);
    }
};

class Solution19 {
public:
    int sumNumbers(TreeNode* root) {
        return mfunc(root,0);
    }
private:
    int mfunc(TreeNode* root , int x){
        if(root==nullptr) return 0;
        x = x*10 +root->val;
        if(!root->left && !root->right) return x;
        return mfunc(root->right,x)+mfunc(root->left,x);
    }
};

class Node20 {
public:
    int val;
    Node20* left;
    Node20* right;
    Node20* next;

    Node20() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node20(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node20(int _val, Node20* _left, Node20* _right, Node20* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution20 {
public:
    Node20* connect(Node20* root) {
        Node20* dimmy = new Node20(0);
        queue<Node20*> q;
        vector<int>nums;
        if(!root) return root;
        q.push(root);
        nums.push_back(1);
        int level =0;
        while(!q.empty()){
            int cnt = 0;
            Node20* last =dimmy;
            for(int i=0;i<nums[level];i++){
                Node20* temp = q.front();
                last->next = temp;
                last = temp;
                q.pop();
                if(temp->left){
                    cnt++;
                    q.push(temp->left);
                }
                if(temp->right){
                    cnt++;
                    q.push(temp->right);
                }
            }
            nums.push_back(cnt);
            level++;
        }
        return root;
    }
};

class Solution21 {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        this->postorder = postorder;
        for(int i =0;i<postorder.size();i++) dic[inorder[i]] = i;
        return recur(postorder.size()-1,0,inorder.size()-1);
    }

private:
    vector<int> postorder;
    unordered_map<int,int> dic;
    TreeNode * recur(int root , int left , int right){
        if(left>right) return nullptr;
        TreeNode* node = new TreeNode(postorder[root]);
        int i = dic[postorder[root]];
        node->right = recur(root-1,i+1,right);
        node->left  = recur( root-1-right+i, left,i-1);
        return node;
    }
};