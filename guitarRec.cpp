#include <iostream>
#include <vector>
#include <algorithm> 
#include <iterator>

using namespace std;

class pickGuitar{
	private:
		vector<int> find_n_del_max(vector <int> val, int *max){
			
			vector<int>::iterator first = val.begin();
			vector<int>::iterator last = val.end();
			int id;
			
			*max = *max_element(first, last);
			
			id = distance(first, max_element(first, last));
			
			cout << "id: " << id <<endl;
			
			val.erase(val.begin()+id);
			
			return val;
		}
		int get_max(vector <int> val){
			vector<int>::iterator first = val.begin();
			vector<int>::iterator last = val.end();
			
			max = *max_element(first, last);
			return max;
		}
	public:
		int maxValue(vector <int> val){
		
			int plMax=0, enMax=0, sz;
			
			int max, id;
			
			size_t half_size;

			//int first=0, last= sz-1;
			//cout << "first: " << first <<endl <<"last: "<< last << endl;
			if(val.empty()) return 0;
			
			if(sz==1){
				//cout <<"Get Max: " << *max_element(val.begin(), val.end())<< endl;
				//val = find_n_del_max(val, &max);
				
				max = get_max(val);
				
				return max;
			}
			else{
				//get max and delete elment
//				val = find_n_del_max(val, &max);
//				plMax = max;
//				val = find_n_del_max(val, &max);
//				enMax = max;
				//split element
				sz = val.size();
				
				half_size = sz/2;
				
				cout << "Size: " << sz << endl << "half size: " << half_size << endl;
				vector<int> split_lo(val.begin(), val.begin() + half_size);

				vector<int> split_hi(val.begin() + half_size, val.end());
				
				//rest
				plMax += maxValue(split_lo) + maxValue(split_hi); 
				enMax += maxValue(split_lo) + maxValue(split_hi);
			}
			
			return plMax-enMax;
		}
}; 


int main(){
	
	pickGuitar git; // class pickguitar yang birisi fungsi maxValue
	
	vector <int> vec; // untuk menyimpan input sebagai list / vector
	
	int in; // input
	int hasil;// ootput
	
	while(cin>>in){
		if(in<1) break;
		vec.push_back(in);
	}
	
	cout << "Size: " <<vec.size() << endl;
	hasil = git.maxValue(vec);
	cout << "Hasil: " << hasil << endl;
}
