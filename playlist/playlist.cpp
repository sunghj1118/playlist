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

    cout << "\nPlay song?\n";
    char checkcontinue;
    int currentsong;

    while (true) {
        cout << "\nEnter number of song to be played: " << endl;
        
        try {
            cin >> currentsong;
            string test = songs.at(currentsong - 1);
            cout << "\nCurrently playing: " << songs[currentsong - 1] << endl;
        }
        catch (exception &e) {
            cout << "There is no song entry for the number: " << currentsong << endl;
        }

        cout << "Play another song? (Y/N)" << endl;
        cin >> checkcontinue;
        if (checkcontinue == 'N' || checkcontinue == 'n') {
            break;
        }
    } 

    return 0;
}