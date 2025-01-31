#include <iostream>
#include "../include/ucrypt/ucrypt.h"

int main()
{
    std::string to_encrypt = "testing code...";
    std::string key = ucrypt::build_key(to_encrypt.size(), 123, 10000);

    const std::string secret_file = "/tmp/secret.txt";
    if (!ucrypt::write_to_file(secret_file, key))
    {
        std::cout << "Failed to write to secret file" << '\n';
        throw std::runtime_error("Tests failed at writing to file");
    }

    std::string secret = ucrypt::read_from_file(secret_file);
    std::string encrypted_msg = ucrypt::encrypt(to_encrypt, secret);
    std::string decrypted_msg = ucrypt::decrypt(encrypted_msg, secret);

    if (to_encrypt != decrypted_msg)
    {
        throw std::runtime_error("Tests failed at encryted/decrypted comparisson");
    }

    std::cout << "message: " << to_encrypt << "\nkey: " << key << "\nEncrypted message: " << encrypted_msg << "\nDecrypted message: " << decrypted_msg << '\n';

    return 0;
}
