#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    string s;
    getline(cin,s);
    int len = s.length();
    int result = 0;
    if(4 == len){
        result += (s[0]-'a') * (pow(25,3) + pow(25,2) + pow(25,1) + 1);
        result += (s[1]-'a') * (pow(25,2) + pow(25,1) + 1) + 1;
        result += (s[2]-'a') * (pow(25,1) + 1) + 1;
        result += (s[3]-'a') * (1) + 1;
    }
    else if(3 == len){
        result += (s[0]-'a') * (pow(25,3) + pow(25,2) + pow(25,1) + 1);
        result += (s[1]-'a') * (pow(25,2) + pow(25,1) + 1) + 1;
        result += (s[2]-'a') * (pow(25,1) + 1) + 1;
    }
    else if(2 == len){
        result += (s[0]-'a') * (pow(25,3) + pow(25,2) + pow(25,1) + 1);
        result += (s[1]-'a') * (pow(25,2) + pow(25,1) + 1) + 1;
    }
    else{
        result += (s[0]-'a') * (pow(25,3) + pow(25,2) + pow(25,1) + 1);
    }
    cout<< result << endl;
    return 0;
}