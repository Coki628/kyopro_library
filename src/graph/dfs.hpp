#include "../macros.hpp"

// 木DP用定型部分
auto dfs = [&](auto&& f, int u, int prv) -> void {
    for (auto v : nodes[u]) {
        if (v == prv) continue;
        f(f, v, u);
    }
};
