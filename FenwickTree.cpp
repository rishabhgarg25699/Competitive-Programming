#include <iostream>
#include <vector>

template <typename T>
class FenwickTree {
	private:
		int n;
		std::vector<T> bit;
	public:
		FenwickTree(int n) {
			this -> n = n;
			bit = std::vector<T>(n+1);
		}

		void update(int x, T delta) {
			for(; x <= n; x += x & -x) {
				bit[x] += delta;
			}
		}

		T query(int x) {
			T res = 0;
			for(; x > 0; x -= x & -x) {
				res += bit[x];
			}
			return res;
		}

		T query_range(int l, int r) {
			return query(r) - query(l-1);
		}
};

int main() {
    // creating FenwickTree object for index from 1 to 10 and type integers;
    FenwickTree<int> ft(10);
    
    //updates
    ft.update(3, 5);
    ft.update(4, 1);
    ft.update(7, 2);
    
    //query in range
    std::cout << ft.query_range(3, 7) <<'\n';
    std::cout << ft.query_range(4, 6) <<'\n';
    
    return 0;
}
