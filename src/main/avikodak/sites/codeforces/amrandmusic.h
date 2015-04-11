/****************************************************************************************************************************************************
 *  File Name                   : amrandmusic.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codeforces\amrandmusic.h
 *  Created on                  : Apr 11, 2015 :: 7:51:59 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://codeforces.com/problemset/problem/507/A
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

#ifndef AMRANDMUSIC_H_
#define AMRANDMUSIC_H_

//Tested
struct valIndex{
public:
	unsigned int value;
	unsigned int index;

	valIndex(unsigned int value,unsigned int index){
		this->value = value;
		this->index = index;
	}
};

//Tested
bool compare(valIndex *first,valIndex *second){
	return first->value < second->value;
}

//Tested
void printInstruments(){
	unsigned int totalDays,instrumentsCount,days;
	scanf("%u %u",&instrumentsCount,&totalDays);
	vector<valIndex *> userInput;
	valIndex *temp;
	for(unsigned int counter = 0;counter < instrumentsCount;counter++){
		scanf("%u",&days);
		temp = new valIndex(days,counter+1);
		userInput.push_back(temp);
	}
	sort(userInput.begin(),userInput.end(),compare);
	queue<unsigned int> result;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(totalDays >= userInput[counter]->value){
			result.push(userInput[counter]->index);
			totalDays -= userInput[counter]->value;
		}else{
			break;
		}
	}
	printf("%u\n",result.size());
	while(!result.empty()){
		printf("%u ",result.front());
		result.pop();
	}
}

#endif /* AMRANDMUSIC_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
