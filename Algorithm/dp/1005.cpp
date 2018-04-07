/*0/1背包问题
一个背包容量为C，有n种物品，每件物品i都有自己的价值v[i]，重量是w[i]
每件物品只能选择：装入还是不装入背包，要求在不超过背包容量的前提下，选出的物品总价值最大。
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int KnapSack(int w[], int v[], int n, int C);
int main()
{
    int n, C; //物品数n,容量C
    cin >> n >> C;
    int w[n], v[n];
    int i;
    for(i=0; i<n; i++)
        cin >> w[i];
    for(i=0; i<n; i++)
        cin >> v[i];

    KnapSack(w, v, n, C);
    return 0;
}

/*设置二维数组dp[n+1][C+1]
dp[i][j]表示将前i个物品装进容量为j的背包获得的最大价值
w[] = {2 2 6 5 4};
v[] = {6 3 5 4 6};
*/
int KnapSack(int w[], int v[], int n, int C)
{
    int i, j;
    int dp[n+1][C+1];
    for(i=0; i<=n; i++)    //初始化第0列
        dp[i][0] = 0;
    for(j=0; j<=C; j++)    //初始化第0行
        dp[0][j] = 0;
    //计算dp数组
    for(i=1; i<=n; i++){
        for(j=1; j<=C; j++){
            //注意w,v数组的下标
            if(j < w[i-1]){   //容量不足以装入物品i
                dp[i][j] = dp[i-1][j];
            }
            else{  //能装入物品i,可选：装还是不装
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i-1]] + v[i-1]);
            }
        }
    }
    // for(i=0; i<=n; i++){
    //     for(j=0; j<=C; j++){
    //         printf("%2d ", dp[i][j]);
    //     }
    //     cout << endl;
    // }
    int x[n]; //求装入背包的物品
    for(j=C, i=n; i>0; i--){
        if(dp[i][j] > dp[i-1][j]){
            x[i-1] = 1;
            j = j-w[i-1];
        }
        else
            x[i-1] = 0;
    }
    for(i=0; i< n; i++)
        cout << x[i] << " ";
    cout << endl;
    return dp[n][C];  //返回背包取得的最大价值
}