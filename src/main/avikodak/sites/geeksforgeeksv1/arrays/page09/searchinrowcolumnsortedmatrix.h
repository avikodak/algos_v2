/****************************************************************************************************************************************************
 *  File Name                   : searchinrowcolumnsortedmatrix.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page08\searchinrowcolumnsortedmatrix.h
 *  Created on                  : Dec 1, 2014 :: 12:31:00 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/search-in-row-wise-and-column-wise-sorted-matrix/
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

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE START                                                                     */
/****************************************************************************************************************************************************/

#ifndef SEARCHINROWCOLUMNSORTEDMATRIX_H_
#define SEARCHINROWCOLUMNSORTEDMATRIX_H_

//Tested
iPair *searchInRowColumnSortedMatrix(vector<vector<int> > userInput,int key) {
    if(userInput.size() == 0 || userInput[0].size() == 0) {
        return null;
    }
    int rowIndex = 0,columnIndex = userInput[0].size()-1;
    while(rowIndex >= 0 && rowIndex < (int)userInput.size() && columnIndex >= 0 && columnIndex < (int)userInput[0].size()) {
        if(userInput[rowIndex][columnIndex] == key) {
            return new iPair(rowIndex,columnIndex);
        } else if(userInput[rowIndex][columnIndex] > key) {
            columnIndex--;
        } else {
            rowIndex++;
        }
    }
    return null;
}

#endif /* SEARCHINROWCOLUMNSORTEDMATRIX_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
