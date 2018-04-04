/*给定一个矩阵m，从左上角开始每次只能向右走或者向下走，
最后达到右下角的位置，路径中所有数字累加起来就是路径和，
返回所有路径的最小路径和，如果给定的m如下，
那么路径1,3,1,0,6,1,0就是最小路径和，返回12.
1 3 5 9
8 1 3 4
5 0 6 1
8 8 4 0
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

/*
dp[i][j]表示的是从原点到i,j位置的最短路径和。
我们首先计算第一行和第一列，直接累加即可，
对于其他位置，要么是从它左边的位置达到，要么是从上边的位置达到，
我们取左边和上边的较小值，然后加上当前的路径值，就是达到当前点的最短路径。
然后从左到右，从上到下依次计算即可。
*/
int dp[4][4] = {0};

int main()
{
    memset(dp, -1, sizeof(int)*16);
    int arr[4][4] = {1,3,5,9,8,1,3,4,5,0,6,1,8,8,4,0};
    int i,j;
    //构建dp[4][4]动态规划表
    for(i=0; i<4; i++){
        for(j=0; j<4; j++){
            if(-1 == dp[i][j]){
                //左上角
                if(0 == i && 0 == j){
                    dp[i][j] = arr[i][j];
                }
                //第一行
                else if(0 == i && j != 0 ){
                    dp[i][j] = arr[i][j] + dp[i][j-1];
                }
                //第一列
                else if(i != 0 && 0 == j){
                    dp[i][j] = arr[i][j] + dp[i-1][j];
                }
                //其他位置
                else{
                    dp[i][j] = arr[i][j] + min(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
    }
    for(i = 0; i< 4; i++){
        for(j = 0; j<4; j++){
            cout << dp[i][j] << "  ";  
        }  
        cout << endl;  
    }
    i = 0;
    j = 0;
    cout << "路径为:" << endl;
    while(i !=3 || j != 3){
        cout << arr[i][j] << "->";
        if(dp[i][j+1] < dp[i+1][j]){
            j++;
        }
        else{
            i++;
        }
    }
    cout << arr[i][j] << endl;
    return 0;
}