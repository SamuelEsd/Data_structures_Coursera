#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;
using std::list;
using std::cin;
using std::cout;

struct Query {
    string type, s;
    size_t ind;
};

class QueryProcessor {
    int bucket_count;
    // store all strings in one vector
    vector<list<string>> elems;
    size_t hash_func(const string& s) const {
        static const size_t multiplier = 263;
        static const size_t prime = 1000000007;
        unsigned long long hash = 0;
        for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
            hash = (hash * multiplier + s[i]) % prime;
        return hash % bucket_count;
    }

public:
    explicit QueryProcessor(int bucket_count): bucket_count(bucket_count) {
        elems.resize(bucket_count);
    }

    Query readQuery() const {
        Query query;
        cin >> query.type;
        if (query.type != "check")
            cin >> query.s;
        else
            cin >> query.ind;
        return query;
    }

    void writeSearchResult(bool was_found) const {
        cout << (was_found ? "yes\n" : "no\n");
    }

    void processQuery(const Query& query) {
        if (query.type == "check") {
            // use reverse order, because we append strings to the end
            list<string> temp = elems[query.ind];
            for (auto l : temp)
            {
                cout << l << " ";
            }
            cout << "\n";
            // for (int i = static_cast<int>(elems.size()) - 1; i >= 0; --i)
            //     if (hash_func(elems[i]) == query.ind)
            //         std::cout << elems[i] << " ";
            // std::cout << "\n";
        } else {
            size_t place = hash_func(query.s);
            if (query.type == "find"){
                list<string> temp = elems[place];
                for (auto l: temp)
                {
                    if (l.compare(query.s) == 0)
                    {
                        writeSearchResult(true);
                        return;
                    }                    
                }
                writeSearchResult(false);
            }   
            else if (query.type == "add") {
                list<string> temp = elems[place];
                for (auto l: temp)
                {
                    if (l.compare(query.s) == 0)
                    {
                        return;
                    }                    
                }
                elems[place].push_front(query.s);
                // if (it == elems.end())
                //     elems.push_back(query.s);
            } else if (query.type == "del") {
                elems[place].remove(query.s);
                // if (it != elems.end())
                //     elems.erase(it);
            }
        }
    }

    void processQueries() {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
            processQuery(readQuery());
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    int bucket_count;
    cin >> bucket_count;
    QueryProcessor proc(bucket_count);
    proc.processQueries();
    return 0;
}


// 5
// 12
// add world
// add HellO
// check 4
// find World
// find world
// del world
// check 4
// del HellO
// add luck
// add GooD
// check 2
// del good
