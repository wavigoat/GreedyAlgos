#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, char *argv[]) {
    if (argc != 4) {
        cout << "usage:\n";
        cout << argv[0] << " <k> <m> <n>\n";
        cout << "where 'k' is the cache size,\n";
        cout << "      'm' is the number of requests to make\n";
        cout << "and   'n' is the upper bound on the number of unique requests made\n";
        return 1;
    }

    int k = stoi(argv[1]);
    int m = stoi(argv[2]);
    int n = stoi(argv[3]);

    // randomization boilerplate
    random_device rd;
    mt19937 g(rd());
    uniform_int_distribution<int> int_dist(0, n);

    vector<int> generated;
    for (int i = 0; i < m; i++) {
        int smallest = int_dist(g);
        for (int j = 1; j < 2; j++) {
            smallest = min(smallest, int_dist(g));
        }
        generated.push_back(smallest);
    }

    cout << k << " " << m << "\n";
    for (int request : generated) {
        cout << request << " ";
    }
    cout << "\n";

    return 0;
}
