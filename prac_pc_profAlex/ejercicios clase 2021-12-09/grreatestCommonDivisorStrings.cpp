#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2)
    {
        string solucion;
        int size1 = str1.size();
        int size2 = str2.size();
        for (int i = 0; i < size1; ++i) {
            if (size1 % (i + 1) != 0 || size2 % (i + 1) != 0)
                continue;

            string ini = str1.substr(0, i + 1);
            string acum1, acum2;

            for (int j = 0; j < size1 / (i + 1); ++j)
                acum1 += ini;
            if (acum1 != str1)
                continue;

            for (int j = 0; j < size2 / (i + 1); ++j)
                acum2 += ini;
            if (acum2 != str2)
                continue;

            solucion = ini;
        }
        return solucion;
    }
};

int main(){
    Solution obj;
    string str1 = "ABABAB";
    string str2 = "ABAB";
    string solucion = obj.gcdOfStrings(str1, str2);
    cout << solucion;  // salida: AB
    return 0;
}
