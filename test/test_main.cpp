#include <plog/Log.h>
#include <plog/Initializers/ConsoleInitializer.h>
#include <plog/Formatters/TxtFormatter.h>
#include <plog/Formatters/MessageOnlyFormatter.h>
// #include <plog/Appenders/ColorConsoleAppender.h>

#include "../include/ucrypt/ucrypt.h"

#ifdef NDEBUG
const plog::Severity plogSeverity = plog::info;
#else
const plog::Severity plogSeverity = plog::debug;
#endif

int main()
{
    static plog::ColorConsoleAppender<plog::MessageOnlyFormatter> consoleAppender;
    plog::init(plogSeverity, &consoleAppender);

    std::string to_encrypt = "testing code...";
    std::string key = ucrypt::build_key(to_encrypt, 123, 10000);

    const std::string secret_file = "/tmp/secret.txt";
    if (!ucrypt::write_to_file(secret_file, key))
    {
        PLOG_ERROR << "Failed to write to secret file";
        throw std::runtime_error("Tests failed at writing to file");
    }

    std::string secret = ucrypt::read_from_file(secret_file);
    std::string encrypted_msg = ucrypt::encrypt(to_encrypt, secret);
    std::string decrypted_msg = ucrypt::decrypt(encrypted_msg, secret);

    if (to_encrypt != decrypted_msg)
    {
        throw std::runtime_error("Tests failed at encryted/decrypted comparisson");
    }

    PLOG_DEBUG << "message: " << to_encrypt << "\nkey: " << key << "\nEncrypted message: " << encrypted_msg << "\nDecrypted message: " << decrypted_msg;

    return 0;
}
