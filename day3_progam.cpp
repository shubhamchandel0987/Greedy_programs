//The maximal square problem leetcode 221

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        int rows=matrix.size();
        if(rows==0)
        return 0;

        int col=matrix[0].size();
        if(col==0)
        return 0;

        int large=0;
        vector<vector<int>> dp(rows+1,vector<int> (col+1,0));

        for(int i=1;i<=rows;i++)
        {
            for(int j=1;j<=col;j++)
            {
                if(matrix[i-1][j-1]=='1')
                {
                    int a=min(dp[i-1][j-1],dp[i-1][j]);
                    dp[i][j]=1+min(a,dp[i][j-1]);
                    if(large<dp[i][j])
                    {
                        large=dp[i][j];
                    }
                }
            }
        }
        return large*large;
    }
};

//Minimum path sum leetcode 64

 int minPathSum(vector<vector<int>>& grid) 
    {
        int rows=grid.size();
    
        if(rows==0)
          return 0;

        int col=grid[0].size();
    
        if(col==0)
          return 0;

        vector<vector<int>> dp(rows,vector<int> (col,0));
        dp[0][0]=grid[0][0];
        for(int i=1;i<col;i++)
        {
            dp[0][i]=dp[0][i-1]+grid[0][i];
        }
        for(int i=1;i<rows;i++)
        {
            dp[i][0]=dp[i-1][0]+grid[i][0];
        }

        for(int i=1;i<rows;i++)
        {
            for(int j=1;j<col;j++)
            {
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j];
            }
        }
        return dp[rows-1][col-1];
        

    }

//Triangle leetcode 120

int minimumTotal(vector<vector<int>>& triangle)
    {
        int n=triangle.size();
        vector<int> dp(n,0);
        
        for(int i=0;i<triangle.size();i++)
        {
            dp[i]=triangle[n-1][i];
        }

        for(int i=n-2;i>=0;i--)
        {
            for(int j=0;j<triangle[i].size();j++)
               dp[j]=min(dp[j],dp[j+1])+triangle[i][j];
        }
        return dp[0];
    }