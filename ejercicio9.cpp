#include <iostream>
#include <vector>

using namespace std;

template<typename forward>
void sort(vector<int>& cnt, forward first, forward last,int& count) {
	auto beg = first;
        auto end = last;
        auto mid = first + (end-beg)/2;
        auto pivot = *mid;
        int vbeg;
        int vend;
        do{
            vbeg = *beg;
            vend = *end;
            if(vbeg >= pivot && vend <= pivot){
                swap(*beg,*end);
                beg++;
                end--;
		count++;
            }
            if(vbeg < pivot)
                beg++;
            if(vend > pivot)
                end--;
        }while(beg <= end);
        if(first < end)
            sort(cnt,first,end,count);
        if(beg < last)
            sort(cnt,beg,last,count);
}

void swap(int beg, int end) {
        auto temp=beg;
        beg = end;
        end = temp;
    }

int main(){
	int num;
	vector<int> v;
	int count = 0;
	while(num != 0){
		cin >> num;
		v.push_back(num);
	}
	sort(v,v.begin(),v.end()-1,count);
	cout << count;
	
return 0;
}
