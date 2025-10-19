# include<iostream>
# include<vector>
# include<unordered_map>
# include<algorithm>
using namespace std;

class Solution01 {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans =0;
        for(int i =1;i<n;i++){
            if(prices[i]>prices[i-1])
            ans+=prices[i]-prices[i-1];
        }
        return ans;
    }
};

class Solution02 {
public:
    bool canJump(vector<int>& nums) {
        int n =nums.size();
        int rightmax = 0;
        for(int i =0 ;i<n-1;i++)
        {
            if(i>rightmax)
            return false;
            rightmax=max(rightmax,i+nums[i]);
        }
        return rightmax>=n-1;
    }
};

class Solution03 {
public:
    int jump(vector<int>& nums) {
        int end =0,jump=0,maxright =0 ;
        int n =nums.size();
        for(int i =0;i<n-1;i++){
           maxright = max(maxright,i+nums[i]);
           if(i==end){
            jump++;
            end = maxright;
           }
        }
        return jump;
    }
};

class Solution04 {
public:
    int hIndex(vector<int>& citations) {
        int ref[1001] = {0};
        int n = citations.size();
        for(int i =0;i<n;i++)
        ref[citations[i]]++;
        int sum =0;
        for(int i =1000;i>=0;i--)
        { 
            sum += ref[i];
            if(sum>=i)
            return i;
        }
        return 0;
    }
};

class RandomizedSet05 {
public:
    unordered_map<int,int> m;
    vector<int> v;
    RandomizedSet05() {
        
    }
    
    bool insert(int val) {
        if(m.find(val)!=m.end())
        return false;
        m[val]=v.size();
        v.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(m.find(val)==m.end())
        return false;
       int  last=v.back();
       int  idexdel=m[val];
        swap(v[v.size()-1],v[idexdel]);
        m[last] = idexdel;
        m.erase(val);
        v.pop_back();
        return true;
    }
    
    int getRandom() {
        return v[rand() % v.size()];
    }
};

class Solution06 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int pre[100005];
        int last[100005];
        int n = nums.size();
        pre[0]=1;
        last[n-1]=1;
        for(int i=1;i<n;i++)
        pre[i]=pre[i-1]*nums[i-1];
        for(int i =n-2;i>=0;i--)
        last[i]=last[i+1]*nums[i+1];
        vector<int> ans;
        for(int i=0;i<n;i++)
        ans.push_back(pre[i]*last[i]);
        return ans;
    }
};

class Solution07 {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int a[100005]={0};
        a[0]=gas[0]-cost[0];
        int minidex=0;
        int min =a[0];
        for(int i =1;i<n;i++ ){
            a[i]=a[i-1]+gas[i]-cost[i];
            if(a[i]<min){
                min = a[i];
                minidex =i;
            }
        }
        minidex=(minidex+1)%n;
        int sum =0;
        for(int i =0,j=minidex;i<n;i++,j=(j+1)%n){
            sum += gas[j]-cost[j];         
            if(sum<0)
            return -1;
        }   
        return minidex;
    }
};

class Solution08 {
public:
    unordered_map<char,int> m ={
        {'I',1},
        {'V',5},
        {'X',10},
        {'L',50},
        {'C',100},
        {'D',500},
        {'M',1000}
    };
    int romanToInt(string s) {
        int ans =0;
        int n = s.length();
        for(int i =0;i<n;i++){
            int value = m[s[i]];
            if(i<n-1&&value<m[s[i+1]])
            ans -= value;
            else 
            ans += value;
        }
        return ans;
        
    }
};

class Solution09 {
public:

    string intToRoman(int num) {
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string result = "";
    string romans[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    for(int i=0;i<13;i++){
        while(num>=values[i]){
            num -= values[i];
            result += romans[i];
        }
    }
    return result;
   }
};

class Solution10 {
public:
    int lengthOfLastWord(string s) {
        int n =0;
        int len = s.length();
        int begin;
        for(begin=len-1;s[begin]==' '&&begin>=0;begin--);
        if(begin<0)
        return 0;
        for(int i = begin;i>=0&&s[i]!=' ';i--)
        n++;
        return n;
    }
};

class Solution11 {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n==1)
        return strs[0];

