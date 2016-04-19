/****************************************************************************************************************************************************
 *  File Name                   : partitionproblem.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\dp\page03\partitionproblem.h
 *  Created on                  : Jan 14, 2015 :: 2:28:37 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/dynamic-programming-set-18-partition-problem/
****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                         NAMESPACE DECLARATION AND IMPORTS                                                             */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/*                                                                 INCLUDES                                                                             */
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
/*                                                             USER DEFINED CONSTANTS                                                                     */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE START                                                                     */
/****************************************************************************************************************************************************/

#ifndef PARTITIONPROBLEM_H_
#define PARTITIONPROBLEM_H_

//Tested
bool partitionProblemMain(vector<int> userInput,int sum,unsigned int currentIndex = 0) {
    if(currentIndex > userInput.size()) {
        return false;
    }
    if(currentIndex == userInput.size()) {
        return sum == 0;
    }
    if(sum == 0) {
        return true;
    }
    return partitionProblemMain(userInput,sum,currentIndex+1) || partitionProblemMain(userInput,sum - userInput[currentIndex],currentIndex+1);
}

//Tested
bool partitionProblem(vector<int> userInput) {
    if(userInput.size() == 0) {
        return true;
    }
    int sum = 0;
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        sum += userInput[counter];
    }
    if(sum%2 == 1) {
        return false;
    }
    return partitionProblemMain(userInput,sum/2);
}

bool partitionProblemMemoization(vector<int> userInput,int sum) {
    if(userInput.size() == 0) {
        return sum == 0;
    }
    if(sum%2 == 1) {
        return true;
    }
    vector<vector<bool> > auxSpace(sum+1);
    for(int rowCounter = 0; rowCounter < sum; rowCounter++) {
        auxSpace[rowCounter].assign(userInput.size()+1,false);
        auxSpace[rowCounter][0] = true;
    }
    for(unsigned int columnCounter = 0; columnCounter < auxSpace[0].size(); columnCounter++) {
        auxSpace[0][columnCounter] = false;
    }
    for(unsigned int rowCounter = 1; rowCounter < auxSpace.size(); rowCounter++) {
        for(unsigned int columnCounter = 1; columnCounter < auxSpace[0].size(); columnCounter++) {
            auxSpace[rowCounter][columnCounter] = auxSpace[rowCounter][columnCounter-1];
            if(rowCounter - userInput[columnCounter] >= 0) {
                auxSpace[rowCounter][columnCounter] = auxSpace[rowCounter][columnCounter] || auxSpace[rowCounter - userInput[columnCounter]][columnCounter-1];
            }
        }
    }
    return auxSpace[auxSpace.size()-1][auxSpace[0].size()-1];
}

#endif /* PARTITIONPROBLEM_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
