#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<long long> cow_heights(N);
    for (int i = 0; i < N; ++i) {
        cin >> cow_heights[i];
    }

    for (int m = 0; m < M; ++m) {
        long long candy_height;
        cin >> candy_height;

        long long lowest_uneaten = 0;
        for (int i = 0; i < N; ++i) {
            if (cow_heights[i] > lowest_uneaten) {
                long long eat_amount = min(candy_height - lowest_uneaten, cow_heights[i] - lowest_uneaten);
                cow_heights[i] += eat_amount;
                lowest_uneaten += eat_amount;
            }
            if (lowest_uneaten >= candy_height) break;
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << cow_heights[i] << '\n';
    }

    return 0;
}
