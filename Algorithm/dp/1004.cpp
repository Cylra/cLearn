/*给定两个字符串str1和str2，返回两个字符串的最长公共子序列，
例如：str1="1A2C3D4B56",str2="B1D23CA45B6A",
"123456"和"12C4B6"都是最长公共子序列，返回哪一个都行。
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int CommonOrder(string str1, int m, string str2, int n);

int main()
{
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    int m = str1.size(), n = str2.size();
    CommonOrder(str1, m, str2, n);
    return 0;
}

/*设str1的长度为m,str2的长度为n,设置二维数组dp[m+1][n+1],
dp[i][j]表示str1[0..i]和str2[0..j]的最长公共子序列的长度
设置状态表S[m+1][n+1],记载求解过程,用于搜索最长公共子序列
str1="abcbdb"
str2="acbbabdbb"
*/
int CommonOrder(string str1, int m, string str2, int n)
{
    //为避免下面的下标问题
    str1 = " " + str1;
    str2 = " " + str2;

    int dp[m+1][n+1], S[m+1][n+1];
    int i, j;
    for(i=0; i<=m; i++){
        for(j=0; j<=n; j++){
            dp[i][j] = 0;
            S[i][j] = 0;
        }
    }
    //第0行和第0列均为0
    for(i=1; i<=m; i++){
        for(j=1; j<=n; j++){
            //此处注意str1和str2的下标是以0开始作比较的
            if(str1[i] == str2[j]){
                dp[i][j] = dp[i-1][j-1] + 1;
                S[i][j] = 1;
            }
            else if(dp[i][j-1] >= dp[i-1][j] ){
                dp[i][j] = dp[i][j-1];
                S[i][j] = 2;
            }
            else{
                dp[i][j] = dp[i-1][j];
                S[i][j] = 3;
            }
        }
    }
    // for(i=0; i<=m; i++){
    //     for(j=0; j<=n; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // for(i=0; i<=m; i++){
    //     for(j=0; j<=n; j++){
    //         cout << S[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    vector<char> v1; //将公共子序列(有多个的话,选择dp[m][n]处进行回溯得到的子序列)
    i=m;
    j=n;
    while(i>0 && j>0){
        if(S[i][j] == 1){
            v1.push_back(str1[i]);
            i--;
            j--;
        }
        else if(S[i][j] == 2){
            j--;
        }
        else{
            i--;
        }
    }
    reverse(v1.begin(), v1.end());
    for(i=0; i< v1.size(); i++) //输出最长公共子序列
        cout << v1[i] << " ";
    cout << endl;
    return dp[m][n]; //返回公共子序列长度
}