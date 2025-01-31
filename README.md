# UCrypt - One-Time Pad Cryptography Library

UCrypt is a lightweight C++ library for implementing One-Time Pad (OTP) cryptography, a simple yet powerful encryption technique that ensures absolute security when used correctly. This library provides functionality to generate encryption keys, encrypt messages, and decrypt ciphertexts.

## Features
 - Generate secure one-time keys.
 - Encrypt and decrypt messages using XOR-based operations.
 - File I/O support for saving and reading keys.
 - Lightweight and easy-to-integrate design.

## Installation

1. Clone the Repository

```bash
git clone https://github.com/yourusername/ucrypt.git
cd ucrypt
```

2. Build the Library

```bash
mkdir build
cd build
cmake ..
make
```

## Usage

Include the Library
Ensure the library is compiled and the include/ directory is accessible in your project.

```cpp
#include <iostream>
#include "ucrypt/UCrypt.h"

int main() {
    std::string plaintext = "Hello, ucrypt!";
    std::string key = ucrypt::build_key(plaintext, 123, 10000);

    // Encrypt
    std::string encrypted_message = ucrypt::encrypt(plaintext, key);
    std::cout << "Encrypted Message: " << encrypted_message << std::endl;

    // Decrypt
    std::string decrypted_message = ucrypt::decrypt(encrypted_message, key);
    std::cout << "Decrypted Message: " << decrypted_message << std::endl;

    return 0;
}
```

# Contributing

Contributions are welcome! If you have suggestions for improvements, please:

1. Fork the repository.
2. Create a new branch.
3. Submit a pull request.

# License

This project is licensed under the MIT License. See the LICENSE file for more details.

# Acknowledgments

Inspired by the simplicity and security of One-Time Pad cryptography. Special thanks to the open-source C++ community for tools and support.

Let me know if you want any customization in the structure or content!