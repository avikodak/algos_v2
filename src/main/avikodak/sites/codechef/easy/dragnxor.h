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
