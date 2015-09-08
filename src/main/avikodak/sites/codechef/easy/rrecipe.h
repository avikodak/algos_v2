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
