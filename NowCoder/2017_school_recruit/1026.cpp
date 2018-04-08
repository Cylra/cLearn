#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

//判断是否为奇数
bool isOdd(int x)
{
    if(x%2 == 1)
        return true;
    else
        return false;
}

//求N(奇数)以内的全部奇数之和
long int f(long int N)
{
    long int ret = (N+1)*(N+1)/4;
    return ret;
}

//返回末尾的偶数的最大奇约数
int fun(int N)
{
    while(1){
        N = N/2;
        if( isOdd(N) ){
            return N;
        }
    }
}

int main()
{
    long int N;
    cin >> N;
    long int sum = 0;
    while(N > 0){
        if( isOdd(N) ){
            sum += f(N);
            N = (N-1)/2;
        }
        else{ //末尾是偶数,就先求出偶数的最大奇约数,然后继续计算奇数(N-1)
            sum += fun(N);
            N = N-1;
        }
    }
    cout << sum << endl;
    return 0;
}