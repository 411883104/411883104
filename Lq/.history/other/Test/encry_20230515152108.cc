#include <iostream>

std::string encode(std::string text, std::string pwd)
{
    std::string res;
    int pwd_len = pwd.size();
    for (size_t i = 0; i < text.size(); i++)
    {
        res.push_back((text[i] * 2 + 32 + pwd[i % pwd_len]) % 128);
    }
    return res;
}

std::string decode(std::string text, std::string pwd)
{
    std::string res;
    int pwd_len = pwd.size();
    for (size_t i = 0; i < text.size(); i++)
    {
        res.push_back(((text[i] - 32 - pwd[i % pwd_len]) / 2) % 128);
    }
    return res;
}

int main()
{
    std::string s;
    std::cin >> s;
    std::cout << encode(s, "666") << std::endl;
}