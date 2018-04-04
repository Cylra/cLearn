/*给定数组arr，返回arr的最长递增子序列的长度，
比如arr=[2,1,5,3,6,4,8,9,7]，
最长递增子序列为[1,3,4,8,9]
返回其长度为5.
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

/*
首先生成dp[n]的数组，dp[i]表示以arr[i]这个数结束的情况下产生的最大递增子序列的长度。
对于第一个数来说，很明显dp[0]为1，对于i>0，
当我们计算dp[i]的时候，我们去考察i位置之前的所有位置，
找到i位置之前的最大的dp值，记为dp[j](0=<j<i),dp[j]代表以arr[j]结尾的最长递增子序列的长度，
而dp[j]又是之前计算过的最大的那个值，我们再来判断arr[i] 是否大于 arr[j],
如果大于，则递增子序列长度+1，dp[i] = dp[j]+1.
计算完dp之后，我们找出dp中的最大值，即为这个串的最长递增子序列。
*/
//dp[n]动态规划表
int dp[5] = {0};

int main()
{
    int arr[5] = {2,4,5,3,1};
    dp[0] = 1;
    int i, j;
    for(i=1; i < 5; i++){
        int _max = 0;
        for(j=0; j < i; j++){
            if(dp[j] > _max && arr[i] > arr[j]){
                _max = dp[j];
            }
        }
        dp[i] = _max + 1;
    }
    for(i=0; i<5; i++)
        cout << dp[i] << "  ";
    cout << endl;

    int maxlist = 0;
    for(i=0; i<5; i++)
        if(dp[i] > maxlist)
            maxlist = dp[i];
    cout << maxlist << endl;
    return 0;
}