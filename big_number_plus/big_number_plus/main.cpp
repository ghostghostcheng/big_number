#include <iostream>
using namespace std;

int main() {
	char char1[100], char2[100];
	int num1[100], num2[100], result[101];
	int str_len_char1 = 0, str_len_char2 = 0;

	for (int i = 0; i < 100; i++) {
		char1[i] = -1;
		char2[i] = -1;
		num1[i] = -1;
		num2[i] = -1;
	}

	cout << "input num1 (less than 100 length):";
	cin.getline(char1, 100);
	str_len_char1 = strlen(char1);
	char1[str_len_char1] = -1;

	cout << "input num2 (less than 100 length):";
	cin.getline(char2, 100);
	str_len_char2 = strlen(char2);
	char2[str_len_char2] = -1;

	for (int i = 0; i < str_len_char1; i++) {     //  char char1[99] -> anti-array -> int num1[0]
		num1[i] = (int)char1[str_len_char1 - i - 1] - 48;   //48 ascii
		cout << num1[i];
	}

	for (int i = 0; i < str_len_char2; i++) {     //  char char2[99] -> anti-array -> int num2[0]
		num2[i] = (int)char2[str_len_char2 - i - 1] - 48;   //48 for ascii
		cout << num2[i];
	}

	int j = 0;
	int carry = 0, tmp_result = 0;
	for (j; j < 100; j++) {

		if (num1[j] < 0 && num2[j] < 0) {
			break;
		} else {

			if (num1[j] < 0) {
				num1[j] = 0;
			}

			if (num2[j] < 0) {
				num2[j] = 0;
			}

			tmp_result = (num1[j] + num2[j] + carry);
			carry = tmp_result / 10;
			result[j] = tmp_result % 10;
		}
	}

	if (carry > 0) {       //last
		result[j] = carry;
		j = j + 1;
	}

	for (int i = j - 1; i >= 0; i--) {
		cout << result[i];
	}

	system("pause");
}

