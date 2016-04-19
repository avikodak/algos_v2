/****************************************************************************************************************************************************
 *  File Name                   : chode.h
 *  File Location               : /home/avikodak/Desktop/projects/algos_v2/src/main/avikodak/sites/codechef/easy/chode.h
 *  Created on                  : 31-Oct-2015 :: 3:28:16 pm
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : https://www.codechef.com/problems/CHODE
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

#ifndef CHODE_H_
#define CHODE_H_

struct chRankFreq {
    char ch;
    unsigned int rank;
    unsigned int frequency;

    chRankFreq(char ch,unsigned int rank,unsigned int frequency) {
        this->ch = ch;
        this->rank = rank;
        this->frequency = frequency;
    }
};

bool sortFunc(chRankFreq *first,chRankFreq *second) {
    if(first->frequency == second->frequency) {
        return first->rank > second->rank;
    } else {
        return first->frequency > second->frequency;
    }
}

void printResults() {
    unsigned int testCases;
    string userInput,encryptedText;
    char ch;
    scanf("%u",&testCases);
    getline(cin,userInput);
    while(testCases--) {
        getline(cin,userInput);
        map<char,unsigned int> charRankMap;
        map<unsigned int,char> rankEncryptCharMap;
        map<char,unsigned int> charRankInputTextMap;
        map<char,chRankFreq *> charFrequencyMap;
        map<char,chRankFreq *>::iterator itToCharFrequencyMap;
        vector<chRankFreq *> charFrequencies;
        for(unsigned long long int counter = 0; counter < userInput.size(); counter++) {
            rankEncryptCharMap[counter] = userInput[counter];
        }
        getline(cin,encryptedText);
        unsigned int rankCounter = 0;
        for(unsigned long long int counter = 0; counter < encryptedText.size(); counter++) {
            ch = encryptedText[counter];
            if(ch >= 'A' && ch <= 'Z') {
                ch = ch -'A' +'a';
            }
            if(ch >= 'a' && ch <= 'z') {
                if(charFrequencyMap.find(ch) == charFrequencyMap.end()) {
                    charRankMap[ch] = rankCounter++;
                    charFrequencyMap[ch] = new chRankFreq(ch,charRankMap.find(ch)->second,1);
                } else {
                    charFrequencyMap[ch]->frequency++;
                }
            }
        }
        for(itToCharFrequencyMap = charFrequencyMap.begin(); itToCharFrequencyMap != charFrequencyMap.end(); itToCharFrequencyMap++) {
            charFrequencies.push_back(itToCharFrequencyMap->second);
        }
        sort(charFrequencies.begin(),charFrequencies.end(),sortFunc);
        string decodedText;
        for(unsigned long long int counter = 0; counter < charFrequencies.size(); counter++) {
            decodedText.push_back(charFrequencies[counter]->ch);
            charRankInputTextMap[charFrequencies[counter]->ch] = counter;
        }
        for(unsigned long long int counter = 0; counter < encryptedText.size(); counter++) {
            ch = encryptedText[counter];
            if(ch >= 'A' && ch <= 'Z') {
                ch = ch - 'A' + 'a';
                printf("%c",rankEncryptCharMap[26-1-charRankInputTextMap[ch]]-'a'+'A');
            } else if(ch >= 'a' && ch <= 'z') {
                printf("%c",rankEncryptCharMap[26-charRankInputTextMap[ch]-1]);
            } else {
                printf("%c",encryptedText[counter]);
            }
        }
        printf("\n");
    }
}

#endif /* CHODE_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
