/****************************************************************************************************************************************************
 *  File Name                   : dragnxor.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codechef\easy\dragnxor.h
 *  Created on                  : Sep 4, 2015 :: 10:18:46 AM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : https://www.codechef.com/problems/DRAGNXOR
 ****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                         NAMESPACE DECLARATION AND IMPORTS                                                        */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/*                                                                 INCLUDES                                                                         */
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
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef DRAGNXOR_H_
#define DRAGNXOR_H_

void binaryString(unsigned int userInput,vector<bool> &binaryRep,unsigned int setBitCount = 0){
	if(userInput == 0 || userInput == 1){
		binaryRep.push_back(userInput==1);
		if(userInput == 1){
			setBitCount++;
		}
		return;
	}
	binaryString(userInput/2,binaryRep);
	if(userInput%2){
		setBitCount++;
	}
	binaryRep.push_back(userInput%2);
}

bool sortFunc(bool first,bool second){
	return !first;
}

void getMaxXorValue(unsigned int first,unsigned int second){
	vector<bool> firstBinaryRep,secondBinaryRep;
	unsigned int firstSetBitCount,secondSetBitCount;
	binaryString(first,firstBinaryRep,firstSetBitCount);
	binaryString(second,secondBinaryRep,secondSetBitCount);
	if(firstSetBitCount > secondSetBitCount){
		sort(firstBinaryRep.begin(),firstBinaryRep.end());
		sort(secondBinaryRep.begin(),secondBinaryRep.end(),sortFunc);
	}else{
		sort(firstBinaryRep.begin(),firstBinaryRep.end(),sortFunc);
		sort(secondBinaryRep.begin(),secondBinaryRep.end());
	}
	unsigned int maxValue = 0;
	for(unsigned int counter = 0;counter < firstBinaryRep.size();counter++){
		maxValue += pow(2,firstBinaryRep.size()-counter-1);
	}
	cout << maxValue << endl;
}

void printResults(){
	unsigned int testCases,bitsSize;
	unsigned int first,second;
	scanf("%u",&testCases);
	while(testCases--){
		cin >> bitsSize >> first >> second;
		getMaxXorValue(first,second);
	}
}

#endif /* DRAGNXOR_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
