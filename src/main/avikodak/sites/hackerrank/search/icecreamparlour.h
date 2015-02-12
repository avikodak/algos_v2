/****************************************************************************************************************************************************
 *  File Name   		: icecreamparlour.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\hackerrank\search\icecreamparlour.h
 *  Created on			: Feb 11, 2015 :: 12:32:13 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: https://www.hackerrank.com/challenges/icecream-parlor
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

#ifndef ICECREAMPARLOUR_H_
#define ICECREAMPARLOUR_H_

//Tested
void getIndicesForSum(){
	int testCases,size,sum,input;
	vector<int> userInput;
	bool flag;
	while(testCases--){
		scanf("%d %d",&sum,&size);
		userInput.clear();
		while(size--){
			scanf("%d",&input);
			userInput.push_back(input);
		}
		flag = false;
		for(unsigned int outerCrawler = 0;outerCrawler < userInput.size();outerCrawler++){
			for(unsigned int innerCrawler = outerCrawler+1;innerCrawler < userInput.size();innerCrawler++){
				if(userInput[outerCrawler] + userInput[innerCrawler] == sum){
					printf("%d %d\n",outerCrawler+1,innerCrawler+1);
					flag = true;
				}
			}
			if(flag){
				break;
			}
		}
	}
}

#endif /* ICECREAMPARLOUR_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
