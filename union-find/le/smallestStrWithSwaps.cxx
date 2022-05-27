#include <bits/stdc++.h>
using namespace std;
// 没想到dfs和union find有异曲同工之妙, 关于找 connected component
class UnionFind {
 private:
  vector<int> root;
  vector<int> size;

 public:
  // 这边为什么要初始化 成员变量的长度呢
  // 不初始化, 就不可以使用
  UnionFind(int sz) : root(sz), size(sz) {
    for (int i = 0; i < sz; i++) {
      root[i] = i;
    }
  }

  int find(int x) {
    if (x == root[x]) {
      return x;
    }
    return root[x] = find(root[x]);
  }

  void unionSet(int x, int y) {
    int root1 = find(x);
    int root2 = find(y);
    // 始终root1  size  < root2
    if (root1 != root2) {
      if (size[root2] > size[root1]) {
        int temp = root2;
        root2 = root1;
        root1 = temp;
      }
      root[root1] = root2;
      size[root2] = size[root1] + size[root2];
      // size.erase(root1);
    }
  }

  bool connected(int x, int y) { return find(x) == find(y); }
};

class Solution {
 public:
  string smallestStringWithSwapsUnion(string s, vector<vector<int>>& pairs) {
    // root index  ->  heap char
    // 小根堆
    map<int, priority_queue<char, vector<char>, greater<char>>> mapQueue;
    map<int, vector<int>> mapIndex;
    UnionFind uf(s.size());
    for (auto pair : pairs) {
      uf.unionSet(pair[0], pair[1]);
    }

    for (int i = 0; i < s.size(); i++) {
      // char c = s[i];
      char root = uf.find(i);
      // 不存在key, 就新建一个
      if (mapQueue.find(root) == mapQueue.end()) {
        // mapQueue[root] = {};
        mapIndex[root] = {};
      }
      // mapQueue[root].push(c);
      mapIndex[root].push_back(i);
    }

    // 按照heap的顺序, 替换原字符串内容
    for (auto& [key, values] : mapQueue) {
      vector<int> valueIndex = mapIndex[key];
      for (auto index : valueIndex) {
        s[index] = values.top();
        values.pop();
      }
    }
    return s;
  }

  static const int MAX_SIZE = 10001;
  bool visited[MAX_SIZE];
  vector<int> adj[MAX_SIZE];

  void DFS(string& s, int v, vector<char>& chars, vector<int>& indices) {
    chars.push_back(s[v]);
    indices.push_back(v);
    visited[v] = true;

    for (auto item : adj[v]) {
      if (!visited[item]) {
        DFS(s, item, chars, indices);
      }
    }
  }

  // 使用dfs版本
  string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
    // add edge
    for (auto edge : pairs) {
      int from = edge[0];
      int to = edge[1];
      adj[from].push_back(to);
      adj[to].push_back(from);
    }

    for (size_t i = 0; i < s.size(); i++) {
      // 没有访问过该点
      if (!visited[i]) {
        // 在里面初始化
        vector<char> chars;
        vector<int> indices;

        DFS(s, i, chars, indices);
        // time cost: O(VlogV)
        sort(chars.begin(), chars.end());
        sort(indices.begin(), indices.end());

        // 按照顺序赋值
        for (int index = 0; index < chars.size(); index++) {
          s[indices[index]] = chars[index];
        }
      }
    }
    return s;
  }
};

