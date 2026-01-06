// Problem: 2349. Design a Number Container System (Medium)
// Link: https://leetcode.com/problems/design-a-number-container-system

class NumberContainers {
public:
    unordered_map<int, priority_queue<int, vector<int>, greater<>>> nums;
    unordered_map<int, int> indices;
    
    NumberContainers() {
        nums.clear();
        indices.clear();
    }
    
    void change(int index, int number) {        
        nums[number].push(index);
        indices[index] = number;
    }
    
    int find(int number) {
        if (!nums.contains(number)) return -1;
        while (!nums[number].empty()) {
            int index = nums[number].top();
            if (indices[index] != number) nums[number].pop();
            else return index;
        }
        nums.erase(number);
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */