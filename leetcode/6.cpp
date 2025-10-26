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
    int climbStairs(int n) {
        vector<int> ans(n);
        if(n<2) return 1;
        ans[0]=1;
        ans[1]=2;
        for(int i =2;i<n;i++)
        ans[i]=ans[i-1]+ans[i-2];
        return ans[n-1];
    }
};

class Solution02 {
public:
    int rob(vector<int>& nums) {
       
        if(nums.size()==1) return nums[0];
         vector<int> ans(nums.size(),0);
         ans[0] = nums[0];
         ans[1] = max(nums[1],nums[0]);
         int total =0;
         for(int i =2;i<nums.size();i++){
            ans[i] = max(ans[i-1],ans[i-2]+nums[i]);
         }
         return ans.back();
    }
};

class Solution03 {
public:
    int trailingZeroes(int n) {
        
        int cnt =0;
        for(int i =5;i<=n;i+=5){
            int temp = i;
            while(temp%5==0){
                cnt++;
                temp = temp/5;
            }
        }
        return  cnt;
    }
};

class Solution04 {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        
        double x0 = static_cast<double>(x);
        double x1;
        
        while (true) {
            x1 = (x0 + x / x0) / 2.0;
            if (abs(x1 - x0) < 1e-6) {
                break;
            }
            x0 = x1;
        }
        
        return static_cast<int>(x1);
    }
};

class Solution05 {
public:
    double myPow(double x, int n) {
        if(x==0.0) return x;
        long long exp =n;
        if(n<0){
            x= 1/x;
            exp = -exp;
        }
        double res =1.0;
        while(exp){

            if(exp &1){
                res = res*x;
            }
            x= x*x;
            exp >>= 1;
        } 
        return res;
    }
};

class Solution06 {
private:
    int quickselect(vector<int>& nums,int k){
        int pivot = nums[rand()%nums.size()];
        vector<int> big,small,equal;
        for(int i =0;i<nums.size();i++){
            if(nums[i]>pivot)
            big.push_back(nums[i]);
            else if(nums[i]==pivot)
            equal.push_back(nums[i]);
            else
            small.push_back(nums[i]);
        }
        if(k<=big.size()) return quickselect(big,k);
        if(nums.size()-small.size()<k)
        return quickselect(small,k-nums.size()+small.size());
        return pivot;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickselect(nums,k);
    }
    class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> min_heap;
        for (int x : nums) {
            min_heap.push(x);
            if (min_heap.size() > k)
                min_heap.pop();
        }
        return min_heap.top();
    }
};
};

class Solution07 {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>q;
        for(int i =0;i<m;i++){
            q.emplace(nums1[i]+nums2[0],i,0);
        }
        vector<vector<int>>ans;
        while(k--){
            auto[_,i,j] = q.top();
            q.pop();
            ans.push_back({nums1[i],nums2[j]});
            if(j+1<n) q.emplace(nums1[i]+nums2[j+1],i,j+1);
        }
        return ans;
    }
};

class Solution08 {
public:
    string addBinary(string a, string b) {
        int len = a.length()-b.length();
        if(len<0){
            a.insert(0,-len,'0');
        }
        else if(len>0){
            b.insert(0,len,'0');
        }
        int carry =0;
        string ans(a.length(),'0');
        for(int i = a.length()-1;i>=0;i--){
            int sum = carry+ a[i]+b[i]-'0'-'0';
            ans[i]= sum%2+'0';
            carry = sum/2;
        }
        if(carry==1) ans.insert(ans.begin(),'1');
        return ans;
    }
};

class Solution09 {
public:
    int reverseBits(int n) {
        int now =0;
        for(int i =31;i>=0;i--){
            int temp = n&1;
            now = now<<1;
            now = now +temp;
            n = n>>1;
        }
        return now;
    }
};

class Solution10 {
public:
    int hammingWeight(int n) {
        int cnt =0;
        while(n){
            if(n&1) cnt++;
            n = n>>1;
        }
        return cnt;
    }
};

class Solution11 {
public:
    int singleNumber(vector<int>& nums) {
        int ans = nums[0];
        for(int i =1;i<nums.size();i++){
            ans =ans^nums[i];
        }
        return ans;
    }
};

class Solution12 {
public:
    int singleNumber(vector<int>& nums) {
        int count[32] = {0};
        for(int i=0;i<nums.size();i++){
            int n =nums[i];
            for(int j =31;j>=0;j--){
                if(n&1) count[j]++;
                n=n>>1;
            }
        }
        int x=1;
        int res =0;
        for(int i =31;i>=0;i--){
            if(count[i]%3) res +=x;
            x=x<<1; 
        }
        return res;
    }
};

class Solution13 {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shift = 0;
        while (left < right) {
            left >>= 1;
            right >>= 1;
            shift++;
        }
        return left << shift;
    }
};

class Solution14 {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
       int n = s.length();
       vector<bool>dp(n+1,false);
       unordered_set<string> wordset(wordDict.begin(),wordDict.end());
       dp[0] = true;
       for(int i =0;i<n;i++){
        if(!dp[i]) continue;
        for(int j = i+1;j<=n;j++){
            string sub = s.substr(i,j-i);
            if(wordset.find(sub)!=wordset.end()) dp[j]=true;
        }         
       } 
       return dp[n];
    }


class Solution {
private:
    bool back_trace(int start, string&s,vector<string>& wordDict,vector<optional<bool>>& memo ){
        int n = s.length();
        if(start == n) return true;
        if(memo[start].has_value()){
            return memo[start].value();
        }
        for(int i=0;i<wordDict.size();i++){
            string& word = wordDict[i];
            int len = word.length();
            if(start+len>n)  continue;
            if(s.compare(start,len,word)==0){
                if(back_trace(start+len,s,wordDict,memo)){
                    memo[start] = true;
                    return true;
                }
            }
        }
        memo[start] = false;
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
                int n = s.length();
        vector<optional<bool>> memo(n + 1);
        return back_trace(0, s, wordDict, memo); 
    }
};
};