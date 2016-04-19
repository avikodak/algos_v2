/****************************************************************************************************************************************************
 *  File Name                   : stonesontable.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\codeforces\stonesontable.h
 *  Created on                  : Feb 28, 2015 :: 7:39:48 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://codeforces.com/problemset/problem/266/A
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
#define MAX_INPUT_SIZE 51

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE START                                                                     */
/****************************************************************************************************************************************************/

#ifndef STONESONTABLE_H_
#define STONESONTABLE_H_

//Tested
void stonesToBeRemoved() {
    unsigned int size,counter = 0,stonesRemovedCounter = 0,frequency;
    char userInput[MAX_INPUT_SIZE];
    scanf("%d",&size);
    scanf("%s",userInput);
    while(counter < size) {
        frequency = 1;
        while(counter + 1 < size && userInput[counter] == userInput[counter+1]) {
            frequency++;
            counter++;
        }
        if(frequency > 1) {
            stonesRemovedCounter += frequency-1;
        }
        counter++;
    }
    printf("%u",stonesRemovedCounter);
}

#endif /* STONESONTABLE_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
