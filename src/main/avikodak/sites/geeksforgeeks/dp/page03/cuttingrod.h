/****************************************************************************************************************************************************
 *  File Name   		: cuttingrod.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\dp\page03\cuttingrod.h
 *  Created on			: Dec 9, 2014 :: 8:02:41 PM
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

#ifndef CUTTINGROD_H_
#define CUTTINGROD_H_

int maxBenefitRodCutting(vector<int> cuts,vector<int> benefits,unsigned int length){
	if(length == 0 || cuts.size() == 0){
		return 0;
	}
	vector<int> maxBenefits(length+1,0);
	for(unsigned int counter = 1;counter <= length;counter++){
		for(unsigned int cutCounter = 0;cutCounter < cuts.size();cutCounter++){
			if(counter >= cuts[cutCounter]){
				maxBenefits[counter] = benefits[cutCounter] + maxBenefits[counter - cuts[cutCounter]];
			}
		}
	}
	return maxBenefits[maxBenefits.size()-1];
}

int maxCuttingRodBenefit(vector<int> cuts,vector<int> benefits,int length){
	if(length < 0){
		return INT_MIN;
	}
	if(length == 0){
		return 0;
	}
	int maxBenefit = INT_MIN;
	for(unsigned int counter = 0;counter < cuts.size();counter++){
		if(cuts[counter] >= length){
			maxBenefit = max(maxBenefit,benefits[counter] + maxCuttingRodBenefit(cuts,benefits,length-cuts[counter]));
		}
	}
	return maxBenefit;
}

#endif /* CUTTINGROD_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
