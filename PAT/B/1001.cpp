#include <iostream>
using namespace std;

bool isOdd(int num)
{
    return (num%2==1 ?true:false);
}

int main()
{
    int num;
    cin>>num;
    if(num > 1000 || num<1)
        return -1;
    int i = 0;
    while(num != 1)
    {
        if(isOdd(num)){
            num = (3*num+1)/2;
        }
        else{
            num = num/2;
        }
        i++;
    }
    cout << i << endl;
    return 0;
}