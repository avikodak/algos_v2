/****************************************************************************************************************************************************
 *  File Name   		: missingnumbers.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\hackerrank\search\missingnumbers.h
 *  Created on			: Feb 12, 2015 :: 12:06:39 PM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: TODO
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

#ifndef MISSINGNUMBERS_H_
#define MISSINGNUMBERS_H_

//Tested
void printMissingNumbers(){
	vector<int> firstList,secondList;
	int firstListSize,secondListSize,input;
	scanf("%d",&firstListSize);
	while(firstListSize--){
		scanf("%d",&input);
		firstList.push_back(input);
	}
	sort(firstList.begin(),firstList.end());
	scanf("%d",&secondListSize);
	while(secondListSize--){
		scanf("%d",&input);
		secondList.push_back(input);
	}
	sort(secondList.begin(),secondList.end());
	unsigned int firstCrawler = 0,secondCrawler = 0,prevNumber = INT_MIN;
	while(firstCrawler < firstList.size() || secondCrawler < secondList.size()){
		if(firstCrawler > firstList.size() || secondCrawler > secondList.size()){
			if(firstCrawler < firstList.size()){
				break;
			}else{
				if(prevNumber != secondList[secondCrawler]){
					printf("%d ",secondList[secondCrawler]);
					prevNumber = secondList[secondCrawler];
				}
				secondCrawler++;
			}
		}else{
			if(firstList[firstCrawler] == secondList[secondCrawler]){
				firstCrawler++;
				secondCrawler++;
			}else if(firstList[firstCrawler] > secondList[secondCrawler]){
				if(prevNumber != secondList[secondCrawler]){
					printf("%d ",secondList[secondCrawler]);
					prevNumber = secondList[secondCrawler];
				}
				secondCrawler++;
			}else{
				firstCrawler++;
			}
		}
	}
}

#endif /* MISSINGNUMBERS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
