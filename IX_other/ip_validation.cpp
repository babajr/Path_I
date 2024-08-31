#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>

using namespace std;

vector<string> split(string s, char c)
{
    vector<string> parts;
    string part;

    // Used for breaking the words in string
    istringstream in(s);
    // getline(orig_str, token_output, delimeter)
    while (getline(in, part, c))
    {
        parts.push_back(part);
    }

    // 0.0.2.67 --> splitted to ["0", "0", "2", "67"]

    return parts;
}

bool validIPv4(string IP)
{
    if (count(IP.begin(), IP.end(), '.') != 3)
    {
        return false;
    }

    vector<string> parts = split(IP, '.');

    if (parts.size() != 4)
    {
        return false;
    }

    for (string part : parts)
    {
        if ((part.empty()) || (part.size() > 3) || (part.size() > 1 && part[0] == '0'))
        {
            return false;
        }

        for (char c : part)
        {
            if (!isdigit(c))
            {
                return false;
            }
        }

        if (stoi(part) > 255)
        {
            return false;
        }
    }

    return true;
}

bool validIPv6(string IP)
{
    if (count(IP.begin(), IP.end(), ':') != 7)
    {
        return false;
    }

    vector<string> parts = split(IP, ':');

    if (parts.size() != 8)
    {
        return false;
    }

    for (string part : parts)
    {
        if (part.empty() || part.size() > 4)
        {
            return false;
        }
        for (char c : part)
        {
            if (!isdigit(c) && (!isalpha(c) || toupper(c) > 'F'))
            {
                return false;
            }
        }
    }

    return true;
}

string validIPAddress(string IP)
{
    return validIPv4(IP) ? "IPv4" : (validIPv6(IP) ? "IPv6" : "Neither");
}

int main()
{
    cout << validIPAddress("01.01.01.01") << endl;
    cout << validIPAddress("2001:0db8:85a3:0:0:8A2E:0370:7334") << endl;
    return 0;
}