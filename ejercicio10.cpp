#include <iostream>
#include <set>

using namespace std;

int main()
{
    int numDays;
    
    while (cin >> numDays, numDays)
    {
        multiset<int> elem;
        
        long long sum = 0;
        
        while (numDays--)
        {
            int k;
            cin >> k;
            
            while (k--)
            {
                int t;
                cin >> t;
                
                elem.insert(t);
            }
            
            auto lowIt = elem.begin();
            auto highIt= --elem.end();
            
            
            sum += *highIt - *lowIt;
            
            elem.erase(lowIt); elem.erase(highIt);
        }
        
        cout << sum << '\n';
    }
}
