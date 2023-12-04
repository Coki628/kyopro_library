#pragma once
#include "../base.hpp"

// Aho-Corasick
// 参考：https://ei1333.github.io/library/string/aho-corasick.hpp
// 使い方
// ・初期化は、AhoCorasick<文字種類数, 最初の文字>
// ・addでパターン文字列を全部詰めてからbuildして、その後moveやmatchを使う。
// ・match(str, now): 現状態がnowで、文字列strが現れた時に、新たに各パターン文字列にマッチした回数を返す。
// ・move(c, now): 現状態がnowで, 文字cが現れたときに、新たにパターン文字列にマッチした個数と、次状態を返す。
template<int char_size>
struct TrieNode {
    int nxt[char_size];

    int exist;
    vector<int> accept;

    TrieNode() : exist(0) {
        memset(nxt, -1, sizeof(nxt));
    }
};

template<int char_size, int margin>
struct Trie {
    using Node = TrieNode<char_size>;

    vector<Node> nodes;
    int root;

    Trie() : root(0) {
        nodes.push_back(Node());
    }

    void update_direct(int node, int id) {
        nodes[node].accept.push_back(id);
    }

    void update_child(int node, int child, int id) {
        ++nodes[node].exist;
    }

    void add(const string &str, int str_index, int node_index, int id) {
        if (str_index == str.size()) {
            update_direct(node_index, id);
        } else {
            const int c = str[str_index] - margin;
            if (nodes[node_index].nxt[c] == -1) {
                nodes[node_index].nxt[c] = (int)nodes.size();
                nodes.push_back(Node());
            }
            add(str, str_index + 1, nodes[node_index].nxt[c], id);
            update_child(node_index, nodes[node_index].nxt[c], id);
        }
    }

    void add(const string &str, int id) {
        add(str, 0, 0, id);
    }

    void add(const string &str) {
        add(str, nodes[0].exist);
    }

    void query(
        const string &str, const function<void(int)> &f, int str_index,
        int node_index
    ) {
        for (auto &idx : nodes[node_index].accept) f(idx);
        if (str_index == str.size()) {
            return;
        } else {
            const int c = str[str_index] - margin;
            if (nodes[node_index].nxt[c] == -1) return;
            query(str, f, str_index + 1, nodes[node_index].nxt[c]);
        }
    }

    void query(const string &str, const function<void(int)> &f) {
        query(str, f, 0, 0);
    }

    int count() const {
        return (nodes[0].exist);
    }

    int size() const {
        return ((int)nodes.size());
    }
};

template<int char_size, int margin>
struct AhoCorasick : Trie<char_size + 1, margin> {
    using Trie<char_size + 1, margin>::Trie;

    const int FAIL = char_size;
    vector<int> correct;

    void build(bool heavy = true) {
        correct.resize(this->size());
        for (int i = 0; i < this->size(); i++) {
            correct[i] = (int)this->nodes[i].accept.size();
        }
        queue<int> que;
        for (int i = 0; i <= char_size; i++) {
            if (~this->nodes[0].nxt[i]) {
                this->nodes[this->nodes[0].nxt[i]].nxt[FAIL] = 0;
                que.emplace(this->nodes[0].nxt[i]);
            } else {
                this->nodes[0].nxt[i] = 0;
            }
        }
        while (!que.empty()) {
            auto &now = this->nodes[que.front()];
            int fail = now.nxt[FAIL];
            correct[que.front()] += correct[fail];
            que.pop();
            for (int i = 0; i < char_size; i++) {
                if (~now.nxt[i]) {
                    this->nodes[now.nxt[i]].nxt[FAIL] =
                        this->nodes[fail].nxt[i];
                    if (heavy) {
                        auto &u = this->nodes[now.nxt[i]].accept;
                        auto &v = this->nodes[this->nodes[fail].nxt[i]].accept;
                        vector<int> accept;
                        set_union(
                            begin(u), end(u), begin(v), end(v),
                            back_inserter(accept)
                        );
                        u = accept;
                    }
                    que.emplace(now.nxt[i]);
                } else {
                    now.nxt[i] = this->nodes[fail].nxt[i];
                }
            }
        }
    }

    map<int, int> match(const string &str, int now = 0) {
        map<int, int> result;
        for (auto &c : str) {
            now = this->nodes[now].nxt[c - margin];
            for (auto &v : this->nodes[now].accept) result[v] += 1;
        }
        return result;
    }

    // Trie木上の位置nowにいて、次に文字cを使った時に、パターン文字列にマッチした個数と次の位置cを返す
    pair<int64_t, int> move(const char &c, int now = 0) {
        now = this->nodes[now].nxt[c - margin];
        return {correct[now], now};
    }

    pair<int64_t, int> move(const string &str, int now = 0) {
        int64_t sum = 0;
        for (auto &c : str) {
            auto nxt = move(c, now);
            sum += nxt.first;
            now = nxt.second;
        }
        return {sum, now};
    }
};
