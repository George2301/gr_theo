//https://leetcode.com/problems/top-k-frequent-elements/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
	unordered_map<int, int> frequency;
	for (auto num : nums) {
		++ frequency[num];
	}

	vector<pair<int, int>> freq_items;
	for (auto item : frequency) {
		freq_items.push_back(make_pair(item.second, item.first));
	}

	vector<int> result;
	make_heap(freq_items.begin(), freq_items.end());
	for (int i = 0; i < k; ++ i) {
		result.push_back(freq_items.front().second);
		pop_heap(freq_items.begin(), freq_items.end());
		freq_items.pop_back();
	}

	return result;
	}
};