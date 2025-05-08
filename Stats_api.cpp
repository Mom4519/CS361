#include <iostream>
#include <stdio.h>     
#include <stdlib.h>
#include <unistd.h>
#include <fstream>

using namespace std;


int main(){
    while(true){
        sleep(1);
        ifstream MyReadFile("prng-service.txt");
        string myText;
        getline (MyReadFile, myText);
        MyReadFile.close();
        if (myText == "run"){
            int num = rand() % 5 + 1;
            printf("%d\n", num);
            ofstream MyWriteFile("prng-service.txt");
            MyWriteFile << num;
            MyWriteFile.close();
        }
        else if (myText == "quit"){
            MyReadFile.close();
            return 1;
        }
    }
}