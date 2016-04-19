/****************************************************************************************************************************************************
 *  File Name   		: decodingsdigitsequence.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\dp\page01\decodingsdigitsequence.h
 *  Created on			: Jan 12, 2015 :: 11:11:56 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/count-possible-decodings-given-digit-sequence/
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

#ifndef DECODINGSDIGITSEQUENCE_H_
#define DECODINGSDIGITSEQUENCE_H_

//Tested
int noOfDecodingsDigitSequence(char *userInput,int length) {
    if(length <= 1) {
        return 1;
    }
    int counter = 0;
    if(userInput[length-1] != '0') {
        counter += noOfDecodingsDigitSequence(userInput,length-1);
    }
    if(userInput[length-2] < '2' || (userInput[length-2] == '2' && userInput[length-1] <'7')) {
        counter += noOfDecodingsDigitSequence(userInput,length-2);
    }
    return counter;
}

//Tested
int noOfDecodingsDigitSequenceMemoization(char *userInput,int length) {
    if(length <= 1) {
        return 1;
    }
    vector<int> auxSpace;
    auxSpace.push_back(1);
    auxSpace.push_back(1);
    int total = 0;
    for(int counter = 2; counter <= length; counter++) {
        total = 0;
        if(userInput[counter-1] != '0') {
            total += auxSpace[counter-1];
        }
        if(userInput[counter-2] < '2' || (userInput[counter-2] == '2' && userInput[counter-1] < '7')) {
            total += auxSpace[counter-2];
        }
        auxSpace.push_back(total);
    }
    return auxSpace[auxSpace.size()-1];
}

#endif /* DECODINGSDIGITSEQUENCE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
