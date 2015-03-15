/****************************************************************************************************************************************************
 *  File Name   		: findhackerrank.h 
 *	File Location		: D:\projects\cpp\algos_v2\src\main\avikodak\sites\hackerrank\regex\findhackerrank.h
 *  Created on			: Mar 12, 2015 :: 5:46:56 PM
 *  Author				: avikodak
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
#define HACKER_RANK_LOWER_CASE "hackerrank"

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef FINDHACKERRANK_H_
#define FINDHACKERRANK_H_

void split(const string &s, char delim, vector<string> &elements) {
    stringstream ss(s);
    string item;
    elements.clear();
    while (getline(ss, item, delim)) {
        elements.push_back(item);
    }
}


void printResultOfConversation(){
	int numberOfTestCases;
	scanf("%d",&numberOfTestCases);
	string userInput;
	vector<string> words;
	int firstWordFlag,lastWordFlag;
	while(numberOfTestCases--){
		cin >> userInput;
		split(userInput,',',words);
		firstWordFlag = words[0].compare(HACKER_RANK_LOWER_CASE);
		lastWordFlag = words[words.size()-1].compare(HACKER_RANK_LOWER_CASE);
		if(firstWordFlag == 0 && lastWordFlag == 0){
			printf("0\n");
		}else if(firstWordFlag == 0){
			printf("1\n");
		}else if(lastWordFlag == 0){
			printf("2\n");
		}else{
			printf("-1\n");
		}
	}
}

#endif /* FINDHACKERRANK_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
