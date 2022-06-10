class RandomizedSet {
private:
    unordered_map<int, int> index;
    vector<int> nums;
public:
    RandomizedSet() {
        srand(time(0));
    }
    
    bool insert(int val) {
        if(index.count(val))
            return false;
        index[val] = nums.size();
        nums.emplace_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(!index.count(val))
            return false;
        index[nums[nums.size()-1]] = index[val];
        swap(nums[index[val]], nums[nums.size()-1]);
        nums.pop_back();
        index.erase(val);
        return true;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
