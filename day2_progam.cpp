//The coin change problem leetcode 322

class Solution {
public:

    int solve(vector<int>&coins,int amount,vector<int> &dp)
    {
        dp[0]=0;

        for(int i=1;i<=amount;i++)
        {
            for(int j=0;j<coins.size();j++)
            {
                if(i-coins[j]>=0 && dp[i-coins[j]]!=100000)
                dp[i]=min(dp[i],1+dp[i-coins[j]]);
            }
        }

        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) 
    {

       vector<int> dp(amount+1,100000);
       int ans=solve(coins,amount,dp);
       if(ans!=100000)
       return ans;
       else
       return -1;
    }
};

//Longest increasing subsequence leetcode 300

class Solution {
public:
    int solve(vector<int> &nums,int curr,int prev,vector<vector<int>> &dp)
    {
        if(curr==nums.size())
         return 0;

        if(dp[curr][prev+1]!=-1)
        return dp[curr][prev+1];

        int take=0;
        if(prev==-1 || nums[curr]>nums[prev])
        take=1+solve(nums,curr+1,curr,dp);


        int not_take=0+solve(nums,curr+1,prev,dp);

        return dp[curr][prev+1]=max(take,not_take);
    }
    int lengthOfLIS(vector<int>& nums) 
    {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
       int ans=solve(nums,0,-1,dp);
       return ans;
        
    }
};
