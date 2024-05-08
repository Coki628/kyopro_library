#pragma once

// 拡張ユークリッドの互除法(ax+by=gcd(a, b)の解を求める)
// 参考：https://atcoder.jp/contests/abc340/editorial/9250
// ・除算やmodに負数がかかると壊れる気がするのだが、何故か大丈夫らしい。
// ・ax+by=gcd(a,b)となるような整数x,yを返す。
// 　右辺がgcdの倍数を取りたいようなら、x,yも倍すればいい。
// 　倍数でないような値は構築不可。多分。
// ・ax-byなら-bを渡せばOKみたいな使い方をしても大丈夫そう。
// ・最後の戻り値は
// 　auto [x, y] = extgcd(a, b);
// 　の向きで受ける。
template<typename T>
pair<T, T> extgcd(T a, T b) {
  if (b == 0) return {1, 0};
  T x, y;
  tie(y, x) = extgcd(b, a % b);
  y -= a / b * x;
  return {x, y};
}
