/****************************************************************************************************************************************************
 *  File Name   		: keyboard.h
 *	File Location		: D:\projects\cpp\algos_v2\src\main\avikodak\sites\codeforces\keyboard.h
 *  Created on			: Mar 8, 2015 :: 12:29:58 PM
 *  Author				: avikodak
 *  Testing Status 		: Tested
 *  URL 				: http://codeforces.com/problemset/problem/474/A
 ****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 														NAMESPACE DECLARATION AND IMPORTS 														    */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/* 																INCLUDES		 																    */
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
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef KEYBOARD_H_
#define KEYBOARD_H_

//Tested
struct iRowColumn {
    int row;
    int column;

    iRowColumn() {

    }

    iRowColumn(int row,int column) {
        this->row = row;
        this->column = column;
    }
};

//Tested
void printRightSentence() {
    char direction;
    char keyboard[3][11] = {"qwertyuiop","asdfghjkl;","zxcvbnm,./"};
    map<char,iRowColumn *> charKeyboardMap;
    map<char,iRowColumn *>::iterator itToCharKeyboardMap;
    iRowColumn *rowColumn;
    int size = sizeof(keyboard[0])/sizeof(char);
    char userInput[CODEFORCES_MAX_INPUT_SIZE];
    for(int outerCounter = 0; outerCounter < 3; outerCounter++) {
        for(int innerCounter = 0; innerCounter < 11; innerCounter++) {
            charKeyboardMap[keyboard[outerCounter][innerCounter]] = new iRowColumn(outerCounter,innerCounter);
        }
    }
    scanf("%c",&direction);
    scanf("%s",userInput);
    size = strlen(userInput);
    for(int counter = 0; counter < size; counter++) {
        itToCharKeyboardMap = charKeyboardMap.find(userInput[counter]);
        rowColumn = itToCharKeyboardMap->second;
        if(direction == 'L') {
            printf("%c",keyboard[rowColumn->row][rowColumn->column+1]);
        } else {
            printf("%c",keyboard[rowColumn->row][rowColumn->column-1]);
        }
    }
}


#endif /* KEYBOARD_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
