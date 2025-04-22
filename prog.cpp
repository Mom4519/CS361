#include <iostream>

#include <string>

using namespace std;

void print_list() {
    printf("Welcome to the NBA Stats Program!\n");
    printf("Please select an option:\n");
    printf("Answer with the corresponding Number\n");
    printf("----------------------------------------\n");
    printf("1. True Shooting calculator\n");
    printf("2. Stat Search Functions\n");
    printf("3. Guess the player Game\n");
    printf("4. Goat Leaderboards\n");
    printf("5. Exit\n");
    printf("----------------------------------------\n");
};



string ask_question() {
    string out;
    print_list();
    cin >> out;
    return out;
}

string ask_number(string question) {
    string out;
    printf("%s", question.c_str());
    cin >> out;
    return out;
}



int main() {
    string input;

    input = ask_question();

    switch (input[0]) {
        case '1':
            printf("You selected calculator\n");
            printf("Please select an option:\n");
            printf("Answer with the corresponding Number\n");
            printf("----------------------------------------\n");
            printf("1. True Shooting\n");
            printf("2. EFG%\n");
            printf("3. BMP\n");
            printf("4. WS\n");
            printf("5. Exit\n");
            printf("----------------------------------------\n");
            break;
        case '2':
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
            break;
        case '3':
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
            break;
        case '4':
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
            break;
        case '5':
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid option. Please try again.\n");
            input = ask_question();
            break;
    }

    string list[5] = {"how many shots taken", "how many shots made", "how many 3pts made", "how many ft made", "how many ft taken"};
    
    for (int i = 0; i < 5; i++) {
        string out = ask_number(list[i]);
        if (out == "exit") {
            printf("Exiting...\n");
            return 0;
        }
    }
}