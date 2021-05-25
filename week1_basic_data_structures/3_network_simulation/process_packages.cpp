#include <iostream>
#include <queue>
#include <vector>

struct Request {
    Request(int arrival_time, int process_time):
        arrival_time(arrival_time),
        process_time(process_time)
    {}

    int arrival_time;
    int process_time;
};

struct Response {
    Response(bool dropped, int start_time):
        dropped(dropped),
        start_time(start_time)
    {}

    bool dropped;
    int start_time;
};

class Buffer {
public:
    Buffer(int size):
        size_(size),
        finish_time_()
    {}

    Response Process(const Request &request) {
        int last_finish = request.arrival_time;
        if(!finish_time_.empty()){
            last_finish = finish_time_.back();
        }
        // free the queue from the finished processes at the time
        // the request arrives
        while(!finish_time_.empty() && finish_time_.front() <= request.arrival_time){
            finish_time_.pop();
        }

        // start time is at least the time 
        // the request request arrive
        int start_time = request.arrival_time;
        //if there's place in the buffer we 
        // proced to process the request
        if(finish_time_.size() < size_){
            if(request.arrival_time < last_finish){
                finish_time_.push(last_finish+request.process_time);
                start_time = last_finish;
            }
            else
            {
                finish_time_.push(request.arrival_time+request.process_time);
            }
            return Response(false,start_time);
        }
        // if not we ignore it
        else{
            return Response(true,start_time);
        }
    }
private:
    int size_;
    std::queue <int> finish_time_;
};

std::vector <Request> ReadRequests() {
    std::vector <Request> requests;
    int count;
    std::cin >> count;
    for (int i = 0; i < count; ++i) {
        int arrival_time, process_time;
        std::cin >> arrival_time >> process_time;
        requests.push_back(Request(arrival_time, process_time));
    }
    return requests;
}

std::vector <Response> ProcessRequests(const std::vector <Request> &requests, Buffer *buffer) {
    std::vector <Response> responses;
    for (int i = 0; i < requests.size(); ++i)
        responses.push_back(buffer->Process(requests[i]));
    return responses;
}

void PrintResponses(const std::vector <Response> &responses) {
    for (int i = 0; i < responses.size(); ++i)
        std::cout << (responses[i].dropped ? -1 : responses[i].start_time) << std::endl;
}

int main() {
    int size;
    std::cin >> size;
    std::vector <Request> requests = ReadRequests();

    Buffer buffer(size);
    std::vector <Response> responses = ProcessRequests(requests, &buffer);

    PrintResponses(responses);
    return 0;
}
