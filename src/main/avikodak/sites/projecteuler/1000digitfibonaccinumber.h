/****************************************************************************************************************************************************
 *  File Name                   : 1000digitfibonaccinumber.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\projecteuler\1000digitfibonaccinumber.h
 *  Created on                  : Jul 31, 2015 :: 2:17:28 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://projecteuler.net/problem=25
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

#ifndef E1000DIGITFIBONACCINUMBER_H_
#define E1000DIGITFIBONACCINUMBER_H_

//Tested
vector<unsigned int> sum(vector<vector<unsigned int> > userInputs){
	vector<unsigned int> result;
	if(userInputs.size() == 0){
		return result;
	}
	reverse(userInputs[0].begin(),userInputs[0].end());
	result = userInputs[0];
	unsigned int firstCrawler,secondCrawler,sum = 0,carry =0;
	for(unsigned int counter = 1;counter < userInputs.size();counter++){
		reverse(userInputs[counter].begin(),userInputs[counter].end());
		firstCrawler = secondCrawler = carry = 0;
		while(firstCrawler < result.size() && secondCrawler < userInputs[counter].size()){
			sum = result[firstCrawler] + userInputs[counter][secondCrawler] + carry;
			result[firstCrawler] = sum%10;
			firstCrawler++;
			secondCrawler++;
			carry = sum/10;
		}
		while(firstCrawler < result.size()){
			sum = result[firstCrawler] + carry;
			result[firstCrawler] = sum%10;
			carry = sum/10;
			firstCrawler++;
		}
		while(secondCrawler < userInputs[counter].size()){
			sum = userInputs[counter][secondCrawler] + carry;
			result.push_back(sum%10);
			carry = sum/10;
			secondCrawler++;
		}
		while(carry){
			result.push_back(carry%10);
			carry /= 10;
		}
	}
	reverse(result.begin(),result.end());
	return result;
}

//Tested
vector<unsigned int> sum(vector<unsigned int> first,vector<unsigned int> second){
	vector<vector<unsigned int> > userInput;
	userInput.push_back(first);
	userInput.push_back(second);
	return sum(userInput);
}

//Tested
//Ans : 4782
void getIndexFor1000DigitNumber(){
	unsigned int index = 2;
	vector<int> first,second,result;
	first.push_back(1);
	second.push_back(1);
	while(1){
		result = sum(first,second);
		if(result.size() == 1000){
			cout << index << endl;
			return;
		}
		second = first;
		first = result;
		index++;
	}
}

#endif /* 1000DIGITFIBONACCINUMBER_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
