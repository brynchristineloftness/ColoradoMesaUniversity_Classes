#include <iostream>
#include <string>
#include <ctype.h>
#include <istream>

using namespace std;

const int MaxGuesses = 15;
char guess[MaxGuesses] = {"0"} ;
char phrase[250];
int CounterofValidGuesses=0;
int NumberofCharacters=0;
bool Winner = false;
int CounterofGuesses=0;
int CounterofInvalidGuesses=0;
void DidYouWin(char* phrase,char entry[]);
void isGuessInPhrase(char* phrase,char& entry);
void OutputPhrasewithGuess(char* phrase,char entry[]);
void MakePicture(int NumofGuesses);
void WinningDinosaur();
void MakeSpaces();
void MakeLetterBank(char* phrase,char entry[]);


int main() {
int i = 0;
char phrase[250];
cout << "Input desired phrase. (Must be all lowercase!)" << " ";
cin.getline(phrase,250);
MakeSpaces();
while (phrase[i]) {
    if ( isalpha(phrase[i]) ) {
        cout << "_ ";
        NumberofCharacters++;
        }
    else if ( isspace(phrase[i])) {cout << "  " << " ";}
    i++;
    }
cout << endl;
for (int j=0; j < MaxGuesses; j++) {
    cout << endl;
    MakePicture(j);
    cout << endl;
    cout << "Input desired guess. (Must be lowercase!)" << "  ";
    cin >> guess[j];
    MakeSpaces();
    cout << "You entered " << guess[j] << " ...";
    isGuessInPhrase(phrase,guess[j]);
    OutputPhrasewithGuess(phrase,guess);
    MakeLetterBank(phrase,guess);
    DidYouWin(phrase,guess);
    if (Winner) {
    WinningDinosaur();
    cout << endl << "You won! The phrase was " << phrase << endl; break;}
}
    if (!Winner) {
    cout << "You lost! The phrase was " << phrase << endl; }
return 0;
}

void DidYouWin(char* phrase,char entry[]) {
int i=0;
while (phrase[i]) {
bool isFound = false;
for (int j=0;j<MaxGuesses;j++) {
    if (entry[j] == phrase[i]) {isFound = true; break;}
}
    if (isFound) {
          CounterofValidGuesses++;
    }
    i++;  }
if (CounterofValidGuesses==NumberofCharacters) {Winner = true;}
else {CounterofValidGuesses=0;}
}

void WinningDinosaur() {
cout << endl;
cout<<"    .-~~^-.                                                                      "<< endl;   
cout<<"  .'  O   \\                                                                     "<< endl;
cout<<" (_____,   \\                                                                    "<< endl;
cout<<"  `----.    \\                                                                   "<< endl;
cout<<"       \\    \\                                                                  "<< endl;
cout<<"        \\    \\                                                                 "<< endl;
cout<<"         \\     `.             _ _                                               "<< endl;
cout<<"          \\       ~- _ _ - ~       ~ - .                                        "<< endl;
cout<<"           \\  Looks like this dino is   ~-.                                     "<< endl;
cout<<"            \\   a Frankenstein-a-saur!    `.                                    "<< endl;
cout<<"             \\    /               /      \\  \\                                 "<< endl;
cout<<"               `. |         }     |         }   \\                               "<< endl;
cout<<"                 `|        /      |        /      \\                             "<< endl;
cout<<"                  |       /       |       /         \\                           "<< endl;
cout<<"                  |      /`- _ _ _|      /.- ~ ^-.    \\                         "<< endl;
cout<<"                  |     /         |     /          `.   \\                       "<< endl;
cout<<"                  |     |         |     |             -.   ` . _ _ _ _ _ _       "<< endl;
cout<<"                  |_____|         |_____|                ~ . _ _ _ _ _ _ _ >     "<< endl;
}

void isGuessInPhrase(char* phrase,char& entry) {
int i=0;
bool ValidGuess = false;
while (phrase[i]) {
    if (entry == phrase[i]) {
        ValidGuess = true;
        cout << "That letter is a good guess!" << endl;
        break;} 
    i++; }
    if (ValidGuess == false) {
        cout << "Your entry is not in the phrase." << endl;
        CounterofInvalidGuesses++;
    }
}

