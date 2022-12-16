#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Song {
	char name[30];
	string artist;
	int repetitions;

public:
	void getData();
	void printData();
};

void Song:: getData() {
	cout << "Enter song name: ";
	cin >> name;
	cout << "Enter artist name: ";
	cin >> artist;
	cout << endl;
	repetitions = 0;
}

void Song :: printData() {
	cout << artist << " - " << name << endl;
}

int main() {
	Song playist[30];
	int n;

	cout << "Enter number of songs: ";
	cin >> n;

	//Adding songs
	for (int i = 0; i < n; i++) {
		playist[i].getData();
	}

	//Print all songs
	for (int i = 0; i < n; i++) {
		playist[i].printData();
	}

	return 0;
}