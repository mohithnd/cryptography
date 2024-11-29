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

int phi(int n)
{
    int ans = 0;

    for (int i = 1; i <= n - 1; i++)
    {
        if (gcd(n, i) == 1)
        {
            ans++;
        }
    }

    return ans;
}

int main()
{
    int n;
    cout << "Enter The Number - ";
    cin >> n;

    cout << phi(n) << endl;

    return 0;
}