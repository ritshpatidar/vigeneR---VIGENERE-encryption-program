#include <iostream>
using namespace std;

class Vigenere{

public:
Vigenere();
private:
char ar[26][26]; //vgnc array
void createSquare();
string encrypt(string msg, string key);
string decrypt(string encrypted, string key);
void setGetEncryption();
void setGetDecryption();
void strToUppercase(string &s);
void removeSpaces(string source);
void isIdealString(string &s);
void checkStringAlphabatic(string &s);

};





















