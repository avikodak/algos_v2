/****************************************************************************************************************************************************
 *  File Name                   : rearrangepositvenegativeon.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page04\rearrangepositvenegativeon.h
 *  Created on                  : Dec 22, 2014 :: 9:02:08 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/rearrange-positive-and-negative-numbers-publish/
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

#ifndef REARRANGEPOSITVENEGATIVEON_H_
#define REARRANGEPOSITVENEGATIVEON_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
void rearrangePositiveNegative(vector<int> &userInput) {
    if(userInput.size() < 2) {
        return;
    }
    unsigned int startCrawler = 0,endCrawler = userInput.size()-1;
    while(startCrawler < endCrawler) {
        while(userInput[startCrawler] < 0) {
            startCrawler++;
        }
        while(userInput[endCrawler] > 0) {
            endCrawler--;
        }
        if(startCrawler < endCrawler) {
            swap(userInput[startCrawler],userInput[endCrawler]);
        }
    }
    for(unsigned int counter = 0; counter <= startCrawler && startCrawler < userInput.size()-1 && userInput[counter] < 0; counter+=2) {
        swap(userInput[counter],userInput[startCrawler++]);
    }
}

#endif /* REARRANGEPOSITVENEGATIVEON_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
