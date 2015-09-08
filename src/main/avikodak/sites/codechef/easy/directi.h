/****************************************************************************************************************************************************
 *  File Name                   : directi.h
 *  File Location               : /home/avikodak/eclipse_ws/algos/algos/src/main/avikodak/sites/codechef/easy/directi.h
 *  Created on                  : 08-Sep-2015 :: 9:55:22 pm
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/DIRECTI
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

#ifndef DIRECTI_H_
#define DIRECTI_H_

//Tested
void reverseDirections(){
	unsigned int size;
	scanf("%u",&size);
	string userInput;
	getline(cin,userInput);
	stack<string> place,direction;
	while(size--){
		getline(cin,userInput);
		if(userInput[0] == 'B'||userInput[0] == 'b'){
			place.push(userInput.substr(9));
		}else if(userInput[0] == 'L' || userInput[0] == 'l'){
			place.push(userInput.substr(8));
			direction.push("Right on ");
		}else if(userInput[0] == 'R' || userInput[0] == 'r'){
			place.push(userInput.substr(9));
			direction.push("Left on ");
		}
	}
	cout << "Begin on " << place.top() << endl;
	place.pop();
	while(!place.empty()){
		cout << direction.top() << place.top() << endl;
		place.pop();
		direction.pop();
	}
}

//Tested
void printResults(){
	unsigned int testCases;
	scanf("%u",&testCases);
	while(testCases--){
		reverseDirections();
	}
}

#endif /* DIRECTI_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
