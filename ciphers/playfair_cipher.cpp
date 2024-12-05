#include <iostream>
#include <vector>
using namespace std;

vector<char> generate_dict(string key)
{
    string alphabets = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    vector<char> dict;
    for (char ch : key)
    {
        if (ch >= 'A' && ch <= 'Z')
        {
            if (ch == 'J')
            {
                ch = 'I';
            }
            bool found = false;
            for (int i = 0; i < dict.size(); i++)
            {
                if (dict[i] == ch)
                {
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                dict.push_back(ch);
            }
        }
    }
    for (char ch : alphabets)
    {
        if (ch == 'J')
        {
            ch = 'I';
        }
        bool found = false;
        for (int i = 0; i < dict.size(); i++)
        {
            if (dict[i] == ch)
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            dict.push_back(ch);
        }
    }
    return dict;
}

vector<vector<char>> generate_key_matrix(vector<char> dict)
{
    vector<vector<char>> key_matrix;
    for (int i = 0; i < 5; i++)
    {
        vector<char> temp;
        for (int j = 0; j < 5; j++)
        {
            char ch = dict[5 * i + j];
            temp.push_back(ch);
        }
        key_matrix.push_back(temp);
    }
    return key_matrix;
}

pair<int, int> find_position(vector<vector<char>> key_matrix, char a)
{
    pair<int, int> p = {0, 0};
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (key_matrix[i][j] == a)
            {
                p.first = i;
                p.second = j;
                return p;
            }
        }
    }
    return p;
}

string cipher_it(string plain_text, vector<vector<char>> key_matrix)
{
    string cipher_text;
    vector<pair<char, char>> pairs;
    int i = 0;
    int n = plain_text.size();
    string cleaned_text;
    for (char ch : plain_text)
    {
        if (ch >= 'A' && ch <= 'Z')
        {
            if (ch == 'J')
            {
                ch = 'I';
            }
            cleaned_text += ch;
        }
    }
    if (cleaned_text.size() % 2 == 1)
    {
        cleaned_text.push_back('X');
    }
    for (int i = 0; i < cleaned_text.size(); i = i + 2)
    {
        char a = cleaned_text[i];
        char b = cleaned_text[i + 1];
        if (a == b)
        {
            b = 'X';
        }
        pairs.push_back({a, b});
    }
    for (auto i : pairs)
    {
        cout << i.first << i.second << "  ";
    }
    cout << endl;
    for (int i = 0; i < pairs.size(); i++)
    {
        pair<int, int> a = find_position(key_matrix, pairs[i].first);
        pair<int, int> b = find_position(key_matrix, pairs[i].second);
        if (a.first == b.first)
        {
            pairs[i].first = key_matrix[a.first][(a.second + 1) % 5];
            pairs[i].second = key_matrix[b.first][(b.second + 1) % 5];
        }
        else if (a.second == b.second)
        {
            pairs[i].first = key_matrix[(a.first + 1) % 5][a.second];
            pairs[i].second = key_matrix[(b.first + 1) % 5][b.second];
        }
        else
        {
            pairs[i].first = key_matrix[a.first][b.second];
            pairs[i].second = key_matrix[b.first][a.second];
        }
    }
    for (auto i : pairs)
    {
        cout << i.first << i.second << "  ";
        cipher_text.push_back(i.first);
        cipher_text.push_back(i.second);
    }
    cout << endl
         << endl;
    int j = 0;
    string ans;
    for (char ch : plain_text)
    {
        if (ch >= 'A' && ch <= 'Z')
        {
            ans.push_back(cipher_text[j]);
            j++;
        }
        else
        {
            ans.push_back(ch);
        }
    }
    if (j < cipher_text.size())
    {
        ans.push_back(' ');
        ans.push_back(cipher_text[j]);
    }
    return ans;
}

int main()
{
    string plain_text = "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z";

    string key = "A FOX JUMPS OVER THE LAZY DOG";
    vector<char> dict(25);
    dict = generate_dict(key);

    vector<vector<char>> key_matrix = generate_key_matrix(dict);
    for (auto i : key_matrix)
    {
        for (auto j : i)
        {
            cout << j << "  ";
        }
        cout << endl;
    }
    cout << endl;

    string cipher_text = cipher_it(plain_text, key_matrix);

    cout << plain_text << endl
         << endl;

    cout << cipher_text << endl
         << endl;

    //  Todo: Add De Cipher Function Implementation
    return 0;
}