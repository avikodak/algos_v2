/****************************************************************************************************************************************************
 *  File Name                   : plgrm.h
 *  File Location               : /home/avikodak/Desktop/projects/algos_v2/src/main/avikodak/sites/codechef/peer/plgrm.h
 *  Created on                  : 21-Sep-2015 :: 9:27:41 pm
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/PLGRM
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
#include <stdint.h>
#include <iomanip>
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

#ifndef PLGRM_H_
#define PLGRM_H_

//Tested
bool isPalindrome(string userInput){
	if(userInput.size() < 2){
		return true;
	}
	unsigned int frontCrawler = 0,rearCrawler = userInput.size()-1;
	while(frontCrawler < rearCrawler){
		if(userInput[frontCrawler] != userInput[rearCrawler]){
			return false;
		}
		frontCrawler++;
		rearCrawler--;
	}
	return true;
}

//Tested
bool isPangram(string userInput){
	if(userInput.size() < 26){
		return false;
	}
	bool flags[26] = {false};
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		flags[userInput[counter]-'a'] = true;
	}
	for(unsigned int counter = 0;counter < 26;counter++){
		if(!flags[counter]){
			return false;
		}
	}
	return true;
}

//Tested
void printResults(){
	unsigned int testCases;
	string userInput;
	bool pangramFlag,palindromeFlag;
	scanf("%u",&testCases);
	while(testCases--){
		cin >> userInput;
		palindromeFlag = isPalindrome(userInput);
		pangramFlag = isPangram(userInput);
		if(palindromeFlag && pangramFlag){
			cout << "palingram" << endl;
		}else if(palindromeFlag){
			cout << "palindrome" << endl;
		}else if(pangramFlag){
			cout << "pangram" << endl;
		}else{
			cout << "none" << endl;
		}
	}
}

#endif /* PLGRM_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
