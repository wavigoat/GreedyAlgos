#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <queue>
#include <fstream>

using namespace std;


int fifo(int capacity, int num_requests, vector<int>& pages) {
    unordered_set<int> s; // stores current pages in memory
    queue<int> indexes; // stores order of pages for FIFO
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

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: ./test <input_file>" << endl;
        return 1;
    }

    ifstream infile(argv[1]);
    int k, m;
    if (!(infile >> k >> m)) return 0;

    vector<int> requests(m);
    for (int i = 0; i < m; i++) {
        infile >> requests[i];
    }

    cout << "FIFO: " << fifo(k, m, requests) << endl;

    return 0;
}