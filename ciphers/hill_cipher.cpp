#include <iostream>
#include <vector>
using namespace std;

vector<char> matrix_multiply(vector<char> str, vector<vector<int>> key)
{
    int win = str.size();
    vector<int> data;
    for (char ch : str)
    {
        data.push_back(ch - 'A');
    }
    vector<char> ans;
    for (int i = 0; i < win; i++)
    {
        int curr = 0;
        for (int j = 0; j < win; j++)
        {
            curr += data[j] * key[j][i];
        }
        ans.push_back('A' + curr % 26);
    }
    return ans;
}

string cipher_it(string plain, vector<vector<int>> key)
{
    string cleaned_text;
    for (char ch : plain)
    {
        if (ch >= 'A' && ch <= 'Z')
        {
            cleaned_text.push_back(ch);
        }
    }
    while (cleaned_text.size() % key.size() != 0)
    {
        cleaned_text.push_back('X');
    }
    vector<vector<char>> pairs;
    for (int i = 0; i < cleaned_text.size(); i = i + key.size())
    {
        vector<char> temp;
        for (int j = 0; j < key.size(); j++)
        {
            temp.push_back(cleaned_text[i + j]);
        }
        pairs.push_back(temp);
    }
    for (auto i : pairs)
    {
        for (char ch : i)
        {
            cout << ch;
        }
        cout << "  ";
    }
    cout << endl;
    for (int i = 0; i < pairs.size(); i++)
    {
        pairs[i] = matrix_multiply(pairs[i], key);
    }
    for (auto i : pairs)
    {
        for (char ch : i)
        {
            cout << ch;
        }
        cout << "  ";
    }
    cout << endl;
    string ans;
    for (auto i : pairs)
    {
        for (char ch : i)
        {
            ans.push_back(ch);
        }
    }
    string cipher_text;
    int i = 0;
    for (char ch : plain)
    {
        if (ch >= 'A' && ch <= 'Z')
        {
            cipher_text.push_back(ans[i]);
            i++;
        }
        else
        {
            cipher_text.push_back(ch);
        }
    }
    return cipher_text;
}

int main()
{
    string plain = "MY NAME IS MOHIT AGRAWAL";
    vector<vector<int>> key = {
        {23, 1, 21},
        {2, 12, 5},
        {3, 10, 13}};
    for (auto i : key)
    {
        for (int j : i)
        {
            cout << j << "  ";
        }
        cout << endl;
    }
    cout << endl;
    cout << plain << endl;
    string cipher_text = cipher_it(plain, key);
    cout << cipher_text << endl;

    //  Todo: Add De Cipher Function Implementation
    return 0;
}