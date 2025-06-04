#include <iostream>
#include <stdio.h>     
#include <stdlib.h>
#include <unistd.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>

#include <string>

using namespace std;

struct NBAPlayer {
    int rank;
    string player;
    int age;
    string team;
    string position;
    int games;
    int gamesStarted;
    float minutes;
    float fg, fga, fgPercent;
    float threeP, threePA, threePPercent;
    float twoP, twoPA, twoPPercent;
    float efgPercent;
    float ft, fta, ftPercent;
    float orb, drb, trb;
    float ast, stl, blk;
    float tov, pf, pts;
};

// Function to guess the player's team
void guessTeam(const NBAPlayer& player) {
    string guess;
    cout << "Guess the team of this player: " << player.player << endl;
    cin.ignore();
    getline(cin, guess);

    if (guess == player.team) {
        cout << "Correct! " << player.player << " plays for the " << player.team << ".\n";
    } else {
        cout << "Wrong! " << player.player << " plays for the " << player.team << ".\n";
    }
}

// Function to guess the player's name
void guessPlayer(const NBAPlayer& player) {
    string guess;
    cout << "Guess the name of the player on this team: " << player.team << endl;
    cin.ignore();
    getline(cin, guess);

    if (guess == player.player) {
        cout << "Correct! The player is " << player.player << ".\n";
    } else {
        cout << "Wrong! The correct answer is " << player.player << ".\n";
    }
}

float safe_stof(const string& s) {
    try {
        return stof(s);
    } catch (...) {
        return 0.0f;
    }
}

int safe_stoi(const string& s) {
    try {
        return stoi(s);
    } catch (const invalid_argument& e) {
        //cerr << "Warning: invalid int value: '" << s << "', defaulting to 0\n";
        return 0;
    } catch (const out_of_range& e) {
        cerr << "Warning: out-of-range int value: '" << s << "', defaulting to 0\n";
        return 0;
    }
}

void fromCSVRow(const string& csvLine, NBAPlayer& player) {
    stringstream ss(csvLine);
    string field;
    vector<string> f;

    while (getline(ss, field, ',')) {
        f.push_back(field);
    }

    player.rank         = safe_stoi(f[0]);
    player.player       = f[1];
    player.age          = safe_stoi(f[2]);
    player.team         = f[3];
    player.position     = f[4];
    player.games        = safe_stoi(f[5]);
    player.gamesStarted = safe_stoi(f[6]);
    player.minutes      = safe_stof(f[7]);
    player.fg           = safe_stof(f[8]);
    player.fga          = safe_stof(f[9]);
    player.fgPercent    = safe_stof(f[10]);
    player.threeP       = safe_stof(f[11]);
    player.threePA      = safe_stof(f[12]);
    player.threePPercent= safe_stof(f[13]);
    player.twoP         = safe_stof(f[14]);
    player.twoPA        = safe_stof(f[15]);
    player.twoPPercent  = safe_stof(f[16]);
    player.efgPercent   = safe_stof(f[17]);
    player.ft           = safe_stof(f[18]);
    player.fta          = safe_stof(f[19]);
    player.ftPercent    = safe_stof(f[20]);
    player.orb          = safe_stof(f[21]);
    player.drb          = safe_stof(f[22]);
    player.trb          = safe_stof(f[23]);
    player.ast          = safe_stof(f[24]);
    player.stl          = safe_stof(f[25]);
    player.blk          = safe_stof(f[26]);
    player.tov          = safe_stof(f[27]);
    player.pf           = safe_stof(f[28]);
    player.pts          = safe_stof(f[29]);
}

void print_list() {
    printf("Welcome to the 2025 NBA Stats Program!\n");
    printf("Please select an option:\n");
    printf("Answer with the corresponding Number\n");
    printf("----------------------------------------\n");
    printf("1. Calculator home\n");
    printf("2. Stat Search Functions\n");
    printf("3. Guess the player Game\n");
    printf("4. Exit\n");
    printf("----------------------------------------\n");
};

void print_list_calc() {
    printf("You selected calculator\n");
    printf("Please select an option:\n");
    printf("Answer with the corresponding Number\n");
    printf("----------------------------------------\n");
    printf("1. True Shooting - 6 inputs\n");
    printf("2. EFG - 4 inputs\n");
    printf("3. Exit\n");
    printf("----------------------------------------\n");
};

void print_list_stats() {
    printf("You selected Stat Search Functions\n");
    printf("Please select an option:\n");
    printf("Answer with the corresponding Number\n");
    printf("----------------------------------------\n");
    printf("1. Look up player by name\n");
    printf("2. Team stat search\n");
    printf("3. Exit\n");
    printf("----------------------------------------\n");
};

void print_list_games() {
    printf("You selected Guess the player Game\n");
    printf("Please select an option:\n");
    printf("Answer with the corresponding Number\n");
    printf("----------------------------------------\n");
    printf("1. Guess the Player\n");
    printf("2. Guess the Team\n");
    printf("3. Exit\n");
    printf("----------------------------------------\n");
};



float TS(float fga, float fgm, float tpa, float tpm, float ftm, float fta) {
    if (fga == 0) {
        return 0;
    }
    float pts = ((fgm - tpm) * 2) + (tpm * 3) + ftm;
    printf("Points: %.2f\n", pts);
    float ts = (pts / (2 * (fga + 0.44 * fta))) * 100;
    return ts;
}

