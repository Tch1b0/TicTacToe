#include <iostream>
#include <iterator>
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
        for (int n=0; n < 3; n++){
            if (pos2 != 0 && pos2 != 2 && field[pos1][pos2-1] == field[pos1][pos2] && field[pos1][pos2] == field[pos1][pos2+1] && field[pos1][pos2] != " "){
                result = field[pos1][pos2];
            }
            else if (pos1 != 0 && pos1 != 3 && field[pos1-1][pos2] == field[pos1][pos2] && field[pos1][pos2] == field[pos1+1][pos2] && field[pos1][pos2] != " "){
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

int main() {
    string field[3][3] = {
        {" ", " ", " "},
        {" ", " ", " "},
        {" ", " ", " "}
    };

    bool run = true;
    int pos1;
    int pos2;
    bool round = false;
    string player;
    string winner;
    while(run){
        drawField(field);

        if (round == false) player = "O";
        else player = "X";
        round = !round;

        winner = checkField(field);
        if (winner == "0"){
            do{
            cout << "Player " << player << endl;
            cout << "Y-axis: ";
            cin >> pos1;
            cout << "X-axis: ";
            cin >> pos2;
            }while(field[pos1-1][pos2-1] != " ");

            field[pos1-1][pos2-1] = player;
            cout << endl;
        }else if (winner == "-") {
            system("color 4");
            cout << "Tie" << endl;
            system("pause");
            exit(0);

        }else{
            system("color 2");
            cout << "Player " << winner << " won!" << endl;
            system("pause");
            exit(0);
        }

        if(field[0][0] != "O" && field[0][0] != "X" && field[0][0] != " "){ 
            field[0][0] = " ";
        }
        system("cls");
    }
}