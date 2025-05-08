#include <iostream>
#include <stdio.h>     
#include <stdlib.h>
#include <unistd.h>
#include <fstream>
#include <cctype>

using namespace std;

int main(){
    while(true){
        sleep(1);
        ifstream MyReadFile("image-service.txt");
        
        string myText;
        getline (MyReadFile, myText);
        MyReadFile.close();
        if (myText.length() == 1 && isdigit(myText[0])){
            string myPath = "/Users/austinc/Desktop/Coding Projects/CS361/Project1/" + myText + ".jpg";
            ofstream MyWriteFile("image-service.txt");
            MyWriteFile << myPath;
            MyWriteFile.close();
        }
        else if (myText == "quit"){
            MyReadFile.close();
            
            return 1;
        }
    }
}