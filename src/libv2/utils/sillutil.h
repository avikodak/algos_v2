/****************************************************************************************************************************************************
 *  File Name                   : sillutil.h
 *  File Location               : /algos_v2/src/libv2/utils/sillutil.h
 *  Created on                  : Jan 18, 2016 :: 8:31:04 PM
 *  Author                      : avikodak
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
#include <libv2/constants/constants.h>
#include <libv2/ds/commonds.h>
#include <libv2/ds/graphds.h>
#include <libv2/ds/linkedlistds.h>
#include <libv2/ds/mathds.h>
#include <libv2/ds/treeds.h>
#include <libv2/ds/linkedlistds.h>

/****************************************************************************************************************************************************/
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef LIBV2_UTILS_SILLUTIL_H_
#define LIBV2_UTILS_SILLUTIL_H_

class sillutil{
private:
public:
	sillNode *getSill(vector<int> userInput){
		if(userInput.size() == 0){
			return null;
		}
		sillNode *head = new sillNode(userInput[0]),*crawler = head;
		for(unsigned int counter = 1;counter < userInput.size();counter++){
			crawler->next = new sillNode(userInput[counter]);
			crawler = crawler->next;
		}
		return head;
	}

	unsigned int getLength(sillNode *ptr){
		if(ptr == null){
			return 0;
		}
		unsigned int length = 0;
		while(ptr != null){
			length++;
			ptr = ptr->next;
		}
		return length;
	}

	void print(sillNode *ptr){
		while(ptr != null){
			printf("%d\t",ptr->value);
			ptr = ptr->next;
		}
	}

};

#endif /* LIBV2_UTILS_SILLUTIL_H_ */
