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
	char action = 0;
	double first_n;
	double second_n;
	double first_buffer = 0;
	double second_buffer = 0;
	double result;
	double buffer;
	char action_2 = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
			count++;
		}
	}
	for (int j = 0; j < count; j++) {
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
                    else
                        if (str[i] == '*') {
                            first_end = true;
                            action = '*';
                        }
                        else if (str[i] == '/') {
                            first_end = true;
                            action = '/';
                        }
        }
        if (first && action && second) {
            if (action == '+') {
                result = first_buffer + second_buffer;
            }
            else if (action == '-') {
                result = first_buffer - second_buffer;
            }
            else if (action == '*') {
                result = first_buffer * second_buffer;
            }
            else if (action == '/') {
                result = first_buffer / second_buffer;
            }
        }
        first_buffer = second_buffer;
        second = false;
        second_end = false;
        second_buffer = 0;
	}
}