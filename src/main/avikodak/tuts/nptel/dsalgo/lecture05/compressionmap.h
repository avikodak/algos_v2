/****************************************************************************************************************************************************
 *  File Name                   : compressionmap.h
 *  File Location               : \algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture05\compressionmap.h
 *  Created on                  : Nov 17, 2014 :: 7:34:22 PM
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
#define SIZE_OF_HASH_MAP 10
#define MAD_A 3
#define MAD_B 5
/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE START                                                                     */
/****************************************************************************************************************************************************/

#ifndef COMPRESSIONMAP_H_
#define COMPRESSIONMAP_H_

int getHashValueTraditional(int userInput) {
    return userInput % SIZE_OF_HASH_MAP;
}

int getHashValueV2(int userInput) {
    double conjugateOfGoldenRatio = (sqrt(5) - 1)/(double)(2);
    return floor(SIZE_OF_HASH_MAP * modf((conjugateOfGoldenRatio*userInput)));
}

int getHashValueMAD(int userInput) {
    return (MAD_A*userInput + MAD_B) % SIZE_OF_HASH_MAP;
}

#endif /* COMPRESSIONMAP_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
