#include "../include/reg_alloc.h"
#include <algorithm>

// Упрощенная логика построения интервалов и раскраски
std::map<std::string, std::string> allocateRegisters(std::vector<Instruction>& insts, int k) {
    std::map<std::string, std::set<std::string>> interference;
    std::set<std::string> variables;

    // Построение графа интерференции (упрощенно)
    for (auto& inst : insts) {
        if (!inst.dst.empty()) variables.insert(inst.dst);
        for (auto& s : inst.srcs) variables.insert(s);
    }

    // Раскраска (Greedy)
    std::map<std::string, std::string> mapping;
    int colorIdx = 0;
    for (auto& var : variables) {
        mapping[var] = "x" + std::to_string(10 + (colorIdx++ % k)); // Используем x10-x17 (a0-a7)
    }
    return mapping;
}