void complexTestCase() {
  Solution* s;

  string str =
      "hzclhxbexrneoueagtqvqvcoqzxatfolqqrrqzmihckxhlzapehosuerutjemlxuhzkdvoqm"
      "gtiqmyrewiiwwmahkdqjsapvlvthabrupatdocnacniqvkuaeluypcodxhaboyvifkqtpdxh"
      "kxmvgpyouhqrbopiqkafajopmezapmrogkloszzlapwpimdstfkuarrevjrrzbizutfaggew"
      "nqbqlcdpczzzlshjyhnojcepqlvcejybelkuekhrngzsbhscquffampocotshpcbhqwpkwsg"
      "ypsctitbcjaekdrbzuzyziiiqjsojgurjspteufezkflpnjtsityphndiwjcmntxgvhupqjn"
      "kivqprileyeqoctomyibjtptuvvniqhjokpxrnbfbdvtfwvhujdycgdaywcmsifkplutowhn"
      "ujfmwrdzzqdmmphxitwlrbwfrxxtkaktackfhtjowexeyxfmsrvzbxhcdhbwlhovmrxf";
  vector<vector<int>> arr{
      {371, 300}, {307, 120}, {197, 67},  {13, 380},  {494, 428}, {486, 15},
      {135, 74},  {477, 238}, {107, 443}, {168, 266}, {339, 348}, {263, 18},
      {450, 160}, {243, 378}, {321, 490}, {335, 413}, {28, 121},  {1, 305},
      {423, 116}, {78, 94},   {424, 145}, {24, 140},  {418, 279}, {127, 96},
      {80, 491},  {162, 272}, {344, 47},  {353, 454}, {436, 58},  {249, 191},
      {111, 215}, {231, 129}, {56, 223},  {150, 498}, {222, 428}, {266, 163},
      {210, 433}, {374, 282}, {179, 256}, {41, 460},  {221, 186}, {263, 175},
      {378, 158}, {7, 475},   {252, 408}, {256, 309}, {286, 289}, {247, 247},
      {418, 389}, {144, 340}, {333, 420}, {309, 165}, {359, 202}, {105, 78},
      {196, 400}, {310, 352}, {379, 126}, {141, 42},  {285, 146}, {455, 191},
      {400, 445}, {165, 196}, {65, 450},  {477, 131}, {218, 284}, {52, 458},
      {354, 168}, {133, 119}, {437, 257}, {390, 174}, {343, 178}, {38, 415},
      {301, 218}, {69, 289},  {82, 391},  {129, 7},   {426, 217}, {339, 128},
      {168, 484}, {350, 6},   {254, 55},  {438, 75},  {497, 432}, {386, 273},
      {258, 301}, {242, 336}, {333, 208}, {121, 367}, {372, 113}, {320, 21},
      {75, 267},  {59, 403},  {152, 58},  {497, 278}, {140, 231}, {272, 331},
      {190, 302}, {37, 319},  {311, 377}, {196, 369}, {460, 476}, {445, 363},
      {210, 167}, {351, 472}, {424, 148}, {486, 123}, {175, 316}, {201, 158},
      {262, 395}, {70, 357},  {61, 240},  {275, 422}, {176, 192}, {147, 131},
      {421, 449}, {444, 439}, {324, 273}, {497, 476}, {123, 409}, {100, 195},
      {438, 453}, {365, 182}, {376, 33},  {274, 247}, {367, 373}, {40, 287},
      {366, 467}, {340, 476}, {233, 75},  {328, 313}, {388, 387}, {457, 192},
      {403, 349}, {137, 298}, {468, 51},  {329, 104}, {206, 44},  {181, 383},
      {299, 222}, {329, 220}, {196, 41},  {305, 83},  {326, 144}, {315, 161},
      {190, 277}, {365, 435}, {149, 88},  {196, 343}, {362, 226}, {21, 386},
      {144, 208}, {332, 85},  {284, 111}, {495, 496}, {57, 470},  {426, 17},
      {65, 73},   {282, 313}, {102, 80},  {414, 12},  {490, 369}, {496, 434},
      {447, 97},  {93, 488},  {59, 333},  {191, 455}, {74, 301},  {299, 79},
      {405, 249}, {258, 158}, {421, 172}, {74, 458},  {427, 60},  {24, 285},
      {251, 294}, {204, 41},  {100, 260}, {231, 101}, {291, 161}, {137, 436},
      {287, 300}, {289, 440}, {213, 17},  {376, 252}, {99, 250},  {111, 238},
      {422, 434}, {39, 211},  {298, 210}, {293, 158}, {29, 299},  {201, 143},
      {200, 155}, {32, 186},  {197, 41},  {179, 187}, {1, 372},   {50, 324},
      {368, 304}, {266, 171}, {155, 18},  {177, 191}, {448, 26},  {242, 96},
      {54, 333},  {55, 297},  {139, 398}, {454, 427}, {294, 288}, {44, 58},
      {402, 211}, {426, 11},  {159, 157}, {270, 444}, {346, 221}, {408, 107},
      {224, 353}, {459, 291}, {232, 44},  {122, 207}, {60, 221},  {260, 130},
      {461, 195}, {21, 355},  {303, 208}, {44, 89},   {453, 216}, {326, 274},
      {374, 261}, {485, 243}, {47, 404},  {130, 412}, {423, 435}, {398, 311},
      {407, 244}, {423, 340}, {145, 245}, {445, 372}, {419, 261}, {471, 161},
      {356, 436}, {379, 107}, {154, 408}, {181, 343}, {142, 384}, {358, 441},
      {447, 493}, {212, 336}, {313, 264}, {438, 91},  {101, 263}, {132, 442},
      {186, 340}, {287, 366}, {81, 303},  {244, 478}, {422, 374}, {281, 218},
      {179, 423}, {490, 239}, {164, 447}, {348, 235}, {292, 14},  {196, 42},
      {222, 428}, {453, 284}, {351, 68},  {166, 391}, {139, 388}, {13, 455},
      {438, 471}, {117, 488}, {451, 227}, {146, 54},  {345, 362}, {458, 119},
      {113, 80},  {32, 3},    {380, 177}, {481, 460}, {333, 165}, {106, 34},
      {340, 225}, {463, 403}, {341, 114}, {181, 222}, {17, 268},  {93, 197},
      {169, 390}, {357, 461}, {46, 46},   {21, 335},  {342, 445}, {213, 241},
      {351, 40},  {282, 186}, {92, 193},  {493, 215}, {250, 415}, {11, 40},
      {362, 37},  {449, 393}, {177, 496}, {38, 90},   {260, 204}, {441, 105},
      {75, 344},  {26, 401},  {133, 478}, {64, 443},  {24, 466},  {84, 14},
      {87, 47},   {1, 336},   {380, 457}, {67, 6},    {479, 361}, {139, 117},
      {377, 310}, {435, 379}, {159, 383}, {401, 61},  {156, 121}, {192, 179},
      {307, 499}, {320, 302}, {167, 180}, {424, 9},   {314, 170}, {447, 21},
      {402, 319}, {192, 140}, {363, 242}, {257, 10},  {216, 465}, {27, 209},
      {332, 494}, {328, 356}, {138, 96},  {155, 149}, {168, 158}, {388, 202},
      {224, 360}, {69, 141},  {244, 357}, {206, 145}, {36, 497},  {151, 300},
      {348, 100}, {297, 386}, {254, 318}, {225, 115}, {188, 192}, {93, 105},
      {156, 199}, {17, 498},  {72, 22},   {58, 61},   {114, 321}, {460, 259},
      {305, 109}, {458, 11},  {293, 343}, {118, 243}, {262, 268}, {94, 78},
      {417, 490}, {199, 124}, {349, 284}, {301, 271}, {268, 154}, {23, 302},
      {209, 96},  {315, 74},  {52, 224},  {118, 416}, {499, 203}, {184, 210},
      {64, 468},  {99, 200},  {173, 454}, {95, 1},    {111, 425}, {118, 471},
      {392, 209}, {133, 145}, {63, 469},  {338, 220}, {463, 181}, {108, 257},
      {308, 390}, {404, 222}, {363, 308}, {13, 110},  {327, 432}, {338, 226},
      {70, 314},  {442, 408}, {452, 349}, {488, 184}, {375, 235}, {42, 2},
      {11, 413},  {242, 394}, {114, 459}, {260, 265}, {43, 219},  {445, 362},
      {419, 41},  {66, 398},  {259, 95},  {258, 92},  {443, 140}, {421, 103},
      {54, 208},  {170, 194}, {427, 448}, {180, 125}, {269, 161}, {312, 348},
      {376, 472}, {180, 245}, {50, 278},  {232, 118}, {139, 61},  {296, 130},
      {86, 212},  {437, 474}, {15, 465},  {257, 291}, {136, 52},  {198, 233},
      {158, 363}, {143, 248}, {407, 110}, {434, 398}, {499, 142}, {479, 353},
      {59, 236},  {66, 269},  {68, 193},  {192, 335}, {299, 36},  {149, 10},
      {78, 140},  {70, 88},   {354, 122}, {14, 380},  {104, 39},  {100, 143},
      {76, 313},  {485, 134}, {217, 382}, {239, 438}, {288, 251}, {387, 328},
      {185, 323}, {7, 152},   {140, 302}, {316, 5},   {181, 316}, {476, 57},
      {416, 194}, {450, 481}, {116, 144}, {496, 11},  {38, 252},  {103, 280},
      {413, 175}, {238, 105}, {430, 269}, {12, 0},    {197, 234}, {325, 91},
      {352, 189}, {241, 359}, {205, 213}, {234, 475}, {302, 347}, {356, 105},
      {307, 297}, {249, 92},  {163, 419}, {455, 296}, {452, 442}, {464, 45},
      {63, 138},  {191, 251}, {60, 160},  {486, 416}, {476, 268}, {338, 472},
      {452, 326}, {268, 277}, {233, 165}, {317, 93},  {405, 195}, {281, 346},
      {230, 421}, {113, 374}};

  cout << s->smallestStringWithSwaps(str, arr);
}

int main(int argc, char const* argv[]) {
  Solution* s;
  vector<vector<int>> arr{{0, 3}, {1, 2}};
  cout << s->smallestStringWithSwaps("dcab", arr);

  // complexTestCase();
  return 0;
}
