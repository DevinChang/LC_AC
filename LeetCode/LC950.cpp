class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
		int n = deck.size();
		sort(deck.begin(), deck.end());
		queue<int> q;
		for(int i = 0; i < n; i++) q.push(i);
		vector<int> res(n);
		int k = 0;
		while(q.size()){
			auto t = q.front();
			q.pop();
			res[t] = deck[k++];
			if(q.size()) {
				q.push(q.front());
				q.pop();
			}
		}
		return res;
	}
};