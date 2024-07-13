vector<int> nextLargerNodes(ListNode* head) {
// Creating a stack of pairs to hold index-value pairs
stack<pair<int, int>> st;
// Creating a vector to store the final result
vector<int> ans;
// Index variable 'i' to keep track of the current index
int i = 0;
// Iterate through the linked list until head becomes NULL
while(head){
// Add a placeholder (0) to the answer vector for the current node
ans.push_back(0);
// Check if the stack is not empty and the current node's value is greater
// than the value at the top of the stack. If true, update the answer vector.
while(!st.empty() && st.top().second < head->val){
auto top = st.top();
st.pop();
ans[top.first] = head->val;
}
// Push the current index-value pair into the stack
st.push({i++, head->val});
// Move to the next node in the linked list
head = head->next;
}