#include <iostream>
#include <vector>
using namespace std;

int main() {
    int harder = 0;
    int easiest = 0;
    int stud_m, dom_ul_n;
    cin >> stud_m >> dom_ul_n;

    vector<double> procent(dom_ul_n, 0);
    vector<int> better_m(dom_ul_n, 0);
    vector<vector<int>> matica(stud_m, vector<int>(dom_ul_n, 0));

    for (size_t i = 0; i < dom_ul_n; i++) {
        cin >> better_m[i];
    }

    for (size_t i = 0; i < stud_m; i++) {
        for (size_t j = 0; j < dom_ul_n; j++) {
            cin >> matica[i][j];
        }
    }

    for (size_t j = 0; j < dom_ul_n; j++) {
        for (size_t i = 0; i < stud_m; i++) {
            procent[j] += matica[i][j];
        }
        procent[j] = (procent[j] / (better_m[j] * stud_m));
    }

    for (size_t i = 0; i < dom_ul_n; i++) {
        if (procent[i] < procent[harder]) {
            harder = i;
        }
        if (procent[i] > procent[easiest]) {
            easiest = i;
        }
    }

    for (size_t i = 0; i < dom_ul_n; i++) {
        cout << procent[i];
        if (i == harder) {
            cout << " harder";
        }
        if (i == easiest) {
            cout << " easiest";
        }
        cout << endl;
    }

    return 0;
}
