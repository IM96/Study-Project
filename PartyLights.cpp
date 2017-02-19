/*Po the Panda will have his birthday next week. 
He plans to throw a party in his house. 
Due to a lot of works have to be taken care, 
Po asks for help from some people, one of them is Gladya. 
Gladya is assigned to make discotic style party lights, 
but she is too lazy, so she only prepares N lights (numbered from 1 to N) with 
different colors and 4 switches (numbered from 1 to 4) to turn on or off N lights during the party.

Here is the configuration of each switch : 
If switch 1 is pressed, then all lights will be switched from on to off, and off to on
If switch 2 is pressed, then all lights which index is odd will be switched from on to off, and off to on
If switch 3 is pressed, then all lights which index is even will be switched from on to off, and off to on 
If switch 4 is pressed, then all lights which index is 3K + 1 (1 <= 3K+1 = N) will be switched from on to off, and off to on
One day before the party, all lights from index 1 to N are turned on. Gladya is wondering about all possible resulting light configurations after she presses the switches C times. For each time, Gladya will randomly choose a switch to press. On the final configuration, she wants some light to be turned on and some to be turned off.

Input
The first line consists of an integer T (T = 100) - the number of cases.
Each test case consists of 4 lines.
The first line consists of two integers N and C (1 = N = 100, 1 = C = 1000) - the number of lights and the number of times Gladya presses the switch.
The second line consists of an integer A (0 = A = N) - the number of lights which should be turned on at the end of the party, followed by A integers Xi (1 = Xi = N, Xi is unique).
The third line consists of an integer B (0 = B = N) - the number of lights which should be turned off at the end of the party, followed by B integers Yi (1 = Yi = N, Yi is unique). It is guaranteed that no Xi is equal to Yi

Output
For each test case, output consists of several lines starting with 
"Kasus K:" (without quotes) where K is the test case number starting from 1. 
Followed by some lines, each of which contains a string S which consists of only '1' or '0', 
where Si means the i-th light is on or off. 
Output all possibilities in lexicographically ascending order. 
(It is guaranteed that each test case has at least an answer)

Sample Input
1
10 1
0
1 7

Sample Output
Kasus 1:
0000000000
0101010101
0110110110

*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <bitset>
#include <string>


using namespace std;

bitset<1> on (string("1"));
bitset<1> off (string("0"));
bitset <100> even (std::string("1010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010"));
bitset <100> odd (std::string("0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101"));


class partyLights{
	public:
		bitset< 100 > lights;
		partyLights(int n, int nPencet){	
			// inisialisasi bit lampu
			nLights = n;
			//lights = bitset<nLights>{}.set();
			lights.set();
			
			return;
		}
			
		void pencet(int nPencet, int status, vector <int> idOn, vector <int> idOff){
					
			// Base case
			if(nPencet<0){
				// check if bit in idOn is true
				for(int iter=0; iter<idOn.size(); iter++){
					if( (lights[100-idOn[iter]] != on) || (lights[100-idOff[iter]] != off) ) return;
				}
				// check if bit in idOff is false
				/*for(int iter=0; iter<idOn.size(); iter++){
					if( (lights[100-idOff[iter]] != off) ) return;
				}*/
				
				// check if bits alredy in list
				if(lights in ans) return;
				// if no add it to ans
				ans.push_back(lights);
				return;
			}
			pencet(nPencet-1, 1, idOn, idOff);
			pencet(nPencet-1, 2, idOn, idOff);
			pencet(nPencet-1, 3, idOn, idOff);
			pencet(nPencet-1, 4, idOn, idOff);
			switch(status){
			
				case 1:
					//flip all bits
					lights.flip();
					break;
				case 2:
					// flip bits in index odd index [1 ... N] 
					(lights^=even); 
					break;
				case 3:
					// flip bits in idex even index [1 .. N]
					(lights^=odd);
					break;
				case 4:
					// file bits in index 3K + 1 (1 <= 3K+1 <= N) index [1 .. N]
					switch4();
					break;
			}
		}
		
		void printAns(){
			sort(ans.begin(), ans.end());
			for(int iter=0; iter<ans.size(); iter++){
				cout << ans[iter];
			}
		}
	private:
		int nLights;
		vector< bitset<100> > ans;	
		
		int idToFlip[33] = {99, 96, 93, 90, 87, 84, 81, 78, 75, 72, 69, 66, 63, 60, 57, 54, 51, 48, 45, 42, 39, 36, 33, 30, 27, 24, 21, 18, 15, 12, 9, 6, 3};
		int nToFlip =33;
		
		void switch4(){
			for(int iter=0; iter<nToFlip; iter++){
				lights.flip(idToFlip[iter]);
			}					
			return;
		}
};

int main(){
	int testCase, nLights, nPress;
	int nOn, nOff;
	vector <int> idOn, idOff;
	
	cin >> testCase >> nLights>> nPress;
	
	cin >> nOn;
	if(nOn>0){
		for(int iter=0; iter<nOn; iter++){
			cin >> idOn[iter];
			//idOn[iter]-=1;
		}
	}
	cin >> nOff;
	if (nOff>0) {
		for(int iter=0; iter<nOn; iter++){
			cin >> idOff[iter];
			//idOff[iter]-=1;
		}
	}
	
	partyLights pandaOj(nLights, nPress, idOn, idOff);
	pandaOj.pencet(nPencet, 1, idOn, idOff);
	pandaOj.pencet(nPencet, 2, idOn, idOff);
	pandaOj.pencet(nPencet, 3, idOn, idOff);
	pandaOj.pencet(nPencet, 4, idOn, idOff);
	pandaOj.printAns();
		
	return 0;	
}
