/****************************************************************************************************************************************************
 *  File Name   		: turnimageby90.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page08\turnimageby90.h
 *  Created on			: Nov 26, 2014 :: 9:12:14 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/turn-an-image-by-90-degree/
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
#include <algorithm/ds/mathds.h>
#include <algorithm/ds/treeds.h>
#include <algorithm/utils/arrayutil.h>
#include <algorithm/utils/avltreeutil.h>
#include <algorithm/utils/bplustreeutil.h>
#include <algorithm/utils/btreeutil.h>
#include <algorithm/utils/commonutil.h>
#include <algorithm/utils/dillutil.h>
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

#ifndef TURNIMAGEBY90_H_
#define TURNIMAGEBY90_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
vector<vector<int> > turnImageBy90(vector<vector<int> > userInput){
	vector<vector<int> > rotatedImage(userInput[0].size());
	if(userInput.size() == 0 || userInput[0].size() == 0){
		return rotatedImage;
	}
	for(unsigned int counter = 0;counter < rotatedImage.size();counter++){
		rotatedImage[counter].assign(userInput.size(),0);
	}
	for(unsigned int rowCounter = 0;rowCounter < userInput.size();rowCounter++){
		for(unsigned int columnCounter = 0;columnCounter < userInput[0].size();columnCounter++){
			rotatedImage[columnCounter][rotatedImage[0].size() - rowCounter - 1] = userInput[rowCounter][columnCounter];
		}
	}
	return rotatedImage;
}

#endif /* TURNIMAGEBY90_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
