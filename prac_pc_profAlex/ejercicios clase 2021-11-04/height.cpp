#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int casos, cantNum, num;
    cin >> casos;
    while(casos--)
    {
        cin >> cantNum;
        vector<int> vec;
        while(cantNum--)
        {
            cin >> num;
            vec.push_back(num);
        }
        sort(vec.begin(), vec.end());
        for(int i = 0; i < vec.size(); i++)
            cout << vec[i] << " ";
        cout << endl;
    }
    return 0;
}
