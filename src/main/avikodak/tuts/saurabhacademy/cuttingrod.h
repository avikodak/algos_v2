/****************************************************************************************************************************************************
 *  File Name   		: cuttingrod.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\saurabhacademy\cuttingrod.h
 *  Created on			: Oct 24, 2014 :: 8:52:41 PM
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

#ifndef CUTTINGROD_H_
#define CUTTINGROD_H_

//Tested
int cuttingRod(map<unsigned int,int> &lengthBenefitMap,unsigned int lengthOfRod){
	if(lengthOfRod <= 0){
		return 0;
	}
	int maxBenefit = 0;
	map<unsigned int,int>::iterator itToLengthBenefitMap;
	for(itToLengthBenefitMap = lengthBenefitMap.begin();itToLengthBenefitMap != lengthBenefitMap.end();itToLengthBenefitMap++){
		if(lengthOfRod >= itToLengthBenefitMap->first){
			maxBenefit = max(maxBenefit,itToLengthBenefitMap->second + cuttingRod(lengthBenefitMap,lengthOfRod - itToLengthBenefitMap->first));
		}
	}
	return maxBenefit;
}

int cuttingRodBottomUp(map<unsigned int,int> lengthBenefitMap,unsigned int lengthOfRod){
	return 0;
}

//Tested
int cuttingRodMemoization(map<unsigned int,int> lengthBenefitMap,unsigned int lengthOfRod){
	if(lengthOfRod <= 0){
		return 0;
	}
	int maxBenefit = 0;
	static map<unsigned int,int> optimizedLengthBenefitMap;
	map<unsigned int,int>::iterator itToLengthBenefitMap,itToOptimizedLengthBenefitMap;
	for(itToLengthBenefitMap = lengthBenefitMap.begin();itToLengthBenefitMap != lengthBenefitMap.end();itToLengthBenefitMap++){
		if(lengthOfRod >= itToLengthBenefitMap->first){
			if((itToOptimizedLengthBenefitMap = optimizedLengthBenefitMap.find((unsigned int)(lengthOfRod - itToLengthBenefitMap->first))) == optimizedLengthBenefitMap.end()){
				maxBenefit = max(maxBenefit,itToLengthBenefitMap->second + cuttingRodMemoization(lengthBenefitMap,lengthOfRod - itToLengthBenefitMap->first));
			}else{
				maxBenefit = max(maxBenefit,itToOptimizedLengthBenefitMap->second);
			}
		}
	}
	optimizedLengthBenefitMap.insert(pair<unsigned int,int>(lengthOfRod,maxBenefit));
	return maxBenefit;
}

#endif /* CUTTINGROD_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
