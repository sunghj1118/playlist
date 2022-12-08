#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string list;
    vector<string> songs;
    cout << "Name songs: \n";
    cout << "When finished say 'done'\n";

    do {
        getline(cin, list);
        songs.push_back(list);
    } while (list != "done");

    songs.pop_back();

    cout << "\nYou have " << songs.size() << " songs in your playlist\n";

    cout << "This is your playlist: \n";
    for (int i = 0; i < songs.size(); i++)
    {
        cout << i + 1 << ". " << songs[i] << endl;
    }
    return 0;
}