        for(int i =0;i<n;i++){
            if(!strs[i][0])
            return "";
        }
        string result ="";
        int len = strs[0].length();
        for(int i=0;i<len;i++){
            bool flag =false;
            for(int j=1;j<n;j++){
                if(strs[j][i]!=strs[0][i])
                {
                    flag =true;
                    break;
                }
            }
            if(flag)
            break;
            else 
            result+=strs[0][i];
        }
        return result;
    }
};

class Solution12 {
public:
    string reverseWords(string s) {
        vector<string> strs;
        int n = s.length();
        for(int i = 0;i<n;){
            if(s[i]==' ')
            {
                i++;    
                continue;
            }

            int j =0;
            int len =0;
            string temp ="";
            for(j=i;s[j]&&s[j]!=' ';j++){
                temp += s[j];
                len++;
            }
            strs.push_back(temp);
            i += len;
        }
        int size = strs.size();
        string result= "";
        for(int i =size-1;i>=0;i--){
            result += strs.back();
            strs.pop_back();
            if(i!=0)
            result += ' ';
        }
        return result;
    }
};

class Solution14 {
public:
    bool isSubsequence(string s, string t) {
        if(s=="")
        return true;

        int len1 = s.length();
        int len2 = t.length();
        if(len1>len2)
        return false;
        bool flag =true;
        int j =0;
        for(int i = 0;i<len1;i++){
            for(;t[j]!=s[i]&&t[j];j++);
            if(j>=len2)
            {
            flag =false;
            break;
            }
            j++;
        }
        return flag;
    }
};

class Solution15 {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size()-1;
        while(i<j){
            if(numbers[i]+numbers[j]>target)
            j--;
            else if(numbers[i]+numbers[j]<target)
            i++;
            else return vector<int>{i+1,j+1};
        }
        return vector<int>{-1,-1};
    }
};

class Solution16 {
public:
    int maxArea(vector<int>& height) {
        int i =0;
        int j = height.size()-1;
        int maxv = min(height[i],height[j])*(j-i);
        while(i<j){
            if(height[i]<height[j]) i++;
            else j--;
            maxv = max(maxv,min(height[i],height[j])*(j-i));
        }
        return maxv;
    }
};

class Solution17 {
public:
    string convert(string s, int numRows) {
        if(numRows < 2)
        return s;
        vector<string> rows(numRows);
        int flag = -1;
        int n=0;
        for(int i =0;s[i];i++){
            if(n==0||n==numRows-1)
            flag = -flag;
            rows[n] += s[i];
            n += flag;
        }
        string result = "";
        for(int i =0;i<numRows;i++)
        result +=rows[i];
        return result;
    }
};

class Solution18 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> result;
        for(int i =0;i<n-2;i++){
           if(i>0&&nums[i-1]==nums[i]) continue;
           int j = i+1;
           int k = n-1;
           while(j<k){
            int v1 =nums[i];
            int v2 = nums[j];
            int v3 = nums[k];
            int sum = v1+v2+v3;
            if(sum ==0){
                result.push_back(vector<int>{v1,v2,v3});
                while(j<n-1 && nums[j]==v2) j++;
                while(k>1 && nums[k]==v3) k--;
            }
            else if(sum <0){
                while(j<n-1 && nums[j]==v2) j++;
            }
            else {
                while(k>1 && nums[k]==v3) k--;
            }
           }
        }
        return result;
    }
};

class Solution19 {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n =nums.size();
        int sum =0;
        for(int i =0;i<n;i++) sum += nums[i];
        if(sum<target)
        return 0;
        int ans = n;
        sum =0;
        for(int i =0,j=0;j<n;j++){
            sum +=nums[j];
            if(sum<target) continue;
            ans = min(ans,j-i+1);
            while(sum>=target&&i<=j){
                sum -= nums[i];
                ans = min(ans,j-i+1);
                i++;
            }
        }
        return ans;
    }
};

class Solution20 {
public:
    int lengthOfLongestSubstring(string s) {
        int n =s.length();
        if(n == 0) return 0;
        unordered_map<char,int> charidex;
        int lenmax =0;
        int left =0;
        for(int i =0 ;i<n;i++){
            char current = s[i];
            if(charidex.find(current)!=charidex.end()&&left<=charidex[current])
            left = charidex[current]+1;
            charidex[current] = i;
            lenmax=max(lenmax,i-left+1);
        }
        return lenmax;
    }
};