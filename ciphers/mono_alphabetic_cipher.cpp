#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

string generate_clean_key(string key, string alphabets)
{
    string ans;
    for (char ch : key)
    {
        if (ch >= 'A' && ch <= 'Z')
        {
            bool found = false;
            for (char ch2 : ans)
            {
                if (ch2 == ch)
                {
                    found = true;
                    break;
                }
            }
            if (found == false)
            {
                ans.push_back(ch);
            }
        }
    }
    for (char ch : alphabets)
    {
        bool found = false;
        for (char ch2 : ans)
        {
            if (ch2 == ch)
            {
                found = true;
                break;
            }
        }
        if (found == false)
        {
            ans.push_back(ch);
        }
    }
    return ans;
}

unordered_map<char, char> create_encrypt_map(string key)
{
    string alphabets = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string clean_key = generate_clean_key(key, alphabets);
    unordered_map<char, char> encrypt_map;
    for (int i = 0; i < alphabets.size(); i++)
    {
        encrypt_map[alphabets[i]] = clean_key[i];
    }
    return encrypt_map;
}

unordered_map<char, char> create_decrypt_map(string key)
{
    string alphabets = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string clean_key = generate_clean_key(key, alphabets);
    unordered_map<char, char> decrypt_map;
    for (int i = 0; i < alphabets.size(); i++)
    {
        decrypt_map[clean_key[i]] = alphabets[i];
    }
    return decrypt_map;
}

string cipher(string text, unordered_map<char, char> encrypt_map)
{
    string ans;
    for (char ch : text)
    {
        if (ch >= 'A' && ch <= 'Z')
        {
            ans.push_back(encrypt_map[ch]);
        }
        else
        {
            ans.push_back(ch);
        }
    }
    return ans;
}

string de_cipher(string cipher, unordered_map<char, char> decrypt_map)
{
    string ans;
    for (char ch : cipher)
    {
        if (ch >= 'A' && ch <= 'Z')
        {
            ans.push_back(decrypt_map[ch]);
        }
        else
        {
            ans.push_back(ch);
        }
    }
    return ans;
}

int main()
{
    string plain_text = "HELLO MY NAME IS MOHTI AGRAWAL";
    cout << plain_text << endl;

    string key = "A FOX JUMPS OVER THE LAZY DOG";
    cout << key << endl;

    unordered_map<char, char> encrypt_map;
    encrypt_map = create_encrypt_map(key);

    string cipher_text = cipher(plain_text, encrypt_map);
    cout << cipher_text << endl;

    unordered_map<char, char> decrypt_map;
    decrypt_map = create_decrypt_map(key);

    string de_cipher_text = de_cipher(cipher_text, decrypt_map);
    cout << de_cipher_text << endl;
    return 0;
}