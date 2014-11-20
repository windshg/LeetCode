LeetCode
========
###Foreword
LeetCode is a cool platform for practicing programming as problems described here are rudimental properly compared to ones in CodeForce, POJ, etc and the user experience is excellent in contrast.

The deduction of solution is more important than the solution itself especially when you work it out for self-improvement. The solution to problem in a small scale is always easy to come up with, say, brute force, while it's bloody difficult in large scale.  TLE, Stack Overflow, etc, pop up in your way to be Accepted. Complexity of time and space is the critical concept in algorithm design which you should always keep in your mind. Think in large scale.
###Retrospect
Sometimes the most straight-forward solutions to some questions are incredibly simple. For example, "Binary Tree Postorder Traversal". A brain-dead recursion may actually be accepted. Cost of time is O(n). Good!!! Cost of space is O(n). Acceptable!!! ... Come on, don't be such a baby. If so, you can't get any improvement after solving this "stupid" question. Try an iterative way with the same complexity of both time and space. Then try a new way with just O(1) space known as “Morris Traversal”...

Whenever you meet a linked-list-related problem, dummy head should be come up in your mind in conditioned response. It's so helpful to have a "useless" node pointing to the real head that you can find out some solutions accidentally at times and make your code more tidy empirically. Of course it's unnecessary to add such an extra character in some situation (say, traveling a linked list, maximum node in a linked list, whatever).

DFS and BFS should always be at the head of your chain of thought when you meet a question not quite complicated literally or brute-force-enabled. It's straight-forward and non-tricky. Moreover, it works.

Dynamic-programming-related problems given in LeetCode (say, Triangle, Edit Distance, etc), are too few and mildly fundamental. Frankly, dynamic programming plays a crucial role in algorithm design. If you really want to dig out something internal and heuristic in rationale, don't be satisfied by LeetCode.

When you find all pairs can be generated from the multiplication of all elements in left subtree and in right subtree respectively, a pitfall may show up. When you find some elements in the result set happen to be duplicated, that means the idea your solution based on was almost incorrect. There is no need to dig out any tricks from it anymore. Try a simple DFS or BFS. You may see the light.

Every recursive solution could be converted to an iterative one deliberately considering that there is no real recursive logic in the process of your final executable program actually. Think about how your computer works when you call a function so that you could think it through. It is roughly as:

* Put parameter variables on stack.
* Put local variables on stack.
* Jump to the address of the function.
* Load variables from stack.
* Run the logic in function.
* clean stack.
* Jump back to caller's space.

Overtly stack is the key point. If you want a conversion from recursion to iteration, stack will be the primitive bridge promising and non-tricky by which it's easy to figure a way out. Necessary is it to make such a conversion in case of large scale. Recursion is easier to come up with and more readable than iteration while correspondingly it would lay higher claim to memory. Local variables would be stacked over and over during the recursive call until the whole invoke finishes or stack overflows to crash. Problem solved when you use heap-allocated stack from STL. Anyway, each way has its merit and is needed in specific case. You have better grasp both of them.

The widespread use of stack as a LIFO associative container is not limited in just being a conversion bridge. When you try using stack to store some extra information for your solution, at first you may consider having elements in your target data set stored in it. However, if you find any of your ideas in which individual's value doesn't make a difference. It's time for you to store something else instead of the raw value. You may take a try to store the frequency of occurrence of elements visited or anything else meaningful.
###Summary
A problem is there, a solution is there.
Life is not easy, especially for coder. 
Long may you code...


