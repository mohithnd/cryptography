#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

int mod_exp(int a, int q, int n)
{
    int result = 1;
    a = a % n;
    while (q > 0)
    {
        if (q % 2 == 1)
        {
            result = (result * a) % n;
        }
        q = q / 2;
        a = (a * a) % n;
    }
    return result;
}

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

bool is_prime(int n, int accuracy)
{
    if (n < 2)
    {
        return false;
    }
    if (n == 2 || n == 3)
    {
        return true;
    }
    if (n % 2 == 0)
    {
        return false;
    }

    while (accuracy)
    {
        int a = 2 + rand() % (n - 4);
        if (gcd(n, a) != 1)
        {
            return false;
        }
        if (mod_exp(a, n - 1, n) != 1)
        {
            return false;
        }
        accuracy--;
    }

    return true;
}

int main()
{

    int n;
    cout << "Enter The Number - ";
    cin >> n;

    if (is_prime(n, 5))
    {
        cout << "May Be Prime" << endl;
    }
    else
    {
        cout << "Composite" << endl;
    }

    return 0;
}