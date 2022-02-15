
#include <iostream>
#include <cstring>

using namespace std;

int nine[10] = { 0 };
int sdoku[9][9] = { 0 };

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
    int aa;
    string a;
    cin >> aa;
    for (int ii = 0; ii < aa; ii++) {
        int start = 1;
        for (int i = 0; i < 9; i++) {
            cin >> a;
            for (int j = 0; j < 9; j++) {
                sdoku[j][i] = a[j] - 48;
            }
        }
        for (int i = 0; i < 9; i++) {
            if (check1(i) == 0) {
                start = 0;
                break;
            }
            if (check2(i) == 0) {
                start = 0;
                break;
            }
            for (int j = 0; j < 9; j += 3) {
                if (check3(i, j) == 0) {
                    start = 0;
                    break;
                }
            }
        }
        if (start == 0) {
            cout << "Could not complete this grid.\n\n";
            continue;
        }
        int zero = 0;
        int pre = -1;
        while (1) {
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    if (sdoku[j][i] == 0) {
                        zero++;

                        if (check1(i) == 1 && nine[0] == 1) {
                            for (int k = 1; k < 10; k++) {
                                if (nine[k] == 0) {
                                    sdoku[j][i] = k; 
                                    zero--; break;
                                }
                            }
                        }
                        else if (check2(j) == 1 && nine[0] == 1) {
                            for (int k = 1; k < 10; k++) {
                                if (nine[k] == 0) {
                                    sdoku[j][i] = k; 
                                    zero--; break;
                                }
                            }
                        }
                        else if (check3(j, i) == 1 && nine[0] == 1) {
                            for (int k = 1; k < 10; k++) {
                                if (nine[k] == 0) {
                                    sdoku[j][i] = k; 
                                    zero--; break;
                                }
                            }
                        }
                        else if (check1(i) == 1 && pre == zero) {
                            for (int k = 1; k < 10; k++) {
                                if (nine[k] == 0) {
                                    sdoku[j][i] = k;
                                    if (check2(j) == 1) {
                                        if (check3(j, i) == 1) {
                                            zero--; break;
                                        }
                                    }
                                    sdoku[j][i] = 0;
                                }
                                check1(i);
                            }
                        }
                    }
                }
            }
            if (zero == 0)break;
            pre = zero;
            zero = 0;
        }
        for (int n = 0; n < 9; n++) {
            for (int m = 0; m < 9; m++) {
                cout << sdoku[m][n];
            }
            cout << "\n";
        }
        cout << "\n";
    }
}
