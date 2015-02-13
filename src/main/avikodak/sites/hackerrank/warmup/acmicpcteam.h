/****************************************************************************************************************************************************
 *  File Name   		: acmicpcteam.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\hackerrank\warmup\acmicpcteam.h
 *  Created on			: Feb 5, 2015 :: 9:06:42 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
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

#ifndef ACMICPCTEAM_H_
#define ACMICPCTEAM_H_

//Tested
void maxTopicsAndTeams(){
	long int people,topics;
	scanf("%ld %ld",&people,&topics);
	vector<string> userInput;
	string input;
	for(unsigned int counter = 0;counter < people;counter++){
		cin >> input;
		userInput.push_back(input);
	}
	hash_map<long int,long int> topicPairsCount;
	int maxTopicsKnown = 0,topicsCount;
	for(unsigned int outerCrawler = 0;outerCrawler < userInput.size()-1;outerCrawler++){
		for(unsigned int innerCrawler = outerCrawler+1;innerCrawler < userInput.size();innerCrawler++){
			topicsCount = 0;
			for(unsigned int counter = 0;counter < topics;counter++){
				if(userInput[outerCrawler] == '1' || userInput[innerCrawler] == '1'){
					topicsCount++;
				}
			}
			maxTopicsKnown = max(maxTopicsKnown,topicsCount);
			if(topicPairsCount.find(topicsCount) == topicPairsCount.end()){
				topicPairsCount[topicsCount] = 1;
			}else{
				topicPairsCount[topicsCount] += 1;
			}
		}
	}
	printf("%d\n%d",maxTopicsKnown,topicPairsCount.find(maxTopicsKnown)->second);
}

#endif /* ACMICPCTEAM_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
