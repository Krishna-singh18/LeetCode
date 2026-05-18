class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int l=0;
        int r=n-1;
        int ans=0;

        while(l<r){
            int hei=min(height[l],height[r]);
            int width=r-l;
            int area=hei*width;

            ans=max(ans,area);

            if(height[l]<height[r]){
                l++;
            }
            else{
                r--;
            }
            
        }
        return ans;
    }
};