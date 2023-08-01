#include<bits/stdc++.h>
using namespace std;

void findPos(char mat[5][5], char ch, int &row, int &col){

    if(ch == 'J')
        ch = 'I'; 
    for(row=0; row<5; row++){
        for(col=0; col<5; col++){
            if(mat[row][col] == ch)

                return;
        }
    }
}

string encrypt(string plain, char mat[5][5]){

    string cipher = "";
    for(int i=0; i<plain.size(); i+=2){

        if(i+1 == plain.size())//last er character er bugus bosanor jonno;
            plain += 'X';

        char ch1 = toupper(plain[i]);
        char ch2 = toupper(plain[i+1]);

        if(ch1 == ch2){//jodi 2 ta chac same hoy tahole akta bugus add korte hobe.
            ch2 = 'X';
            i--;
        }

        int row1, col1, row2, col2;
        findPos(mat, ch1, row1, col1);
        findPos(mat, ch2, row2, col2);

        if(row1 == row2){
            col1 = (col1 + 1) % 5;
            col2 = (col2 + 1) % 5;
        }
        else if(col1 == col2){
            row1 = (row1 + 1) % 5;
            row2 = (row2 + 1) % 5;
        }
        else{
            swap(col1, col2);
        }
        cipher += mat[row1][col1];
        cipher += mat[row2][col2];
    }
    return cipher;
}

string decrypt(string cipher, char mat[5][5]){

    string decipher = "";
    for(int i=0; i<cipher.size(); i+=2){

        char ch1 = toupper(cipher[i]);
        char ch2 = toupper(cipher[i+1]);

        int row1, col1, row2, col2;
        findPos(mat, ch1, row1, col1);
        findPos(mat, ch2, row2, col2);

        if(row1 == row2){
            col1 = (col1 - 1 + 5) % 5;
            col2 = (col2 - 1 + 5) % 5;
        }
        else if(col1 == col2){
            row1 = (row1 - 1 + 5) % 5;
            row2 = (row2 - 1 + 5) % 5;
        }
        else{
            swap(col1, col2);
        }
        decipher += tolower(mat[row1][col1]);
        decipher += tolower(mat[row2][col2]);
    }
    return decipher;
}

int main(){

    freopen("playfair.txt", "r", stdin);
    char mat[5][5];
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            cin >> mat[i][j];

    string plain;
    cin >> plain;

    string cipher = encrypt(plain, mat);
    cout << "Ciphertext: " << cipher << endl;

    cout << "Plaintext: " << decrypt(cipher, mat) << endl;

    return 0;
}
