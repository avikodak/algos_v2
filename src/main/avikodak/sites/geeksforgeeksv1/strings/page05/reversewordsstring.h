/****************************************************************************************************************************************************
 *  File Name                   : reversewordsstring.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\strings\page04\reversewordsstring.h
 *  Created on                  : Dec 4, 2014 :: 6:33:02 PM
 *  Author                      : AVINASH
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
#include <lib/ds/mathds.h>
#include <lib/ds/treeds.h>
#include <lib/utils/arrayutil.h>
#include <lib/utils/avltreeutil.h>
#include <lib/utils/bplustreeutil.h>
#include <lib/utils/btreeutil.h>
#include <lib/utils/commonutil.h>
#include <lib/utils/dillutil.h>
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

#ifndef REVERSEWORDSSTRING_H_
#define REVERSEWORDSSTRING_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
void reverseWord(char *startPtr,char *endPtr) {
    char tempch;
    while(startPtr != endPtr) {
        tempch = startPtr[0];
        startPtr[0] = endPtr[0];
        endPtr[0] = tempch;
        if(startPtr + 1 == endPtr) {
            break;
        }
        startPtr++;
        endPtr--;
    }
}

//Tested
void reverseWordsInString(char *userInput) {
    if(userInput == null) {
        return;
    }
    char *startCrawler = userInput,*rearCrawler;
    while(*startCrawler != '\0') {
        while(startCrawler[0] == ' ') {
            startCrawler++;
        }
        rearCrawler = startCrawler;
        while(rearCrawler[1] != ' ' && rearCrawler[1] != '\0') {
            rearCrawler++;
        }
        reverseWord(startCrawler,rearCrawler);
        startCrawler = rearCrawler+1;
    }
    reverseWord(userInput,rearCrawler);
}

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/


#endif /* REVERSEWORDSSTRING_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
