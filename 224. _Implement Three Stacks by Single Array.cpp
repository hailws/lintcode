/**
Implement three stacks by single array.

You can assume the three stacks has the same size and big enough, you don't need to care about how to extend it if one of the stack is full.

Example
ThreeStacks(5)  // create 3 stacks with size 5 in single array. stack index from 0 to 2
push(0, 10) // push 10 in the 1st stack.
push(0, 11)
push(1, 20) // push 20 in the 2nd stack.
push(1, 21)
pop(0) // return 11
pop(1) // return 21
peek(1) // return 20
push(2, 30)  // push 30 in the 3rd stack.
pop(2) // return 30
isEmpty(2) // return true
isEmpty(0) // return false
 */
/**
用单一数组实现三个栈。这里我讨巧了，弄了三个大小相同的栈，完全忽略了栈之间会出现overlap后需要rotate的情况，竟然也通过了ORZ。正统方法还是三个指针，一个指向数组头，一个指向数组尾，一个指向数组1/3大小处。如果出现overlap的情况，就把中间的栈整体向反方向挪动一格。
*/

class ThreeStacks {
private:
    vector<int> q;
    vector<int> idx=vector<int>(3);
    int idx1,idx2,idx3,n;
public:
    /*
    * @param size: An integer
    */ThreeStacks(int size) {
        q.reserve(size*3);
        for(auto i:idx){
            i=0;
        }
        n=size;// do intialization if necessary
    }

    /*
     * @param stackNum: An integer
     * @param value: An integer
     * @return: nothing
     */
    void push(int stackNum, int value) {
        q[n*stackNum+idx[stackNum]]=value;
        idx[stackNum]++;// Push value into stackNum stack
    }

    /*
     * @param stackNum: An integer
     * @return: the top element
     */
    int pop(int stackNum) {
        int rst=q[n*stackNum+idx[stackNum]-1];
        idx[stackNum]--;
        return rst;// Pop and return the top element from stackNum stack
    }

    /*
     * @param stackNum: An integer
     * @return: the top element
     */
    int peek(int stackNum) {
        return q[n*stackNum+idx[stackNum]-1];// Return the top element
    }

    /*
     * @param stackNum: An integer
     * @return: true if the stack is empty else false
     */
    bool isEmpty(int stackNum) {
        return idx[stackNum]==0;// write your code here
    }
};