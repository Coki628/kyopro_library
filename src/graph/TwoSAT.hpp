#pragma once
#include "../acl/twosat.hpp"

// 2-SAT
// 参考：https://suisen-cp.github.io/cp-library-cpp/library/algorithm/two_sat.hpp
// ・ACLをラップして、直感的なメソッドをたくさん生やしておいた。
struct TwoSAT : public atcoder::two_sat {
    using base_type = atcoder::two_sat;
    using base_type::base_type;

    virtual void add_clause(int i, bool f, int j, bool g) {
        base_type::add_clause(i, f, j, g);
    }

    // A or B
    void a_or_b(int a, int b) {
        add_clause(a, true, b, true);
    }

    // A and B
    void a_and_b(int a, int b) {
        add_clause(a, true, a, true);
        add_clause(b, true, b, true);
    }

    // A xor B
    void a_xor_b(int a, int b) {
        add_clause(a, true, b, true);
        add_clause(a, false, b, false);
    }

    // AかつB、がダメ
    // not (A and B)
    void not_a_and_b(int a, int b) {
        add_clause(a, false, b, false);
    }

    // AかつBではない、がダメ
    // not (A and !B)
    void not_a_and_nb(int a, int b) {
        add_clause(a, false, b, true);
    }

    // AではないかつB、がダメ
    // not (A! and B)
    void not_na_and_b(int a, int b) {
        add_clause(a, true, b, false);
    }

    // AではないかつBではない、がダメ
    // not (!A and !B)
    void not_na_and_nb(int a, int b) {
        add_clause(a, true, b, true);
    }

    // AならばB
    void a_then_b(int a, int b) {
        not_a_and_nb(a, b);
    }

    // a=fが必須
    void a_is_f(int a, bool f) {
        add_clause(a, f, a, f);
    }
};
