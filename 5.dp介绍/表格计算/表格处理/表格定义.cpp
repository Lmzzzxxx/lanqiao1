#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <iomanip>
using namespace std;
//要考虑到是代表公式还是数据
enum Type {NUMBER,SUM,AVG,STD};
struct Cell{
  Type type;
  double val;
  int x1,y1,x2,y2;
  bool computed;
  double cache;//如果是公式是否计算出来了
}；
int N,M;
vector<vector<Cell>> table;
vector evaluate(int r, int c){
  Cell& cell = table[r][c];
  if(cell.computed) 
    return cell.cache;
  if(cell.type == NUMBER){
    cell.computed = true;
    cell.cache = cell.val;
    return cell.cache;
  }
  double sum = 0;
  double numSQ = 0;
  int count = 0;
  for(int i = cell.x1;i <= cell.x2;++i){
    for(int j = cell.y1;i <= cell.y2;++j){
      double v = evaluate(i,j);
      sum += v;
      numSq += v*v;
      count ++;
    }
  }
  if(cell.type == SUM){
    cell.cahce = sum;
  }
  if(cell.type == AVG){
    cell.cache = sum / count;
  }
  if(cell.type == STD){
    double avg = sum / count;
    double variance = (numSq/count) - (avg*avg);
    cell.cache = sqrt(max(0.0,variance));
  }
  cell.computed = true;
  return cell.cache;
}

