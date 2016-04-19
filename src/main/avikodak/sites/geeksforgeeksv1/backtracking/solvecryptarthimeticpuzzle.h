/****************************************************************************************************************************************************
 *  File Name   		: solvecryptarthimeticpuzzle.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\backtracking\solvecryptarthimeticpuzzle.h
 *  Created on			: Jan 7, 2015 :: 8:12:56 PM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: TODO
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

#ifndef SOLVECRYPTARTHIMETICPUZZLE_H_
#define SOLVECRYPTARTHIMETICPUZZLE_H_

struct cryptArithmeticDS {
    vector<int> firstInput;
    vector<int> secondInput;
    vector<int> result;

};

bool isSafeCryptarthimeticPuzzle(vector<int> numbersAssigned,unsigned int index,int number) {
    for(unsigned int counter = 0; counter < numbersAssigned.size(); counter++) {
        if(counter != index) {
            if(numbersAssigned[counter] == number) {
                return true;
            }
        }
    }
    return false;
}

bool checkSolution(cryptArithmeticDS puzzle,vector<int> numbersAssigned) {
    unsigned int firstCounter = 0,secondCounter = 0;
    int carry = 0,sum;
    while(firstCounter < puzzle.firstInput.size() && secondCounter < puzzle.secondInput.size()) {
        sum = puzzle.firstInput[firstCounter] + puzzle.secondInput[secondCounter] + carry;
        if(sum%10 != numbersAssigned[puzzle.result[firstCounter]]) {
            return false;
        }
        carry = sum/10;
        firstCounter++;
        secondCounter++;
    }
    while(firstCounter < puzzle.firstInput.size()) {
        sum = puzzle.firstInput[firstCounter] + carry;
        if(sum%10 != numbersAssigned[puzzle.result[firstCounter]]) {
            return false;
        }
        carry = sum/10;
        firstCounter++;
    }
    while(secondCounter < puzzle.secondInput.size()) {
        sum = puzzle.secondInput[secondCounter] + carry;
        if(sum%10 != numbersAssigned[puzzle.result[secondCounter]]) {
            return false;
        }
        carry = sum/10;
        secondCounter++;
    }
    return true;
}

bool solveCryptarthimeticPuzzle(cryptArithmeticDS puzzle,vector<int> numbersAssigned,unsigned int currentIndex) {
    if(currentIndex == numbersAssigned.size()) {
        if(checkSolution(puzzle,numbersAssigned)) {
            return true;
        }
        return false;
    }
    for(unsigned int counter = 0; counter < 10; counter++) {
        if(isSafeCryptarthimeticPuzzle(numbersAssigned,currentIndex,counter)) {
            numbersAssigned[counter];
            if(solveCryptarthimeticPuzzle(puzzle,numbersAssigned,currentIndex+1)) {
                return true;
            }
        }
    }
    return false;
}

#endif /* SOLVECRYPTARTHIMETICPUZZLE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
