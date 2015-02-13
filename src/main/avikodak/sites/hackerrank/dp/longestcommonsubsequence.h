/****************************************************************************************************************************************************
 *  File Name   		: longestcommonsubsequence.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\hackerrank\dp\longestcommonsubsequence.h
 *  Created on			: Feb 13, 2015 :: 9:35:50 AM
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

#ifndef LONGESTCOMMONSUBSEQUENCE_H_
#define LONGESTCOMMONSUBSEQUENCE_H_

//Tested
void printLongestCommonSubsequence(){
	int firstInputSize = 5,secondInputSize = 6;
	int input;
	scanf("%d %d",&firstInputSize,&secondInputSize);
	vector<int> firstUserInput,secondUserInput;
	vector<vector<int> > auxSpace(firstInputSize+1);
	for(int counter = 0;counter < firstInputSize+1;counter++){
		auxSpace[counter].assign(secondInputSize+1,0);
	}
	while(firstInputSize--){
		scanf("%d",&input);
		firstUserInput.push_back(input);
	}
	while(secondInputSize--){
		scanf("%d",&input);
		secondUserInput.push_back(input);
	}
	for(unsigned int outerCrawler = 1;outerCrawler < auxSpace.size();outerCrawler++){
		for(unsigned int innerCrawler = 1;innerCrawler < auxSpace[0].size();innerCrawler++){
			if(firstUserInput[outerCrawler-1] == secondUserInput[innerCrawler-1]){
				auxSpace[outerCrawler][innerCrawler] = 1 + auxSpace[outerCrawler-1][innerCrawler-1];
			}else{
				auxSpace[outerCrawler][innerCrawler] = max(auxSpace[outerCrawler-1][innerCrawler],auxSpace[outerCrawler][innerCrawler-1]);
			}
		}
	}
	int rowCounter = auxSpace.size()-1,columnCounter = auxSpace[0].size()-1;
	stack<int> sequence;
	while(rowCounter > 0 && columnCounter > 0){
		if(firstUserInput[rowCounter-1] == secondUserInput[columnCounter-1]){
			sequence.push(firstUserInput[rowCounter-1]);
			rowCounter -= 1;
			columnCounter -= 1;
		}else if(auxSpace[rowCounter-1][columnCounter] > auxSpace[rowCounter][columnCounter-1]){
			rowCounter -= 1;
		}else{
			columnCounter -= 1;
		}
	}
	while(!sequence.empty()){
		printf("%d ",sequence.top());
		sequence.pop();
	}
}


#endif /* LONGESTCOMMONSUBSEQUENCE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
