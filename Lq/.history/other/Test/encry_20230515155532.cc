#include <iostream>

std::string encode(std::string text, std::string pwd)
{
    std::string res;
    int pwd_len = pwd.size();
    for (size_t i = 0; i < text.size(); i++)
    {
        res.push_back((text[i] + 32 + pwd[i % pwd_len]) % 128);
    }
    return res;
}

std::string decode(std::string text, std::string pwd)
{
    std::string res;
    int pwd_len = pwd.size();
    for (size_t i = 0; i < text.size(); i++)
    {
        // +512防止出现负数
        res.push_back(((text[i] + 512 - 32 - pwd[i % pwd_len])) % 128);
    }
    return res;
}

int main()
{
    std::string s, pwd;
    std::cout << "input text: ";
    getline(std::cin, s);
    // std::cin >> s;
    std::cout << "input password: ";
    // std::cin >> pwd;
    getline(std::cin, pwd);
    auto str = encode(s, pwd);
    std::cout << "after encode: " << str << std::endl;
    std::cout << "after decode: " << decode(str, pwd) << std::endl;
}