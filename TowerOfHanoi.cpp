#include <iostream>
using namespace std;
void tow(int n, int n1, int n3, int n2)
{
    if(n>0)
    {
        tow(n-1, n1, n2, n3);
        cout << "Move disk " << n << " from " << n1 << " to " << n3 << "." << endl;
        tow(n-1, n2, n3, n1);
    }
}
int main()
{
    int n;
    cout << "Enter the no. of disks: ";
    cin >> n;
    cout << endl;
    tow(n, 1, 3, 2);
    return 0;
}