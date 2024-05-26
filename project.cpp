#include <iostream>
#include <string>

using namespace std;

struct Music {
    string name;
    string artist;
    int album;
    string genre;
};

void display(Music songs[], int count) {
    cout << "\nMusic Organizer:\n";
    cout << "----------------------------\n";
    for (int i = 0; i < count; i++) {
        cout << "Name: " << songs[i].name << " | Artist: " << songs[i].artist
             << " | Album: " << songs[i].album << " | Genre: " << songs[i].genre << '\n';
    }
    cout << "----------------------------\n";
}

void displayGrouped(Music songs[], int count) {
    cout << "\nGrouped Music:\n";
    cout << "----------------------------\n";
    for (int i = 0; i < count; ) {
        cout << songs[i].genre << ": ";
        int j = i;
        while (j < count && songs[j].genre == songs[i].genre) {
            cout << songs[j].name << ", ";
            j++;
        }
        cout << '\n';
        i = j;
    }
    cout << "----------------------------\n";
}

void displayArtist(Music songs[], int count) {
    cout << "\nGrouped Artists:\n";
    cout << "----------------------------\n";
    for (int i = 0; i < count; ) {
        cout << songs[i].artist << ": ";
        int j = i;
        while (j < count && songs[j].artist == songs[i].artist) {
            cout << songs[j].name << ", ";
            j++;
        }
        cout << '\n';
        i = j;
    }
    cout << "----------------------------\n";
}

void sortByAlbum(Music songs[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (songs[i].album > songs[j].album) {
                Music temp = songs[i];
                songs[i] = songs[j];
                songs[j] = temp;
            }
        }
    }
}

void sortByGenreNameAlbum(Music songs[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (songs[i].genre > songs[j].genre ||
                (songs[i].genre == songs[j].genre && songs[i].name > songs[j].name) ||
                (songs[i].genre == songs[j].genre && songs[i].name == songs[j].name && songs[i].album > songs[j].album)) {
                Music temp = songs[i];
                songs[i] = songs[j];
                songs[j] = temp;
            }
        }
    }
}

int main() {
    Music songs[100];
    int count = 0;

    cout << "Welcome to the Music Organizer!\n";
    while (true) {
        cout << "\nEnter Music Details:\n";
        cout << "Name: ";
        cin.ignore();  
        getline(cin, songs[count].name);
        cout << "Artist: ";
        getline(cin, songs[count].artist);
        cout << "Album Number: ";
        cin >> songs[count].album;
        cin.ignore(); 
        cout << "Choose Genre (rock/pop/rap/classical/others): ";
        getline(cin, songs[count].genre);

        count++;

        char choice;
        cout << "Do you want to add more music? (y/n): ";
        cin >> choice;
        if (choice != 'y' && choice != 'Y') {
            break;
        }
    }

    sortByGenreNameAlbum(songs, count);

    displayGrouped(songs, count);
    sortByAlbum(songs, count);
    display(songs, count);
    displayArtist(songs, count);

    return 0;
}
