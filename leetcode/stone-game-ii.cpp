/*************************************************************************
	> File Name: stone-game-ii.cpp
	> Author:henuzxy 
	> Mail: 
	> Created Time: Mon 29 Jul 2019 02:20:48 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<cstring>
#include<algorithm>
using namespace std;

class Solution{
public:
    int dp[110][110];
    int sum[110];
    int stoneGameII(vector<int> & piles){
        memset(dp,0,sizeof(dp));
        memset(sum,0,sizeof(sum));
        int N = piles.size();
        for(int i=N-1;i>=0;--i)
            sum[i] = sum[i+1] + piles[i];

        for(int i=N-1;i>=0;--i){
            for(int j=1;j<=N;++j){
                for(int k=1;k<=2*j && i+k <= N;++k){
                    dp[i][j] = max(dp[i][j],sum[i]-dp[i+k][max(j,k)]);
                }
            }
        }
        for(int i=0;i<N;++i){
            for(int j=1;j<=N;++j){
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return dp[0][1];
    }
};
int main(int argc,char* argv[]){
    Solution s;
    vector<int> vec{2,7,9,4,4};
    cout << s.stoneGameII(vec) << endl;
    return 0;
}
