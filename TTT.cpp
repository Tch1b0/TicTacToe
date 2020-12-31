#include <iostream>
#include <iterator>
#include <time.h>
using namespace std;

void drawField(string field[3][3]){
    cout << "   1 2 3 |x" << endl;
    cout << "1  " << field[0][0] <<"|" << field[0][1] << "|" << field[0][2] << endl;
    cout << "  --+-+--" << endl;
    cout << "2  " << field[1][0] << "|" << field[1][1] << "|" << field[1][2] << endl;
    cout << "  --+-+--" << endl;
    cout << "3  " << field[2][0] << "|" << field[2][1] << "|" << field[2][2] << endl ;
    cout << "_" << endl;
    cout << "y"  << endl << endl << endl;
}

string checkField(string field[3][3]){
    int pos1 = 0;
    int pos2 = 0;
    string result = "0";
    bool freefields = false;
    for (int i=0; i < 3; i++){
        if (field[pos1][0] == field[pos1][1] && field[pos1][1] == field[pos1][2] && field[pos1][1] != " "){
            result = field[pos1][1];
        }
        for (int n=0; n < 3; n++){
            if (field[0][pos2] == field[1][pos2] && field[1][pos2] == field[2][pos2] && field[1][pos2] != " "){
                result = field[1][pos2];
            }
            else if (field[pos1-1][pos2] == field[pos1][pos2] && field[pos1][pos2] == field[pos1+1][pos2] && field[pos1][pos2] != " "){
                result = field[pos1][pos2];
            }
            else if (field[0][0] == field[1][1] && field[1][1] == field[2][2] && field[1][1] != " " || field[0][2] == field[1][1] && field[2][0] == field[1][1] && field[1][1] != " "){
                result = field[1][1];
            }
            if (field[pos1][pos2] == " ") freefields = true;
            pos2++;
        }
        pos1++;
    }
    if (freefields == false) result = "-";
    return result;
}

//void computerTurn(){}

int main() {
    string field[3][3] = {
        {" ", " ", " "},
        {" ", " ", " "},
        {" ", " ", " "}
    };
    bool run = true;
    int pos1;
    int pos2;
    int cpos1;
    int cpos2;
    bool round = false;
    string player;
    string winner;
    string choice;
    string* fieldpointer0 = field[0];
    string* fieldpointer1 = field[1];
    string* fieldpointer2 = field[2];

    do{
        cout << "Do you want to play against" << endl << "another (p)layer or the (c)omputer?" << endl;
        cin >> choice;
        system("cls");
    }while(choice != "p" && choice != "c");

    while(run){
        if (choice == "p" || choice == "c" && round == false){
            drawField(field);
        }

        if (round == false) player = "O";
        else if(round == true && choice == "p") player = "X";
        else if (choice == "c" && round == true){
            int counter = 0;
            srand(time(NULL));
            do{
                cpos1 = rand() % 3;
                cpos2 = rand() % 3;
                counter++;
            }while(field[cpos1][cpos2] != " " && counter < 100);
            if (counter < 100){
                field[cpos1][cpos2] = "X";
            }
        }

        winner = checkField(field);
        if (round == false && winner == "0" || round == true && choice != "c" && winner == "0"){
            do{
            cout << "Player " << player << endl;
            cout << "y-axis: ";
            cin >> pos1;
            cout << "x-axis: ";
            cin >> pos2;
            }while(field[pos1-1][pos2-1] != " ");

            field[pos1-1][pos2-1] = player;
            cout << endl;
        }else if (winner == "-") {
            system("cls");
            drawField(field);
            system("color 4");
            cout << "Tie" << endl;
            system("pause");
            exit(0);

        }else if (winner == "O" || winner == "X"){
            system("cls");
            drawField(field);
            system("color 2");
            cout << "Player " << winner << " won!" << endl;
            system("pause");
            exit(0);
        }

        if(field[0][0] != "O" && field[0][0] != "X" && field[0][0] != " "){ 
            field[0][0] = " ";
        }
        round = !round;
        system("cls");
    }
}