/****************************************************************************************************************************************************
 *  File Name                   : permutedmultiples.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\projecteuler\permutedmultiples.h
 *  Created on                  : Aug 17, 2015 :: 9:17:40 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://projecteuler.net/problem=52
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

#ifndef PERMUTEDMULTIPLES_H_
#define PERMUTEDMULTIPLES_H_

//Tested
string convertUIntToString(unsigned int value) {
    stringstream stream;
    stream << value;
    string result;
    result.append(stream.str());
    stream.clear();
    return result;
}

//Tested
bool isPermutedMultiple(unsigned int multiple,unsigned int originalNumber) {
    string strMultiple = convertUIntToString(multiple);
    string strOriginal = convertUIntToString(originalNumber);
    sort(strMultiple.begin(),strMultiple.end());
    sort(strOriginal.begin(),strOriginal.end());
    return strOriginal.compare(strMultiple) == 0;
}

//Tested
//Ans : 142857
void printPermutedMultiple() {
    unsigned int counter = 1;
    while(true) {
        if(isPermutedMultiple(2*counter,counter)) {
            if(isPermutedMultiple(3*counter,counter)) {
                if(isPermutedMultiple(4*counter,counter)) {
                    if(isPermutedMultiple(5*counter,counter)) {
                        if(isPermutedMultiple(6*counter,counter)) {
                            cout << counter << endl;
                            return;
                        }
                    }
                }
            }
        }
        counter++;
    }
}

#endif /* PERMUTEDMULTIPLES_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
