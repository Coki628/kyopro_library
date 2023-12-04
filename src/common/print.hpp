#pragma once
#include "../macros.hpp"

// pair
template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
    return os << p.first << ' ' << p.second;
}

// tuple
// see: https://gist.github.com/naskya/1e5e5cd269cfe16a76988378a60e2ca3#file-debug_print-hpp-L150
template<class T, size_t... Is>
void print_tuple(ostream &os, const T &arg, index_sequence<Is...>) {
    static_cast<void>(((os << (Is == 0 ? "" : " "), os << get<Is>(arg)), ...));
}
template<class... Ts>
ostream &operator<<(ostream &os, const tuple<Ts...> &arg) {
    print_tuple(os, arg, make_index_sequence<sizeof...(Ts)>());
    return os;
}

// 旧仕様。新仕様である程度動作問題ない確認が取れたら削除
// template<typename T1, typename T2, typename T3>
// ostream &operator<<(ostream &os, const tuple<T1, T2, T3> &tp) {
//     return os << get<0>(tp) << ' ' << get<1>(tp) << ' ' << get<2>(tp);
// }
// template<typename T1, typename T2, typename T3, typename T4>
// ostream &operator<<(ostream &os, const tuple<T1, T2, T3, T4> &tp) {
//     return os << get<0>(tp) << ' ' << get<1>(tp) << ' ' << get<2>(tp) << ' ' << get<3>(tp);
// }
// template<typename T1, typename T2, typename T3>
// void print(const tuple<T1, T2, T3> &tp) {
//     cout << get<0>(tp) << ' ' << get<1>(tp) << ' ' << get<2>(tp) << '\n';
// }
// template<typename T1, typename T2, typename T3, typename T4>
// void print(const tuple<T1, T2, T3, T4> &tp) {
//     cout << get<0>(tp) << ' ' << get<1>(tp) << ' ' << get<2>(tp) << ' ' << get<3>(tp) << '\n';
// }

// vector
template<typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
    rep(i, vec.size()) {
        os << vec[i];
        if (i != (int)vec.size() - 1) {
            os << ' ';
        }
    }
    return os;
}
template<typename T>
void print(const vector<T> &vec, string sep = " ") {
    rep(i, vec.size()) {
        cout << vec[i];
        if (i != (int)vec.size() - 1) cout << sep;
    }
    cout << '\n';
}

// array
template<typename T, size_t N>
ostream &operator<<(ostream &os, const array<T, N> &arr) {
    rep(i, N) {
        os << arr[i];
        if (i != (int)N - 1) {
            os << ' ';
        }
    }
    return os;
}
template<typename T, size_t N>
void print(const array<T, N> &arr, string sep = " ") {
    rep(i, N) {
        cout << arr[i];
        if (i != (int)N - 1) cout << sep;
    }
    cout << '\n';
}

// deque
template<typename T>
void print(const deque<T> &que, string sep = " ") {
    vector<T> vec(ALL(que));
    print(vec, sep);
}

// set
template<typename T>
void print(const set<T> &se, string sep = " ") {
    vector<T> vec(ALL(se));
    print(vec, sep);
}

// set, multiset, deque, etc...
// ※とても汎用性高いんだけど、stringまで取り込まれてvectorにされてしまうので使わない
// template<template<typename T>class Container, typename T>
// void print(const Container<T>& con, string sep=" ") {
//     vector<T> V(ALL(con));
//     print(V, sep);
// }

// initializer_list (「print({1, 2, 3, 4});」とかできる)
template<typename T>
void print(const initializer_list<T> &li, string sep = " ") {
    vector<T> V(ALL(li));
    print(V, sep);
}

// 可変長引数。operator<<が定義されてさえいれば、型が違う同士でも雑多に並べて出力できる
// ※print(vector, "\n")とかもここに来てしまったので一旦中止
// template<typename T, typename... Ts>
// void print(const T val, Ts... ts) {
//     if constexpr (sizeof...(Ts) == 0) {
//         cout << val << '\n';
//     } else {
//         cout << val << ' ';
//         print(ts...);
//     }
// }

