#include <string>
#include <random>
#include <chrono>

namespace ucrypt
{
    /**
     * @brief Generates a one-time pad key for encryption.
     *
     * @param text The plaintext message for which the key is generated.
     * @param seed_for_key_gen The seed value used to initialize the random number generator.
     * @param limit_randint_gen The upper limit for random integer generation.
     * @return std::string The generated key, with the same length as the input text.
     *
     * This function uses a seeded random number generator to create a pseudo-random key
     * for encrypting the input text. The generated key is suitable for XOR-based encryption.
     */
    std::string build_key(const std::string& text,
                          const std::size_t& seed_for_key_gen,
                          const std::size_t& limit_randint_gen);

    /**
     * @brief Encrypts a plaintext message using the one-time pad key.
     *
     * @param text The plaintext message to be encrypted.
     * @param key The one-time pad key used for encryption (must have the same length as the text).
     * @return std::string The encrypted message.
     *
     * The encryption is performed using a character-by-character XOR operation between
     * the plaintext and the key.
     */
    std::string encrypt(const std::string& text, const std::string& key);

    /**
     * @brief Decrypts an encrypted message using the one-time pad key.
     *
     * @param encrypted_text The encrypted message to be decrypted.
     * @param key The one-time pad key used for decryption (must have the same length as the encrypted text).
     * @return std::string The decrypted plaintext message.
     *
     * Decryption is the reverse process of encryption, achieved using the same XOR operation
     * between the encrypted text and the key.
     */
    std::string decrypt(const std::string& encrypted_text, const std::string& key);

    /**
     * @brief Reads the content of a file.
     *
     * @param filename The name of the file to be read.
     * @return std::string The content of the file as a string. Returns an empty string if the file cannot be opened.
     *
     * This function reads the entire content of the specified file into a string.
     */
    std::string read_from_file(const std::string& filename);

    /**
     * @brief Writes content std::string to a file.
     *
     * @param filename The name of the file to write to.
     * @param content The content to be written into the file.
     * @return bool True if the content is successfully written to the file, false otherwise.
     *
     * This function creates or overwrites the specified file with the provided content.
     */
    bool write_to_file(const std::string& filename, const std::string& content);
};
