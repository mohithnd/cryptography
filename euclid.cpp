#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int main()
{
    int a;
    cout << "Enter The First Number - ";
    cin >> a;

    int b;
    cout << "Enter The Second Number - ";
    cin >> b;

    cout << gcd(a, b) << endl;
    return 0;
}