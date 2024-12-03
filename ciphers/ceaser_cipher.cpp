#include <iostream>
using namespace std;

string ceaser(string plain, int shift_key)
{
    int n = plain.size();
    for (int i = 0; i < n; i++)
    {
        char ch = plain[i];
        if (ch >= 'A' && ch <= 'Z')
        {
            int digit = ch - 'A';
            digit = (digit + shift_key) % 26;
            plain[i] = digit + 'A';
        }
        else if (ch >= 'a' && ch <= 'z')
        {
            int digit = ch - 'a';
            digit = (digit + shift_key) % 26;
            plain[i] = digit + 'a';
        }
        else
        {
            plain[i] = ch;
        }
    }
    return plain;
}

int main()
{
    string plain_text = "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z";
    int shift_key;
    cout << "Enter Key: ";
    cin >> shift_key;
    string cipher_text = ceaser(plain_text, shift_key);
    cout << plain_text << endl;
    cout << cipher_text << endl;
    return 0;
}