/****************************************************************************************************************************************************
 *  File Name                   : rrecipe.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codechef\easy\rrecipe.h
 *  Created on                  : Sep 6, 2015 :: 10:03:28 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/RRECIPE
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
#define MODN 10000009

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef RRECIPE_H_
#define RRECIPE_H_

//Tested
void totalPossibilities(string userInput){
	int frontCrawler = 0,rearCrawler = userInput.size()-1;
	long long int total = 1;
	while(frontCrawler <= rearCrawler){
		if(userInput[frontCrawler] == '?' ||  userInput[rearCrawler] == '?'){
			if((userInput[frontCrawler] == '?' && userInput[rearCrawler] == '?') || frontCrawler == rearCrawler){
				total *= 26;
				total %= MODN;
			}
		}else if(userInput[frontCrawler] != userInput[rearCrawler]){
			printf("0\n");
			return;
		}
		frontCrawler++;
		rearCrawler--;
	}
	cout << total << endl;
}

//Tested
void printResults(){
	unsigned int testCases;
	scanf("%u",&testCases);
	string userInput;
	while(testCases--){
		cin >> userInput;
		totalPossibilities(userInput);
	}
}

#endif /* RRECIPE_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
