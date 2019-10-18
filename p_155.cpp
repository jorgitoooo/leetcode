/* ---------------
 * Jorge L. Garcia
 * //2019
 * ---------------
 * Min Stack
 */

#include <climits>
#include <cstdio>
#include <vector>

using namespace std;

class MinStack {
    struct min_el {
			int val;
			int idx;
		} min_el;

    vector<int> stk;

public:
    MinStack() {
        min_el.val = INT_MAX;
        min_el.idx = -1;
    }
    
    void push(int x) {
        if(x < min_el.val) {
            min_el.val = x;
            min_el.idx = stk.size();
        }
        stk.emplace_back(x);
    }
    
    void pop() {
        if(stk.size() > 0) {
            if(min_el.idx == (stk.size() - 1)) {
                min_el.val = INT_MAX;
                min_el.idx = -1;
                stk.pop_back();

                for(int i = 0; i < stk.size(); i++) {
                    if(stk[i] < min_el.val) {
                        min_el.val = stk[i];
                        min_el.idx = i;
                    }
                }
            } else {
                stk.pop_back();
            }
        }
    }
    
    int top() {
        return stk.back();
    }
    
    int getMin() {
        return min_el.val;
    }
};

int main(int argc, char **argv)
{
	MinStack *minstk = new MinStack();

	minstk->push(4);
	minstk->push(-2);
	minstk->push(3);

	printf("min: %d\n", minstk->getMin());
	printf("top: %d\n", minstk->top());
	minstk->pop();
	printf("min: %d\n", minstk->getMin());
	printf("top: %d\n", minstk->top());
	minstk->pop();
	printf("min: %d\n", minstk->getMin());
	printf("top: %d\n", minstk->top());
	minstk->pop();

	return 0;
}
