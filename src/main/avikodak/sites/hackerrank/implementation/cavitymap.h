/****************************************************************************************************************************************************
 *  File Name   		: cavitymap.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\hackerrank\implementation\cavitymap.h
 *  Created on			: Feb 11, 2015 :: 10:36:48 AM
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

#ifndef CAVITYMAP_H_
#define CAVITYMAP_H_

//Tested
void printCavities(){
	string line;
	getline(cin,line);
	stringstream convert(line);
	int size;
	convert >> size;
	vector<vector<int> > userInput(size),auxSpace(size);
	for(long int counter = 0;counter < size;counter++){
		userInput[counter].assign(size,0);
		auxSpace[counter].assign(size,0);
	}
	int rowCounter = 0;
	while(getline(cin, line) && size--){
		for(unsigned int columnCounter = 0;columnCounter < line.size();columnCounter++){
			userInput[rowCounter][columnCounter] = line[columnCounter]-'0';
			auxSpace[rowCounter][columnCounter] = userInput[rowCounter][columnCounter];
		}
		if(size == 0){
			break;
		}
		rowCounter++;
	}
	for(unsigned int outerCrawler = 1;outerCrawler < userInput.size()-1;outerCrawler++){
		for(unsigned int innerCrawler = 1;innerCrawler < userInput.size()-1;innerCrawler++){
			if(userInput[outerCrawler][innerCrawler] > userInput[outerCrawler-1][innerCrawler] && userInput[outerCrawler][innerCrawler] > userInput[outerCrawler+1][innerCrawler] && userInput[outerCrawler][innerCrawler] > userInput[outerCrawler][innerCrawler-1] && userInput[outerCrawler][innerCrawler] > userInput[outerCrawler][innerCrawler+1]){
				auxSpace[outerCrawler][innerCrawler] = INT_MAX;
			}
		}
	}
	for(unsigned int outerCrawler = 0;outerCrawler < auxSpace.size();outerCrawler++){
		for(unsigned int innerCrawler = 0;innerCrawler < auxSpace.size();innerCrawler++){
			if(auxSpace[outerCrawler][innerCrawler] == INT_MAX){
				printf("X");
			}else{
				printf("%d",auxSpace[outerCrawler][innerCrawler]);
			}
		}
		printf("\n");
	}
}

#endif /* CAVITYMAP_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
