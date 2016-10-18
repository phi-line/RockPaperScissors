//
//  main.cpp
//  Classwork 10.18.16
//
//  Created by admin on 10/18/16.
//  Copyright © 2016 admin. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>

#define ever ;;

using namespace std;

enum throw_type{rock, paper, scissors, last};
string strInput, throw_type;
//rock paper scissors
int main() {
   for(ever){
      enum throw_type currentThrow, computerThrow;
      while(cout << "Input your throw (rock, paper or scissors): " &&
            getline(cin, strInput)){
         istringstream iss {strInput};
         if ((iss >> throw_type) && !(iss >> strInput)){
            if (toupper(strInput[0] = 'R')){
               currentThrow = rock;
               break;
            } else if (toupper(strInput[0] = 'P')){
               currentThrow = paper;
               break;
            } else if (toupper(strInput[0] = 'S')){
               currentThrow = scissors;
               break;
            }
         }
         std::cerr << "Invalid input -- must be R , P or S" << endl;
      }
      computerThrow = static_cast<enum throw_type>(rand() % last);
      switch (currentThrow){
         case rock:
            if (computerThrow == rock){
               cout << "Opponent thows rock -- you TIE" <<endl;
            }
            if (computerThrow == paper){
               cout << "Opponent throws paper -- you LOSE" <<endl;
            }
            if (computerThrow == scissors){
               cout << "Opponent throws scissors -- you WIN" <<endl;
            }
            break;
         case paper:
            if (computerThrow == rock){
               cout << "Opponent thows rock -- you WIN" <<endl;
            }
            if (computerThrow == paper){
               cout << "Opponent throws paper -- you TIE" <<endl;
            }
            if (computerThrow == scissors){
               cout << "Opponent throws scissors -- you LOSE" <<endl;
            }
            break;
         case scissors:
            if (computerThrow == rock){
               cout << "Opponent thows rock -- you LOSE" <<endl;
            }
            if (computerThrow == paper){
               cout << "Opponent throws paper -- you WIN" <<endl;
            }
            if (computerThrow == scissors){
               cout << "Opponent throws scissors -- you TIE" <<endl;
            }
            break;
         default:
            break;
      }
   }
}
