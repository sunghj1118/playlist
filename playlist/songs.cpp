#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Playlist {
	vector<string> plist;
public:
	Playlist(vector<string> list) : plist(list) {}
	Playlist operator += (string s) {
		plist.push_back(s);
		return *this;
	}
	Playlist operator -= (string s) {
		int size = plist.size();


		int i = 0;
		for (i; i < size; i++) {
			if (plist[i] == s) {
				break;
			}
		}
		plist.erase(plist.begin() + i);
		return *this;
	}
	void Print() {
		for (int i = 0; i < plist.size(); i++) {
			cout << plist[i] << " ";
		}
	}
};

int main() {
	int num;
	cin >> num;

	vector<string> strlist;
	string s;
	while (num--) {
		cin >> s;
		strlist.push_back(s);
	}

	Playlist plist(strlist);

	string as;
	while (cin >> as) {
		if (as[0] == '+') {
			plist += as.substr(1, string::npos);
		}
		else if (as[0] == '-') {
			plist -= as.substr(1, string::npos);
		}
	}

	plist.Print();
}