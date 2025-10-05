class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0;

        int n=height.size();

        int i=0;
        int j=n-1;

        while(i<j){
            int w=j-i;
            int h=min(height[i],height[j]);
            int area=w*h;

            ans=max(ans,area);

            if(height[i]>height[j]){
                j--;
            }else{
                i++;
            }
        }
        return ans;
    }
};