#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<string> compare(vector<string> a, vector<string> b)
{
    for (int i = 0; i < a.size(); ++i)
    {
        if (stoi(a[i]) > stoi(b[i]))
        {
            return a;
        }

        if (stoi(a[i]) < stoi(b[i]))
        {
            return b;
        }
    }

    return a;
}

vector<string> split(const string &str, char delimiter)
{
    vector<string> output;
    string::size_type startPos = 0;
    string::size_type endPos = 0;

    while ((endPos = str.find(delimiter, startPos)) != string::npos)
    {
        output.push_back(str.substr(startPos, endPos - startPos));
        startPos = endPos + 1;     
    }

    output.push_back(str.substr(startPos));

    return output;
}

int main(int argc, char const *argv[])
{
    try
    {
        vector<vector<string>> ip_pool;
        for (string line; getline(cin, line);)
        {
            vector<string> tabSplit = split(line, '\t');
            ip_pool.push_back(split(tabSplit.at(0), '.'));
        }

        // string line;
        // for (int i = 0; i < 3; ++i)
        // {
        //     getline(cin,line);
        //     vector<string> tabSplit = split(line, '\t');
        //     ip_pool.push_back(split(tabSplit.at(0), '.'));
        // }

        for (auto i = ip_pool.begin(); i != ip_pool.end()-1; ++i)
        {
            if (compare(*i, *(i+1)) == *(i+1))
            {
                auto it = ip_pool.begin();
                ip_pool.insert(it, *(i+1));
                ip_pool.erase(i+2);
                i = ip_pool.begin() - 1;
            }
        }



        for (vector<vector<string>>::const_iterator ip = ip_pool.cbegin(); ip != ip_pool.cend(); ++ip)
        {
            for (vector<string>::const_iterator ip_part = ip->cbegin();ip_part != ip->cend(); ++ip_part)
            {
                if (ip_part != ip->cbegin())
                {
                    cout << ".";
                }
                cout << *ip_part;
            }
            cout << endl;
        }
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
    }

    return 0;
    
}
