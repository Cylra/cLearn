/*见网页
(https://blog.csdn.net/uestclr/article/details/50760563)
有n级台阶，一个人每次上一级或者两级，问有多少种走完n级台阶的方法。
*/
#include <iostream>
#include <cstring>

using namespace std;

/*f(n)表示走上n级台阶的方法数
f(1) = 1
f(2) = 2
n > 3
f(n) = f(n-1) + f(n-2)
dp[n]表示动态规划表,dp[i], 0<i<=n,
表示到达i级台阶的方法数
*/
//dp是全局数组,大小为n,全部初始化为0,是题目中的动态规划表
int *dp;
int fun(int n)
{
    if(1 == n || 2 == n){
        return n;
    }
    //判断n-1和n-2有没有被计算过
    if(!dp[n-1]){
        dp[n-1] = fun(n-1);
    }
    if(!dp[n-2]){
        dp[n-2] = fun(n-2);
    }
    return dp[n-1]+dp[n-2];
}

int main()
{
    int n;
    cin >> n;
    dp = new int[n];
    memset(dp, 0, sizeof(int) * n);
    cout << fun(n) << endl;
    delete[] dp;
    return 0;
}