#include "../includes/Matrix.hpp"

int main()
{
	vector<vector <int> > as = {{0, 1},
								{1, 2},
								{3, 1}};
	vector<vector <int>	> bs =  {{3, 2},
								{5, 3}};
	Matrix<int> a(as);
	Matrix<int> b(bs);
	a.showMatrix();
	cout << endl;
	a = a.transpose();
	a.showMatrix();
}
