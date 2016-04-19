/****************************************************************************************************************************************************
 *  File Name                   : songsofpi.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\hackerrank\warmup\songsofpi.h
 *  Created on                  : May 1, 2015 :: 4:16:05 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.hackerrank.com/challenges/song-of-pi
 ****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                         NAMESPACE DECLARATION AND IMPORTS                                                        */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/*                                                                 INCLUDES                                                                         */
/****************************************************************************************************************************************************/

#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <hash_map>
#include <stack>
#include <queue>
#include <limits.h>
#include <lib/constants/constants.h>
#include <lib/ds/commonds.h>
#include <lib/ds/linkedlistds.h>
#include <lib/ds/graphds.h>
#include <lib/ds/mathds.h>
#include <lib/ds/treeds.h>
#include <lib/utils/arrayutil.h>
#include <lib/utils/avltreeutil.h>
#include <lib/utils/bplustreeutil.h>
#include <lib/utils/btreeutil.h>
#include <lib/utils/commonutil.h>
#include <lib/utils/dillutil.h>
#include <lib/utils/graphutil.h>
#include <lib/utils/mathutil.h>
#include <lib/utils/redblacktreeutil.h>
#include <lib/utils/sillutil.h>
#include <lib/utils/treeutil.h>
#include <lib/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef SONGSOFPI_H_
#define SONGSOFPI_H_

//Tested
bool isChar(char userInput) {
    if((userInput >= 'a' && userInput <= 'z')||(userInput >= 'A' && userInput <= 'Z')) {
        return true;
    }
    return false;
}

//Tested
void isPISong() {
    unsigned int testCases;
    cin >> testCases;
    string piValue = "31415926535897932384626433833";
    string charCount;
    unsigned int letterCount;
    string userInput;
    getline(std::cin,userInput);
    while(testCases--) {
        charCount.clear();
        getline(std::cin,userInput);
        letterCount = 0;
        for(unsigned int counter = 0; counter < userInput.size(); counter++) {
            if(isChar(userInput[counter])) {
                letterCount++;
            } else {
                if(letterCount != 0) {
                    charCount.push_back(letterCount+'0');
                }
                letterCount = 0;
            }
        }
        if(letterCount != 0) {
            charCount.push_back(letterCount+'0');
        }
        bool flag = true;
        for(unsigned int counter = 0; counter < charCount.size(); counter++) {
            if(piValue[counter] != charCount[counter]) {
                flag = false;
                break;
            }
        }
        printf("%s\n",flag?"It's a pi song.":"It's not a pi song.");
    }
}

#endif /* SONGSOFPI_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
