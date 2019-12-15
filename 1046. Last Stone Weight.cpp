//https://leetcode.com/problems/last-stone-weight/

class Solution {
public:
    int lastStoneWeight(vector<int> &stones)
    {
        int heap[stones.size()];
        for (int i = 0; i < stones.size(); ++i)
        {
            heap[i] = stones[i];
            push_heap(heap, heap + i + 1);
        }
        int heap_size = stones.size() - 1;
        while (heap_size != 0)
        {
            pop_heap(heap, heap + heap_size + 1);
            int x1 = heap[heap_size];
            heap_size--;
            pop_heap(heap, heap + heap_size + 1);
            int x2 = heap[heap_size];
            heap_size--;
            int x = abs(x1 - x2);
            heap[++heap_size] = x;
            push_heap(heap, heap + heap_size + 1);
        }
        return heap[0];
    }
};