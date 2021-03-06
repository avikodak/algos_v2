/****************************************************************************************************************************************************
 *  File Name                   : longestincseq.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\hackerrank\dp\longestincseq.h
 *  Created on                  : Feb 12, 2015 :: 8:52:03 PM
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

#ifndef LONGESTINCSEQ_H_
#define LONGESTINCSEQ_H_

//Tested
void printLengthLIS() {
    long int input,size;
    unsigned int counter;
    vector<long int> auxSpace;
    scanf("%ld",&size);
    while(size--) {
        scanf("%ld",&input);
        if(auxSpace.size() == 0 || auxSpace[0] > input) {
            if(auxSpace.size() == 0) {
                auxSpace.push_back(input);
            } else {
                auxSpace[0] = input;
            }
        } else if(auxSpace[auxSpace.size()-1] < input) {
            auxSpace.push_back(input);
        } else {
            counter = 0;
            while(counter < auxSpace.size() && input > auxSpace[counter]) {
                counter++;
            }
            auxSpace[counter] = input;
        }
    }
    printf("%u",auxSpace.size());
}

#endif /* LONGESTINCSEQ_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
