#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
   int numSpecialEquivGroups(vector<string>& words)
   {
        map<pair<vector<int>,vector<int>>,int> myMap;
        int solucion, i, j;
        for(i = 0; i < words.size(); i++)
        {
            vector<int> impar, par;
            for(j = 0; j < words[i].size(); j++){
                if( !(j%2) ) {
                    par.push_back(words[i][j]-'0');
                } else {
                     impar.push_back((words[i][j]-'0'));
                }
            }
            sort(impar.begin(),impar.end());
            sort(par.begin(),par.end());
            myMap[{par,impar}]++;
        }
        solucion = myMap.size();
        return solucion;
    }
};

int main(){
    Solution obj;
    vector<string> vec{"abc","acb","bac","bca","cab","cba"};
    int solucion = obj.numSpecialEquivGroups(vec);
    cout << solucion;
    return 0;
}
