//
// Created by chus on 17/03/19.
//

#include "ListSearch.h"
#include "LetterList.cpp"
#include "LetterList.h"
#include "LetterNode.h"
#include "LetterNode.cpp"
#include "algorithm"

#include <string>
#include<fstream>
#include<iostream>
#include<cstdlib>



using namespace std;


int ListSearch::search(string Words) {
    {
        ifstream fin;
        fin.open("/home/chus/CLionProjects/Scrabble/src/tec/ac/cr/Scrabble/Logic/Lists/words.text");
        if (fin.fail()) {
            cout << "No hay ni pinga.\n";
            exit(1);
        }
        string search;
        cout << "Ingrese algo"
                " ";
        cin >> search;
        bool isFound = 0;
        while (!fin.eof()) {
            string temp = "";
            getline(fin, temp);
            for (int i = 0; i < search.size(); i++) {
                if (temp[i] == search[i])
                    isFound = 1;
                else {
                    isFound = 0;
                    break;
                }
            }

            if (isFound == 1) {
                cout << "Su palabra si esta y es ";
                cout << temp;
                break;
            }
        }


        if (fin.eof() && (!isFound)) {
            cout << "Su palabra no existe F\n";
        }

        fin.close();

        return 0;
    }
}
