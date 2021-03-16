#include <iostream> 
using namespace std;
int main()
{
    int a[10];
    int max = 0,i;
    cout << "ÇëÊäÈë10¸öÊý" << endl;
    for (i = 0; i < 10; i++)
        {
            cin >> a[i];
        }
    max = a[0];
    for (i = 0; i < 10; i++)
       
        {
            if (a[i] > max)	
                {
                    max = a[i];
                }
        }
    cout << "max: " << max << endl;
    return 0;
}