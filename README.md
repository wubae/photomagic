# Linear Feedback Shift Register & PhotoMagic
This is a C++ project that uses [SFML](https://www.sfml-dev.org/) (Simple and Fast Multimedia Library) to render graphics, handle input, and play sounds. This project implements a 16-bit Fibonacci Linear Feedback Shift Register (LFSR) to encrpyt and decrpyt images by transforming pixel colors using bitwise XOR. It uses SFML for image preprocessing and the Boost library to validate the LFSR's correctness through unit testing.

---

## Requirements

- **C++ compiler** (e.g., `g++`, `clang++`)
- **SFML 2.5.1+**

## 💻 Installation (macOS)

### Install SFML via Homebrew
```bash
brew install sfml
```

### Build Instructions
1. Clone or Download the Repository
```bash
git clone https://github.com/wubae/photomagic.git
cd Hexaflake
```

2. Build the Project Using `make`
```bash
make
```

3. Run the Program

Example:
```bash
./PhotoMagic input.png output.png 1011011000110110
```

### Screenshots
#### Input Image
![Input File](/input-file.png)

#### Decoding
![Decoding](/decoding_screenshot.png)

#### Encoding
![Encoding](/encoding_screenshot.png)
