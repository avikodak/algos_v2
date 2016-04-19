/****************************************************************************************************************************************************
 *  File Name                   : permutationrepeating.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\strings\page04\permutationrepeating.h
 *  Created on                  : Jan 16, 2015 :: 11:13:11 AM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : TODO
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

#ifndef PERMUTATIONREPEATING_H_
#define PERMUTATIONREPEATING_H_

//Tested
void printPermutationRepeatingMain(char *userInput,char *result,int length,int index) {
    if(index == length) {
        printf("%s\n",result);
        return;
    }
    char *crawler = userInput;
    for(int counter = 0; counter < length; counter++) {
        result[index] = crawler[counter];
        printPermutationRepeatingMain(userInput,result,length,index+1);
    }
}

//Tested
void printPermutationRepeating(char *userInput,int length) {
    if(userInput == null || userInput[0] == '\0') {
        return;
    }
    char *result = (char *)malloc(sizeof(char) * (length+1));
    result[length] = '\0';
    printPermutationRepeatingMain(userInput,result,length,0);
}

#endif /* PERMUTATIONREPEATING_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
