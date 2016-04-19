/****************************************************************************************************************************************************
 *  File Name                   : permut2.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\codechef\permut2.h
 *  Created on                  : Feb 6, 2015 :: 6:43:56 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.codechef.com/problems/PERMUT2
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

#ifndef PERMUT2_H_
#define PERMUT2_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
void arePermutationsAmbiguous() {
    int testCaseSize;
    vector<int> userInput,auxSpace;
    int number;
    bool flag;
    while(true) {
        scanf("%d",&testCaseSize);
        if(testCaseSize == 0) {
            break;
        }
        userInput.clear();
        auxSpace.clear();
        while(testCaseSize--) {
            scanf("%d",&number);
            userInput.push_back(number);
        }
        auxSpace.assign(userInput.size(),0);
        for(unsigned int counter = 0; counter < userInput.size(); counter++) {
            auxSpace[userInput[counter]-1] = counter+1;
        }
        flag = true;
        for(unsigned int counter = 0; counter < userInput.size(); counter++) {
            if(userInput[counter] != auxSpace[counter]) {
                flag = false;
            }
        }
        if(flag) {
            cout << "ambiguous" << endl;
        } else {
            cout << "not ambiguous" << endl;
        }
    }
}

#endif /* PERMUT2_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
