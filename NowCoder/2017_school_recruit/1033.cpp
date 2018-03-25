#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    long int M;
    int N;
    cin >> M >> N;
    vector<char> v1;
    bool bNeg = false;
    if(M < 0){
        M = -M;
        bNeg = true;
    }
    while(M != 0){
        int k = M % N;
        if(k > 9){
            v1.push_back('A' + k-10);
        }
        else{
            v1.push_back('0' + k-0);
        }
        M = M/N;
    }
    int i;
    reverse(v1.begin(),v1.end());
    if(bNeg){
        cout << '-' ;
    }
    for(i=0; i<v1.size(); i++){
        cout << v1[i];
    }
    cout << endl;
    return 0;
}