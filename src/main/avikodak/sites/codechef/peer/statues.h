/****************************************************************************************************************************************************
 *  File Name                   : statues.h
 *  File Location               : /home/avikodak/Desktop/projects/algos_v2/src/main/avikodak/sites/codechef/peer/statues.h
 *  Created on                  : 12-Sep-2015 :: 1:09:43 pm
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/STATUES
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
#include <stdint.h>
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

#ifndef STATUES_H_
#define STATUES_H_

//Tested
void printTotalMoves(vector<int> userInput,int average,int testCaseNo) {
    int totalMoves = 0;
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        if(average < userInput[counter]) {
            totalMoves += (userInput[counter] - average);
        }
    }
    cout << "Set #" << testCaseNo << endl;
    printf("The minimum number of moves is %u.\n\n",totalMoves);
}

//Tested
void printResults() {
    int size,input,sum,testCase = 0;
    vector<int> userInput;
    do {
        scanf("%u",&size);
        testCase++;
        if(size == 0) {
            break;
        }
        userInput.clear();
        sum = 0;
        for(int counter = 0; counter < size; counter++) {
            scanf("%u",&input);
            userInput.push_back(input);
            sum += input;
        }
        printTotalMoves(userInput,sum/size,testCase);
    } while(true);
}

#endif /* STATUES_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
