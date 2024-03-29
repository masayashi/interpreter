// 解説に出てきたけどまだ使わないっぽいものを写して置いとくところ

#include <stack>

/*------------------------------------------------------------------------------
  オペランドスタック (p.17)
  std::stack のラッパ。
  sdt::stack は、先頭の要素をPOPしたいときに
  　　stack.top();
  　　stack.pop();
  とやる必要があって面倒だから。
 -----------------------------------------------------------------------------*/
class MyStack
{
public:
    void push(double n) { mStack.push(n); }
    int size() const { return static_cast<int>(mStack.size()); }
    bool empty() const { return mStack.empty(); }
    double pop() const
    {
	if (mStack.empty()); // { err_exit("stack underflow\n"); }
	double d = mStack.top();
	mStack.pop;
	return d;
    }
	    
private:
    stack<double> mStack;
};


/*------------------------------------------------------------------------------
  メモリ構成 (p.18)
  データ用のメモリをdouble幅の配列で管理する。
  操作できるデータ型を複数（char, int, double）サポートする場合は、それぞれの型の配列を
  用意する必要がある。
 -----------------------------------------------------------------------------*/
class MyMemory
{
public:
    void auto_resize(int n);
    void set(int addr, double dt);
    void add(int addr, double dt);
    double get(int addr);
    int size();
    void push_back(double d);

private:
    vector<double> mMem;
};

/*------------------------------------------------------------------------------
  レジスタ構成（p.19）
  ベースレジスタは、実行中の関数のために確保するローカルメモリ領域（フレーム）の先頭アドレスを保持する。
  スラックポインタレジスタは、確保したローカルメモリ領域の最終アドレス＋１を保持する。
  関す呼び出しが行われるたびに、この二つのレジスタが伸び縮みして、関数用の適切なフレームを確保する。
 -----------------------------------------------------------------------------*/
int baseReg; // ベースレジスタ
int spReg;   // スタックポインタレジスタ

/*------------------------------------------------------------------------------
  記号表領域（p.21)
  プログラム内に登場する識別師の情報を登録するための記号表。
  Gtable[] 大域名用記号表。グローバル変数名や関数名を登録する。
  Ltable[] 局所名記号表。関数ごとの仮引数名やローカル変数名を登録する。
  -----------------------------------------------------------------------------*/
vector<SymTbl> Gtable;
vector<SymTbl> Ltable;

