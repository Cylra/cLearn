#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void replaceSpace(char *str,int length) {
        vector<vector <char> > v1;
        vector <char> tmp;
        char *c = str;
        int pos;
        for(pos=0; pos<length; pos++)
        {
            if(c[pos] == ' '){
                v1.push_back(tmp);
                tmp.clear();
                //cout << "--------" << endl;
                continue;
            }
            //cout << "--Push:" << c[pos] << endl;
            tmp.push_back(c[pos]);
        }
        //少push了一个单词
        v1.push_back(tmp);
        cout << str << endl;
        int i, j, k=0;
        cout << v1.size() << endl;
        for(i=0; i<v1.size(); i++){
            tmp = v1[i];
            for(j=0; j<tmp.size(); j++){
                str[k++] = tmp[j];
            }
            //cout <<  tmp[j] << endl;
            //最后1个单词的末尾,不需要补%20
            if(i == v1.size() -1){
                str[k] = '\0';
                break;
            }
            str[k++] = '%';
            str[k++] = '2';
            str[k++] = '0';
        }
        cout << str << endl;
	}
};

int main()
{
    Solution s1;
    char str[100] = "We Are Happy.";
    s1.replaceSpace(str, 13);
    return 0;
}