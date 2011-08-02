#include <vector>
#include <limits>
#include <algorithm>

class Quantile{
  std::vector<double> data;
  bool sorted;

public:
  Quantile(): sorted(true){}
  void fill(double val){
    data.push_back(val);
    sorted = false;
  }

  void reset(){ data.clear(); }

  double xlow(double prop){
    if(prop < 0 || prop > 1)  return -std::numeric_limits<double>::max();
    sort();
    double i = data.size() * prop;
    if(data.size()==0) return -std::numeric_limits<double>::max();
    if(i==0) return data[0];
    if(i>=data.size()) return data[data.size()-1];
    return 0.5 * (data[i-1] + data[i]);
  }

  void sort(){
    if(!sorted) std::sort(data.begin(), data.end());
    sorted = true;
  }
  
  double xhigh(double prop){
    return xlow(1-prop);
  }
  
};

  
