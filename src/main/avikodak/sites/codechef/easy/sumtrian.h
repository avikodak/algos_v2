/****************************************************************************************************************************************************
 *  File Name   		: sumtrian.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\codechef\sumtrian.h
 *  Created on			: Feb 5, 2015 :: 10:33:39 AM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.codechef.com/problems/SUMTRIAN
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

#ifndef SUMTRIAN_H_
#define SUMTRIAN_H_

/****************************************************************************************************************************************************/
/* 																O(LOGN) Algorithm 															    	*/
/****************************************************************************************************************************************************/
//Tested
void maxSumTriangle(){
	int testCases;
	scanf("%d",&testCases);
	int rows;
	int number;
	int maxSum = 0;
	while(testCases--){
		scanf("%d",&rows);
		vector<vector<int> > userInput(rows);
		maxSum = 0;
		for(int rowCounter = 0;rowCounter < rows;rowCounter++){
			for(int columnCounter = 0;columnCounter <= rowCounter;columnCounter++){
				scanf("%d",&number);
				if(rowCounter-1 >= 0){
					if(columnCounter-1 >= 0 && (int)userInput[rowCounter-1].size() > columnCounter){
						number += max(userInput[rowCounter-1][columnCounter-1],userInput[rowCounter-1][columnCounter]);
					} else if((int)userInput[rowCounter-1].size() > columnCounter){
						number += userInput[rowCounter-1][columnCounter];
					}else if(columnCounter-1 >= 0){
						number += userInput[rowCounter-1][columnCounter-1];
					}
				}
				maxSum = max(maxSum,number);
				userInput[rowCounter].push_back(number);
			}
		}
		userInput.clear();
		printf("%d\n",maxSum);
	}
}

#endif /* SUMTRIAN_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
