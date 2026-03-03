#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

int fifo(int capacity, int num_requests, vector<int> &pages) {
    unordered_set<int> s; // stores current pages in memory
    queue<int> indexes;   // stores order of pages for FIFO
    int page_faults = 0;

    for (int i = 0; i < num_requests; i++) {
        int page = pages[i];
        // if page is not in cache, we have a miss
        if (s.find(page) == s.end()) {
            // cache is full, remove oldest page
            if (s.size() == capacity) {
                int oldest_page = indexes.front();
                indexes.pop();
                s.erase(oldest_page);
            }
            // add new page to memory and update the queue
            s.insert(page);
            indexes.push(page);
            page_faults++;
        }
    }

    return page_faults;
}

int lru(int capacity, int num_requests, vector<int> &requests) {
    int misses = 0;

    vector<int> values;
    vector<int> access_times;

    for (int i = 0; i < num_requests; i++) {
        int request = requests[i];
        auto iter = find(values.begin(), values.end(), request);

        if (iter == values.end()) {
            // not in cache
            if (values.size() < capacity) {
                // cache not full
                values.push_back(request);
                access_times.push_back(i);
            } else {
                // cache full, kick something out
                int oldest_seen = i + 1; // dummy value greater than current time
                int oldest_index = -1;
                for (int j = 0; j < capacity; j++) {
                    if (access_times[j] < oldest_seen) {
                        oldest_seen = access_times[j];
                        oldest_index = j;
                    }
                }
                values[oldest_index] = request;
                access_times[oldest_index] = i;
            }
            misses++;
        } else {
            // value in cache, need to update access time
            int index = iter - values.begin();
            access_times[index] = i;
        }
    }

    return misses;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cerr << "Usage: ./test <input_file>" << endl;
        return 1;
    }

    ifstream infile(argv[1]);
    int k, m;
    if (!(infile >> k >> m))
        return 0;

    vector<int> requests(m);
    for (int i = 0; i < m; i++) {
        infile >> requests[i];
    }

    cout << "FIFO: " << fifo(k, m, requests) << endl;
    cout << "LRU: " << lru(k, m, requests) << "\n";

    return 0;
}
