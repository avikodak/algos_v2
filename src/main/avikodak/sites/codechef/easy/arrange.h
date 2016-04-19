/****************************************************************************************************************************************************
 *  File Name                   : arrange.h
 *  File Location               : /home/avikodak/Desktop/projects/algos_v2/src/main/avikodak/sites/codechef/easy/arrange.h
 *  Created on                  : 30-Oct-2015 :: 8:27:00 am
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/ARRANGE
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

#ifndef ARRANGE_H_
#define ARRANGE_H_

//Tested
unsigned int reverseBits(unsigned int num,unsigned int bitCount) {
    unsigned int result = 0, temp;
    for (unsigned int counter = 0; counter < bitCount; counter++) {
        temp = (num & (1 << counter));
        if(temp)
            result |= (1 << ((bitCount - 1) - counter));
    }

    return result;
}

//Tested
void printResults() {
    unsigned int testCases,bitCount,index;
    string userInput,result;
    scanf("%u",&testCases);
    while(testCases--) {
        scanf("%u",&bitCount);
        cin >> userInput;
        result = userInput;
        for(unsigned int counter = 0; counter < userInput.size(); counter++) {
            index = reverseBits(counter,bitCount);
            result[index] = userInput[counter];
        }
        cout << result << endl;
    }
}

#endif /* ARRANGE_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
