#include <iostream>
#include <stdio.h>     
#include <stdlib.h>
#include <unistd.h>
#include <fstream>

using namespace std;

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
    return ((fgm + (0.5 * tpm)) / fga) * 100;
}


int main(){
    while(true){
        sleep(1);
        ifstream MyReadFile("Calculator.txt");
        string myText;
        getline (MyReadFile, myText);
        printf("%s\n", myText.c_str());
        MyReadFile.close();
       
        if (myText == "runT "){
            printf("Running...\n");
            ifstream MyReadFile("Calculator.txt");
            int fga, fgm, tpa, tpm, ftm, fta;
            while(getline (MyReadFile, myText)){
                printf("%s\n", myText.c_str());
            }
            MyReadFile.close();
            char buffer[256];
            strncpy(buffer, myText.c_str(), sizeof(buffer));
            buffer[sizeof(buffer) - 1] = '\0';
            char *token = strtok(buffer, ",");
            fga = atof(token);
            token = strtok(NULL, ",");
            fgm = atof(token);
            token = strtok(NULL, ",");
            tpa = atof(token);
            token = strtok(NULL, ",");
            tpm = atof(token);
            //float ts = TS(fga, fgm, tpa, tpm, ftm, fta);
            float efg = EFG(fga, fgm, tpa, tpm);
            printf("Effective Field Goal Percentage: %.2f\n", efg);
            ofstream MyWriteFile("Calculator.txt");
            MyWriteFile << efg; // Replace with actual result variable
            MyWriteFile.close();
        }
        else if (myText == "runE "){
            printf("Running...\n");
            ifstream MyReadFile("Calculator.txt");
            int fga, fgm, tpa, tpm, ftm, fta;
            while(getline (MyReadFile, myText)){
                printf("%s\n", myText.c_str());
            }
            MyReadFile.close();
            char buffer[256];
            strncpy(buffer, myText.c_str(), sizeof(buffer));
            buffer[sizeof(buffer) - 1] = '\0';
            char *token = strtok(buffer, ",");
            fga = atof(token);
            token = strtok(NULL, ",");
            fgm = atof(token);
            token = strtok(NULL, ",");
            tpa = atof(token);
            token = strtok(NULL, ",");
            tpm = atof(token);
            token = strtok(NULL, ",");
            fta = atof(token);
            token = strtok(NULL, ",");
            ftm = atof(token);
            float ts = TS(fga, fgm, tpa, tpm, ftm, fta);
            //float efg = EFG(fga, fgm, tpa, tpm);
            printf("Effective Field Goal Percentage: %.2f\n", ts);
            ofstream MyWriteFile("Calculator.txt");
            MyWriteFile << ts; // Replace with actual result variable
            MyWriteFile.close();
        }
        else if (myText == "quit"){
            MyReadFile.close();
            return 1;
        }
    }
}