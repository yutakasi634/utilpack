# utilpack
使いまわせそうなプログラムの保存用レポジトリ。
## array_matrix.hpp
```cpp
namespace Utilpack {
template <typename valu_T, std::size_t row_Num, std::size_t column_Num>
class array_matrix;
}
```

2次元のarray。
以下の関数とstd::arrayの関数を複数実装。

|メンバ関数                     |補足
|----------------------------|--------------------------------------------|
|at(std::size_t, std::size_t)|(行番号,列番号)の要素にアクセス。                   |
|rowbegin(std::size_t)       |行の先頭要素を指すイテレータを取得する。                |
|rowend(std::size_t)         |行の末尾の1つ次の要素を指すイテレータを取得する。         |
|columnbegin(std::size_t)    |列の先頭要素を指すstride_iteratorを取得する。        |
|columnend(std::size_t)      |行の末尾の1つ次の要素を指すstride_iteratorを取得する。 |
|size()                      |要素数を取得する。                                |
|max_size()                  |格納可能な最大の要素数を取得する。                   |
|row_num()                   |行数を取得する。                                 |
|column_num()                |列数を取得する。                                 |
|empty()　　　　　　　　　　　　　|コンテナが空かどうかを判定する。                       |

at()はコンパイルオプションに`-D DEBUG`を指定した場合、範囲外参照チェックを行う。

|演算子|補足                  |
|-----|---------------------|
|==   |                     |
|!=   |                     |
|<<   |" "刻みで要素を矩形に出力。|

## stride_iterator.hpp
一度に指定幅進むイテレーター。
