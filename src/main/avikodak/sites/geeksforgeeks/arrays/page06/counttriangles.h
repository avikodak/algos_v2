/****************************************************************************************************************************************************
 *  File Name   		: counttriangles.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page06\counttriangles.h
 *  Created on			: Jan 3, 2015 :: 10:09:48 AM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: http://www.geeksforgeeks.org/find-number-of-triangles-possible/
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

#ifndef COUNTTRIANGLES_H_
#define COUNTTRIANGLES_H_

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
int countPossibleTrianglesON2(vector<int> userInput){
	if(userInput.size() < 2){
		return 0;
	}
	int triangleCounter = 0;
	sort(userInput.begin(),userInput.end());
	unsigned int thirdSideCounter;
	for(unsigned int firstSideCounter = 0;firstSideCounter < userInput.size()-2;firstSideCounter++){
		thirdSideCounter = firstSideCounter + 2;
		for(unsigned int secondSideCounter = firstSideCounter+1;secondSideCounter < userInput.size()-1;secondSideCounter++){
			while(thirdSideCounter < userInput.size() && userInput[firstSideCounter] + userInput[secondSideCounter] > userInput[thirdSideCounter]){
				thirdSideCounter++;
			}
			triangleCounter += thirdSideCounter - secondSideCounter - 1;
		}
	}
	return triangleCounter;
}

/****************************************************************************************************************************************************/
/* 																O(N^3) Algorithm 																    */
/****************************************************************************************************************************************************/
int countPossibleTrianglesON3(vector<int> userInput){
	if(userInput.size() < 2){
		return 0;
	}
	int counter = 0;
	for(unsigned int outerCrawler = 0;outerCrawler < userInput.size()-2;outerCrawler++){
		for(unsigned int middleCrawler = outerCrawler+1;middleCrawler < userInput.size()-1;middleCrawler++){
			for(unsigned int innerCrawler = middleCrawler+1;innerCrawler < userInput.size();innerCrawler++){
				if(userInput[innerCrawler] < userInput[outerCrawler] + userInput[middleCrawler] && userInput[middleCrawler] < userInput[outerCrawler] + userInpu[innerCrawler] && userInput[outerCrawler] < userInput[middleCrawler]+userInput[innerCrawler]){
					counter++;
				}
			}
		}
	}
	return counter;
}

#endif /* COUNTTRIANGLES_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