float EFG(float fga, float fgm, float tpa, float tpm){ 
    return ((fgm + (0.5 * tpm)) / fga);
}

int num_str(string str){
    int x;
    cout << str << endl;
    cin >> x; 
    return x;  
}

string ask_question(void(*func)()) {
    string out;
    func();
    cin >> out;
    return out;
}

string ask_number(string question) {
    string out;
    printf("%s", question.c_str());
    cin.ignore();
    getline(cin, out);
    return out;
}



int main() {
    string input;

    input = ask_question(&print_list);
    while (input != "4") {
        
        switch (input[0]) {
            case '0':
                input = ask_question(&print_list);
                break;
            case '1':
               
                input = ask_question(&print_list_calc);
                if (input == "3") input = '0';
                if (input == "1") {
                    input = "0";
                    float fga = num_str("Enter field goal attempts");
                    float fgm = num_str("Enter field goals made");
                    float tpa = num_str("Enter three point attempts");
                    float tpm = num_str("Enter three point made");
                    float fta = num_str("Enter free throws attempts");
                    float ftm = num_str("Enter free throws made");
                    
                    
                    ofstream MyWriteFile("Calculator.txt");

                    MyWriteFile << "runE \n";
                    MyWriteFile << fga << "," << fgm << "," << tpa << "," << tpm << "," << fta << "," << ftm;
                    MyWriteFile.close();
                    sleep(10);

                    ifstream MyReadFile("Calculator.txt");
                    string myText;
                    getline (MyReadFile, myText);
                    //printf("%s\n", myText.c_str());
                    MyReadFile.close();

                    float num = stof(myText);

                    printf("Effective Field Goal Percentage %.2f\n", num);
                }
                if (input == "2") {
                    input = "0";
                    float fga = num_str("Enter field goal attempts");
                    float fgm = num_str("Enter field goals made");
                    float tpa = num_str("Enter three point attempts");
                    float tpm = num_str("Enter three point made");
                    
                    ofstream MyWriteFile("Calculator.txt");

                    MyWriteFile << "runT \n";
                    MyWriteFile << fga << "," << fgm << "," << tpa << "," << tpm;
                    MyWriteFile.close();
                    sleep(10);

                    ifstream MyReadFile("Calculator.txt");
                    string myText;
                    getline (MyReadFile, myText);
                    //printf("%s\n", myText.c_str());
                    MyReadFile.close();

                    float num = stof(myText);

                    printf("Effective Field Goal Percentage %.2f\n", num);
                }
                break;
            case '2':
                
                input = ask_question(&print_list_stats);
                //player 
                if (input == "1"){
                    input = "0";
                    string name = ask_number("Enter the player's name (make sure its full name case sensitive):\n");
                    cout << "Searching for player: " << name << endl;
                    ofstream MyWriteFile("Calculator.txt");

                    MyWriteFile << "runT \n";
                    MyWriteFile << name;
                    MyWriteFile.close();
                    sleep(10);

                    ifstream MyReadFile("Calculator.txt");
                    string myText;
                    getline (MyReadFile, myText);
                    //printf("%s\n", myText.c_str());
                    cout << myText << endl;
                    MyReadFile.close();
                    //clear file
                    ofstream MyCloseFile("Calculator.txt", std::ios::trunc);
                    MyCloseFile.close();

                    

                    //printf("Player Stats: \n%s\n", myText.c_str());
                }
                //team
                if (input == "2") {
                    input = "0";
                    string team = ask_number("Enter the Team's Abrevation (EX: LAL, BOS):\n");
                    ofstream MyWriteFile("Calculator.txt");

                    MyWriteFile << "runE \n";
                    MyWriteFile << team;
                    MyWriteFile.close();
                    sleep(10);
                    
                    ifstream MyReadFile("Calculator.txt");
                string myText;

                while (getline(MyReadFile, myText)) {
                    cout << myText << endl;  // or send this to another microservice
                }
                cout << "----------------------------------------\n";
                MyReadFile.close();

                // Clear the file after reading
                ofstream MyCloseFile("Calculator.txt", ios::trunc);
                MyCloseFile.close();

                }
                if (input == "3") input = '0';
                break;
            case '3':
               
                input = ask_question(&print_list_games);
                if(input == "1"){
                    ofstream MyWriteFile("gussing.txt");

                    MyWriteFile << "player \n";
                    MyWriteFile.close();
                    sleep(10);

                    ifstream MyReadFile("gussing.txt");
                    string myText;
                    getline (MyReadFile, myText);
                    MyReadFile.close();
                    NBAPlayer p;
                    fromCSVRow(myText, p);
                    guessPlayer(p);
                }
                if(input == "2"){
                    ofstream MyWriteFile("gussing.txt");

                    MyWriteFile << "team \n";
                    MyWriteFile.close();
                    sleep(10);

                    ifstream MyReadFile("gussing.txt");
                    string myText;
                    getline (MyReadFile, myText);
                    MyReadFile.close();
                    NBAPlayer p;
                    fromCSVRow(myText, p);
                    guessTeam(p);
                }
                if (input == "3") input = '0';
                break;
            
            case '4':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                input = ask_question(&print_list);
                break;
        }
    }
    
    
}