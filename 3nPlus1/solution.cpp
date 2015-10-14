#include <iostream>
#include <limits>
using namespace std;

int read_i(){
  int i = 0;
  cin >> i;
  return i;
}

int read_j(){
  int j = 0;
  cin >> j;
  return j;
}

int get_max_cycle(int i, int j){
  int max_cycles = numeric_limits<int>::min();
  int n = 0;
  int cycles = 1; //need to start with 1

  for (int k = i; k <= j; k++) {
    n = k;
    cycles = 1;
    while(n != 1){
      if( n % 2 == 0){ // even
        n = n / 2;
      }else{ //odd
        n = n * 3 + 1;
      }
      cycles++;
    }
    printf("Cycles for %i: %i\n",k,cycles);
    if(cycles > max_cycles){
      max_cycles = cycles;
    }
  }
  return max_cycles;
}

int main() {

  cout << "Please enter inputs:\n";
  int i = read_i();
  int j = read_j();

  if((i<0) || (j<0) || (j>1000000) || (i>1000000) || (i>j)){
    cout << "Invalid inputs!\n";
    return 1;
  }

  int max_cycle = get_max_cycle(i,j);

  printf("%i %i %i\n", i,j, max_cycle);

  return 0;
}
