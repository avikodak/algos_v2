/****************************************************************************************************************************************************
 *  File Name                   : cd1it3.h
 *  File Location               : /home/avikodak/Desktop/projects/algos_v2/src/main/avikodak/sites/codechef/peer/cd1it3.h
 *  Created on                  : 24-Sep-2015 :: 9:17:03 am
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/CD1IT3
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

#ifndef CD1IT3_H_
#define CD1IT3_H_

//Tested
void printResults() {
    unsigned int size;
    long long int reqSum,input,reqNumber;
    vector<long long int> userInput;
    scanf("%u %lld",&size,&reqSum);
    while(size--) {
        scanf("%lld",&input);
        userInput.push_back(input);
    }
    sort(userInput.begin(),userInput.end());
    bool pairPresent = false;
    for(unsigned int counter =0; counter < userInput.size(); counter++) {
        reqNumber = reqSum - userInput[counter];
        if(userInput[counter] == reqNumber) {
            if(counter+1 < userInput.size() && userInput[counter] == userInput[counter+1]) {
                pairPresent = true;
                break;
            }
        } else {
            if(binary_search(userInput.begin(),userInput.end(),reqNumber)) {
                pairPresent = true;
                break;
            }
        }
    }
    printf("%s\n",pairPresent?"Yes":"No");
}

#endif /* CD1IT3_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
