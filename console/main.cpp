#include <cstdlib>
#include <iostream>
#include <time.h>
#include <vector>

// inclusive
int rand_range(int min, int max){
	return min + (rand() % (max-min + 1));
}

class RandListHolder{
	private:
		std::vector<std::vector<int>> roll_results;
	public:
		void run_roll();
		void run_multiple_rolls(unsigned int n);
		void print_result(unsigned int i);
		void print_all_results();
		int count_number(int n);
};

void RandListHolder::run_roll(){
	std::vector<int> roll_result;
	roll_result.resize(6);
	for (int i=0; i<6; i++){
		roll_result[i] = rand_range(1, 49);
	}
	roll_results.push_back(roll_result);
}
void RandListHolder::run_multiple_rolls(unsigned int n){
	for (int i=0; i<n; i++){
		run_roll();
	}
}
void RandListHolder::print_result(unsigned int i){
	if(i>=roll_results.size()){
		std::cout<<"Nie da się wyświetlić rezultatu, który nie został jeszcze wygenerowany"<<std::endl;
		return;
	}
	for (int j=0; j<6; j++){
		std::cout<<roll_results[i][j]<<" ";
	}
	std::cout<<std::endl;
}
void RandListHolder::print_all_results(){
	std::cout<<"Zestawy wylosowanych liczb:"<<std::endl;
	for(int i=0; i<roll_results.size(); i++){
		std::cout<<"Losowanie "<<i+1<<": ";
		print_result(i);
	}
}
int RandListHolder::count_number(int n){
	int counter = 0;
	for (int i=0; i<roll_results.size(); i++){
		for (int j=0; j<roll_results[i].size(); j++){
			if(roll_results[i][j] == n){
				counter += 1;
			}
		}
	}
	return counter;
}


int main(){
	srand(time(0));
	
	std::cout<<"Ile wygenerować losowań?"<<std::endl;
	int rolls;
	std::cin>>rolls;

	RandListHolder roll_holder;
	roll_holder.run_multiple_rolls(rolls);
	roll_holder.print_all_results();
	for (int i=1; i<50; i++){
		std::cout<<"Wystąpienia liczby "<<i<<": "<<roll_holder.count_number(i)<<std::endl;
	}

	return 0;
}
