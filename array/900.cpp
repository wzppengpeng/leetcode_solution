class RLEIterator {
public:
    RLEIterator(vector<int> A) {
        for(size_t i = 0; i < A.size(); i += 2) {
            int num = A[i], val = A[i + 1];
            if(num > 0) {
                data_.emplace_back(val);
                count_.emplace_back(num);
            }
        }
        pos_ = 0;
        inner_pos_ = 0;
    }

    int next(int n) {
        if(pos_ >= data_.size()) return -1;
        while(pos_ < data_.size() && count_[pos_] - inner_pos_ < n) {
            n -= (count_[pos_] - inner_pos_);
            ++pos_;
            inner_pos_ = 0;
        }
        if(pos_ >= data_.size()) return -1;
        inner_pos_ += n;
        return data_[pos_];
    }


private:
    std::vector<int> data_;
    std::vector<int> count_;

    int pos_;
    int inner_pos_ = 0;
};