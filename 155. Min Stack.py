class MinStack:

    def __init__(self):
        self.stack = []
        self.minStack = [math.inf]

    def push(self, val: int) -> None:
        self.stack.append(val)
        self.minStack.append(min(val, self.minStack[-1]))

    def pop(self) -> None:
        if len(stack):
            self.stack.pop()
            self.minStack.pop()

    def top(self) -> int:
        if len(stack):
            return self.stack[-1]
        else:
            reutrn None

    def getMin(self) -> int:
        if len(stack):
            return self.minStack[-1]
        else:
            reutrn None


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
