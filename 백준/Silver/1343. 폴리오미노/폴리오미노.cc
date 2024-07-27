#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string board, result;
	int cnt = 0;

	cin >> board;

	board += ' ';

	for (int i = 0; i < board.size() - 1; i++) {

		if (board[i] == 'X') cnt++;

		if (board[i] == '.') {
			result += ".";
			if (cnt % 2 != 0) break;
			else cnt = 0;
		}

		if (cnt == 2 && board[i + 1] != 'X') {
			result += "BB";
			cnt = 0;
		}
		else if (cnt == 4) {
			result += "AAAA";
			cnt = 0;
		}


	}

	if (cnt % 2 == 1) cout << -1;
	else cout << result;
}