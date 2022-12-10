#include <iostream>
#include <vector>
#include <string>

using namespace std;

string list;
vector<string> songs;

// function declarations
void displayMenu();
void addSong();
void deleteSong();
void playSong();
void displayPlaylist();

void displayPlayingMenu();


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
        if (list == "" || list == "done") { continue; }
        else{
            songs.push_back(list);
        }
    } while (list != "done");
}

// Deletes a song(s) from the playlist.
void deleteSong() {
    int erased_song;
    
    cout << "Name number of the song to delete: ";
    do {
        cin >> erased_song;

        if (list == "") { continue; }
        else {
            songs.erase(songs.begin() + erased_song - 1);
        }
    } while (list != "done");
}

// Plays a song in the playlist when selected.
void playSong() {

    int currentsong = 0;

    while (true) {
        displayPlayingMenu();
        cout << "Enter choice: ";
        int choice;
        
        cin >> choice;
        char checkcontinue;

        switch (choice) {
        case 1:     //Plays next song in order.
            try {
                // Initialized currentsong if uninitialized. The playlist loops to the beginning if it reaches the end.
                if (currentsong <= 0 || currentsong >= songs.size()) {
                    currentsong = 1;
                }
                else {
                    currentsong = currentsong + 1;
                }

                string test = songs.at(currentsong - 1);
                cout << "\nCurrently playing: " << songs[currentsong - 1] << endl;
            }
            catch (exception& e) {
                cout << "There is no song entry for the number: " << currentsong << endl;
            }
            break;
        case 2:     //Repeats current song.
            try {
                string test = songs.at(currentsong - 1);
                cout << "\nCurrently re-playing: " << songs[currentsong -1] << endl;
            }
            catch (exception& e) {
                cout << "There is no song entry for the number: " << currentsong << endl;
            }
            break;
        case 3:     //Plays random song in list.
            break;
        case 4:     //Plays chosen song.
        {
            cout << "\nEnter number of song to be played: " << endl;
            try {
                cin >> currentsong;
                string test = songs.at(currentsong - 1);
                cout << "\nCurrently playing: " << songs[currentsong - 1] << endl;
            }
            catch (exception& e) {
                cout << "There is no song entry for the number: " << currentsong << endl;
            }
        }
            break;
        default:    //catches unavailable inputs.
            cout << "Returning to menu." << endl;
        }




        
        //Asks user if they will continue listening.
        cout << "Play another song? (Y/N)" << endl;
        cin >> checkcontinue;
        if (checkcontinue == 'N' || checkcontinue == 'n') {
            break;
        }
    }
}

// Displays all the songs in the playlist.
void displayPlaylist() {
    cout << "\nYou have " << songs.size() << " songs in your playlist\n";
    try {        
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


void displayPlayingMenu() {
    cout << "1. Play next song in order.\n";
    cout << "2. Repeat this song.\n";
    cout << "3. Shuffle.\n";
    cout << "4. Choose number of song to be played.\n";
    cout << "5. Exit.\n";
}