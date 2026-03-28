#pragma once
#include <vector>
#include <string>
#include <set>
#include <map>

enum class Op { LI, LW, ADD, ADDI, SUB, MUL, SLLI, BLT, RET };

struct Instruction {
    int id;
    Op op;
    std::string dst;
    std::vector<std::string> srcs;
    int latency = 1; // Циклы (LW=2, MUL=3, остальные=1)

    Instruction(int i, Op o, std::string d, std::vector<std::string> s, int l = 1)
        : id(i), op(o), dst(d), srcs(s), latency(l) {}
};