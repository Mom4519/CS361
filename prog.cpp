#include <iostream>
#include <stdio.h>     
#include <stdlib.h>
#include <unistd.h>
#include <fstream>


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

void print_list() {
    printf("Welcome to the NBA Stats Program!\n");
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


void api_call(){
    // Placeholder for API call
    printf("API call made.\n");
    string input = ask_number("1 to run the program 2 to quit\n");
    if(input == "1"){
           
        ofstream MyWriteFile("Stats_api.txt");

        MyWriteFile << "run";
        MyWriteFile.close();
        sleep(3);

        ifstream MyReadFile("Stats_api.txt");
        string myText;
        getline (MyReadFile, myText);
        MyReadFile.close();

        int num = stoi(myText);

        ofstream MyWriteFileIM("gussing_game.txt");
        MyWriteFileIM << myText;
        MyWriteFileIM.close();
        sleep(3);

        ifstream MyReadFileIM("gussing_game.txt");
        getline (MyReadFileIM, myText);
        printf("%s\n", myText.c_str());

        
        
        MyReadFileIM.close();
        
    }
    else if(input == "2"){
        ofstream MyWriteFileIM("gussing_game.txt");
        ofstream MyWriteFile("Stats_api.txt");
        MyWriteFileIM << "quit";
        MyWriteFile << "quit";
        MyWriteFile.close();
        MyWriteFileIM.close();
        
    }
    else{
        printf("Plese pick 1 or 2");
    }
}

// string list[5] = {"how many shots taken", "how many shots made", "how many 3pts made", "how many ft made", "how many ft taken"};
    
//     for (int i = 0; i < 5; i++) {
//         string out = ask_number(list[i]);
//         if (out == "exit") {
//             printf("Exiting...\n");
//             return 0;
//         }
//     }

int main() {
    string input;

    input = ask_question(&print_list);
    while (input != "5") {
        
        switch (input[0]) {
            case '0':
                input = ask_question(&print_list);
                break;
            case '1':
               
                input = ask_question(&print_list_calc);
                if (input == "5") input = '0';
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

                    MyWriteFile << "runE \n";
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

                    MyWriteFile << "runT \n";
                    MyWriteFile << team;
                    MyWriteFile.close();
                    sleep(10);
                
                }
                if (input == "5") input = '0';
                break;
            case '3':
               
                input = ask_question(&print_list_games);
                if (input == "5") input = '0';
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