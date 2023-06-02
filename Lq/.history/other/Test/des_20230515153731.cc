#include <iostream>
#include <string>
#include <vector>

// S盒
const unsigned char sbox[256] = {
    // S盒内容...
};

// 逆S盒
const unsigned char invSbox[256] = {
    // 逆S盒内容...
};

// 密钥扩展
std::vector<unsigned char> expandKey(const std::vector<unsigned char>& key)
{
    std::vector<unsigned char> expandedKey = key;
    const unsigned int numWords = expandedKey.size() / 4;
    const unsigned int numRounds = numWords + 6;

    for (unsigned int i = numWords; i < 4 * (numRounds + 1); i++)
    {
        unsigned char temp[4];
        for (unsigned int j = 0; j < 4; j++)
        {
            temp[j] = expandedKey[(i - 1) * 4 + j];
        }
        if (i % numWords == 0)
        {
            // 旋转字节
            unsigned char tempByte = temp[0];
            for (unsigned int j = 0; j < 3; j++)
            {
                temp[j] = temp[j + 1];
            }
            temp[3] = tempByte;

            // 字节替换
            for (unsigned int j = 0; j < 4; j++)
            {
                temp[j] = sbox[temp[j]];
            }

            // 轮常量
            temp[0] ^= (unsigned char)(0x1B << 24 >> (i / numWords - 1));
        }
        else if (numWords > 6 && i % numWords == 4)
        {
            // 字节替换
            for (unsigned int j = 0; j < 4; j++)
            {
                temp[j] = sbox[temp[j]];
            }
        }

        for (unsigned int j = 0; j < 4; j++)
        {
            expandedKey.push_back(expandedKey[(i - numWords) * 4 + j] ^ temp[j]);
        }
    }

    return expandedKey;
}

// 字节替换
void subBytes(std::vector<unsigned char>& state)
{
    for (unsigned int i = 0; i < state.size(); i++)
    {
        state[i] = sbox[state[i]];
    }
}

// 逆字节替换
void invSubBytes(std::vector<unsigned char>& state)
{
    for (unsigned int i = 0; i < state.size(); i++)
    {
        state[i] = invSbox[state[i]];
    }
}

// 列混淆
void mixColumns(std::vector<unsigned char>& state)
{
    unsigned char tmp[4];
    for (unsigned int i = 0; i < 4; i++)
    {
        tmp[0] = (unsigned char)(state[i] ^ state[4 + i] ^ state[8 + i] ^ state[12+i];
    for (unsigned int i = 0; i < 4; i++) {
            unsigned char t = state[i] ^ state[4 + i] ^ state[8 + i] ^ state[12 + i];
            unsigned char u = state[i];
            state[i] ^= t ^ xtime(state[i] ^ state[4 + i]);
            state[4 + i] ^= t ^ xtime(state[4 + i] ^ state[8 + i]);
            state[8 + i] ^= t ^ xtime(state[8 + i] ^ state[12 + i]);
            state[12 + i] ^= t ^ xtime(state[12 + i] ^ u);
    }
    }

    // 逆列混淆
    void invMixColumns(std::vector<unsigned char> & state)
    {
        unsigned char tmp[4];
        for (unsigned int i = 0; i < 4; i++)
        {
            unsigned char u = xtime(xtime(state[i] ^ state[8 + i]));
            unsigned char v = xtime(xtime(state[4 + i] ^ state[12 + i]));
            tmp[i] = state[i] ^ u;
            tmp[4 + i] = state[4 + i] ^ v;
            tmp[8 + i] = state[8 + i] ^ u;
            tmp[12 + i] = state[12 + i] ^ v;
        }
        for (unsigned int i = 0; i < 4; i++)
        {
            state[i] = tmp[i] ^ tmp[4 + i] ^ tmp[8 + i] ^ tmp[12 + i];
        }
    }

    // 密钥加
    void addRoundKey(std::vector<unsigned char> & state,
                     const std::vector<unsigned char>& roundKey)
    {
        for (unsigned int i = 0; i < state.size(); i++)
        {
            state[i] ^= roundKey[i];
        }
    }

    // 加密
    std::vector<unsigned char> encrypt(const std::vector<unsigned char>& plainText,
                                       const std::vector<unsigned char>& key)
    {
        std::vector<unsigned char> cipherText;
        const unsigned int numRounds = key.size() / 4 - 1;
        std::vector<unsigned char> expandedKey = expandKey(key);

        std::vector<unsigned char> state(plainText.begin(), plainText.end());

        addRoundKey(state, std::vector<unsigned char>(expandedKey.begin(),
                                                      expandedKey.begin() + 16));

        for (unsigned int round = 0; round < numRounds; round++)
        {
            subBytes(state);
            shiftRows(state);
            mixColumns(state);
            addRoundKey(state, std::vector<unsigned char>(
                                   expandedKey.begin() + (round + 1) * 16,
                                   expandedKey.begin() + (round + 2) * 16));
        }

        subBytes(state);
        shiftRows(state);
        addRoundKey(state, std::vector<unsigned char>(
                               expandedKey.begin() + numRounds * 16, expandedKey.end()));

        cipherText.insert(cipherText.end(), state.begin(), state.end());

        return cipherText;
    }

    // 解密
    std::vector<unsigned char> decrypt(const std::vector<unsigned char>& cipherText,
                                       const std::vector<unsigned char>& key)
    {
        std::vector<unsigned char> plainText;
        const unsigned int numRounds = key.size() / 4 - 1;
        std::vector<unsigned char> expandedKey = expandKey(key);

        std::vector<unsigned char> state(cipherText.begin(), cipherText.end());

        addRoundKey(state, std::vector<unsigned char>(
                               expandedKey.begin() + numRounds * 16, expandedKey.end()));

        invShiftRows(state);
        invSubBytes(state);
        addRoundKey(state,
                    std::vector<unsigned char>(expandedKey.begin() + (numRounds - 1) * 16,
                                               expandedKey.begin() + numRounds * 16));

        for (int round = numRounds - 1; round > 0; round--)
        {
            invMixColumns(state);
            invShiftRows(state);
            invSubBytes(state);
            addRoundKey(state, std::vector<unsigned char>(
                                   expandedKey.begin() + round * 16,
                                   expandedKey.begin() + (round + 1) * 16));
        }

        invShiftRows(state);
        invSubBytes(state);
        addRoundKey(state, std::vector<unsigned char>(expandedKey.begin(),
                                                      expandedKey.begin() + 16));

        plainText.insert(plainText.end(), state.begin(), state.end());

        return plainText;
    }

    int main()
    {
        std::string plaintext = "Hello, World!";
        std::string key = "SecretKey12345678"; // 16字节密钥

        std::vector<unsigned char> plainBytes(plaintext.begin(), plaintext.end());
        std::vector<unsigned char> keyBytes(key.begin(), key.end());

        std::vector<unsigned char> cipherBytes = encrypt(plainBytes, keyBytes);
        std::vector<unsigned char> decryptedBytes = decrypt(cipherBytes, keyBytes);

        std::string encryptedText(cipherBytes.begin(), cipherBytes.end());
        std::string decryptedText(decryptedBytes.begin(), decryptedBytes.end());

        std::cout << "Plaintext: " << plaintext << std::endl;
        std::cout << "Encrypted text: " << encryptedText << std::endl;
        std::cout << "Decrypted text: " << decryptedText << std::endl;

        return 0;
    }
