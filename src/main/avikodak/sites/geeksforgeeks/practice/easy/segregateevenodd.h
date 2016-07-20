/****************************************************************************************************************************************************
 *  File Name                   : segregateevenodd.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/geeksforgeeks/practice/easy/segregateevenodd.h
 *  Created on                  : Jul 7, 2016 :: 12:33:58 AM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : http://www.practice.geeksforgeeks.org/problem-page.php?pid=488
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

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_EASY_SEGREGATEEVENODD_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_EASY_SEGREGATEEVENODD_H_

int partitionIntoEvenOdd(vector<long long int> userInput) {
    int frontCrawler = 0, rearCrawler = userInput.size() - 1;
    while (frontCrawler < rearCrawler) {
        while (userInput[frontCrawler] % 2 == 0) {
            frontCrawler++;
        }
        while (frontCrawler < rearCrawler && userInput[rearCrawler] % 2 == 1) {
            rearCrawler--;
        }
        if (frontCrawler < rearCrawler) {
            swap(userInput[frontCrawler], userInput[rearCrawler]);
        }
    }
    swap(userInput[frontCrawler], userInput[rearCrawler]);
    return rearCrawler;
}

void solveProblem() {
    unsigned int testCases, size;
    long long int input;
    vector<long long int> userInput;
    scanf("%u", &testCases);
    while (testCases--) {
        scanf("%u", &size);
        userInput.clear();
        for (unsigned int counter = 0; counter < size; counter++) {
            scanf("%lld", &input);
            userInput.push_back(input);
        }
        int separatingIndex = partitionIntoEvenOdd(userInput);
        sort(userInput.begin(), userInput.begin() + separatingIndex);
        sort(userInput.begin() + separatingIndex + 1, userInput.end());
        for (unsigned int counter = 0; counter < size; counter++) {
            printf("%lld ", userInput[counter]);
        }
        printf("\n");
    }
}

#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_EASY_SEGREGATEEVENODD_H_ */

/*
 42
 449 328 474 150 709 467 329 936 440 700 117 258 811 952 491 993 931 823 431 359 590 899 153 292 370 404 698 699 876 442 705 757 527 868 893 642 273 18 885 675 788 291

 Its Correct output is:
 18 150 258 292 328 370 404 440 442 474 590 642 698 700 788 868 876 936 952 117 153 273 291 329 359 431 449 467 491 527 675 699 705 709 757 811 823 885 893 899 931 993

 And Your Output is:
 18 150 258 292 328 359 370 404 440 442 474 590 642 698 700 788 868 876 936 952 117 153 273 291 329 431 449 467 491 527 675 699 705 709 757 811 823 885 893 899 931 993


 */
