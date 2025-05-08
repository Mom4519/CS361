#include <iostream>
#include <stdio.h>     
#include <stdlib.h>
#include <unistd.h>
#include <fstream>


#include <string>

using namespace std;

void print_list() {
    printf("Welcome to the NBA Stats Program!\n");
    printf("Please select an option:\n");
    printf("Answer with the corresponding Number\n");
    printf("----------------------------------------\n");
    printf("1. Calculator home\n");
    printf("2. Stat Search Functions\n");
    printf("3. Guess the player Game\n");
    printf("4. Goat Leaderboards\n");
    printf("5. Exit\n");
    printf("----------------------------------------\n");
};

void print_list_calc() {
    printf("You selected calculator\n");
    printf("Please select an option:\n");
    printf("Answer with the corresponding Number\n");
    printf("----------------------------------------\n");
    printf("1. True Shooting (6 inputs)\n");
    printf("2. EFG% (4 inputs)\n");
    printf("3. BMP\n");
    printf("4. WS\n");
    printf("5. Exit\n");
    printf("----------------------------------------\n");
};

void print_list_stats() {
    printf("You selected Stat Search Functions\n");
    printf("Please select an option:\n");
    printf("Answer with the corresponding Number\n");
    printf("----------------------------------------\n");
    printf("1. Look up player by name\n");
    printf("2. Team stat leader\n");
    printf("3. Season stat leader\n");
    printf("4. Playoff stat leader\n");
    printf("5. All time stat leader\n");
    printf("6. Finals stat leader\n");
    printf("5. Exit\n");
    printf("----------------------------------------\n");
};

void print_list_games() {
    printf("You selected Guess the player Game\n");
    printf("Please select an option:\n");
    printf("Answer with the corresponding Number\n");
    printf("----------------------------------------\n");
    printf("1. Guess the Player\n");
    printf("2. Guess the Team\n");
    printf("3. Guess the Nickname\n");
    printf("4. Guess the Coach\n");
    printf("5. Exit\n");
    printf("----------------------------------------\n");
};

void print_list_goats() {
    printf("You selected Goat Leaderboards\n");
    printf("Please select an option:\n");
    printf("Answer with the corresponding Number\n");
    printf("----------------------------------------\n");
    printf("1. Championship leaderboard\n");
    printf("2. MVP leaderboard\n");
    printf("3. Scoring Champions\n");
    printf("4. DPOY leaderboard\n");
    printf("5. Exit\n");
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

string ask_question(void(*func)()) {
    string out;
    func();
    cin >> out;
    return out;
}

string ask_number(string question) {
    string out;
    printf("%s", question.c_str());
    cin >> out;
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
                    float fga = stof(ask_number("How many shots taken?\n"));
                    float fgm = stof(ask_number("How many shots made?\n"));
                    float tpa = stof(ask_number("How many 3pts taken?\n"));
                    float tpm = stof(ask_number("How many 3pts made?\n"));
                    float fta = stof(ask_number("How many free throws taken?\n"));
                    float ftm = stof(ask_number("How many free throws made?\n"));
                    printf("True Shooting %.2f\n", TS(fga, fgm, tpa, tpm, ftm, fta));
                }
                if (input == "2") {
                    float fga = stof(ask_number("How many shots taken?\n"));
                    float fgm = stof(ask_number("How many shots made?\n"));
                    float tpa = stof(ask_number("How many 3pts taken?\n"));
                    float tpm = stof(ask_number("How many 3pts made?\n"));
                    float fta = stof(ask_number("How many free throws taken?\n"));
                    float ftm = stof(ask_number("How many free throws made?\n"));
                    printf("Effective Field Goal Percentage %.2f\n", EFG(fga, fgm, tpa, tpm));
                }
                break;
            case '2':
                
                input = ask_question(&print_list_stats);
                if (input == "5") input = '0';
                break;
            case '3':
               
                input = ask_question(&print_list_games);
                if (input == "5") input = '0';
                break;
            case '4':
                
                input = ask_question(&print_list_goats);
                if (input == "5") input = '0';
                break;
            case '5':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                input = ask_question(&print_list);
                break;
        }
    }
    
    
}