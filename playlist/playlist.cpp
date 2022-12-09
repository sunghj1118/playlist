#include <iostream>
#include <vector>
#include <string>

using namespace std;

string list;
vector<string> songs;

void displayMenu();
void addSong();
void deleteSong();
void playSong();
void displayPlaylist();


int main()
{
    int choice;
    char confirm;

    do
    {
        displayMenu();
        cout << "Enter choice: " << endl;
        cin >> choice;
        
        switch (choice) {
        case 1: addSong(); break;
        case 2: deleteSong(); break;
        case 3: playSong(); break;
        case 4: displayPlaylist(); break;
        default: cout << "invalid choice" << endl;
        }

        cout << "\nReturn to menu? (Y/N)" << endl;
        cin >> confirm;
    } while (confirm == 'Y' || confirm == 'y');

    return 0;
}



// Displays the main menu.
void displayMenu() {
    cout << "MENU\n";
    cout << "1. Add songs.\n";
    cout << "2. Delete songs.\n";
    cout << "3. Play songs.\n";
    cout << "4. Display playlist.\n\n";
}

// Adds a song(s) to the playlist.
void addSong() {
    cout << "\nName songs: \n";
    cout << "When finished say 'done'\n";

    do {
        getline(cin, list);
        if (list == ""){continue;}
        else{
            songs.push_back(list);
        }
    } while (list != "done");
}

// Deletes a song(s) from the playlist.
void deleteSong() {
    cout << "Name songs to delete: ";
}

// Plays a song in the playlist when selected.
void playSong() {
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
        catch (exception& e) {
            cout << "There is no song entry for the number: " << currentsong << endl;
        }

        cout << "Play another song? (Y/N)" << endl;
        cin >> checkcontinue;
        if (checkcontinue == 'N' || checkcontinue == 'n') {
            break;
        }
    }
}

// Displays all the songs in the playlist.
void displayPlaylist() {
    cout << "\nYou have " << songs.size() - 1 << " songs in your playlist\n";
    try {
        string test = songs.at(0);
        songs.pop_back();
        
        cout << "This is your playlist: \n";
        for (int i = 0; i < songs.size(); i++)
        {
            cout << i + 1 << ". " << songs[i] << endl;
        }
    }
    catch (exception& e) {
        cout << "Add more songs to display." << endl;
    }
}