#include <iostream>
#include <string>

using namespace std;
int main() {
	int count = 0;
	string str;
	getline(cin, str);
	bool first = false;
	bool first_end = false;
	bool second = false;
	bool second_end = false;
	int result_i = 0;
	char action = 0;
	double first_n = 0;
	double second_n = 0;
	double first_buffer = 0;
	double second_buffer = 0;
	double result = 0;
	double buffer = 0;
	char action_2 = 0;
	bool priorety = false;
	bool complete = false;
	string converted_int;
	int first_pos;
	int second_pos;
	for (int i = 0; i < str.size(); i++) {
		if (i + 1 == str.size()) {
			if (second || str[i] >= '0' && str[i] <= '9') {
				second_pos = i;
				second_end = true;
			}
			else break;
		}
		if (str[i] >= '0' && str[i] <= '9') {
			if (!first_end) {
				first = true;
				first_n = str[i] - 48;
				first_buffer = first_buffer * 10 + first_n;
				first_pos = i;
			}
			else {
				if (priorety) {
					second = true;
					second_n = str[i] - 48;
					second_buffer = second_buffer * 10 + second_n;
				}

			}
		}
		else if (str[i] == '+') {
			if (!first_end) {
				first = false;
				first_n = 0;
				first_buffer = 0;
			}
			else {
				second_pos = i - 1;
				second_end = true;
			}
		}
		else if (str[i] == '-') {
			if (!first_end) {
				first = false;
				first_n = 0;
				first_buffer = 0;
			}
			else {
				second_pos = i - 1;
				second_end = true;
			}
		}
		else if (str[i] == '*') {
			if (!first_end) {
				action = '*';
				first_end = true;
				priorety = true;
			}
			else {
				second_pos = i - 1;
				second_end = true;
			}
		}
		else if (str[i] == '/') {
			if (!first_end) {
				action = '/';
				first_end = true;
				priorety = true;
			}
			else {
				second_pos = i - 1;
				second_end = true;
			}
		}
		if (first_end && second_end) {
			if (action == 42) {
				result = first_buffer * second_buffer;
				if (int(result) - result == 0) {
					result_i = int(result);
					converted_int = to_string(result_i);
				}
			}
			else if (action == '/') {
				result = first_buffer / second_buffer;
				if (int(result) - result == 0) {
					result_i = int(result);
					converted_int = to_string(result_i);
				}
			}
			count = second_pos - first_pos + 1;
			str.replace(first_pos, count, converted_int);
			first = false;
			first_end = false;
			second = false;
			second_end = false;
			action = 0;
			first_n = 0;
			second_n = 0;
			first_buffer = 0;
			second_buffer = 0;
			result = 0;
			buffer = 0;
			action_2 = 0;
			priorety = false;
			complete = false;
			converted_int = {""};
			first_pos = 0;
			second_pos = 0;
			result_i = 0;
			i = -1;
		}


	}
	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			if (first_end) {
				second = true;
				second_n = str[i] - 48;
				second_buffer = (second_buffer * 10) + second_n;
			}
			else {
				first = true;
				first_n = str[i] - 48;
				first_buffer = (first_buffer * 10) + first_n;
			}

		}
		else
			if (str[i] == '+') {
				first_end = true;
				action = '+';
			}
			else
				if (str[i] == '-') {
					first_end = true;
					action = '-';
				}
		if (first && action && second) {
			if (action == '+') {
				result = first_buffer + second_buffer;
			}
			else if (action == '-') {
				result = first_buffer - second_buffer;
			}
		}
		first_buffer = second_buffer;
		second = false;
		second_end = false;
		second_buffer = 0;
	}
	cout << result;
}
	