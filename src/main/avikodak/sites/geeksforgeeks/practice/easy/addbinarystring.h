/****************************************************************************************************************************************************
 *  File Name                   : addbinarystring.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/geeksforgeeks/practice/easy/addbinarystring.h
 *  Created on                  : Jun 26, 2016 :: 10:52:32 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.practice.geeksforgeeks.org/problem-page.php?pid=569
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

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_EASY_ADDBINARYSTRING_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_EASY_ADDBINARYSTRING_H_

//Tested
void solveProblem() {
    unsigned int testCases, sum, carry;
    string fUserInput, sUserInput;
    int fCrawler, sCrawler;
    scanf("%u", &testCases);
    bool sumFlags[] = { false, true, false, true };
    bool carryFlags[] = { false, false, true, true };
    stack<bool> auxSpace;
    while (testCases--) {
        cin >> fUserInput >> sUserInput;
        sum = carry = 0;
        fCrawler = fUserInput.size() - 1;
        sCrawler = sUserInput.size() - 1;
        while (fCrawler >= 0 || sCrawler >= 0) {
            sum = carry;
            if (fCrawler >= 0) {
                sum += fUserInput[fCrawler] - '0';
            }
            if (sCrawler >= 0) {
                sum += sUserInput[sCrawler] - '0';
            }
            auxSpace.push(sumFlags[sum]);
            carry = carryFlags[sum] ? 1 : 0;
            fCrawler--;
            sCrawler--;
        }
        if (carry) {
            auxSpace.push(true);
        }
        while (!auxSpace.empty()) {
            printf("%d", auxSpace.top() ? 1 : 0);
            auxSpace.pop();
        }
        printf("\n");
    }
}

#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_EASY_ADDBINARYSTRING_H_ */
