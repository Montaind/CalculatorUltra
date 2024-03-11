#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main() {
	string actions;
	string str;
	vector<int> positions;
	getline(cin, str);
	bool first = false;
	bool first_end = false;
	bool second = false;
	bool second_end = false;
	char action = 0;
	double all_buffer;
	double first_n;
	double second_n;
	double first_buffer = 0;
	double second_buffer = 0;
	double result;
	double buffer;
	int a;
	int b;
	char action_2 = 0;
	int count = 0;
	string v;
	for (char c : str) if (c != ' ') v += c;
	str = v;
	cout << str << endl;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
			{
				if (str[i] == '+') {
					actions.push_back('+');
					positions.push_back(i);
				}
				else if (str[i] == '-') {
					actions.push_back('-');
					positions.push_back(i);
				}
				else if (str[i] == '*') {
					actions.push_back('*');
					positions.push_back(i);
				}
				else if (str[i] == '/') {
					actions.push_back('/');
					positions.push_back(i);
				}
				count++;
			}
		}
	}
	for (int i = 0; i < count; i++) {
		if (actions[i] == '*' || actions[i] == '/') {
			int a = positions[i];
			int b = positions[i - 1];
			actions.erase(i);
			positions.erase(positions.begin()+(i-1));
			break;
		}
	}









	for (int i = 0; i < count; i++) {
		cout << actions[i];
	}
	cout << "\n";
	for (int i = 0; i < positions.size(); i++) {
		cout << positions[i] << " ";
	}
}