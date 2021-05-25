#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::priority_queue;
using std::greater;

class JobQueue {
 private:
  int num_workers_;
  vector<int> jobs_;

  vector<int> assigned_workers_;
  vector<long long> start_times_;

  void WriteResponse() const {
    for (int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    int m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    for(int i = 0; i < m; ++i)
      cin >> jobs_[i];
  }

  void AssignJobs() {
    // TODO: replace this code with a faster algorithm.
    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());
    priority_queue<long long, vector<vector<long long>>, greater<vector<long long>> > next_free_time;
    for (long long  i = 0; i < num_workers_; i++)
    {
      vector<long long> temp {0,i};
      next_free_time.push(temp);
    }
    
    for (int i = 0; i < jobs_.size(); ++i) {
      long long duration = jobs_[i];
      long long next_worker = next_free_time.top()[1];
      long long start = next_free_time.top()[0];

      assigned_workers_[i] = next_worker;
      start_times_[i] = start;
      next_free_time.pop();
      next_free_time.push({start+duration,next_worker});
    }
  }

 public:
  void Solve() {
    ReadData();
    AssignJobs();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}