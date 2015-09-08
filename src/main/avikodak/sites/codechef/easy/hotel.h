/****************************************************************************************************************************************************
 *  File Name                   : hotel.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codechef\easy\hotel.h
 *  Created on                  : Sep 1, 2015 :: 1:10:02 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : https://www.codechef.com/problems/HOTEL
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

#ifndef HOTEL_H_
#define HOTEL_H_

struct interval{
	unsigned int start;
	unsigned int end;

	interval(){};

	interval(unsigned int start,unsigned int end){
		this->start = start;
		this->end = end;
	}
};

void printMaxOverlappingInterval(vector<interval *> userInput){
	unsigned int overlapCount = 0;
	for(unsigned int outerCounter = 1;outerCounter < userInput.size();outerCounter++){
		for(unsigned int innerCounter = 0;innerCounter < outerCounter;innerCounter++){
			if(userInput[outerCounter]->start >= userInput[innerCounter]->start && userInput[outerCounter]->start < userInput[innerCounter]->end){
				overlapCount++;
			}
		}
	}
	cout << overlapCount << endl;
}

void printResults(){
	unsigned int testCases,size;
	scanf("%u",&testCases);
	unsigned int start,end;
	vector<interval *> userInput;
	while(testCases--){
		scnaf("%u",&size);
		userInput.clear();
		while(size--){
			scanf("%u",&start,&end);
			userInput.push_back(new interval(start,end));
		}
		printMaxOverlappingInterval(userInput);
	}
}


void printMaxOverlappingInterval(vector<unsigned int> startTimes,vector<unsigned int> endTimes){
	unsigned int overlapCount = 0,maxOverlapCount = 0;
	for(unsigned int outerCounter = 1;outerCounter < startTimes.size();outerCounter++){
		overlapCount = 1;
		for(unsigned int innerCounter = 0;innerCounter < outerCounter;innerCounter++){
			if(startTimes[outerCounter] < endTimes[innerCounter] && endTimes[outerCounter] > startTimes[innerCounter]){
				cout << startTimes[outerCounter] << " - " << endTimes[outerCounter] <<" " <<startTimes[innerCounter] <<  "-" << endTimes[innerCounter] << endl;
				overlapCount++;
			}
		}
		cout << endl << endl;
		maxOverlapCount = max(maxOverlapCount,overlapCount);
	}
	cout << maxOverlapCount << endl;
}

void printResults(){
	unsigned int testCases,size;
	scanf("%u",&testCases);
	unsigned int start,end;
	vector<unsigned int> startTimes;
	vector<unsigned int> endTimes;
	while(testCases--){
		scanf("%u",&size);
		startTimes.clear();
		endTimes.clear();
		for(unsigned int counter = 0;counter < size;counter++){
			scanf("%u",&start);
			startTimes.push_back(start);
		}
		for(unsigned int counter = 0;counter < size;counter++){
			scanf("%u",&end);
			endTimes.push_back(end);
		}
		printMaxOverlappingInterval(startTimes,endTimes);
	}
}

#endif /* HOTEL_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
