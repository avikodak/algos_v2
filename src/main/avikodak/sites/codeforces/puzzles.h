/****************************************************************************************************************************************************
 *  File Name                   : puzzles.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codeforces\puzzles.h
 *  Created on                  : Apr 28, 2015 :: 7:44:38 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://codeforces.com/problemset/problem/337/A
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

#ifndef PUZZLES_H_
#define PUZZLES_H_

//Tested
void getMinDifference(){
	unsigned int itemCount,totalStudents,input,frontCrawler= 0,rearCrawler,minDifference = UINT_MAX;
	vector<unsigned int> userInput;
	scanf("%u %u",&totalStudents,&itemCount);
	while(itemCount--){
		scanf("%u",&input);
		userInput.push_back(input);
	}
	sort(userInput.begin(),userInput.end());
	rearCrawler = totalStudents-1;
	while(rearCrawler < userInput.size()){
		minDifference = min(minDifference,userInput[rearCrawler]-userInput[frontCrawler]);
		frontCrawler++;
		rearCrawler++;
	}
	printf("%u",minDifference);
}

#endif /* PUZZLES_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
