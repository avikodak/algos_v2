/****************************************************************************************************************************************************
 *  File Name                   : latticepaths.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\projecteuler\latticepaths.h
 *  Created on                  : Aug 11, 2015 :: 9:14:32 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://projecteuler.net/problem=15
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

#ifndef LATTICEPATHS_H_
#define LATTICEPATHS_H_

//Tested
//Ans : 137846528820
unsigned long long int getTotalLatticePaths(unsigned int size) {
    vector<vector<unsigned long long int> > matrix(size+1);
    for(unsigned int counter = 0; counter < matrix.size(); counter++) {
        matrix[counter].assign(size+1,0);
    }
    for(unsigned int rowCounter = 0; rowCounter < size+1; rowCounter++) {
        matrix[rowCounter][size] = 1;
    }
    for(unsigned int columnCounter = 0; columnCounter < size+1; columnCounter++) {
        matrix[size][columnCounter] = 1;
    }
    matrix[size][size] = 0;
    for(int rowCounter = size-1; rowCounter >= 0; rowCounter--) {
        for(int columnCounter = size-1; columnCounter >= 0; columnCounter--) {
            matrix[rowCounter][columnCounter] = matrix[rowCounter][columnCounter+1] + matrix[rowCounter+1][columnCounter];
        }
    }
    cout << matrix[0][0] << endl;
}

#endif /* LATTICEPATHS_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
