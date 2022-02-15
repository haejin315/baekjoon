// baekjoon(1051_숫자 정사각형).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	string a[50];
	int aa[50][50] = { 0 };
	int b;
	if (n > m) { b = m; }
	else { b = n; }
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int i = 0;
	int c = 0;
	int d = 1;
	int e = 1;
	while (1) {
		while (1) {
			if (i + d >= n || c + d >= m) {
				d = 1;
				e = 1;
				break;
			}
			if (a[i][c] == a[i + d][c] && a[i][c] == a[i][c + d] && a[i][c] == a[i + d][c + d]) {
				d++;
				e = d;
				aa[i][c] = e;
			}
			else {
				d++;
			}
		}
		if (i + 1 < n) { i++; }
		else {
			if (c + 1 < m) { i = 0; c++; }
			else {
				break;
			}
		}
	}
	int ans = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (aa[i][j] > ans) {
				ans = aa[i][j];
			}
		}
	}
	if (ans == 0) { ans++; }
	cout << ans * ans;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
