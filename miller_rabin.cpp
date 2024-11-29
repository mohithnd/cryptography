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

    int q = n - 1, k = 0;
    while (q % 2 == 0)
    {
        q = q / 2;
        k++;
    }

    for (int i = 0; i < accuracy; i++)
    {
        int a = 2 + rand() % (n - 4);
        int x = mod_exp(a, q, n);
        if (x == 1 || x == n - 1)
        {
            continue;
        }

        bool found = false;
        for (int j = 0; j < k - 1; j++)
        {
            x = mod_exp(x, 2, n);
            if (x == n - 1 || x == 1)
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            return false;
        }
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