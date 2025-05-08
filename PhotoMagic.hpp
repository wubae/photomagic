// Copyright [2023] <Wu Li> [legal/copyright]
#ifndef _HOME_WU_PS1_PHOTOMAGIC_HPP_
#define _HOME_WU_PS1_PHOTOMAGIC_HPP_

#include <iostream>
#include <string>
#include "FibLFSR.hpp"

namespace PhotoMagic {
// Transforms image using FibLFSR
void transform(sf::Image&, FibLFSR*);
// Display an encrypted copy of the picture, using the LFSR to do the
// encryption
}

#endif  // _HOME_WU_PS1_FIBLFSR_HPP_
