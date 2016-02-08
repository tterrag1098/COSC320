#include <Sorter.h>

template<size_t N>
class MergeSorter : public Sorter<int, N>
{
public:
    MergeSorter() : Sorter<int, N>("Merge") {}
    void sort(int li[N])
    {
        // Reset the operation counter
        this->reset();
        // Offload to a recursive helper method
        sort(li, 0, N);
    }
private:
    // Work array, instance value to avoid unnecessary allocation
    int work[N];
    void merge(int* li, int low, int high, int mid)
    {
        // The index for the left half
        int idx1 = low;
        // The index for the right half
        int idx2 = mid;
        for (int i = low; i < high; i++)
        {
            // One operation per loop
            this->op();
            // Cache the values for cleaner code
            int left = li[idx1], right = li[idx2];
            // If we are not done with the left list, or we ARE done with the right list, this block will always be used
            // Otherwise, check that the element from the left list is lower than (or equal to) the right list
            // Since both lists are sorted, we can process them in order
            if (idx1 < mid && (idx2 >= high || left <= right))
            {
                // Add the current left value to the work array at this position
                work[i] = left;
                idx1++;
            }
            else
            {
                // Add the current right value to the work array at this position
                work[i] = right;
                idx2++;
            }
            // One guaranteed operation
            this->op();
            // Go through the potentially short-circuited comparisons
            // If idx1 is finished, we must have done more than one comparison
            if (idx1 >= mid)
            {
                this->op();
                // If the idx2 is not finished, 3 comparisons were done, so add one more
                if (idx2 < high)
                {
                    this->op();
                }
            }
        }

        // Copy the now sorted subsection of the work array into the real array
        for (int i = low; i < high; i++)
        {
            // One operation per copy
            this->op();
            li[i] = work[i];
        }
    }

    void sort(int* li, int low, int high)
    {
        // Base case: difference between high and low being less than 2 means that we have single element sub-arrays
        if (high - low >= 2)
        {
            // The middle position, exclusive
            int mid = (low + high) / 2;
            // Sort the array from low (inclusive) to mid (exclusive)
            sort(li, low, mid);
            // Sort the array from mid (inclusive) to high (exclusive)
            sort(li, mid, high);
            // Merge the resulting sorted sub-arrays
            merge(li, low, high, mid);
        }
        // One operation in if block
        this->op();
    }
};
