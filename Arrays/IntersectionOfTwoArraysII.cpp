class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> intersections;
        vector<int> finalVector;
        
        for(const auto &x : nums1){
            if (intersections.count(x) > 0){
                intersections[x]++;
            }
            else{
                intersections[x] = 1;
            }
        }
        
        for(const auto &x : nums2){
            if (intersections.count(x) > 0){
                if(intersections[x] > 0){
                    intersections[x]--;
                    finalVector.push_back(x);
                }
            }
        }
        
        return finalVector;
    }
};


# Follow up questions: If the arrays are sorted?

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> finalVector;
        auto fst = nums1.begin(), snd = nums2.begin();
        
        while(fst != nums1.end() && snd != nums2.end()){
            if(*fst > *snd){
                snd++;
            }
            else if (*fst < *snd){
                fst++;
            }
            else{
                finalVector.push_back(*fst);
                fst++;
                snd++;
            }
        }
        
        return finalVector;
    }
};