// 改行のみ
void print() {
    cout << '\n';
}

// その他 (pair,tuple,string等もここに来てoperator<<に渡される)
template<typename T>
void print(T out) {
    cout << out << '\n';
}

// debug (変数名付きで出力、stderrなので提出を邪魔しない)
// #define debug(x) (cerr << #x << ": " << x << endl);
// 可変長引数対応版
// see: https://blog.naskya.net/post/meu0vkh5cpl1/
#define debug(...) multi_debug(#__VA_ARGS__, __VA_ARGS__)
template<class Tp, class... Ts>
void multi_debug(string names, Tp arg, Ts... args) {
    // args...のパラメータが0個のとき、単にargだけを出力して終了
    if constexpr (sizeof...(Ts) == 0) {
        while (names.back() == ' ') {
            names.pop_back();
        }
        cerr << names << ": " << arg << endl;
    } else {
        // namesには全部の変数の名前が格納されているので、1つ目の変数名の終わりの','の位置を探す
        int n = names.size(), comma_pos = -1, paren_depth = 0,
            inside_quote = false;
        rep(i, n) {
            if (not inside_quote and paren_depth == 0 and names[i] == ',') {
                comma_pos = i;
                break;
            }
            if (names[i] == '\"' or names[i] == '\'') {
                if (i > 0 and names[i - 1] == '\\') continue;
                inside_quote ^= true;
            }
            if (not inside_quote and names[i] == '(') {
                paren_depth++;
            }
            if (not inside_quote and names[i] == ')') {
                paren_depth--;
            }
        }
        assert(comma_pos != -1);
        string name = names.substr(0, comma_pos);
        while (name.back() == ' ') {
            name.pop_back();
        }
        cerr << name << ": " << arg << endl;

        int next_begin_at = comma_pos + 1;
        while (names[next_begin_at] == ' ') {
            next_begin_at++;
        }
        names = names.substr(next_begin_at);
        // この関数を再帰的に呼んで残りの変数も出力する
        multi_debug(names, args...);
    }
}

// 後方互換
template<typename T>
void print(const vector<T> &V, char sep) {
    print(V, string{sep});
}
template<typename T, size_t N>
void print(const array<T, N> &arr, char sep) {
    print(arr, string{sep});
}

// TODO：そのうち自動実行とかできるようにする。
// test cases for print() and cout <<
// pair<char, int> p = {'a', 1};
// cout << p << '\n';
// print(p);
// tuple<char, int, ll, string> tp = {'a', 1, 2, "abc"};
// cout << tp << '\n';
// print(tp);
// vector<ll> vec = {1, 2, 3, 4, 5};
// cout << vec << '\n';
// print(vec);
// print(vec, "\n");
// array<ll, 5> arr = {1, 2, 3, 4, 5};
// cout << arr << '\n';
// print(arr);
// print(arr, "\n");
// deque<ll> que = {1, 2, 3, 4, 5};
// print(que);
// print(que, "\n");
// set<ll> se = {1, 2, 3, 4, 5};
// print(se);
// print(se, "\n");
// print({1, 2, 3, 4, 5});
// print({1, 2, 3, 4, 5}, "\n");
// print();
// ll a = 100;
// cout << a << '\n';
// print(a);
// print(100);
// string S = "abc";
// cout << S << '\n';
// print(S);
// print("abc");
// char c = 'a';
// cout << c << '\n';
// print(c);
// print('a');
// // print(1, "abc", 22LL);
// // print(s, c);

// test cases for debug()
// int a = 2;
// string b = "agc";
// char c = 'z';
// ll d = 10000;
// debug(a,  b, "aaa", 'y', c,d, max((ll)a, d));
