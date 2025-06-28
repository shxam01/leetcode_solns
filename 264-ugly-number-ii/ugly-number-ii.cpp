class Solution {
public:
    const int N = 1690;
    vector<int> vec;

    void helper() {
        vec.push_back(1);
        int i2=0;
        int i3=0;
        int i5=0;

        for(int i=1;i<N;i++){
            int next2=vec[i2]*2;
            int next3=vec[i3]*3;
            int next5=vec[i5]*5;
            int next_ugly=min(next2,min(next3,next5));
            if(next2==next_ugly) i2++;
            if(next3==next_ugly) i3++;
            if(next5==next_ugly) i5++;
            vec.push_back(next_ugly);
        }
    }

    int nthUglyNumber(int n) {
        if (vec.empty()) helper();
        return vec[n - 1];
    }
};