#include <iostream>
#include <stdio.h>     
#include <stdlib.h>
#include <unistd.h>
#include <fstream>
#include <sstream>
#include <unordered_map>

using namespace std;

//struct and function
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

NBAPlayer getPlayerByName(const string& name, const unordered_map<string, NBAPlayer>& playersByName) {
    auto it = playersByName.find(name);
    if (it != playersByName.end()) {
        return it->second;
    } else {
        throw runtime_error("Player not found: " + name);
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


void addOrMergePlayer(unordered_map<string, NBAPlayer>& nameMap,
                      unordered_map<int, NBAPlayer>& rankMap,
                      unordered_map<string, vector<NBAPlayer>>& teamMap,
                      const NBAPlayer& p) {
    if (nameMap.find(p.player) != nameMap.end()) {
        NBAPlayer& existing = nameMap[p.player];

        // Sum fields
        existing.games += p.games;
        existing.gamesStarted += p.gamesStarted;
        existing.minutes += p.minutes;
        existing.fg += p.fg;
        existing.fga += p.fga;
        existing.threeP += p.threeP;
        existing.threePA += p.threePA;
        existing.twoP += p.twoP;
        existing.twoPA += p.twoPA;
        existing.ft += p.ft;
        existing.fta += p.fta;
        existing.orb += p.orb;
        existing.drb += p.drb;
        existing.trb += p.trb;
        existing.ast += p.ast;
        existing.stl += p.stl;
        existing.blk += p.blk;
        existing.tov += p.tov;
        existing.pf += p.pf;
        existing.pts += p.pts;

        // Optionally recompute %s later
    } else {
        nameMap[p.player] = p;
        rankMap[p.rank] = p;
        teamMap[p.team].push_back(p); // Add to team map
    }
}

void loadNBAStats(const string& filename,
                  unordered_map<string, NBAPlayer>& nameMap,
                  unordered_map<int, NBAPlayer>& rankMap,
                  unordered_map<string, vector<NBAPlayer>>& teamMap) {
    ifstream file(filename);
    string line;

    if (!file.is_open()) {
        cerr << "Failed to open file.\n";
        return;
    }

    getline(file, line); // skip header

    while (getline(file, line)) {
        istringstream ss(line);
        NBAPlayer p;
        string value;
        getline(ss, value, ','); p.rank = safe_stoi(value);
        getline(ss, p.player, ',');
        getline(ss, value, ','); p.age = safe_stoi(value);
        getline(ss, p.team, ',');
        getline(ss, p.position, ',');
        getline(ss, value, ','); p.games = safe_stoi(value);
        getline(ss, value, ','); p.gamesStarted = safe_stoi(value);
        getline(ss, value, ','); p.minutes = safe_stof(value);
        getline(ss, value, ','); p.fg = safe_stof(value);
        getline(ss, value, ','); p.fga = safe_stof(value);
        getline(ss, value, ','); p.fgPercent = safe_stof(value);
        getline(ss, value, ','); p.threeP = safe_stof(value);
        getline(ss, value, ','); p.threePA = safe_stof(value);
        getline(ss, value, ','); p.threePPercent = safe_stof(value);
        getline(ss, value, ','); p.twoP = safe_stof(value);
        getline(ss, value, ','); p.twoPA = safe_stof(value);
        getline(ss, value, ','); p.twoPPercent = safe_stof(value);
        getline(ss, value, ','); p.efgPercent = safe_stof(value);
        getline(ss, value, ','); p.ft = safe_stof(value);
        getline(ss, value, ','); p.fta = safe_stof(value);
        getline(ss, value, ','); p.ftPercent = safe_stof(value);
        getline(ss, value, ','); p.orb = safe_stof(value);
        getline(ss, value, ','); p.drb = safe_stof(value);
        getline(ss, value, ','); p.trb = safe_stof(value);
        getline(ss, value, ','); p.ast = safe_stof(value);
        getline(ss, value, ','); p.stl = safe_stof(value);
        getline(ss, value, ','); p.blk = safe_stof(value);
        getline(ss, value, ','); p.tov = safe_stof(value);
        getline(ss, value, ','); p.pf = safe_stof(value);
        getline(ss, value, ','); p.pts = safe_stof(value);


        addOrMergePlayer(nameMap, rankMap, teamMap, p);
    }

    file.close();
}

void printPlayer(const NBAPlayer& p) {
    float ppg = (p.games > 0) ? p.pts / p.games : 0.0f;
    cout << "Player: " << p.player << "\n"
         << "Team: " << p.team << ", Position: " << p.position << "\n"
         << "Games: " << p.games << ", Total Points: " << p.pts << ", PPG: " << ppg << "\n";
}

void printTeamStats(const string& team, const unordered_map<string, vector<NBAPlayer>>& teamMap) {
    if (teamMap.find(team) == teamMap.end()) {
        cout << "Team not found.\n";
        return;
    }

    const vector<NBAPlayer>& roster = teamMap.at(team);
    cout << "=== " << team << " Roster ===\n";

    for (const NBAPlayer& p : roster) {
        float ppg = (p.games > 0) ? p.pts : 0.0f;
        cout << p.player << " | Games: " << p.games << " | PPG: " << ppg << "\n";
    }
}



int main(){
    unordered_map<string, NBAPlayer> nameMap;
    unordered_map<int, NBAPlayer> rankMap;
    unordered_map<string, vector<NBAPlayer>> teamMap;

    loadNBAStats("nba_stats_2024.csv", nameMap, rankMap, teamMap);
    
    while(true){
        sleep(1);
        ifstream MyReadFile("Calculator.txt");
        string myText;
        getline (MyReadFile, myText);
        printf("%s\n", myText.c_str());
        MyReadFile.close();
       
        if (myText == "runT "){
            ifstream MyReadFile("Calculator.txt");
            getline (MyReadFile, myText);
            getline (MyReadFile, myText);
            MyReadFile.close();
            try {
                NBAPlayer p = getPlayerByName( myText, nameMap);
                ofstream outFile("Calculator.txt");
                outFile << p.player << " Stats: " << p.pts << ", " << p.ast << ", " << p.trb << "\n";
                outFile.close();
            } catch (const exception& e) {
                cerr << e.what() << "\n";
            }
            // ofstream outFile("Calculator.txt");
            // outFile << p.player << " Stats: " << p.pts << ", " << p.ast << ", " << p.trb << "\n";

        }
        else if (myText == "runE "){
            ifstream MyReadFile("Calculator.txt");
            getline (MyReadFile, myText);
            try {
                string team = myText; // Example team
                printTeamStats(team, teamMap);
            } catch (const exception& e) {
                cerr << e.what() << "\n";
            }
        }
        else if (myText == "quit"){
            MyReadFile.close();
            return 1;
        }
    }
}