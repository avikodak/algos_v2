/****************************************************************************************************************************************************
 *  File Name   		: arrayhash.h
 *	File Location		: D:\projects\cpp\algos_v2\src\main\avikodak\sites\topcoder\division02\level01\arrayhash.h
 *  Created on			: Mar 27, 2015 :: 8:34:38 PM
 *  Author				: avikodak
 *  Testing Status 		: Tested
 *  URL 				: http://community.topcoder.com/stat?c=problem_statement&pm=4503
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

#ifndef ARRAYHASH_H_
#define ARRAYHASH_H_

//Tested
class ArrayHash {
public:
    int getHash(vector<string> userInput) {
        int hashValue = 0;
        for(unsigned int outerCrawler = 0; outerCrawler < userInput.size(); outerCrawler++) {
            for(unsigned int innerCrawler = 0; innerCrawler < userInput[outerCrawler].size(); innerCrawler++) {
                hashValue += outerCrawler + innerCrawler + (userInput[outerCrawler][innerCrawler] -'A');
            }
        }
    }
};

#endif /* ARRAYHASH_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
