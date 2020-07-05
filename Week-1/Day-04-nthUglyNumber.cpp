class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> primes = {2, 3, 5};
        if(primes.size() == 0 or n == 1)  return 1;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        pq.push(1);
        long long prev = -1, mx = INT_MAX;
        while(n--) {
            while(pq.top() == prev) pq.pop();
            cout<<pq.top()<<" ";
            long long t = pq.top();
            for(long long i : primes) {
                long long temp = i*t;
                if(temp > mx)   break;
                pq.push(temp);
            }
            prev = pq.top();
            if(n == 0)  return pq.top();
            pq.pop();
        }
        return pq.top();
    }
};
