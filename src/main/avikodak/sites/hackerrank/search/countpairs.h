/****************************************************************************************************************************************************
 *  File Name   		: countpairs.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\hackerrank\search\countpairs.h
 *  Created on			: Jan 30, 2015 :: 9:00:30 AM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: https://www.hackerrank.com/challenges/pairs
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
#include <algorithm/constants/constants.h>
#include <algorithm/ds/commonds.h>
#include <algorithm/ds/linkedlistds.h>
#include <algorithm/ds/graphds.h>
#include <algorithm/ds/mathds.h>
#include <algorithm/ds/treeds.h>
#include <algorithm/utils/arrayutil.h>
#include <algorithm/utils/avltreeutil.h>
#include <algorithm/utils/bplustreeutil.h>
#include <algorithm/utils/btreeutil.h>
#include <algorithm/utils/commonutil.h>
#include <algorithm/utils/dillutil.h>
#include <algorithm/utils/graphutil.h>
#include <algorithm/utils/mathutil.h>
#include <algorithm/utils/redblacktreeutil.h>
#include <algorithm/utils/sillutil.h>
#include <algorithm/utils/treeutil.h>
#include <algorithm/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef COUNTPAIRS_H_
#define COUNTPAIRS_H_

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int pairs(vector < int > userInput,int difference) {
   int result = 0;
   sort(userInput.begin(),userInput.end());
   int firstCrawler = 0,secoundCrawler = 1,currentDifference;
   while(firstCrawler < userInput.size() && secoundCrawler < userInput.size()){
       currentDifference = userInput[secoundCrawler] - userInput[firstCrawler];
       if(currentDifference == difference){
           result += 1;
           firstCrawler++;
           secoundCrawler++;
       }else if(currentDifference > difference){
           firstCrawler++;
       }else{
           secoundCrawler++;
       }
   }
   return result;
}

#endif /* COUNTPAIRS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
