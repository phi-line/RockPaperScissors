//
//  main.cpp
//  Rock Paper Scissors
//
//  Created by Kishan Emens on 10/18/16.
//  Copyright © 2016 Kishan Emens. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

#define ever ;;

using namespace std;

enum throw_type{rock, paper, scissors, last};
string strInput, throwSelection, winMsg;
double winRatio = 0;
int numWins = 0, totalPlays = 0;
//rock paper scissors
int main() {
   //infinite loop
   for(ever){
      //input throw
      enum throw_type currThrow, compThrow;
      while(cout << "Input your throw -- Rock, Paper, or Scissors): " &&
            getline(cin, strInput)){
         istringstream iss {strInput};
         if ((iss >> throwSelection) && !(iss >> strInput)){
            if (toupper(throwSelection[0]) =='R'){
               currThrow = rock;
               break;
            } else if (toupper(throwSelection[0]) == 'P'){
               currThrow = paper;
               break;
            } else if (toupper(throwSelection[0]) == 'S'){
               currThrow = scissors;
               break;
            }
         }
         std::cerr << "Invalid input -- must be R , P or S" << endl;
      }

      //check for win conditions
      compThrow = static_cast<enum throw_type>(rand() % last);
      if (currThrow == compThrow){
         winMsg = "TIE";
         --totalPlays;
      }
      else if ((currThrow==rock && compThrow==scissors) ||
               (currThrow==paper && compThrow==rock) ||
               (currThrow==scissors && compThrow==paper)){
         winMsg = "WIN";
         ++numWins;
      }
      else
         winMsg = "LOSE";

      //calculate win ratio
      ++totalPlays;
      winRatio = (double(numWins) / totalPlays)*100;
      cout << "You " << right << setw(4) << winMsg << "! "
           << "Win Ratio: " << fixed << setprecision(2) << winRatio << "%\n";
   }
}
