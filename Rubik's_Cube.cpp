// six faces of cube FRONT(F), BACK(B), UP(U), DOWN(U), LEFT(L) and RIGHT(R)
// R: 90 degree clockwise rotation of the right face
// R': 90 degree anticlockwise rotation of the right face
// R2: 180 degree rotation of the right face
// BLF2: rotating the back face by 90 degrees clockwise, then the left face
//       by 90 degrees clockwise followed by the front face by 180 degrees.

/* To find out the number of times the sequence should 
 be applied repeatedly to the cube to get back the original cube*/

#include<bits/stdc++.h>
using namespace std;
int state[55];

void rotate(int a, int b, int c, int d){
	int temp = state[d];
	state[d] = state[c];
	state[c] = state[b];
	state[b] = state[a];
	state[a] = temp;
}

long long gcd(long long a, long long b)
{
	if (a == 0)
		return b;
	if (b == 0)
		return a;
	if (a == 1 or b == 1)
		return 1;
	if (a == b)
		return a;
	
	if (a > b)
		return gcd(b, a%b);
	else
		return gcd(a, b%a);
}

void Permute(char code){
	switch(code){
		case 'U':{
			rotate(19, 21, 27, 25);
			rotate(20, 24, 26, 22);
			rotate(7, 28, 39, 18);
			rotate(8, 31, 38, 15);
			rotate(9, 34, 37, 12);
			break;
		}
		case 'D':{
			rotate(46, 48, 54, 52);
			rotate(47, 51, 53, 49);
			rotate(43, 36, 3, 10);
			rotate(44, 33, 2, 13);
			rotate(45, 30, 1, 16);
			break;
		}
		case 'F':{
			rotate(37, 39, 45, 43);
			rotate(38, 42, 44, 40);
			rotate(25, 34, 48, 16);
			rotate(26, 35, 47, 17);
			rotate(27, 36, 46, 18);
			break;
		}
		case 'B':{
			rotate(1, 3, 9, 7);
			rotate(2, 6, 8, 4);
			rotate(19, 10, 54, 28);
			rotate(20, 11, 53, 29);
			rotate(21, 12, 52, 30);
			break;
		}
		case 'L':{
			rotate(10, 12, 18, 16);
			rotate(11, 15, 17, 13);
			rotate(1, 19, 37, 46);
			rotate(4, 22, 40, 49);
			rotate(7, 25, 43, 52);
			break;
		}
		case 'R':{
			rotate(28, 30, 36, 34);
			rotate(29, 33, 35, 31);
			rotate(48, 39, 21, 3);
			rotate(51, 42, 24, 6);
			rotate(54, 45, 27, 9);
			break;
		}
	}
}

long long lcm(long long a, long long b){
	if (a == 1)
		return b;
	if (b == 1)
		return a;
	if (a == b)
		return a;
	return (a/gcd(a, b))*b;
}

int main ()
{
	int i, j, temp;
	long long moves, cycle_len;
	char input[1010], code;
	bool seen[55];
	for (i=1; i<=54; i++){
		state[i] = i;
		seen[i] = false;
	}
	scanf("%s", input);
	i = 0;
	while (input[i] != '\0'){
		code = input[i];
		if (input[i+1] != '\'' and input[i+1] != '2'){
			Permute(code);
			i++;
		}
		else{
			Permute(code);
			Permute(code);
			if (input[i+1] == '\'')
				Permute(code);
			i += 2;
		}
	}
	moves = 1;
	for (i=1; i<=54; i++){
		if (seen[i])
			continue;
		seen[i] = true;
		cycle_len = 1;
		temp = i;
		j = state[i];
		while (temp != j){
			j = state[j];
			seen[j] = true;
			cycle_len++;
		}
		moves = lcm(moves, cycle_len);
	}
	printf("%lld\n", moves);
	return 0;
}
