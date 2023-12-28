---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://blog.naskya.net/post/meu0vkh5cpl1/
  bundledCode: "#line 2 \"src/base.hpp\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 3 \"src/common/debug_print.hpp\"\n\n// see: https://blog.naskya.net/post/meu0vkh5cpl1/\n\
    // \u30FB\u306A\u3093\u3067\u3082\u8AAD\u3081\u308B\u5F37\u529B\u306A\u30C7\u30D0\
    \u30C3\u30B0\u51FA\u529B\u3002\n// \u3000\u30B3\u30FC\u30C9\u9577\u304C\u3068\u3066\
    \u3082\u9577\u3044\u306E\u3067\u666E\u6BB5\u4F7F\u3044\u306F\u3057\u3066\u3044\
    \u306A\u3044\u304C\u3001\u53C2\u8003\u306B\u306A\u308B\u90E8\u5206\u3082\u591A\
    \u3044\u305F\u3081\u53D6\u3063\u3066\u304A\u304F\u3002\n\n#ifdef __LOCAL\n\n#ifndef\
    \ DEBUG_PRINT_HPP\n#define DEBUG_PRINT_HPP\n\n#define INCLUDED(n) ((defined _GLIBCXX_##n)\
    \ || (defined _LIBCPP_##n))\n\n#if __cplusplus < 201703L\n#warning Please use\
    \ C++17 (or later version).\n#endif\n#if !INCLUDED(ALGORITHM)\n#warning Please\
    \ include <algorithm> before including debug_print.hpp.\n#endif\n#if !INCLUDED(CCTYPE)\n\
    #warning Please include <cctype> before including debug_print.hpp.\n#endif\n#if\
    \ !INCLUDED(IOSTREAM)\n#warning Please include <iostream> before including debug_print.hpp.\n\
    #endif\n#if !INCLUDED(ITERATOR)\n#warning Please include <iterator> before including\
    \ debug_print.hpp.\n#endif\n#if !INCLUDED(STRING_VIEW)\n#warning Please include\
    \ <string_view> before including debug_print.hpp.\n#endif\n#if !INCLUDED(TYPE_TRAITS)\n\
    #warning Please include <type_traits> before including debug_print.hpp.\n#endif\n\
    \nnamespace debug_print {\nstd::ostream &os = std::cerr;\n\ntemplate<class Tp>\n\
    auto has_cbegin(int)\n    -> decltype(std::cbegin(std::declval<Tp>()), std::true_type{});\n\
    template<class Tp>\nauto has_cbegin(...) -> std::false_type;\ntemplate<class Tp>\n\
    auto has_value_type(int)\n    -> decltype(std::declval<typename Tp::value_type>(),\
    \ std::true_type{});\ntemplate<class Tp>\nauto has_value_type(...) -> std::false_type;\n\
    \ntemplate<class Tp>\n[[maybe_unused]] constexpr bool is_iterable_container_v\
    \ =\n    decltype(has_cbegin<Tp>(int{}))::value;\ntemplate<class Tp>\n[[maybe_unused]]\
    \ constexpr bool is_container_v =\n    decltype(has_value_type<Tp>(int{}))::value\
    \ || is_iterable_container_v<Tp>;\n\ntemplate<>\n[[maybe_unused]] constexpr bool\
    \ is_iterable_container_v<std::string_view> =\n    false;\ntemplate<>\n[[maybe_unused]]\
    \ constexpr bool is_container_v<std::string_view> = false;\n#if INCLUDED(STRING)\n\
    template<>\n[[maybe_unused]] constexpr bool is_iterable_container_v<std::string>\
    \ = false;\ntemplate<>\n[[maybe_unused]] constexpr bool is_container_v<std::string>\
    \ = false;\n#endif\n\ntemplate<class Tp, class... Ts>\nstruct first_element {\n\
    \    using type = Tp;\n};\ntemplate<class... Ts>\nusing first_t = typename first_element<Ts...>::type;\n\
    \ntemplate<\n    class Tp,\n    std::enable_if_t<\n        !decltype(has_value_type<Tp>(int{}))::value,\
    \ std::nullptr_t> = nullptr>\nauto check_elem(int) -> decltype(*std::cbegin(std::declval<Tp>()));\n\
    template<\n    class Tp,\n    std::enable_if_t<\n        decltype(has_value_type<Tp>(int{}))::value,\
    \ std::nullptr_t> = nullptr>\nauto check_elem(int) -> typename Tp::value_type;\n\
    template<class Tp>\nauto check_elem(...) -> void;\n\ntemplate<class Tp>\nusing\
    \ elem_t = decltype(check_elem<Tp>(int{}));\n\ntemplate<class Tp>\n[[maybe_unused]]\
    \ constexpr bool is_multidim_container_v =\n    is_container_v<Tp> && is_container_v<elem_t<Tp>>;\n\
    \ntemplate<class Tp>\nstd::enable_if_t<!is_container_v<Tp>> out(const Tp &);\n\
    void out(const char &);\nvoid out(const char *);\nvoid out(const std::string_view\
    \ &);\n\n#if INCLUDED(STRING)\nvoid out(const std::string &);\n#endif\n\n#ifdef\
    \ __SIZEOF_INT128__\nvoid out(const __int128 &);\nvoid out(const unsigned __int128\
    \ &);\n#endif\n\ntemplate<class Tp1, class Tp2>\nvoid out(const std::pair<Tp1,\
    \ Tp2> &);\n\n#if INCLUDED(TUPLE)\ntemplate<class... Ts>\nvoid out(const std::tuple<Ts...>\
    \ &);\n#endif\n\n#if INCLUDED(STACK)\ntemplate<class... Ts>\nvoid out(std::stack<Ts...>);\n\
    #endif\n\n#if INCLUDED(QUEUE)\ntemplate<class... Ts>\nvoid out(std::queue<Ts...>);\n\
    template<class... Ts>\nvoid out(std::priority_queue<Ts...>);\n#endif\n\ntemplate<class\
    \ C>\nstd::enable_if_t<is_iterable_container_v<C>> out(const C &);\n\ntemplate<class\
    \ Tp>\nstd::enable_if_t<!is_container_v<Tp>> out(const Tp &arg) {\n    os << arg;\n\
    }\n\nvoid out(const char &arg) {\n    os << '\\'' << arg << '\\'';\n}\n\nvoid\
    \ out(const char *arg) {\n    os << '\\\"' << arg << '\\\"';\n}\n\nvoid out(const\
    \ std::string_view &arg) {\n    os << '\\\"' << arg << '\\\"';\n}\n\n#if INCLUDED(STRING)\n\
    void out(const std::string &arg) {\n    os << '\\\"' << arg << '\\\"';\n}\n#endif\n\
    \n#ifdef __SIZEOF_INT128__\nvoid out(const __int128 &arg) {\n    int sign = (arg\
    \ < 0) ? (-1) : 1;\n    if (sign == -1) os << '-';\n    __int128 base = sign;\n\
    \    while (sign * arg >= sign * base * 10) base *= 10;\n    while (base) {\n\
    \        os << static_cast<char>('0' + (arg / base % 10));\n        base /= 10;\n\
    \    }\n}\n\nvoid out(const unsigned __int128 &arg) {\n    unsigned __int128 base\
    \ = 1;\n    while (arg >= base * 10) base *= 10;\n    while (base) {\n       \
    \ os << static_cast<char>('0' + (arg / base % 10));\n        base /= 10;\n   \
    \ }\n}\n#endif\n\ntemplate<class Tp1, class Tp2>\nvoid out(const std::pair<Tp1,\
    \ Tp2> &arg) {\n    os << '(';\n    out(arg.first);\n    os << \", \";\n    out(arg.second);\n\
    \    os << ')';\n}\n\n#if INCLUDED(TUPLE)\ntemplate<class T, std::size_t... Is>\n\
    void print_tuple(const T &arg, std::index_sequence<Is...>) {\n    static_cast<void>(\n\
    \        ((os << (Is == 0 ? \"\" : \", \"), out(std::get<Is>(arg))), ...)\n  \
    \  );\n}\n\ntemplate<class... Ts>\nvoid out(const std::tuple<Ts...> &arg) {\n\
    \    os << '(';\n    print_tuple(arg, std::make_index_sequence<sizeof...(Ts)>());\n\
    \    os << ')';\n}\n#endif\n\n#if INCLUDED(STACK)\ntemplate<class... Ts>\nvoid\
    \ out(std::stack<Ts...> arg) {\n    os << \"[\";\n    while (!arg.empty()) {\n\
    \        out(arg.top());\n        if (arg.size() > 1) {\n            os << \"\
    , \";\n        }\n        arg.pop();\n    }\n    os << ']';\n}\n#endif\n\n#if\
    \ INCLUDED(QUEUE)\ntemplate<class... Ts>\nvoid out(std::queue<Ts...> arg) {\n\
    \    os << \"[\";\n    while (!arg.empty()) {\n        out(arg.front());\n   \
    \     if (arg.size() > 1) {\n            os << \", \";\n        }\n        arg.pop();\n\
    \    }\n    os << ']';\n}\ntemplate<class... Ts>\nvoid out(std::priority_queue<Ts...>\
    \ arg) {\n    os << \"[\";\n    while (!arg.empty()) {\n        out(arg.top());\n\
    \        if (arg.size() > 1) {\n            os << \", \";\n        }\n       \
    \ arg.pop();\n    }\n    os << ']';\n}\n#endif\n\ntemplate<class Container>\n\
    std::enable_if_t<is_iterable_container_v<Container>> out(const Container &arg)\
    \ {\n    int sz = std::distance(std::cbegin(arg), std::cend(arg));\n    os <<\
    \ \"[\";\n    int i = 0;\n    std::for_each(\n        std::cbegin(arg), std::cend(arg),\n\
    \        [sz, &i](const elem_t<Container> &elem) {\n            out(elem);\n \
    \           if (i < sz - 1) {\n                os << \", \";\n            }\n\
    \            i++;\n        }\n    );\n    os << ']';\n}\n\ntemplate<class Tp>\n\
    std::enable_if_t<!is_multidim_container_v<Tp>>\nprint(std::string_view name, const\
    \ Tp &arg) {\n    os << name << \": \";\n    out(arg);\n    if constexpr (is_container_v<Tp>)\
    \ os << std::endl;\n}\n\ntemplate<class Tp>\nstd::enable_if_t<is_multidim_container_v<Tp>>\n\
    print(std::string_view name, const Tp &arg) {\n    os << name << \": \";\n   \
    \ if (std::distance(std::cbegin(arg), std::cend(arg)) == 0) {\n        os << \"\
    []\" << std::endl;\n        return;\n    }\n    std::for_each(\n        std::cbegin(arg),\
    \ std::cend(arg),\n        [&name, is_first_elem = true](const elem_t<Tp> &elem)\
    \ mutable {\n            if (is_first_elem) is_first_elem = false;\n         \
    \   else\n                for (std::size_t i = 0; i < name.length() + 2; i++)\
    \ os << ' ';\n            out(elem);\n            os << std::endl;\n        }\n\
    \    );\n}\n\ntemplate<class Tp, class... Ts>\nvoid multi_print(std::string_view\
    \ names, const Tp &arg, const Ts &...args) {\n    if constexpr (sizeof...(Ts)\
    \ == 0) {\n        names.remove_suffix(std::distance(\n            names.crbegin(),\
    \ std::find_if_not(\n                                 names.crbegin(), names.crend(),\n\
    \                                 [](const char c) { return std::isspace(c); }\n\
    \                             )\n        ));\n        print(names, arg);\n   \
    \     if constexpr (!is_container_v<Tp>) os << std::endl;\n    } else {\n    \
    \    std::size_t comma_pos = 0;\n\n        for (std::size_t i = 0, paren_depth\
    \ = 0, inside_quote = false;\n             i < names.length(); i++) {\n      \
    \      if (!inside_quote && paren_depth == 0 && i > 0 &&\n                names[i\
    \ - 1] != '\\'' && names[i] == ',') {\n                comma_pos = i;\n      \
    \          break;\n            }\n            if (names[i] == '\\\"' || names[i]\
    \ == '\\'') {\n                if (i > 0 && names[i - 1] == '\\\\') continue;\n\
    \                inside_quote ^= true;\n            }\n            if (!inside_quote\
    \ && names[i] == '(' &&\n                (i == 0 || names[i - 1] != '\\''))\n\
    \                paren_depth++;\n            if (!inside_quote && names[i] ==\
    \ ')' &&\n                (i == 0 || names[i - 1] != '\\''))\n               \
    \ paren_depth--;\n        }\n\n        const std::size_t first_varname_length\
    \ =\n            comma_pos - std::distance(\n                            names.crend()\
    \ - comma_pos,\n                            std::find_if_not(\n              \
    \                  names.crend() - comma_pos, names.crend(),\n               \
    \                 [](const char c) { return std::isspace(c); }\n             \
    \               )\n                        );\n        print(names.substr(0, first_varname_length),\
    \ arg);\n\n        if constexpr (!is_container_v<Tp>) {\n            if constexpr\
    \ (is_container_v<first_t<Ts...>>) os << std::endl;\n            else os << \"\
    , \";\n        }\n\n        const std::size_t next_varname_begins_at = std::distance(\n\
    \            names.cbegin(), std::find_if_not(\n                             \
    \   names.cbegin() + comma_pos + 1, names.cend(),\n                          \
    \      [](const char c) { return std::isspace(c); }\n                        \
    \    )\n        );\n        names.remove_prefix(next_varname_begins_at);\n\n \
    \       multi_print(names, args...);\n    }\n}\n} // namespace debug_print\n\n\
    #undef INCLUDED\n\n#endif // DEBUG_PRINT_HPP\n\n#define debug(...) debug_print::multi_print(#__VA_ARGS__,\
    \ __VA_ARGS__)\n#else\n#pragma GCC diagnostic ignored \"-Wunused-variable\"\n\
    #define debug(...) (static_cast<void>(0))\n#endif\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n// see: https://blog.naskya.net/post/meu0vkh5cpl1/\n\
    // \u30FB\u306A\u3093\u3067\u3082\u8AAD\u3081\u308B\u5F37\u529B\u306A\u30C7\u30D0\
    \u30C3\u30B0\u51FA\u529B\u3002\n// \u3000\u30B3\u30FC\u30C9\u9577\u304C\u3068\u3066\
    \u3082\u9577\u3044\u306E\u3067\u666E\u6BB5\u4F7F\u3044\u306F\u3057\u3066\u3044\
    \u306A\u3044\u304C\u3001\u53C2\u8003\u306B\u306A\u308B\u90E8\u5206\u3082\u591A\
    \u3044\u305F\u3081\u53D6\u3063\u3066\u304A\u304F\u3002\n\n#ifdef __LOCAL\n\n#ifndef\
    \ DEBUG_PRINT_HPP\n#define DEBUG_PRINT_HPP\n\n#define INCLUDED(n) ((defined _GLIBCXX_##n)\
    \ || (defined _LIBCPP_##n))\n\n#if __cplusplus < 201703L\n#warning Please use\
    \ C++17 (or later version).\n#endif\n#if !INCLUDED(ALGORITHM)\n#warning Please\
    \ include <algorithm> before including debug_print.hpp.\n#endif\n#if !INCLUDED(CCTYPE)\n\
    #warning Please include <cctype> before including debug_print.hpp.\n#endif\n#if\
    \ !INCLUDED(IOSTREAM)\n#warning Please include <iostream> before including debug_print.hpp.\n\
    #endif\n#if !INCLUDED(ITERATOR)\n#warning Please include <iterator> before including\
    \ debug_print.hpp.\n#endif\n#if !INCLUDED(STRING_VIEW)\n#warning Please include\
    \ <string_view> before including debug_print.hpp.\n#endif\n#if !INCLUDED(TYPE_TRAITS)\n\
    #warning Please include <type_traits> before including debug_print.hpp.\n#endif\n\
    \nnamespace debug_print {\nstd::ostream &os = std::cerr;\n\ntemplate<class Tp>\n\
    auto has_cbegin(int)\n    -> decltype(std::cbegin(std::declval<Tp>()), std::true_type{});\n\
    template<class Tp>\nauto has_cbegin(...) -> std::false_type;\ntemplate<class Tp>\n\
    auto has_value_type(int)\n    -> decltype(std::declval<typename Tp::value_type>(),\
    \ std::true_type{});\ntemplate<class Tp>\nauto has_value_type(...) -> std::false_type;\n\
    \ntemplate<class Tp>\n[[maybe_unused]] constexpr bool is_iterable_container_v\
    \ =\n    decltype(has_cbegin<Tp>(int{}))::value;\ntemplate<class Tp>\n[[maybe_unused]]\
    \ constexpr bool is_container_v =\n    decltype(has_value_type<Tp>(int{}))::value\
    \ || is_iterable_container_v<Tp>;\n\ntemplate<>\n[[maybe_unused]] constexpr bool\
    \ is_iterable_container_v<std::string_view> =\n    false;\ntemplate<>\n[[maybe_unused]]\
    \ constexpr bool is_container_v<std::string_view> = false;\n#if INCLUDED(STRING)\n\
    template<>\n[[maybe_unused]] constexpr bool is_iterable_container_v<std::string>\
    \ = false;\ntemplate<>\n[[maybe_unused]] constexpr bool is_container_v<std::string>\
    \ = false;\n#endif\n\ntemplate<class Tp, class... Ts>\nstruct first_element {\n\
    \    using type = Tp;\n};\ntemplate<class... Ts>\nusing first_t = typename first_element<Ts...>::type;\n\
    \ntemplate<\n    class Tp,\n    std::enable_if_t<\n        !decltype(has_value_type<Tp>(int{}))::value,\
    \ std::nullptr_t> = nullptr>\nauto check_elem(int) -> decltype(*std::cbegin(std::declval<Tp>()));\n\
    template<\n    class Tp,\n    std::enable_if_t<\n        decltype(has_value_type<Tp>(int{}))::value,\
    \ std::nullptr_t> = nullptr>\nauto check_elem(int) -> typename Tp::value_type;\n\
    template<class Tp>\nauto check_elem(...) -> void;\n\ntemplate<class Tp>\nusing\
    \ elem_t = decltype(check_elem<Tp>(int{}));\n\ntemplate<class Tp>\n[[maybe_unused]]\
    \ constexpr bool is_multidim_container_v =\n    is_container_v<Tp> && is_container_v<elem_t<Tp>>;\n\
    \ntemplate<class Tp>\nstd::enable_if_t<!is_container_v<Tp>> out(const Tp &);\n\
    void out(const char &);\nvoid out(const char *);\nvoid out(const std::string_view\
    \ &);\n\n#if INCLUDED(STRING)\nvoid out(const std::string &);\n#endif\n\n#ifdef\
    \ __SIZEOF_INT128__\nvoid out(const __int128 &);\nvoid out(const unsigned __int128\
    \ &);\n#endif\n\ntemplate<class Tp1, class Tp2>\nvoid out(const std::pair<Tp1,\
    \ Tp2> &);\n\n#if INCLUDED(TUPLE)\ntemplate<class... Ts>\nvoid out(const std::tuple<Ts...>\
    \ &);\n#endif\n\n#if INCLUDED(STACK)\ntemplate<class... Ts>\nvoid out(std::stack<Ts...>);\n\
    #endif\n\n#if INCLUDED(QUEUE)\ntemplate<class... Ts>\nvoid out(std::queue<Ts...>);\n\
    template<class... Ts>\nvoid out(std::priority_queue<Ts...>);\n#endif\n\ntemplate<class\
    \ C>\nstd::enable_if_t<is_iterable_container_v<C>> out(const C &);\n\ntemplate<class\
    \ Tp>\nstd::enable_if_t<!is_container_v<Tp>> out(const Tp &arg) {\n    os << arg;\n\
    }\n\nvoid out(const char &arg) {\n    os << '\\'' << arg << '\\'';\n}\n\nvoid\
    \ out(const char *arg) {\n    os << '\\\"' << arg << '\\\"';\n}\n\nvoid out(const\
    \ std::string_view &arg) {\n    os << '\\\"' << arg << '\\\"';\n}\n\n#if INCLUDED(STRING)\n\
    void out(const std::string &arg) {\n    os << '\\\"' << arg << '\\\"';\n}\n#endif\n\
    \n#ifdef __SIZEOF_INT128__\nvoid out(const __int128 &arg) {\n    int sign = (arg\
    \ < 0) ? (-1) : 1;\n    if (sign == -1) os << '-';\n    __int128 base = sign;\n\
    \    while (sign * arg >= sign * base * 10) base *= 10;\n    while (base) {\n\
    \        os << static_cast<char>('0' + (arg / base % 10));\n        base /= 10;\n\
    \    }\n}\n\nvoid out(const unsigned __int128 &arg) {\n    unsigned __int128 base\
    \ = 1;\n    while (arg >= base * 10) base *= 10;\n    while (base) {\n       \
    \ os << static_cast<char>('0' + (arg / base % 10));\n        base /= 10;\n   \
    \ }\n}\n#endif\n\ntemplate<class Tp1, class Tp2>\nvoid out(const std::pair<Tp1,\
    \ Tp2> &arg) {\n    os << '(';\n    out(arg.first);\n    os << \", \";\n    out(arg.second);\n\
    \    os << ')';\n}\n\n#if INCLUDED(TUPLE)\ntemplate<class T, std::size_t... Is>\n\
    void print_tuple(const T &arg, std::index_sequence<Is...>) {\n    static_cast<void>(\n\
    \        ((os << (Is == 0 ? \"\" : \", \"), out(std::get<Is>(arg))), ...)\n  \
    \  );\n}\n\ntemplate<class... Ts>\nvoid out(const std::tuple<Ts...> &arg) {\n\
    \    os << '(';\n    print_tuple(arg, std::make_index_sequence<sizeof...(Ts)>());\n\
    \    os << ')';\n}\n#endif\n\n#if INCLUDED(STACK)\ntemplate<class... Ts>\nvoid\
    \ out(std::stack<Ts...> arg) {\n    os << \"[\";\n    while (!arg.empty()) {\n\
    \        out(arg.top());\n        if (arg.size() > 1) {\n            os << \"\
    , \";\n        }\n        arg.pop();\n    }\n    os << ']';\n}\n#endif\n\n#if\
    \ INCLUDED(QUEUE)\ntemplate<class... Ts>\nvoid out(std::queue<Ts...> arg) {\n\
    \    os << \"[\";\n    while (!arg.empty()) {\n        out(arg.front());\n   \
    \     if (arg.size() > 1) {\n            os << \", \";\n        }\n        arg.pop();\n\
    \    }\n    os << ']';\n}\ntemplate<class... Ts>\nvoid out(std::priority_queue<Ts...>\
    \ arg) {\n    os << \"[\";\n    while (!arg.empty()) {\n        out(arg.top());\n\
    \        if (arg.size() > 1) {\n            os << \", \";\n        }\n       \
    \ arg.pop();\n    }\n    os << ']';\n}\n#endif\n\ntemplate<class Container>\n\
    std::enable_if_t<is_iterable_container_v<Container>> out(const Container &arg)\
    \ {\n    int sz = std::distance(std::cbegin(arg), std::cend(arg));\n    os <<\
    \ \"[\";\n    int i = 0;\n    std::for_each(\n        std::cbegin(arg), std::cend(arg),\n\
    \        [sz, &i](const elem_t<Container> &elem) {\n            out(elem);\n \
    \           if (i < sz - 1) {\n                os << \", \";\n            }\n\
    \            i++;\n        }\n    );\n    os << ']';\n}\n\ntemplate<class Tp>\n\
    std::enable_if_t<!is_multidim_container_v<Tp>>\nprint(std::string_view name, const\
    \ Tp &arg) {\n    os << name << \": \";\n    out(arg);\n    if constexpr (is_container_v<Tp>)\
    \ os << std::endl;\n}\n\ntemplate<class Tp>\nstd::enable_if_t<is_multidim_container_v<Tp>>\n\
    print(std::string_view name, const Tp &arg) {\n    os << name << \": \";\n   \
    \ if (std::distance(std::cbegin(arg), std::cend(arg)) == 0) {\n        os << \"\
    []\" << std::endl;\n        return;\n    }\n    std::for_each(\n        std::cbegin(arg),\
    \ std::cend(arg),\n        [&name, is_first_elem = true](const elem_t<Tp> &elem)\
    \ mutable {\n            if (is_first_elem) is_first_elem = false;\n         \
    \   else\n                for (std::size_t i = 0; i < name.length() + 2; i++)\
    \ os << ' ';\n            out(elem);\n            os << std::endl;\n        }\n\
    \    );\n}\n\ntemplate<class Tp, class... Ts>\nvoid multi_print(std::string_view\
    \ names, const Tp &arg, const Ts &...args) {\n    if constexpr (sizeof...(Ts)\
    \ == 0) {\n        names.remove_suffix(std::distance(\n            names.crbegin(),\
    \ std::find_if_not(\n                                 names.crbegin(), names.crend(),\n\
    \                                 [](const char c) { return std::isspace(c); }\n\
    \                             )\n        ));\n        print(names, arg);\n   \
    \     if constexpr (!is_container_v<Tp>) os << std::endl;\n    } else {\n    \
    \    std::size_t comma_pos = 0;\n\n        for (std::size_t i = 0, paren_depth\
    \ = 0, inside_quote = false;\n             i < names.length(); i++) {\n      \
    \      if (!inside_quote && paren_depth == 0 && i > 0 &&\n                names[i\
    \ - 1] != '\\'' && names[i] == ',') {\n                comma_pos = i;\n      \
    \          break;\n            }\n            if (names[i] == '\\\"' || names[i]\
    \ == '\\'') {\n                if (i > 0 && names[i - 1] == '\\\\') continue;\n\
    \                inside_quote ^= true;\n            }\n            if (!inside_quote\
    \ && names[i] == '(' &&\n                (i == 0 || names[i - 1] != '\\''))\n\
    \                paren_depth++;\n            if (!inside_quote && names[i] ==\
    \ ')' &&\n                (i == 0 || names[i - 1] != '\\''))\n               \
    \ paren_depth--;\n        }\n\n        const std::size_t first_varname_length\
    \ =\n            comma_pos - std::distance(\n                            names.crend()\
    \ - comma_pos,\n                            std::find_if_not(\n              \
    \                  names.crend() - comma_pos, names.crend(),\n               \
    \                 [](const char c) { return std::isspace(c); }\n             \
    \               )\n                        );\n        print(names.substr(0, first_varname_length),\
    \ arg);\n\n        if constexpr (!is_container_v<Tp>) {\n            if constexpr\
    \ (is_container_v<first_t<Ts...>>) os << std::endl;\n            else os << \"\
    , \";\n        }\n\n        const std::size_t next_varname_begins_at = std::distance(\n\
    \            names.cbegin(), std::find_if_not(\n                             \
    \   names.cbegin() + comma_pos + 1, names.cend(),\n                          \
    \      [](const char c) { return std::isspace(c); }\n                        \
    \    )\n        );\n        names.remove_prefix(next_varname_begins_at);\n\n \
    \       multi_print(names, args...);\n    }\n}\n} // namespace debug_print\n\n\
    #undef INCLUDED\n\n#endif // DEBUG_PRINT_HPP\n\n#define debug(...) debug_print::multi_print(#__VA_ARGS__,\
    \ __VA_ARGS__)\n#else\n#pragma GCC diagnostic ignored \"-Wunused-variable\"\n\
    #define debug(...) (static_cast<void>(0))\n#endif\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/common/debug_print.hpp
  requiredBy: []
  timestamp: '2023-12-04 15:39:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/common/debug_print.hpp
layout: document
redirect_from:
- /library/src/common/debug_print.hpp
- /library/src/common/debug_print.hpp.html
title: src/common/debug_print.hpp
---
