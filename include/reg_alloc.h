#pragma once
#include <vector>
#include <string>
#include <map>
#include <set>
#include "../include/codegen.h"

std::map<std::string, std::string> allocateRegisters(std::vector<Instruction>& insts, int k);