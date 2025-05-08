// Copyright [2023] <Wu Li> [legal/copyright]
#ifndef _HOME_WU_PS1_FIBLFSR_HPP_
#define _HOME_WU_PS1_FIBLFSR_HPP_

#include <iostream>
#include <string>

class FibLFSR {
 public:
    // Constructor to create LFSR with the given initial seed
    explicit FibLFSR(std::string seed) : tap(seed) {}
    // Simulate one step and return the new bit as 0 or 1
    int step();
    // Simulate k steps and return a k-bit integer
    int generate(int k);
    // Overloaded friend << stream insertion operator to display
    friend std::ostream& operator<<(std::ostream& out, const FibLFSR& lfsr);
 private:
    // Any fields that you need
    std::string tap;
};

#endif  // _HOME_WU_PS1_FIBLFSR_HPP_
