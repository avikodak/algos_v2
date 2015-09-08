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
