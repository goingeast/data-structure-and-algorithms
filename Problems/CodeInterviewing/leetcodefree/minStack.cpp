class MinStack {
public:
    void push(int x) {
        if(minStack.empty()){
            minStack.push(x);
            min = x;
            return;
        }
        if(x < min){
        	minStack.push(x - min + x);
        	min = x;
        }else{
        	minStack.push(x);
        }
    }

    void pop() {
        if(minStack.top() < min){
        	min =  min - minStack.top() + min;
        }
        minStack.pop();
        
    }

    int top() {
    	long top =  minStack.top();
    	if(top < min){
    	    top = min;
    	}
    	return top;
    }

    int getMin() {
        return min;
    }
 private:
 	stack<long> minStack;
 	long min;
};