#include <iostream>
#include <string>
 
using namespace std;
 
int main()
{
	int n;
	string str;
	cin >> n;
	while (n--) {
		cin >> str;
		bool orz = false;
		for (int i = 0; i < str.length(); i++) {
			if (str.substr(i, 3) == "orz") {
				orz = true;
				break;
			}
		}
		if (!orz) {
			for (int i = str.length()-1; i >= 0; i--) {
				if (str.substr(i, 2) == "rz") {
					str.insert(i,"o");
					orz = true;
					break;
				}
				else if (str.substr(i, 2) == "oz") {
					str.insert(i+1, "r");
					orz = true;
					break;
				}
				else if (str.substr(i, 2) == "or") {
					str.insert(i+2, "z");
					orz = true;
					break;
				}
			}
		}
		if (!orz) {
			for (int i = str.length() - 1; i >= 0; i--) {
				if (str[i] == 'z') {
					str.insert(i, "r");
					str.insert(i, "o");
					orz = true;
					break;
				}
				else if (str[i] == 'r') {
					str.insert(i + 1, "z");
					str.insert(i , "o");
					orz = true;
					break;
				}
				else if (str[i] == 'o') {
					str.insert(i +1, "z");
					str.insert(i + 1, "r");
					orz = true;
					break;
				}
			}
		}
		if (!orz) {
			str += "orz";
		}
		cout << str << "\n";
	}
	return 0;
}
