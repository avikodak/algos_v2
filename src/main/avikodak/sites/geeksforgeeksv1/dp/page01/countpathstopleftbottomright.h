/****************************************************************************************************************************************************
 *  File Name   		: countpathstopleftbottomright.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\dp\page01\countpathstopleftbottomright.h
 *  Created on			: Jan 12, 2015 :: 11:44:09 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/count-possible-paths-top-left-bottom-right-nxm-matrix/
****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 														NAMESPACE DECLARATION AND IMPORTS 														    */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/* 																INCLUDES		 																    */
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
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef COUNTPATHSTOPLEFTBOTTOMRIGHT_H_
#define COUNTPATHSTOPLEFTBOTTOMRIGHT_H_

//Tested
int countPathsFromTopLeftToBottomRight(int row,int column) {
    if(row == 1 || column == 1) { // OR is used since there is only one way to reach beginning after we reach first row or first column
        return 1;
    }
    return countPathsFromTopLeftToBottomRight(row-1,column) + countPathsFromTopLeftToBottomRight(row,column-1);
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int countPathsFromTopLeftToBottomRightDP(int row,int column) {
    if(row == 1 || column == 1) {
        return 1;
    }
    vector<vector<int> > auxSpace(row);
    for(int counter = 0; counter < row; counter++) {
        auxSpace[counter].assign(column,1);
    }
    for(int outerCrawler = 1; outerCrawler < row; outerCrawler++) {
        for(int innerCrawler = 1; innerCrawler < column; innerCrawler++) {
            auxSpace[outerCrawler][innerCrawler] = auxSpace[outerCrawler-1][innerCrawler] + auxSpace[outerCrawler][innerCrawler-1];
        }
    }
    return auxSpace[row-1][column-1];
}

#endif /* COUNTPATHSTOPLEFTBOTTOMRIGHT_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
