//climbing stairs leetcode problem 70

class Solution {
public:
    int climbStairs(int n) 
    {
       vector<int> dp(n+1,0);
       dp[0]=1;
       dp[1]=1;

       for(int i=2;i<=n;i++)
       {
        dp[i]=dp[i-1]+dp[i-2];
       }
       return dp[n];
    }
};

//House robber leetcode problem 198

class Solution {
public:
    int house_rob(vector<int>& nums,int n,vector<int> &dp)
    {
        if(n<0)
          return 0;
        if(n==0)
        {
            return nums[0];
        }
        if(dp[n]!=-1)
           return dp[n];

        return dp[n]=max(house_rob(nums,n-2,dp)+nums[n],house_rob(nums,n-1,dp)+0);


    }
    int rob(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        int res= house_rob(nums,n-1,dp);
        return res;
    }

};