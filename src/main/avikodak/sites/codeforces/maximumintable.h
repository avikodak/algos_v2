/****************************************************************************************************************************************************
 *  File Name                   : maximumintable.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codeforces\maximumintable.h
 *  Created on                  : Apr 9, 2015 :: 11:54:01 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://codeforces.com/problemset/problem/509/A
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

#ifndef MAXIMUMINTABLE_H_
#define MAXIMUMINTABLE_H_

//Tested
void getMaximumTable() {
    unsigned int size;
    scanf("%u",&size);
    vector<vector<unsigned int> > matrix(size);
    for(unsigned int counter = 0; counter < size; counter++) {
        matrix[counter].assign(size,1);
    }
    for(unsigned int rowCounter = 1; rowCounter < size; rowCounter++) {
        for(unsigned int columnCounter = 1; columnCounter < size; columnCounter++) {
            matrix[rowCounter][columnCounter] = matrix[rowCounter-1][columnCounter] + matrix[rowCounter][columnCounter-1];
        }
    }
    printf("%d",matrix[size-1][size-1]);
}

#endif /* MAXIMUMINTABLE_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
