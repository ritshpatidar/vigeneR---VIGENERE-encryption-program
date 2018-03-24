#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include "Vigenere.h"
using namespace std;


char ar[26][26]; //vgnc array

Vigenere::Vigenere(){  
  
  cout<<endl;
  cout<<"[-----Welcome to vigeneR Program-----]"<<endl;
  cout<<endl;
  cout<<"INFO: This program is case insensitive, no matter whether your inputs are in"<<endl;
  cout<<"      Uppercase or Lowercase. But the key must be in alphabetical form"<<endl;
  cout<<"      Eg- \"HELLOFriends\",\"hello mike patel\",\"HELLOFRIENDS\" are allowed as a Text"<<endl;
  cout<<"      Eg- \"HELLOFRIENDS\",\"hellofriends\",\"helloFriends\" are allowed as a Key"<<endl;
  cout<<"      Eg- \"hello friends\",\"Hello FRIENDS\" are not allowed as a key"<<endl;
  cout<<"      Eg- \"hello1friends\",\"HEL10Fr!end$/546\" are not allowed as both Key and Text"<<endl;
  cout<<"      because this program is based on vigenere encryption"<<endl;
  createSquare();
  
  char input;
  while(1){
  
    cout<<"Choose Option:  1.Encrypt Text  2.Decrypt Text  3.Exit \nYour Option: "; // how to recognize int in char array c++
    cin>>input;    
    cin.ignore(1,'\n');
    cout<<endl;
    if(!isdigit(input)){
      cout<<"Invalid option, please choose option again"<<endl;
      cout<<endl;
      continue;
    }    

    switch((int)input - '0'){

    case 1: setGetEncryption(); break;
    case 2: setGetDecryption(); break;
    case 3: cout<<"You are now Exit!"<<endl; exit(0); break;
    default: cout<<"Invalid option, please choose option again"<<endl; break;

    }

  }


}

void Vigenere::createSquare(){

  char c = 'A';
  char temp = c;
  
 for(int i = 0; i<=25; i++){

    for(int j = 0; j<=25; j++){

      //store 1
      ar[i][j] = c;
      //store 0
      c++;
      if(c > 'Z'){
       c = 'A';
      }

  }

  temp++;
  c = temp;

}

 cout<<endl; 

}


string Vigenere::encrypt(string msg, string key){


int msgIndex[msg.length()];
int keyIndex[key.length()];


char epted[msg.length()];
  
for(int i = 0; i<msg.length(); i++){
  
  if(msg[i] == ' ' && key[i] == ' '){
    epted[i] = ' ';
    continue;
  }  

  for(int j = 0; j<=25; j++){
   
     if(msg[i] == ar[0][j]){
       msgIndex[i] = j;
       break;
     }

  }
   
  for(int k = 0; k<=25; k++){
     if(key[i] == ar[k][0]){
       keyIndex[i] = k;
       break;
     }
  }

  epted[i] = ar[keyIndex[i]][msgIndex[i]];

 
}

string eptedToReturn(epted, msg.length());

return eptedToReturn;

}

//decrypt 1

  string Vigenere::decrypt(string encrypted, string key){
     
    int column[key.length()];
    char ans[key.length()];

     for(int i = 0; i<key.length(); i++){
        
        if(key[i] == ' ' && encrypted[i] == ' '){
            ans[i] = ' ';
            continue;
        }        
      
        for(int j = 0; j<25; j++){
           if(ar[0][j] == key[i]){
              column[i] = j;
              break;
           }
        }

        for(int k = 0; k<25; k++){
           if(ar[k][column[i]] == encrypted[i]){
              ans[i] = ar[k][0];
              break;
           }
        }
 
     }
     
   string decryToReturn(ans, key.length());

   return decryToReturn;   

  }

//decrypt 0

// sged 1

 void Vigenere::setGetEncryption(){

    cout<<"---------------------------------Encryption Start-------------------------------"<<endl;
    cout<<endl;   

    string  realkey;
    cout<<"Enter Key: ";
    getline(cin, realkey);
    cout<<endl;
    checkStringAlphabatic(realkey);    
    //

    cout<<"Enter Text: ";
    string msg;
    getline(cin, msg);
    cout<<endl;
    isIdealString(msg);
    
    //convert
     if(!all_of(realkey.begin(),realkey.end(),&::isupper))
      strToUppercase(realkey);
     if(!all_of(msg.begin(),msg.end(),&::isupper))
      strToUppercase(msg);
    //convert

    //key generator
    char keyArray[msg.length()];
 
    int kind = 0; 
    for(int i = 0; i<msg.length(); i++){
      
      if(msg[i] == ' '){
        keyArray[i] = ' ';
        continue;
      }    
      keyArray[i] = realkey[kind];
      kind++;
      if(kind > realkey.length()-1)
        kind = 0;

    }
    //key generator


    string key(keyArray, msg.length());
  
    cout<<"Encrypted Text: "<<encrypt(msg,key)<<endl;
    
    cout<<"---------------------------------Encryption End-------------------------------"<<endl;
    cout<<endl;

 }

 void Vigenere::setGetDecryption(){

    cout<<"---------------------------------Decryption Start-------------------------------"<<endl;
    cout<<endl;

    cout<<"Enter Key: ";
    string  realkey;
    getline(cin,realkey);
    cout<<endl;
    checkStringAlphabatic(realkey);

    cout<<"Enter Encrypted Text: ";
    string eKey;
    getline(cin,eKey);
    cout<<endl;
    isIdealString(eKey);

    //convert
     if(!all_of(realkey.begin(),realkey.end(),&::isupper))
      strToUppercase(realkey);
     if(!all_of(eKey.begin(),eKey.end(),&::isupper))
      strToUppercase(eKey);
    //convert

    //key generator
    char keyArray[eKey.length()]; //kind for k_ey ind_ex
 
    int kind = 0; 
    for(int i = 0; i<eKey.length(); i++){

      if(eKey[i] == ' '){
        keyArray[i] = ' ';
        continue;
      }
      keyArray[i] = realkey[kind];
      kind++;
      if(kind > realkey.length()-1)
        kind = 0;

    }
   //key generator


    string key(keyArray, eKey.length());
  
    cout<<"Decrypted Text: "<<decrypt(eKey,key)<<endl; 

    cout<<"---------------------------------Decryption End-------------------------------"<<endl;
    cout<<endl;

 }

// sged 0

//string to upper case
void Vigenere::strToUppercase(string &s){
  
  transform(s.begin(), s.end(), s.begin(), ::toupper);  

}
//string to upper case

void Vigenere::isIdealString(string &s){

  int b = 5;
  do{
    
   if(b == 1){
      break;
   }
   if(b == 0){
      cout<<"Sorry! all characters of string are not alphabetical/space"<<endl;
      cout<<"Enter Again: ";
      s.clear();
      getline(cin, s);
      cout<<endl;
   }

   for(int i=0; i<s.length(); i++){
       
       if(!isalpha(s[i]) && s[i] != ' '){
         b = 0;
         break;
       } else{
         b = 1;
       }
    }

   if(b != 0)
     b = 1;

  } while(1);

}

void Vigenere::checkStringAlphabatic(string &s){ //cannot use ' ' as character in key..that is why this function is defined to take only alphabets

   while(!all_of(s.begin(), s.end(), ::isalpha )){
      cout<<"Sorry! all characters of string are not alphabetical"<<endl;
      cout<<"Enter Again: ";
      getline(cin, s);
      cout<<endl;
    }

}

















