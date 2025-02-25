#include "../include/ucrypt/ucrypt.h"

#include <fstream>
#include <sstream>
#include <iostream>

std::string ucrypt::build_key(const std::size_t& text_length,
                              const std::size_t& seed_for_key_gen,
                              const std::size_t& limit_randint_gen)
{
    auto now = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();

    std::mt19937 gen(now);
    std::uniform_int_distribution<int> dist(1, limit_randint_gen);

    std::string key(text_length, '\0');

    for (std::size_t i = 0; i < text_length; ++i)
    {
        key[i] = static_cast<char>(dist(gen)*seed_for_key_gen%256);
    }

    return key;
}

std::string ucrypt::encrypt(const std::string& text, const std::string& key)
{
    std::string encrypted_text = "";
    encrypted_text.reserve(text.size());
    for (std::size_t i = 0; i < text.size(); ++i)
    {
        encrypted_text += char(text[i] ^ key[i]);
    }
    return encrypted_text;
}

std::string ucrypt::decrypt(const std::string& encrypted_text, const std::string& key)
{
    std::string decrypted_text = "";
    decrypted_text.reserve(encrypted_text.size());
    for (std::size_t i = 0; i < encrypted_text.size(); ++i)
    {
        decrypted_text += char(encrypted_text[i] ^ key[i]);
    }
    return decrypted_text;
}

std::string ucrypt::read_from_file(const std::string& filename)
{
    std::ifstream infile(filename, std::ios::in);
    if (!infile.is_open())
        return "";

    std::ostringstream oss;
    oss << infile.rdbuf();
    infile.close();

    return oss.str();
}

bool ucrypt::write_to_file(const std::string& filename, const std::string& content)
{
    std::ofstream outfile(filename, std::ios::out | std::ios::trunc);
    if (!outfile.is_open())
        return false;

    outfile << content;
    outfile.close();

    return true;
}
