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
