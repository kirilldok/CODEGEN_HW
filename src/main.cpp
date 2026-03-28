#include "../include/codegen.h"
#include "../include/schelduler.h"
#include <iostream>

int main() {
    // Внутренний цикл: result += 30 * a[j] - i - 2
    // j инкрементируется на 2 (так как четные j пропускаются)
    std::vector<Instruction> innerBlock = {
        {0, Op::SLLI, "t0", {"j"}, 1},        // offset = j * 4
        {1, Op::ADD,  "t1", {"a", "t0"}, 1},  // addr = a + offset
        {2, Op::LW,   "t2", {"t1"}, 2},       // val = *addr
        {3, Op::LI,   "t3", {}, 1},           // t3 = 30 (const)
        {4, Op::MUL,  "t4", {"t2", "t3"}, 3}, // t4 = val * 30
        {5, Op::SUB,  "t4", {"t4", "i"}, 1},  // t4 = t4 - i
        {6, Op::ADDI, "res", {"res"}, 1},     // res = res - 2
        {7, Op::ADD,  "res", {"res", "t4"}, 1}
    };

    std::cout << "--- Исходный выбор инструкций ---" << std::endl;

    auto scheduled = schedule(innerBlock);
    std::cout << "\n--- После планирования (List Scheduling) ---" << std::endl;
    for (auto& inst : scheduled) std::cout << "ID: " << inst.id << " Op: " << (int)inst.op << std::endl;

    return 0;
}