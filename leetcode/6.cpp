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