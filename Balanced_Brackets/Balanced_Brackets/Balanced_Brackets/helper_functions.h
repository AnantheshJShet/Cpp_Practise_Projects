#ifndef HELPER_FUNCTIONS_H
#define HELPER_FUNCTIONS_H

#include<iostream>
#include<string>

#include "typedefs.h"

extern bool isWithinBounds(const uint32 var, const uint32 min, const uint32 max);
extern bool isOpeningBracket(const char ch);
extern bool isClosingBracket(const char ch);
extern bool isBracket(const char ch);
extern bool seqContainsOnlyBrackets(const std::string seq);
extern bool areBracketsBalanced(const char open, const char close);

#endif