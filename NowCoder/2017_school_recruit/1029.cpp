#include <iostream>
#include <algorithm>

using namespace std;

/*
首先生成dp[n]的数组，dp[i]表示以arr[i]为最后一个元素的连续子数组和的最大值
dp[0] = arr[0]
当i>0
dp[i] = max(dp[n-1], 0) + arr[i]

测试用例
9
-1 -2 -3 -4 -5 -6 -7 -8 -9
*/
int main()
{
    int n;
    cin >> n;
    int arr[n];
    int dp[n];

    int i;
    for(i=0; i < n; i++)
        cin >> arr[i];
    //初始化
    dp[0] = arr[0];

    for(i=1; i < n; i++){
        dp[i] = max(dp[i-1], 0) + arr[i];
    }
    
    int _max = dp[0];
    for(i=1; i < n; i++)
        if(dp[i] > _max)
            _max = dp[i];
    cout << _max << endl;
    return 0;
}