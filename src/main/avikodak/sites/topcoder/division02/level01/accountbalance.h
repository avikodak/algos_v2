/****************************************************************************************************************************************************
 *  File Name   		: accountbalance.h 
 *  File Location		: D:\projects\cpp\algos_v2\src\main\avikodak\sites\topcoder\division02\level01\accountbalance.h
 *  Created on			: Mar 28, 2015 :: 12:49:39 PM
 *  Author				: avikodak
 *  Testing Status 		: Tested
 *  URL 				: http://community.topcoder.com/stat?c=problem_statement&pm=6036
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

#ifndef ACCOUNTBALANCE_H_
#define ACCOUNTBALANCE_H_

//Tested
class AccountBalance{
private:
	vector<string> splitString(string userInput,char delimiter){
		vector<string> result;
		istringstream f(userInput);
		string s;
		while (getline(f, s, delimiter)) {
			result.push_back(s);
		}
		f.str("");
		return result;
	}

	int convertStringToInt(string userInput){
		if(userInput.size() == 0){
			return 0;
		}
		int number = 0;
		for(unsigned int counter = 0;counter < userInput.size();counter++){
			number = (number << 3) + (number << 1) + (userInput[counter] - '0');
		}
		return number;
	}
public:
	int processTransactions(int balance, vector<string> transactions){
		for(unsigned int counter = 0;counter < transactions.size();counter++){
			if(transactions[counter][0] == 'C'){
				balance += convertStringToInt(splitString(transactions[counter],' ')[1]);
			}else{
				balance -= convertStringToInt(splitString(transactions[counter],' ')[1]);
			}
		}
		return balance;
	}
};


#endif /* ACCOUNTBALANCE_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
