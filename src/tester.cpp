/****************************************************************************************************************************************************
 *  File Name                   : tester.cpp 
 *  File Location               : \algos_v2\src\tester.cpp
 *  Created on                  : Oct 9, 2014 :: 12:55:16 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : TODO
 ****************************************************************************************************************************************************/
struct sillNode;

/****************************************************************************************************************************************************/
/*                                                         NAMESPACE DECLARATION AND IMPORTS                                                             */
/****************************************************************************************************************************************************/
using namespace std;

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
#include <lib/ds/graphds.h>
#include <lib/ds/linkedlistds.h>
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
#include <lib/utils/trieutil.h>
#include <lib/utils/treeutil.h>
#include <lib/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/*                                                             Testing Includes                                                                        */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE START                                                                     */
/****************************************************************************************************************************************************/
int findMaxIJ(vector<int> userInput) {
    vector<int> smallestTillNow;
    smallestTillNow.push_back(userInput[0]);
    for (unsigned int counter = 1; counter < userInput.size(); counter++) {
        smallestTillNow.push_back(min(smallestTillNow[smallestTillNow.size() - 1], userInput[counter]));
    }
    vector<int> greaterTillNow;
    greaterTillNow.assign(userInput.size(), 0);
    greaterTillNow[userInput.size() - 1] = userInput.size() - 1;
    for (int counter = userInput.size() - 2; counter >= 0; counter--) {

    }

}

int main() {
    return 0;
}

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/

