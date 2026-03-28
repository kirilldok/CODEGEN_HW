#include "../include/scheduler.h"
#include <queue>

std::vector<Instruction> schedule(std::vector<Instruction>& block) {
    std::vector<Instruction> scheduled;
    std::map<int, int> in_degree;
    std::map<int, std::vector<int>> adj;

    // Построение графа зависимостей (RAW)
    for (size_t i = 0; i < block.size(); ++i) {
        for (size_t j = i + 1; j < block.size(); ++j) {
            for (auto& src : block[j].srcs) {
                if (src == block[i].dst) {
                    adj[block[i].id].push_back(block[j].id);
                    in_degree[block[j].id]++;
                }
            }
        }
    }

    auto cmp = [&](int a, int b) { return block[a].latency < block[b].latency; };
    std::priority_queue<int, std::vector<int>, decltype(cmp)> ready(cmp);

    for (auto& inst : block) {
        if (in_degree[inst.id] == 0) ready.push(inst.id);
    }

    while (!ready.empty()) {
        int curr_id = ready.top();
        ready.pop();
        scheduled.push_back(block[curr_id]);

        for (int neighbor : adj[curr_id]) {
            in_degree[neighbor]--;
            if (in_degree[neighbor] == 0) ready.push(neighbor);
        }
    }
    return scheduled;
}