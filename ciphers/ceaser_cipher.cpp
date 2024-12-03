#include <iostream>
using namespace std;

string ceaser_cipher(string plain, int shift_key)
{
    string cipher_text;
    int n = plain.size();
    for (int i = 0; i < n; i++)
    {
        char ch = plain[i];
        if (ch >= 'A' && ch <= 'Z')
        {
            ch = (ch - 'A' + shift_key) % 26 + 'A';
        }
        else if (ch >= 'a' && ch <= 'z')
        {
            ch = (ch - 'a' + shift_key) % 26 + 'a';
        }
        cipher_text += ch;
    }
    return cipher_text;
}

string ceaser_de_cipher(string cipher, int shift_key)
{
    string plain_text;
    int n = cipher.size();
    for (int i = 0; i < n; i++)
    {
        char ch = cipher[i];
        if (ch >= 'A' && ch <= 'Z')
        {
            ch = (ch - 'A' - shift_key + 26) % 26 + 'A';
        }
        else if (ch >= 'a' && ch <= 'z')
        {
            ch = (ch - 'a' - shift_key + 26) % 26 + 'a';
        }
        plain_text += ch;
    }
    return plain_text;
}

int main()
{
    string plain_text = "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z";
    cout << plain_text << endl;

    string cipher_text = ceaser_cipher(plain_text, 3);
    cout << cipher_text << endl;

    string de_cipher_text = ceaser_de_cipher(cipher_text, 3);
    cout << de_cipher_text << endl;
    return 0;
}