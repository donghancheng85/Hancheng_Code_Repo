#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

class SnapshotArray
{
public:
    // members
    std::size_t size;
    std::size_t snapId{0};
    std::vector<int> array;
    std::unordered_map<std::size_t, std::unordered_map<std::size_t, int>> snapshots{};
    std::pair<std::size_t, int> tempSnap{};

    // constructor
    explicit SnapshotArray(std::size_t length) : size{length}, array(size, 0)
    {
    }
    // Function setValue sets the value at a given index idx to val.
    void SetValue(std::size_t idx, int val)
    {
        if (idx >= size)
            return;
        array[idx] = val;
        snapshots[snapId][idx] = val;
    }

    // This function takes no parameters and returns the snapid.
    // snapid is the number of times that the snapshot() function was called minus 1.
    int Snapshot()
    {
        ++snapId;
        snapshots[snapId] = snapshots[snapId-1];
        return snapId - 1;
    }

    // Function get_value returns the value at the index idx with the given snapid.
    int GetValue(std::size_t idx, std::size_t snapshotId)
    {
        if (snapshots.count(snapshotId) && idx < size)
        {
            // snapshot id exist
            if (snapshots[snapshotId].count(idx))
                return snapshots[snapshotId][idx];
            else
                return 0;
        }
        return -1;
    }
};

int main()
{
}
