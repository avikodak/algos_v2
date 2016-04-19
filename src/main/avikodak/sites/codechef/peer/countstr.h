/****************************************************************************************************************************************************
 *  File Name                   : countstr.h
 *  File Location               : /home/avikodak/Desktop/projects/algos_v2/src/main/avikodak/sites/codechef/peer/countstr.h
 *  Created on                  : 14-Oct-2015 :: 7:19:37 pm
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/COUNTSTR
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
#include <iomanip>
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

#ifndef COUNTSTR_H_
#define COUNTSTR_H_

//Tested
void printResults() {
    unsigned int rows,columns,input,testCases,rowStart,rowEnd,columnStart,columnEnd,total = 0;
    scanf("%u %u",&rows,&columns);
    vector<vector<unsigned int> > matrix(rows);
    for(unsigned int rowCounter = 0; rowCounter < rows; rowCounter++) {
        matrix[rowCounter].assign(columns,0);
    }
    for(unsigned int rowCounter = 0; rowCounter < rows; rowCounter++) {
        for(unsigned int columnCounter = 0; columnCounter < columns; columnCounter++) {
            scanf("%u",&input);
            matrix[rowCounter][columnCounter] = input;
        }
    }
    scanf("%u",&testCases);
    while(testCases--) {
        scanf("%u %u %u %u",&rowStart,&columnStart,&rowEnd,&columnEnd);
        total = 0;
        for(unsigned int rowCounter = rowStart-1; rowCounter < rowEnd; rowCounter++) {
            for(unsigned int columnCounter = columnStart-1; columnCounter < columnEnd; columnCounter++) {
                total += matrix[rowCounter][columnCounter];
            }
        }
        printf("%u\n",total);
    }
}

#endif /* COUNTSTR_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
