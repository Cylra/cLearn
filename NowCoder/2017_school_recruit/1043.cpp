#include <iostream>
#include <vector>
using namespace std;

int main()
{
    //计算出1000以内的质数表
    vector<int> v1(1000, 1);
    int i,j;
    for(i=2; i<1000; i++){
        for(j=2; i*j < 1000; j++){
            if(v1[i]){
                v1[i*j] = 0;  //质数的倍数归0
            }
        }
    }

    int n;
    cin >> n;
    int result = 0;
    for(i=2; i <= n/2; i++){
        if(v1[i] && v1[n-i])
            result++;
    }
    cout << result << endl;
    return 0;
}