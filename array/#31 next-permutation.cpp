class Solution {
public:
    void nextPermutation(vector<int> &num) {
        nextPermutation(num.begin(), num.end());
    }
    
private:
    template<typename Type>
    bool nextPermutation(Type begin, Type end) {
        const auto rbegin = reverse_iterator<Type>(end);
        const auto rend   = reverse_iterator<Type>(begin);
        
        // Find the first element (pivot) which is less than its successor.
        auto pivot = next(rbegin);
        while (pivot != rend && *pivot >= *prev(pivot))
            ++pivot;

        bool greater = true;
        if (pivot != rend) {
            // Find the number which is greater than pivot, and swap it with pivot
            auto change = find_if(rbegin, pivot, bind1st(less<int>(), *pivot));
            swap(*change, *pivot);
        }
        else
            greater = false;
        
        // Make the sequence after pivot non-descending
        reverse(rbegin, pivot);
        
        return greater;
    }
};