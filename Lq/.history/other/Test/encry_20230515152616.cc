#include <iostream>

std::string encode(std::string text, std::string pwd)
{
    std::string res;
    int pwd_len = pwd.size();
    for (size_t i = 0; i < text.size(); i++)
    {
        res.push_back(((text[i] << 1) + 32 + pwd[i % pwd_len]) % 128);
    }
    return res;
}

std::string decode(std::string text, std::string pwd)
{
    std::string res;
    int pwd_len = pwd.size();
    for (size_t i = 0; i < text.size(); i++)
    {
        res.push_back(((text[i] + 512 - 32 - pwd[i % pwd_len]) >> 1) % 128);
    }
    return res;
}

int main()
{
    std::string s;
    std::cin >> s;
    auto str = encode(s, "666");
    std::cout << str << std::endl;
    std::cout << decode(str, "666") << std::endl;
}