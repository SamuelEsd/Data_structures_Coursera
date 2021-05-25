#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

class HeapBuilder {
 private:
  vector<int> data_;
  vector< pair<int, int> > swaps_;

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

  void ReadData() {
    int n;
    cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
  }

  void GenerateSwaps() {
    swaps_.clear();
    for(int i = floor(data_.size()/2); i >= 0; i--){
      int j = i;
      // check the children if there exist
      while((j*2)+1 < data_.size() || (j*2)+2 < data_.size()){
        // if both children exists
        if((j*2)+2 < data_.size()){
          int m = (data_[(j*2)+1] < data_[(j*2)+2])?(j*2)+1:(j*2)+2;
          
          // get the min of both and if is 
          // lower than the actual we swap the values
          if(data_[m] < data_[j]){
            std::swap(data_[j],data_[m]);
            swaps_.push_back(make_pair(j, m));
            j = m;
          }
          else
          {
            break;
          }
        }
        // if only left child exists
        else if((j*2)+1 < data_.size()){
          if(data_[(j*2)+1] < data_[j]){
            std::swap(data_[j],data_[(j*2)+1]);
            swaps_.push_back(make_pair(j, (j*2)+1));
            break;
          }
          else
          {
            break;
          }          
        }
        // if there are no children
        else
        {
          break;
        }
      }
    }
  }

 public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
