// 11498 - Division of Nlogonia

#include <iostream>
using namespace std;

int main()
{
	int casos, n, m, x, y;

    while(true)
    {
        cin >> casos;
        if(casos == 0)
            break;

        cin >> n >> m;
        while(casos--)
        {
            cin >> x >> y;
            if (x == n || y == m)
                cout << "divisa" << endl;
            else if (x > n && y > m)
                cout << "NE" << endl;
            else if (x > n && y < m)
                cout << "SE" << endl;
            else if (x < n && y > m)
                cout << "NO" << endl;
            else if (x < n && y < m)
                cout << "SO" << endl;
        }
    }
	return 0;
}


