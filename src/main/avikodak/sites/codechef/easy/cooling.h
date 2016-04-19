/****************************************************************************************************************************************************
 *  File Name                   : cooling.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\codechef\easy\cooling.h
 *  Created on                  : Feb 8, 2015 :: 8:46:05 PM
 *  Author                      : AVINASH
 *  Testing Status              : Tested
 *  URL                         : http://www.codechef.com/problems/COOLING
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
#define MAX_SIZE 30

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE START                                                                     */
/****************************************************************************************************************************************************/

#ifndef COOLING_H_
#define COOLING_H_

/****************************************************************************************************************************************************/
/*                                                                 O(NLOGN) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
void getMaxPiesCooled() {
    int testCases,size,input;
    int pieWeights[MAX_SIZE],maxWeights[MAX_SIZE];
    scanf("%d",&testCases);
    int maxPies,pieCounter,weightCounter;
    while(testCases--) {
        scanf("%d",&size);
        for(int counter = 0; counter < size; counter++) {
            scanf("%d",&input);
            pieWeights[counter] = input;
        }
        for(int counter = 0; counter < size; counter++) {
            scanf("%d",&input);
            maxWeights[counter] = input;
        }
        sort(pieWeights,pieWeights+size);
        sort(maxWeights,maxWeights+size);
        maxPies = 0;
        pieCounter = 0;
        weightCounter = 0;
        while(pieCounter < size && weightCounter < size) {
            while(weightCounter < size && maxWeights[weightCounter] < pieWeights[pieCounter]) {
                weightCounter++;
            }
            if(weightCounter < size) {
                maxPies++;
                weightCounter++;
                pieCounter++;
            }
        }
        printf("%d\n",maxPies);
    }
}

#endif /* COOLING_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
