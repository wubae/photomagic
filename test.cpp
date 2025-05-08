// Copyright 2022
// By Dr. Rykalova
// Editted by Dr. Daly
// test.cpp for PS1a
// updated 5/12/2022

#include <iostream>
#include <string>

#include "FibLFSR.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

// First Test
BOOST_AUTO_TEST_CASE(testStepInstr1) {
  FibLFSR l("1011011000110110");
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 1);
  BOOST_REQUIRE_EQUAL(l.step(), 1);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 1);
}

// Second Test
BOOST_AUTO_TEST_CASE(testStepInstr2) {
  FibLFSR m("1011011000110110");
  BOOST_REQUIRE_EQUAL(m.generate(9), 51);
}

// Third Test
// 32-bit
BOOST_AUTO_TEST_CASE(testStepInstr3) {
  FibLFSR l("01001010101011110010010101110011");
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 1);
  BOOST_REQUIRE_EQUAL(l.step(), 1);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 1);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 1);
}

// Fourth Test
// 32-bit
BOOST_AUTO_TEST_CASE(testStepInstr4) {
  FibLFSR m("01001010101011110010010101110011");
  BOOST_REQUIRE_EQUAL(m.generate(5), 6);
}

// Fifth Test
// 64-bit
BOOST_AUTO_TEST_CASE(testStepInstr5) {
  FibLFSR l("1000011110010110100101111111110011111100110100101101101100111110");
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 1);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 1);
}

// Sixth Test
// 64-bit
BOOST_AUTO_TEST_CASE(testStepInstr6) {
  FibLFSR m("1000011110010110100101111111110011111100110100101101101100111110");
  BOOST_REQUIRE_EQUAL(m.generate(8), 9);
}
