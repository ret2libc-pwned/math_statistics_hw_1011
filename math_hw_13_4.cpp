#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

constexpr int number_of_groups = 9;

struct Statistics_Data {
private:
	unordered_map<double, int> count;

public:
	double mean, median;
	vector<double> mode;
	Statistics_Data(const vector<double>& v) {
		for (auto x : v) {
			++count[x];
			mean += x;
		}
		mean /= v.size();
		if (v.size() & 1) {
			median = v[v.size() / 2];
		} else {
			median = (v[v.size() / 2] + v[v.size() / 2 + 1]) / 2;
		}
		int max_y = -1;
		for (auto [x, y] : count)
			max_y = max(max_y, y);
		for (auto [x, y] : count) {
			if (y == max_y) mode.push_back(x);
		}
	}
};

template <typename T> pair<T, T> minmax(const vector<T>& v) {
	return make_pair(*min_element(v.begin(), v.end()), *max_element(v.begin(), v.end()));
}

string interval_string(double l, double r) {
	return "\"[" + to_string(l) + ", " + to_string(r) + ")\"";
}

int main(int argc, const char** argv) {
	string file_name = "data";
	if (argc >= 2) file_name = argv[1];
	ifstream fin(file_name + ".txt"); ofstream fout(file_name + "_result.csv");
	fout << fixed << setprecision(4);
	vector<double> v;
	for (double buf; fin >> buf; ) {
		v.push_back(buf);
	}
	auto dat = Statistics_Data(v);
	fout << "Mean," << dat.mean << ",Median," << dat.median << ",Mode,";
	for (auto x : dat.mode) {
		fout << x << " ";
	}
	fout << "\n\n";
	auto p = minmax(v);
	int left = floor(p.first), right = ceil(p.second);
	double length = 1.00 * (right - left) / number_of_groups;		// 组距
	vector< vector<double> > groups(number_of_groups);
	for (auto x : v) {
		int index = (x - left) / length;
		groups[index].push_back(x);
	}
	for (auto& g : groups)
		sort(g.begin(), g.end());
	fout << "#,Interval,Count,Freq,Datas\n";
	for (int i = 0; i < number_of_groups; ++i) {
		int count = groups[i].size();
		double l = left + i * length, r = l + length;
		fout 	<< i << ","
				<< interval_string(l, r) << ","
				<< count << ","
				<< 1.00 * count / v.size()
				<< ",";
		for (auto x : groups[i]) {
			fout << x << " ";
		}
		fout << endl;
	}
	cout << "Done\n";
	fin.close(); fout.close();
	return 0;
}