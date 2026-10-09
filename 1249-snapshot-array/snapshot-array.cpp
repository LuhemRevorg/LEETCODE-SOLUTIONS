class SnapshotArray {
    int snap_idx;
    std::vector<std::vector<int>> snapchat;
    
public:
    SnapshotArray(int length): snap_idx(0) {
        snapchat = std::vector<std::vector<int>>(length, std::vector<int>(1,0));
    }
    
    void set(int index, int val) {
        auto &vec = snapchat[index];
        if ((int)vec.size() <= snap_idx) vec.resize(snap_idx + 1, vec.back());
        vec[snap_idx] = val;
    }
    
    int snap() {
        ++snap_idx;
        return snap_idx - 1;
    }
    
    int get(int index, int snap_id) {
        auto &vec = snapchat[index];
        if (vec.size() <= snap_id) {
            return vec.back();
        }
        return vec[snap_id];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
