#pragma once

// 2-SAT
// 使用方法：https://atcoder.github.io/ac-library/document_ja/twosat.html
// ・元々は「A|B and A|B and...」なんだけどｄ、変形させると色々な条件に対応できる。
// 　・A or B (cf1903f)
// 　　A|B (これはそのまま)
// 　・A xor B (abc327_d,cf1438c)
// 　　A&!B or !A&B -> A|B and !A|!B
// 　・not (A and B) (aclpc_h,yukico274)
// 　　!(A&B) -> !A|!B
// 　・not (A and !B) (aclpc_h)
// 　　!(A&!B) -> !A|B
// 　・not (!A and B) (aclpc_h)
// 　　!(!A&B) -> A|!B
// 　・not (!A and !B) (aclpc_h)
// 　　!(!A&!B) -> A|B
// 　・A and B (cf1494b)
// 　　A&B -> A|A and B|B
#include "atcoder/twosat"
