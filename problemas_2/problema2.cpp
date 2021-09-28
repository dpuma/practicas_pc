#include<iostream>
using namespace std;

int main()
{
    int n, num;
    cin >> n;
    while(n--)
    {
        cin >> num;
        cout << abs( (( (((((num*567)/9)+7492)*235)/47)-498 )/10)%10 ) << endl;
    }
}
