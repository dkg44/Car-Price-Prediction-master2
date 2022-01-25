//https://leetcode.com/problems/super-egg-drop/description/

class Solution {
public:
    int dp[101][10001];

    int mcm(int eggs,int floor){

        if(floor == 1 or floor == 0) return floor;

        if(eggs == 1) return floor;

        if(dp[eggs][floor] != -1) return dp[eggs][floor];

        int mini = INT_MAX;

        int lowbound = 0,highbound = floor;

        int temp = 0;

        // using binary search

        while(highbound >= lowbound){

            int midbound = (highbound+lowbound)/2;

            int eggbreak = mcm(eggs-1,midbound-1);

            int eggnotbreak = mcm(eggs,floor-midbound);

            temp = 1 + max(eggbreak,eggnotbreak);

            if(eggbreak > eggnotbreak){

                highbound = midbound - 1;

            }

            else{

                lowbound = midbound + 1;

            }

            mini = min(mini,temp);

        }

        return dp[eggs][floor] = mini;

    }
    int superEggDrop(int k, int n) {
        memset(dp,-1,sizeof(dp));

        return mcm(k,n);
        
    }
};