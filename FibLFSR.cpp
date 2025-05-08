// Copyright [2023] <Wu Li> [legal/copyright]
#include "FibLFSR.hpp"

// Simulate a step of the LFSR and return the new rightmost bit
int FibLFSR::step() {
    int xor_output = tap.at(tap.size() - 15 - 1);

    // 3 taps in positions 13, 12, and 10
    xor_output ^= tap.at(tap.size() - 13 - 1);
    xor_output ^= tap.at(tap.size() - 12 - 1);
    xor_output ^= tap.at(tap.size() - 10 - 1);

    // Append 1 if xor_output is true (1)
    if (xor_output) {
        xor_output = 1;
        tap.append("1");
    }
    // Append 0 if xor_output is false (0)
    if (!xor_output) {
        xor_output = 0;
        tap.append("0");
    }

    // Erase the leftmost bit
    tap.erase(0, 1);

    return xor_output;
}

// Takes an integer k as an argument and returns a k-bit integer
// simulating k steps of the LFSR
int FibLFSR::generate(int k) {
    // Initialize variable to 0
    int variable = 0;

    for (int i = 0; i < k; i++) {
        // Double the variable and add the bit returned by step()
        variable = (variable * 2) + (FibLFSR::step());
    }

    return variable;
}
// Overloaded stream insertion operator
std::ostream& operator<<(std::ostream& out, const FibLFSR& lfsr) {
    out << lfsr.tap;
    return out;
}
