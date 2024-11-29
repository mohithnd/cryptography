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

string co_prime(int a, int b)
{
    if (gcd(a, b) == 1)
    {
        return "Co Prime";
    }
    else
    {
        return "Not Co Prime";
    }
}

int main()
{
    int a;
    cout << "Enter The First Number - ";
    cin >> a;

    int b;
    cout << "Enter The Second Number - ";
    cin >> b;

    cout << co_prime(a, b) << endl;
    return 0;
}