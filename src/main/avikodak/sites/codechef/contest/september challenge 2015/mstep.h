/****************************************************************************************************************************************************
 *  File Name                   : mstep.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codechef\contest\september challenge 2015\mstep.h
 *  Created on                  : Sep 6, 2015 :: 1:36:26 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/SEPT15/problems/MSTEP
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

#ifndef MSTEP_H_
#define MSTEP_H_

//Tested
struct rowColumn {
	int row;
	int column;

	rowColumn(){}

	rowColumn(int row,int column){
		this->row = row;
		this->column = column;
	}
};

//Tested
void calTotalSteps(map<unsigned int,rowColumn *> valuePositionMap,unsigned int size){
	rowColumn *ptr = valuePositionMap.find(1)->second;
	int rowCrawler = ptr->row,columnCrawler = ptr->column;
	unsigned int totalSteps = 0;
	unsigned int limit = size * size;
	for(unsigned int counter = 2;counter <= limit;counter++){
		ptr = valuePositionMap.find(counter)->second;
		totalSteps += abs(rowCrawler - ptr->row) + abs(columnCrawler - ptr->column);
		rowCrawler = ptr->row;
		columnCrawler = ptr->column;
	}
	cout << totalSteps << endl;
}

//Tested
void printResults() {
	unsigned int testCases,input;
	int size;
	scanf("%u", &testCases);
	map<unsigned int,rowColumn *> valuePositionMap;
	while(testCases--) {
		valuePositionMap.clear();
		scanf("%u",&size);
		for(int rowCounter = 1;rowCounter <= size;rowCounter++){
			for(int columnCounter = 1;columnCounter <= size;columnCounter++){
				scanf("%u",&input);
				valuePositionMap.insert(pair<unsigned int,rowColumn *>(input,new rowColumn(rowCounter,columnCounter)));
			}
		}
		calTotalSteps(valuePositionMap,size);
	}
}


#endif /* MSTEP_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
