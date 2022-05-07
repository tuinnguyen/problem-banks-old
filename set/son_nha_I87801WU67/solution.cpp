#include <bits/stdc++.h>
#define ll long long

using namespace std;

int t;
ll ar[100005];
ll n, w;

void solve() {
	cin >> n >> w;
	vector<ll> c(n + 1);
	c[w] = 1;
	for(int i = w+1; i <= n; ++i) c[i] = c[i - 1] + 1;
	
	set<ll> s;
	for(int i = 0; i < n; ++i) {
		cin >> ar[i];
		if (i == 0) s.insert(0);
		else if (ar[i] != ar[i - 1]) s.insert(i);
	}
	
	int q;
	cin >> q;
	ll ans = 0;
	for (set<ll>::iterator it = s.begin(); it != s.end(); ++it) {
		ll curr = (*it);
		++it;
		ll next;
		if(it == s.end()) next = n;
		else next = (*it);
		--it;
		ans += c[next-curr];
	}

	while (q--) {
		ll po,color;
		cin >> po >> color;
		if (n == 1) {
			cout << c[1] << "\n";
			continue;
		}
		--po;

		if (ar[po] == color) {
			cout << ans << "\n";
			continue;
		}
		
		ll prev = ar[po];
		ar[po] = color;
		if (po == 0 || po == n - 1) {
			if (po == 0) {
				if (ar[po + 1] == ar[po]) {
					auto it = s.upper_bound(po + 1);
					ll l;
					if (it == s.end()) l = n - (po + 1);
					else l = (*it)-(po+1);

					ans -= c[l] + c[1];
					ans += c[l + 1];
					s.erase(po + 1);
					s.insert(po);
				}
				else {
					if (ar[po + 1] == prev) {
						auto it = s.upper_bound(po);
						ll l;
						if (it == s.end()) l = n - (po);
						else l = (*it) - po;

						ans -= c[l];
						ans += c[1] + c[l - 1];
					}

					s.insert(po + 1);
				}
			}
			else {
				if (ar[po - 1] == ar[po]) {
					auto it = s.lower_bound(po);
					--it;
					ll l;
					if (it == s.begin()) l = po;
					else l = po - (*it);

					ans -= c[l] + c[1];
					ans += c[l + 1];
					s.erase(po);
				}
				else {
					if (prev == ar[po - 1]) {
						auto it = s.end();
						--it;
						ll l = n - (*it);

						ans -= c[l];
						ans += c[1] + c[l - 1];
					}

					s.insert(po);
				}	
			}
		}
		else {
			if (ar[po - 1] == ar[po] && ar[po + 1] == ar[po]) {
				auto it = s.lower_bound(po);
				ll l = 0;
				it--;
				ll left = *it;
				it++;
				ans -= c[po - left];
				ans -= c[1];
				l += 1 + (po - left);
				ll right = po + 1;
				++it; 
				++it;
				if (it == s.end()) {
					ans -= c[n - right];
					l += (n - right);
				}
				else {
					ans -= c[(*it) - right];
					l += (*it) - right;
				}
				--it;
				--it;
				ans += c[l];
				s.erase(po);
				s.erase(po + 1);
			}
			else {
				if (ar[po + 1] == ar[po]) {
					auto it = s.lower_bound(po + 1);
					--it;
					if (ar[po - 1] == prev) {
						ans -= c[po + 1 - (*it)];
						ans += c[po - (*it)];	
					}
					else ans -= c[1];
					++it;
					++it;
					if (it == s.end()) {
						ans -= c[n - po - 1];
						ans += c[n - po];
					}
					else {
						ans -= c[(*it) - po - 1];
						ans += c[(*it) - po];
					}
					--it;
					s.erase(po + 1);
					s.insert(po);
				}
				else {
					if (ar[po - 1] == ar[po]) {
						auto it = s.lower_bound(po);
						--it;
						ans -= c[po - (*it)];
						ans += c[po + 1 - (*it)];
						++it;
						++it;
						if (prev == ar[po + 1]) {
							if (it == s.end()) {
								ans -= c[n - po];
								ans += c[n - po - 1];
							}
							else {
								ans -= c[(*it) - po];
								ans += c[(*it) - po - 1];
							}
						}
						else ans -= c[1];
						--it;
						s.erase(po);
						s.insert(po + 1);
					}
					else {
						s.insert(po);
						auto it = s.lower_bound(po);
						--it;
						ll left = *it;
						++it;
						++it;
						ll right;
						if (it == s.end()) right = n;
						else right = *it;
						
						if (prev == ar[po - 1] && prev == ar[po + 1]){
							ans -= c[right - left];
							ans += c[1] + c[po - left] + c[right - po - 1];	
						}
						else {
							if (prev == ar[po - 1]) {
								ans -= c[po + 1 - left];
								ans += c[po - left] + c[1];
							}
							else {
								if (prev == ar[po + 1]) {
									ans -= c[right - po];
									ans += c[right - (po + 1)] + c[1];
								}
							}
						}
						s.insert(po + 1);
					}
				}
			}
		}
		cout << ans << "\n";
	}
}

int main() {
	cin >> t;
	while (t--) {
		solve();
	}	
	return 0;
}
