#include "../base.hpp"
#include "acl/mincostflow.hpp"
#include "bellman_ford.hpp"

// 最小費用流
// 使い方
// ・復元はedgesを呼び出して頂点番号とか流量確認しながらゴニョゴニョやる。(practice2_eなど)
// ・最終的な流量だけでなく途中経過も欲しい場合はslopeが使える。
// 　折れ線グラフが返されるので、必要に応じて間の値は計算する。(abc247_g)
// ・基本的にACLに準じているので、ACLのと同じように使える。
// ・追加点としては、どう下駄を履かせるか考えずに負辺ありをそのまま渡せるようにしてある。
// 　内部ではベルマンフォードを回してポテンシャルを計算してる。
// 　ベルマンフォードは2乗オーダーだけど、そもそも最小費用流自体が線形logとか無理だと思うので、
// 　大概の場合はこれで問題ないと思う。
// 　でもフローで構築するグラフはほぼ閉路なしのDAGだと思うので、
// 　DAGであればDPでもポテンシャルは求まるとのこと。
// 参考：https://niuez.hatenablog.com/entry/2019/03/04/142903
// 　　　https://ikatakos.com/pot/programming_algorithm/graph_theory/minimum_cost_flow
// 最小費用流関係の用語について
// ・最小費用最大流(AOJ1088など)
// 　「流量優先で一番多く流して、その時の流量とコスト」を取得する。
// 　ACLの場合は流量指定に対して、それに達するまでできる限り最大限流して、
// 　無理ならそれに近い最大まで流すような仕様なので、特に気にしなくてもこれが取得できる。
// 　なお、flowを呼ぶ時に第三引数を省略すれば勝手にnumeric_limits::max()まで流してくれるので、
// 　それでもいいし、もちろん自分で想定される最大流量を指定してもいい。
// ・任意流量の最小費用流(AOJ2293、practice2_eなど)
// 　「流量は任意、コスト優先で流して、その時の流量とコスト」を取得する。
// 　流量は何でもいいから利得最大が取りたい、みたいな時に使う。
// 　これをやるためには、始点から終点へ流量無制限の直通辺を張る必要がある。
// 　そうすれば本来の辺で流し切れない分は全てこちらに流れるので、
// 　流量は常に最大、その中で利得が高いものが選ばれて、これが取得できる。
// 　流量無制限は適当にINFでも構わないが、注意点として、
// 　flowを呼ぶ時に直通辺の流量より大きい値を指定しないことがある。
// 　これが大きいと流量が優先されてしまい、利得最大が取れない可能性がある。
template<typename Cap, typename Cost>
struct MinCostFlow : atcoder::mcf_graph<Cap, Cost> {
    using base_type = atcoder::mcf_graph<Cap, Cost>;

    int N;
    bool has_negative = false;
    vector<tuple<int, int, Cost>> temp_edges;
    vector<Cap> caps;
    vector<Cost> potential;

    MinCostFlow(int N) : base_type(N), N(N), has_negative(false) {
        potential.assign(N, 0);
    }

    int add_edge(int from, int to, Cap cap, Cost cost) {
        if (cost < 0) {
            has_negative = true;
        }
        int m = temp_edges.size();
        temp_edges.emplace_back(from, to, cost);
        caps.emplace_back(cap);
        return m;
    }

    void build(int s) {
        if (has_negative) {
            potential = bellman_ford(N, temp_edges, s);
            for (int i = 0; i < N; i++) {
                // sから到達不可の点のことは考えてなくていい
                if (potential[i] >= INF) {
                    potential[i] = 0;
                }
                // 負閉路はないものとする
                assert(potential[i] > -INF);
            }
        }
        for (int i = 0; i < temp_edges.size(); i++) {
            auto [from, to, cost] = temp_edges[i];
            base_type::add_edge(from, to, caps[i], cost + potential[from] - potential[to]);
        }
    }

    pair<Cap, Cost> flow(int s, int t) {
        return flow(s, t, numeric_limits<Cap>::max());
    }
    pair<Cap, Cost> flow(int s, int t, Cap flow_limit) {
        return slope(s, t, flow_limit).back();
    }
    vector<pair<Cap, Cost>> slope(int s, int t) {
        return slope(s, t, numeric_limits<Cap>::max());
    }
    vector<pair<Cap, Cost>> slope(int s, int t, Cap flow_limit) {
        build(s);
        auto result = base_type::slope(s, t, flow_limit);
        if (has_negative) {
            for (auto &[flow, cost] : result) {
                cost += (potential[t] - potential[s]) * flow;
            }
        }
        return result;
    }
};
