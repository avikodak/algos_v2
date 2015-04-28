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
