#include <iostream>
#include <cstring>
#include <vector>
#include <tuple>

using namespace std;

int nine[10] = { 0 };
int sdoku[9][9] = { 0 };
vector<tuple<int, int, int>> ve;

int check1(int i) {
    memset(nine, 0, 10 * sizeof(int));
    for (int j = 0; j < 9; j++) {
        nine[sdoku[j][i]]++;
    }
    for (int k = 1; k < 10; k++) {
        if (nine[k] > 1) {
            return 0;
        }
    }
    return 1;
}
int check2(int j) {
    memset(nine, 0, 10 * sizeof(int));
    for (int i = 0; i < 9; i++) {
        nine[sdoku[j][i]]++;
    }
    for (int k = 1; k < 10; k++) {
        if (nine[k] > 1) {
            return 0;
        }
    }
    return 1;
}
int check3(int a, int b) {
    memset(nine, 0, 10 * sizeof(int));
    int j = a;
    int i = b;
    if (a % 3 == 1)j = a - 1;
    else if (a % 3 == 2)j = a - 2;
    if (b % 3 == 1)i = b - 1;
    else if (b % 3 == 2)i = b - 2;
    nine[sdoku[j][i]]++;
    nine[sdoku[j + 1][i]]++;
    nine[sdoku[j + 2][i]]++;
    nine[sdoku[j][i + 1]]++;
    nine[sdoku[j + 1][i + 1]]++;
    nine[sdoku[j + 2][i + 1]]++;
    nine[sdoku[j][i + 2]]++;
    nine[sdoku[j + 1][i + 2]]++;
    nine[sdoku[j + 2][i + 2]]++;
    for (int k = 1; k < 10; k++) {
        if (nine[k] > 1) {
            return 0;
        }
    }
    return 1;
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int start = 1;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> sdoku[j][i];
        }
    }
    int k = 1;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (sdoku[j][i] == 0) {
                if (k == 10) {
                    if (ve.size() != 0) {
                        j = get<0>(ve[ve.size() - 1]) - 1;
                        if (j == 8) {
                            i = get<1>(ve[ve.size() - 1]) - 1;
                            sdoku[j + 1][i + 1] = 0;
                        }
                        else {
                            i = get<1>(ve[ve.size() - 1]);
                            sdoku[j + 1][i] = 0;
                        }
                        k = get<2>(ve[ve.size() - 1]) + 1;
                        ve.pop_back();
                    }
                    continue;
                }
                for (k; k < 10; k++) {
                    sdoku[j][i] = k;
                    if (check1(i) && check2(j) && check3(j, i)) {
                        ve.push_back(make_tuple(j, i, k));
                        k = 1;
                        break;
                    }
                }
                if (k == 10) {
                    sdoku[j][i] = 0;
                    if (ve.size() != 0) {
                        j = get<0>(ve[ve.size() - 1]) - 1;
                        if (j == 8) {
                            i = get<1>(ve[ve.size() - 1]) - 1;
                            sdoku[j + 1][i + 1] = 0;
                        }
                        else {
                            i = get<1>(ve[ve.size() - 1]);
                            sdoku[j + 1][i] = 0;
                        }
                        k = get<2>(ve[ve.size() - 1]) + 1;
                        ve.pop_back();
                    }
                    continue;
                }
            }
        }
    }
    for (int n = 0; n < 9; n++) {
        for (int m = 0; m < 9; m++) {
            cout << sdoku[m][n] << " ";
        }
        cout << "\n";
    }
}
