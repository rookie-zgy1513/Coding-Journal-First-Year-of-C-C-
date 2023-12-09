#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Stone {
    int count;
    int size;
};

bool compareSize(const Stone& a, const Stone& b) {
    return a.size < b.size;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<Stone> stones(m);
    for (int i = 0; i < m; ++i) {
        cin >> stones[i].count;
    }
    for (int i = 0; i < m; ++i) {
        cin >> stones[i].size;
    }

    sort(stones.begin(), stones.end(), compareSize);

    long long maxHarmony = 0;
    for (int i = 0; i < m/2; ++i) {
        int harmony = (stones[i].size + stones[m-1-i].size) % k;
        maxHarmony += (long long)harmony * stones[i].count * stones[m-1-i].count;
    }

    cout << maxHarmony << endl;

    return 0;
}
