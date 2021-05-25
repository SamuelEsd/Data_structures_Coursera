#include <iostream>
#include <vector>
#include <deque>

using std::cin;
using std::cout;
using std::vector;
using std::max;


void max_sliding_window_naive(vector<int> const & A, int w) {
    for (size_t i = 0; i < A.size() - w + 1; ++i) {
        int window_max = A.at(i);
        for (size_t j = i + 1; j < i + w; ++j)
            window_max = max(window_max, A.at(j));

        cout << window_max << " ";
    }

    return;
}

void maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> msw;
    std::deque<int> window;
    // inlitialize the deque
    for(int i = 0; i < k ; i++){
        if(window.empty()){
            window.push_back(i);
        }
        else{
            while(!window.empty() && nums[window.back()] <= nums[i]){
                window.pop_back();
            }
            window.push_back(i);
        }
    }
    
    // slide the window
    for(int i = k; i < nums.size(); i++){
        cout << nums[window.front()] << " ";
        if(window.front() <= i-k){ /// ojo con <=
            window.pop_front();
        }
        if(window.empty()){
            window.push_back(i);
        }
        else{
            while(!window.empty() && nums[window.back()] <= nums[i]){
                window.pop_back();
            }
            window.push_back(i);
        }
        
    }
    msw.push_back(nums[window.front()]);
    cout << nums[window.front()] << " ";
    return;
}

int main() {
    int n = 0;
    cin >> n;

    vector<int> A(n);
    for (size_t i = 0; i < n; ++i)
        cin >> A.at(i);

    int w = 0;
    cin >> w;

    maxSlidingWindow(A, w);

    return 0;
}
