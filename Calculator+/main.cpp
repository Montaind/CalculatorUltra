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
	int action_pos = 0;
	string converted_int;
	int first_pos;
	int second_pos;
	char action_old = 0;
	int divine_counter = 1;
	bool point_found = false;
	bool point_found1 = false;
	bool point_found2 = false;
	string v;
	for (char c : str) if (c != ' ') v += c;
	str = v;

	for (int i = 0; i < str.size(); i++) {
	
	}





	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			if (!first_end) {
				if (!first) {
					first = true;
					first_n = str[i] - 48;
					first_buffer = first_buffer * 10 + first_n;
					first_pos = i;
				}
				else {
					first_n = str[i] - 48;
					first_buffer = first_buffer * 10 + first_n;
				}
			}
			else {
				if (priorety) {
					second = true;
					second_n = str[i] - 48;
					second_buffer = second_buffer * 10 + second_n;
				}

			}
		}
		else if (str[i] == '.') {
			point_found = true;
			if (first_end) {
				point_found2 = true;
			}
			else {
				point_found1 = true;
			}
		}
		else if (str[i] == '+') {
			if (!first_end) {
				first = false;
				first_n = 0;
				first_buffer = 0;
				action_pos = i;
			}
			else {
				second_pos = i - 1;
				second_end = true;
			}
		}
		else if (str[i] == '-') {
			if (!first_end) {
				action_pos = i;
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
				action_pos = i;
				action = '*';
				first_end = true;
				priorety = true;
			}
			else {
				action_old = action;
				action = '*';
				second_pos = i - 1;
				second_end = true;
			}
		}
		else if (str[i] == '/') {
			if (!first_end) {
				action_pos = i;
				action = '/';
				first_end = true;
				priorety = true;
			}
			else {
				action_old = action;
				action = '/';
				second_pos = i - 1;
				second_end = true;
			}
		}
		if (i+1 == str.size()) {
			if (second || str[i] >= '0' && str[i] <= '9') {
				if (action_pos - first_pos > 0) {
					second_pos = i;
					second_end = true;
				}
				else {
					first = false;
					first_n = false;
					first_end = false;
					first_buffer = 0;
					point_found = false;
					divine_counter = 1;
					point_found1 = false;
					point_found2 = false;
					break;
				}
			}
			else {
				first = false;
				first_n = false;
				first_end = false;
				first_buffer = 0;
				point_found = false;
				divine_counter = 1;
				point_found1 = false;
				point_found2 = false;
				break;
			}

		}
		if (point_found) {
			if (point_found1) {
				if (first && !first_end) {
					divine_counter *= 10;
				}
				else if (first_end) {
					first_buffer /= divine_counter;
					point_found = false;
					divine_counter = 1;
					point_found1 = false;
				}
			}
			else if (point_found2) {
				if (second && !second_end) {
					divine_counter *= 10;
				}
				else if (second_end) {
					second_buffer /= divine_counter;
					point_found = false;
					divine_counter = 1;
					point_found2 = false;
				}
			}
		}
		if (first_end && second_end) {
			if (!action_old) {
				if (action == '*') {
					result = first_buffer * second_buffer;
					if (int(result) - result == 0) {
						result_i = int(result);
						converted_int = to_string(result_i);

					}
					else converted_int = to_string(result);
				}
				else if (action == '/') {
					result = first_buffer / second_buffer;
					if (int(result) - result == 0) {
						result_i = int(result);
						converted_int = to_string(result_i);
					}
					else converted_int = to_string(result);
				}
			}
			else {
				if (action_old == '*') {
					result = first_buffer * second_buffer;
					if (int(result) - result == 0) {
						result_i = int(result);
						converted_int = to_string(result_i);
					}
					else converted_int = to_string(result);
				}
				else if (action_old == '/') {
					result = first_buffer / second_buffer;
					if (int(result) - result == 0) {
						result_i = int(result);
						converted_int = to_string(result_i);
					}
					else converted_int = to_string(result);
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
			converted_int = { "" };
			first_pos = 0;
			second_pos = 0;
			result_i = 0;
			i = -1;
			action_pos = 0;
			count = 0;
			action_old = 0;
			point_found = false;
			divine_counter = 1;
			point_found1 = false;
			point_found2 = false;
		}
	}
	



	for (int i = 0; i < str.size(); i++) {
		if (i + 1 == str.size()) {
			second_end = true;
		}
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
			if (str[i] == '.') {
				point_found = true;
				if (first_end) {
					point_found2 = true;
				}
				else {
					point_found1 = true;
				}
			}
			if (str[i] == '+') {
				if (action) {
					if (first_end) {
						second_end = true;
						action_2 = '+';
					}
					else {
						first_end = true;
						action_2 = '+';
					}
				}
				else {
					if (first_end) {
						second_end = true;
						action = '+';
					}
					else {
						first_end = true;
						action = '+';
					}
				}
			}
			else
				if (str[i] == '-') {
					if (action) {
						if (first_end) {
							second_end = true;
							action_2 = '-';
						}
						else {
							first_end = true;
							action_2 = '-';
						}
					}
					else {
						if (first_end) {
							second_end = true;
							action = '-';
						}
						else {
							first_end = true;
							action = '-';
						}
					}
				}
				else
					if (str[i] == '*') {
						if (action) {
							if (first_end) {
								second_end = true;
								action_2 = '*';
							}
							else {
								first_end = true;
								action_2 = '*';
							}
						}
						else {
							if (first_end) {
								second_end = true;
								action = '*';
							}
							else {
								first_end = true;
								action = '*';
							}
						}
					}
					else if (str[i] == '/') {
						if (action) {
							if (first_end) {
								second_end = true;
								action_2 = '/';
							}
							else {
								first_end = true;
								action_2 = '/';
							}
						}
						else {
							if (first_end) {
								second_end = true;
								action = '/';
							}
							else {
								first_end = true;
								action = '/';
							}
						}
					}
			if (point_found) {
				if (point_found1) {
					if (first && !first_end) {
						divine_counter *= 10;
					}
					else if (first_end) {
						first_buffer /= divine_counter;
						point_found = false;
						divine_counter = 1;
						point_found1 = false;
					}
				}
				else if (point_found2) {
					if (second && !second_end) {
						divine_counter *= 10;
					}
					else if (second_end) {
						second_buffer /= divine_counter;
						point_found = false;
						divine_counter = 1;
						point_found2 = false;
					}
				}
			}
		if (first && action && second_end) {
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
			second = false;
			second_end = false;
			buffer = result;
			first_buffer = buffer;
			action = action_2;
			second_n = 0;
			second_buffer = 0;
			result = 0;
		}
	}
	if (buffer == 0) {
		count = 0;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
				count++;
			}
		}
		if (count == 0) {
			for (int j = 0; j < str.size(); j++) {
				cout << str[j];
			}
		}
	}
	else {
		cout << buffer;
	}
}