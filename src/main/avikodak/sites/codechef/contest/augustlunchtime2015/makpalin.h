/****************************************************************************************************************************************************
 *  File Name                   : makpalin.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codechef\contest\augustlunchtime2015\makpalin.h
 *  Created on                  : Aug 30, 2015 :: 11:15:20 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/LTIME27/problems/MAKPALIN
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

#ifndef MAKPALIN_H_
#define MAKPALIN_H_

//Tested
bool isPalindrome(string userInput){
	unsigned long int frontCrawler = 0,rearCrawler = userInput.size()-1;
	while(frontCrawler < rearCrawler){
		if(userInput[frontCrawler] != userInput[rearCrawler]){
			if(userInput[frontCrawler] != '?' && userInput[rearCrawler] != '?'){
				return false;
			}
		}
		frontCrawler++;
		rearCrawler--;
	}
	return true;
}

//Tested
void printTotalPossiblePalindrome(string userInput){
	unsigned long int total = 0;
	for(unsigned long int counter = 0;counter <= userInput.size();counter++){
		userInput.insert(counter,1,'?');
		if(isPalindrome(userInput)){
			total++;
		}
		userInput.erase(counter,1);
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
		printTotalPossiblePalindrome(userInput);
	}
}

#endif /* MAKPALIN_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