void OutputPhrasewithGuess(char* phrase,char entry[]) {
    int i = 0;
    while (phrase[i]) {
        bool found=false;
    for (int j=0;j<MaxGuesses;j++) {
        if (phrase[i] == entry[j]) {
            found=true;
             }
    }
        if ( isspace(phrase[i])) {cout <<" " << " ";}
        else if ( !found) {cout << "_ "; }
        else {cout << phrase[i]<< " ";}
    i++;
    }
}

void MakeSpaces() {
cout << '\n'<<'\n'<<'\n'<<'\n'<<'\n'<<'\n'<<'\n'<<'\n'<<'\n'<<'\n'<<'\n'<<'\n'<<'\n'<<'\n'<<'\n'<<'\n'<<'\n'<<'\n'<<'\n'<<'\n'<<'\n'<<'\n'<<'\n'<<'\n'<<'\n'<< endl;
}

void MakeLetterBank(char* phrase,char entry[]) {
cout << endl;
int j=0;
cout << "These are all your guessed letters thus far: ";
while (entry[j]) {
	if (isalpha(entry[j])){
		cout << entry[j] << " "; }
j++;
}
}

void MakePicture(int NumofGuesses) {
if (NumofGuesses == 0) {
cout<<"    .-~~^-.              "<< endl;   
cout<<"  .'  O   \\             "<< endl;
cout<<" (_____,   \\            "<< endl;
cout<<"  `----.    \\           "<< endl;
cout<<"       \\    \\          "<< endl;
cout<<"        \\    \\         "<< endl;
cout<<"         \\     `.             _ _           "<< endl;
cout<<"          \\       ~- _ _ - ~       ~ - .    "<< endl;
cout<<"           \\  Guess the phrase or watch  ~-.            "<< endl;
cout<<"            \\   the dinosaur go extinct!    `.          "<< endl;
cout<<"             \\    /               /      \\   \\        "<< endl;
cout<<"               `. |         }     |         }   \\       "<< endl;
cout<<"                 `|        /      |        /      \\     "<< endl;
cout<<"                  |       /       |       /         \\           "<< endl;
cout<<"                  |      /`- _ _ _|      /.- ~ ^-.    \\         "<< endl;
cout<<"                  |     /         |     /          `.   \\       "<< endl;
cout<<"                  |     |         |     |             -.   ` . _ _ _ _ _ _   "<< endl;
cout<<"                  |_____|         |_____|                ~ . _ _ _ _ _ _ _ > "<< endl;
cout<<endl;
cout << "Keep in mind, even if you get the answer correct, ";
cout << "time is still running out for Mr. Dino!" << endl;
cout << "Will his extinction be reversed? Only you can help!"<< endl;
cout << endl;
cout<< endl;
}

else if (NumofGuesses == 1) {
cout<<"    .-~~^-.                              "<< endl;   
cout<<"  .'  O   \\                             "<< endl;
cout<<" (_____,   \\                            "<< endl;
cout<<"  `----.    \\                           "<< endl;
cout<<"       \\    \\                          "<< endl;
cout<<"        \\    \\                         "<< endl;
cout<<"         \\     `.             _ _       "<< endl;
cout<<"          \\       ~- _ _ - ~       ~ - .        "<< endl;
cout<<"           \\                             ~-.        "<< endl;
cout<<"            \\  It all starts with the TAIL! `.      "<< endl;
cout<<"             \\    /               /      \\   \\    "<< endl;
cout<<"               `. |         }     |         }   \\   "<< endl;
cout<<"                 `|        /      |        /      \\ "<< endl;
cout<<"                  |       /       |       /         \\   "<< endl;
cout<<"                  |      /`- _ _ _|      /.- ~ ^-.    \\ "<< endl;
cout<<"                  |     /         |     /          `.   \\   "<< endl;
cout<<"                  |     |         |     |             -.   ` . _ _ _ "<< endl;
cout<<"                  |_____|         |_____|               ~ . _ _ _ _ "<< endl;
cout << endl;
cout << "Keep in mind, even if you get the answer correct, ";
cout << "time is still running out for Mr. Dino!" << endl;
cout << "Will his extinction be reversed? Only you can help!"<< endl;
cout << endl;
cout<< endl;
}
else if (NumofGuesses == 2) {
cout<<"    .-~~^-.                                  "<< endl;   
cout<<"  .'  O   \\                                 "<< endl;
cout<<" (_____,   \\                                "<< endl;
cout<<"  `----.    \\                               "<< endl;
cout<<"       \\    \\                              "<< endl;
cout<<"        \\    \\                             "<< endl;
cout<<"         \\     `.             _ _                   "<< endl;
cout<<"          \\       ~- _ _ - ~       ~ - .            "<< endl;
cout<<"           \\   Help the dinosaur's TAIL! ~-.        "<< endl;
cout<<"            \\    It's vanishing!            `.      "<< endl;
cout<<"             \\    /               /      \\   \\    "<< endl;
cout<<"               `. |         }     |         }   \\   "<< endl;
cout<<"                 `|        /      |        /      \\         "<< endl;
cout<<"                  |       /       |       /         \\       "<< endl;
cout<<"                  |      /`- _ _ _|      /.- ~ ^-.    \\     "<< endl;
cout<<"                  |     /         |     /          `.   \\   "<< endl;
cout<<"                  |     |         |     |             -.   ` "<< endl;
cout<<"                  |_____|         |_____|                ~ .  "<< endl;
cout << endl;
cout << "Keep in mind, even if you get the answer correct, ";
cout << "time is still running out for Mr. Dino!" << endl;
cout << "Will his extinction be reversed? Only you can help!"<< endl;
cout << endl;
cout<< endl;
}
else if (NumofGuesses == 3) {
cout<<"    .-~~^-.                                              "<< endl;   
cout<<"  .'  O   \\                                             "<< endl;
cout<<" (_____,   \\                                            "<< endl;
cout<<"  `----.    \\                                           "<< endl;
cout<<"       \\    \\                                          "<< endl;
cout<<"        \\    \\                                         "<< endl;
cout<<"         \\     `.             _ _                       "<< endl;
cout<<"          \\       ~- _ _ - ~       ~ - .                "<< endl;
cout<<"           \\  At this rate, it will be   ~-.            "<< endl;
cout<<"            \\ TAIL end of the game in no time`.         "<< endl;
cout<<"             \\    /               /      \\   \\        "<< endl;
cout<<"               `. |         }     |         }   \\       "<< endl;
cout<<"                 `|        /      |        /      \\     "<< endl;
cout<<"                  |       /       |       /         \\   "<< endl;
cout<<"                  |      /`- _ _ _|      /.- ~ ^-.    \\ "<< endl;
cout<<"                  |     /         |     /          `.    "<< endl;
cout<<"                  |     |         |     |                "<< endl;
cout<<"                  |_____|         |_____|                "<< endl;
cout << endl;
cout << "Keep in mind, even if you get the answer correct, ";
cout << "time is still running out for Mr. Dino!" << endl;
cout << "Will his extinction be reversed? Only you can help!"<< endl;
cout << endl;
cout<< endl;
}
else if (NumofGuesses == 4) {
cout<<"    .-~~^-.                                              "<< endl;   
cout<<"  .'  O   \\                                             "<< endl;
cout<<" (_____,   \\                                            "<< endl;
cout<<"  `----.    \\                                           "<< endl;
cout<<"       \\    \\                                          "<< endl;
cout<<"        \\    \\                                         "<< endl;
cout<<"         \\     `.             _ _                       "<< endl;
cout<<"          \\       ~- _ _ - ~       ~ - .                "<< endl;
cout<<"           \\ No shopping for this dino,  ~-.            "<< endl;
cout<<"            \\       No access to re-TAIL!   `.          "<< endl;
cout<<"             \\    /               /      \\   \\        "<< endl;
cout<<"               `. |         }     |         }   \\       "<< endl;
cout<<"                 `|        /      |        /      \\     "<< endl;
cout<<"                  |       /       |       /              "<< endl;
cout<<"                  |      /`- _ _ _|      /.- ~ ^-        "<< endl;
cout<<"                  |     /         |     /                "<< endl;
cout<<"                  |     |         |     |                "<< endl;
cout<<"                  |_____|         |_____|                "<< endl;
cout << endl;
cout << "Keep in mind, even if you get the answer correct, ";
cout << "time is still running out for Mr. Dino!" << endl;
cout << "Will his extinction be reversed? Only you can help!"<< endl;
cout << endl;
cout<< endl;
}
else if (NumofGuesses == 5) {
cout<<"    .-~~^-.                                              "<< endl;   
cout<<"  .'  O   \\                                             "<< endl;
cout<<" (_____,   \\                                            "<< endl;
cout<<"  `----.    \\                                           "<< endl;
cout<<"       \\    \\                                          "<< endl;
cout<<"        \\    \\                                         "<< endl;
cout<<"         \\     `.             _ _                       "<< endl;
cout<<"          \\       ~- _ _ - ~       ~ - .                "<< endl;
cout<<"           \\   The LEG-stinction has     ~-.            "<< endl;
cout<<"            \\            begun!!            `.          "<< endl;
cout<<"             \\    /               /      \\   \\        "<< endl;
cout<<"               `. |         }     |         }   \\       "<< endl;
cout<<"                 `|        /      |        /      \\     "<< endl;
cout<<"                  |       /       |       /              "<< endl;
cout<<"                  |      /`- _ _ _|      /.- ~ ^-        "<< endl;
cout<<"                  |     /         |     /                "<< endl;
cout<<"                  |     |         |     |                "<< endl;
cout<<"                  |_____|                                "<< endl;
cout << endl;
cout << "Keep in mind, even if you get the answer correct, ";
cout << "time is still running out for Mr. Dino!" << endl;
cout << "Will his extinction be reversed? Only you can help!"<< endl;
cout << endl;
cout<< endl;
}
else if (NumofGuesses == 6) {
cout<<"    .-~~^-.                                              "<< endl;   
cout<<"  .'  O   \\                                             "<< endl;
cout<<" (_____,   \\                                            "<< endl;
cout<<"  `----.    \\                                           "<< endl;
cout<<"       \\    \\                                          "<< endl;
cout<<"        \\    \\                                         "<< endl;
cout<<"         \\     `.             _ _                       "<< endl;
cout<<"          \\       ~- _ _ - ~       ~ - .                "<< endl;
cout<<"           \\   This is what happens when ~-.            "<< endl;
cout<<"            \\    you skip LEG day...        `.          "<< endl;
cout<<"             \\    /               /      \\   \\        "<< endl;
cout<<"               `. |         }     |         }   \\       "<< endl;
cout<<"                 `|        /      |        /      \\     "<< endl;
cout<<"                  |       /       |       /              "<< endl;
cout<<"                  |      /`- _ _ _|      /.- ~ ^-        "<< endl;
cout<<"                  |     /                                "<< endl;
cout<<"                  |     |                                "<< endl;
cout<<"                  |_____|                                "<< endl;
cout << endl;
cout << "Keep in mind, even if you get the answer correct, ";
cout << "time is still running out for Mr. Dino!" << endl;
cout << "Will his extinction be reversed? Only you can help!"<< endl;
cout << endl;
cout<< endl;
}
else if (NumofGuesses == 7) {
cout<<"    .-~~^-.                                          "<< endl;   
cout<<"  .'  O   \\                                         "<< endl;
cout<<" (_____,   \\                                        "<< endl;
cout<<"  `----.    \\                                       "<< endl;
cout<<"       \\    \\                                      "<< endl;
cout<<"        \\    \\                                     "<< endl;
cout<<"         \\     `.             _ _                   "<< endl;
cout<<"          \\       ~- _ _ - ~       ~ - .            "<< endl;
cout<<"           \\   You BUTT-er try again!    ~-.        "<< endl;
cout<<"            \\    Time is running out!               "<< endl;
cout<<"             \\    /               /      \\         "<< endl;
cout<<"               `. |         }     |         }        "<< endl;
cout<<"                 `|        /      |        /         "<< endl;
cout<<"                  |       /       |       /          "<< endl;
cout<<"                  |      /`- _ _ _|      /.-         "<< endl;
cout<<"                  |     /                            "<< endl;
cout<<"                  |     |                            "<< endl;
cout<<"                  |_____|                            "<< endl;
cout << endl;
cout << "Keep in mind, even if you get the answer correct, ";
cout << "time is still running out for Mr. Dino!" << endl;
cout << "Will his extinction be reversed? Only you can help!"<< endl;
cout << endl;
cout<< endl;
}
else if (NumofGuesses == 8) {
cout<<"    .-~~^-.                                  "<< endl;   
cout<<"  .'  O   \\                                 "<< endl;
cout<<" (_____,   \\                                "<< endl;
cout<<"  `----.    \\                               "<< endl;
cout<<"       \\    \\                              "<< endl;
cout<<"        \\    \\                             "<< endl;
cout<<"         \\     `.             _ _           "<< endl;
cout<<"          \\       ~- _ _ - ~       ~ - .    "<< endl;
cout<<"           \\   You really need a LEG-up ~-  "<< endl;
cout<<"            \\       in this game!           "<< endl;
cout<<"             \\    /               /         "<< endl;
cout<<"               `. |         }     |          "<< endl;
cout<<"                 `|        /      |          "<< endl;
cout<<"                  |       /       |          "<< endl;
cout<<"                  |      /`- _ _ _           "<< endl;
cout<<"                  |     /                    "<< endl;
cout<<"                  |     |                    "<< endl;
cout<<"                  |_____|                    "<< endl;
cout << endl;
cout << "Keep in mind, even if you get the answer correct, ";
cout << "time is still running out for Mr. Dino!" << endl;
cout << "Will his extinction be reversed? Only you can help!"<< endl;
cout << endl;
cout<< endl;
}
else if (NumofGuesses == 9) {
cout<<"    .-~~^-.                                  "<< endl;   
cout<<"  .'  O   \\                                 "<< endl;
cout<<" (_____,   \\                                "<< endl;
cout<<"  `----.    \\                               "<< endl;
cout<<"       \\    \\                              "<< endl;
cout<<"        \\    \\                             "<< endl;
cout<<"         \\     `.                           "<< endl;
cout<<"          \\       ~- _ _ - ~                "<< endl;
cout<<"           \\ This dinosaur can't stomach    "<< endl;
cout<<"            \\   many more of your wrong     "<< endl;
cout<<"             \\    /  guesses!               "<< endl;
cout<<"               `. |         }                "<< endl;
cout<<"                 `|        /                 "<< endl;
cout<<"                  |       /                  "<< endl;
cout<<"                  |      /`- _ _             "<< endl;
cout<<"                  |     /                    "<< endl;
cout<<"                  |     |                    "<< endl;
cout<<"                  |_____|                    "<< endl;
cout << endl;
cout << "Keep in mind, even if you get the answer correct, ";
cout << "time is still running out for Mr. Dino!" << endl;
cout << "Will his extinction be reversed? Only you can help!"<< endl;
cout << endl;
cout<< endl;
}
else if (NumofGuesses == 10) {
cout<<"    .-~~^-.                          "<< endl;   
cout<<"  .'  O   \\                         "<< endl;
cout<<" (_____,   \\                        "<< endl;
cout<<"  `----.    \\                       "<< endl;
cout<<"       \\    \\                      "<< endl;
cout<<"        \\    \\                     "<< endl;
cout<<"         \\     `.                   "<< endl;
cout<<"          \\       ~- _              "<< endl;
cout<<"           \\ This poor dino is      "<< endl;
cout<<"            \\   about to forgo      "<< endl;
cout<<"             \\    /  it's torso!!   "<< endl;
cout<<"               `. |         }        "<< endl;
cout<<"                 `|        /         "<< endl;
cout<<"                  |       /          "<< endl;
cout<<"                  |      /           "<< endl;
cout<<"                  |     /            "<< endl;
cout<<"                  |     |            "<< endl;
cout<<"                  |_____|            "<< endl;
cout << endl;
cout << "Keep in mind, even if you get the answer correct, ";
cout << "time is still running out for Mr. Dino!" << endl;
cout << "Will his extinction be reversed? Only you can help!"<< endl;
cout << endl;
cout<< endl;
}
else if (NumofGuesses == 11) {
cout<<"    .-~~^-.                      "<< endl;   
cout<<"  .'  O   \\                     "<< endl;
cout<<" (_____,   \\                    "<< endl;
cout<<"  `----.    \\                   "<< endl;
cout<<"       \\    \\                  "<< endl;
cout<<"        \\    \\                 "<< endl;
cout<<"         \\     `.               "<< endl;
cout<<"          \\       ~- _          "<< endl;
cout<<"           \\ This dino is       "<< endl;
cout<<"            \\   FOOTING your    "<< endl;
cout<<"             \\    /  bill!      "<< endl;
cout<<"               `. |         }    "<< endl;
cout<<"                 `|        /     "<< endl;
cout<<"                  |       /      "<< endl;
cout<<"                  |      /       "<< endl;
cout << endl;
cout << "Keep in mind, even if you get the answer correct, ";
cout << "time is still running out for Mr. Dino!" << endl;
cout << "Will his extinction be reversed? Only you can help!"<< endl;
cout << endl;
cout<< endl;
}
else if (NumofGuesses == 12) {
cout<<"    .-~~^-.                          "<< endl;   
cout<<"  .'  O   \\                         "<< endl;
cout<<" (_____,   \\                        "<< endl;
cout<<"  `----.    \\                       "<< endl;
cout<<"       \\    \\                      "<< endl;
cout<<"        \\    \\                     "<< endl;
cout<<"         \\     `.                   "<< endl;
cout<<"          \\       ~- _              "<< endl;
cout<<"           \\ This dinosaur          "<< endl;
cout<<"            \\   KNEE'ds your help!  "<< endl;
cout<<"             \\    /                 "<< endl;
cout<<"               `. |                  "<< endl;
cout<<"                 `                   "<< endl;
cout << endl;
cout << "Keep in mind, even if you get the answer correct, ";
cout << "time is still running out for Mr. Dino!" << endl;
cout << "Will his extinction be reversed? Only you can help!"<< endl;
cout << endl;
cout<< endl;
}
else if (NumofGuesses == 13) {
cout<<"    .-~~^-.                              "<< endl;   
cout<<"  .'  O   \\                             "<< endl;
cout<<" (_____,   \\                            "<< endl;
cout<<"  `----.    \\                           "<< endl;
cout<<"       \\    \\                          "<< endl;
cout<<"        \\    \\                         "<< endl;
cout<<"         \\ This dinosaur                "<< endl;
cout<<"          stuck his neck out for you!    "<< endl;
cout<<"             Look where it got him...    "<< endl;
cout << endl;
cout << "Keep in mind, even if you get the answer correct, ";
cout << "time is still running out for Mr. Dino!" << endl;
cout << "Will his extinction be reversed? Only you can help!"<< endl;
cout << endl;
cout<< endl;
}
else {
cout<<"    .-~~^-.                  "<< endl;   
cout<<"  .'  O   \\                 "<< endl;
cout<<" (_____,   \\                "<< endl;
cout<<"  `----.   Face it.          "<< endl;
cout<<"       \\ Dino's days        "<< endl;
cout<<"      are coming to an end.  "<< endl;
cout<< endl;
}

cout << "You have " << MaxGuesses - NumofGuesses << " guesses remaining in your game.";
//cout << "You have thus far incorrectly guessed the letters, " << IncorrectAnswers(phrase,guess);
}
