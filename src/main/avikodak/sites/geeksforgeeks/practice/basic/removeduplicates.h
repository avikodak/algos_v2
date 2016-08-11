/****************************************************************************************************************************************************
 *  File Name                   : removeduplicates.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/geeksforgeeks/practice/basic/removeduplicates.h
 *  Created on                  : Aug 7, 2016 :: 1:11:32 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.practice.geeksforgeeks.org/problem-page.php?pid=700246
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
#include <libv2/common/commonincludes.h>
#include <libv2/constants/constants.h>
#include <libv2/ds/commonds.h>
#include <libv2/ds/graphds.h>
#include <libv2/ds/linkedlistds.h>
#include <libv2/ds/mathds.h>
#include <libv2/ds/treeds.h>
#include <libv2/utils/abtreeutil.h>
#include <libv2/utils/arrayutil.h>
#include <libv2/utils/avltreeutil.h>
#include <libv2/utils/bplustreeutil.h>
#include <libv2/utils/bstutil.h>
#include <libv2/utils/btreeutil.h>
#include <libv2/utils/commonutil.h>
#include <libv2/utils/dillutil.h>
#include <libv2/utils/graphutil.h>
#include <libv2/utils/ioutil.h>
#include <libv2/utils/mathutil.h>
#include <libv2/utils/redblacktreeutil.h>
#include <libv2/utils/sillutil.h>
#include <libv2/utils/treeutil.h>
#include <libv2/utils/trieutil.h>
#include <libv2/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_BASIC_REMOVEDUPLICATES_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_BASIC_REMOVEDUPLICATES_H_

//Tested
int remove_duplicate(int userInput[], int size) {
    int fillIndex = -1;
    int outerCrawler, innerCrawler;
    while (outerCrawler < size) {
        innerCrawler = outerCrawler;
        while (innerCrawler < size && userInput[innerCrawler] == userInput[outerCrawler]) {
            innerCrawler++;
        }
        userInput[++fillIndex] = userInput[outerCrawler];
        outerCrawler = innerCrawler;
    }
    return fillIndex + 1;
}

#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_BASIC_REMOVEDUPLICATES_H_ */
