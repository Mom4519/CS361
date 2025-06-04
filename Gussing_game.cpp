#include <iostream>
#include <stdio.h>     
#include <stdlib.h>
#include <unistd.h>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main(){
    srand(time(0)); // Seed for random number generation
    while(true){
        sleep(1);
        ifstream MyReadFile("gussing.txt");
        string myText;
        getline (MyReadFile, myText);
        printf("%s\n", myText.c_str());
        MyReadFile.close();
       
        if (myText == "team "){
           int randomNum = rand() % 400 + 1;
            ofstream MyWriteFile("Calculator.txt");

            MyWriteFile << "rank\n";
            MyWriteFile << randomNum; // Random player number for guessing game
            MyWriteFile.close();
            sleep(6);

            ifstream MyReadFile("Calculator.txt");
            string myText;
            getline (MyReadFile, myText);
            MyReadFile.close();

            ofstream MyWriteFileIM("gussing.txt", ios::trunc);
            MyWriteFileIM << myText; // Write the player rank to gussing.txt for the game
            MyWriteFileIM.close();

            sleep(5);
            ofstream MyCloseFile("Calculator.txt", ios::trunc);
            MyCloseFile.close();

            ofstream MyCloseFile2("gussing.txt", ios::trunc);
            MyCloseFile2.close(); // Clear the gussing.txt for next game
        }
        else if (myText == "player "){
            int randomNum = rand() % 20 + 1;
            ofstream MyWriteFile("Calculator.txt");

            MyWriteFile << "rank\n";
            MyWriteFile << randomNum; // Random player number for guessing game
            MyWriteFile.close();
            sleep(6);

            ifstream MyReadFile("Calculator.txt");
            string myText;
            getline (MyReadFile, myText);
            MyReadFile.close();

            ofstream MyWriteFileIM("gussing.txt", ios::trunc);
            MyWriteFileIM << myText; // Write the player rank to gussing.txt for the game
            MyWriteFileIM.close();


            sleep(5); // Give some time for the user to guess
            ofstream MyCloseFile("Calculator.txt", ios::trunc);
            MyCloseFile.close();

            ofstream MyCloseFile2("gussing.txt", ios::trunc);
            MyCloseFile2.close(); // Clear the gussing.txt for next game
        }
        else if (myText == "quit"){
            MyReadFile.close();
            return 1;
        }
    }
}