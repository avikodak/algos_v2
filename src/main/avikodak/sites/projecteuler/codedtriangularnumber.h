/****************************************************************************************************************************************************
 *  File Name                   : codedtriangularnumber.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\projecteuler\codedtriangularnumber.h
 *  Created on                  : Aug 16, 2015 :: 7:23:53 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://projecteuler.net/problem=42
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

#ifndef CODEDTRIANGULARNUMBER_H_
#define CODEDTRIANGULARNUMBER_H_

//Tested
unsigned int getTriangleNumber(unsigned int userInput) {
    return (userInput*(userInput+1))/2;
}

//Tested
map<unsigned int,bool> generateTriangularNumber(unsigned int userInput) {
    map<unsigned int,bool> triangleNumberMap;
    for(unsigned int counter = 0; counter <= userInput; counter++) {
        triangleNumberMap.insert(pair<unsigned int,bool>(getTriangleNumber(counter),true));
    }
    return triangleNumberMap;
}

//Tested
unsigned int getStringCharValue(string userInput) {
    unsigned int sum = 0;
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        if(userInput[counter] >= 'A' && userInput[counter] <= 'Z') {
            sum += userInput[counter] - 'A' + 1;
        } else if(userInput[counter] >= 'a' && userInput[counter] <= 'z') {
            sum += userInput[counter] - 'a' + 1;
        }
    }
    return sum;
}

//Tested
//Ans : 162
void getTotalCodedTriangleNumber() {
    map<unsigned int,bool> triangleNumberMap = generateTriangularNumber(20);
    unsigned int testCases;
    scanf("%u",&testCases);
    string userInput;
    unsigned int counter = 0,strValue;
    while(testCases--) {
        cin >> userInput;
        strValue = getStringCharValue(userInput);
        if(triangleNumberMap.find(strValue) != triangleNumberMap.end()) {
            counter++;
        }
    }
    cout << counter << endl;
}

#endif /* CODEDTRIANGULARNUMBER_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
